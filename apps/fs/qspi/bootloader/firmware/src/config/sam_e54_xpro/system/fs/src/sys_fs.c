/*******************************************************************************
  File System System-Library Interface Implementation.

  Company:
    Microchip Technology Inc.

  File Name:
    sys_fs.c

  Summary:
    This file contains implementation of SYS_FS functions.

  Description:
    This file contains implementation of SYS_FS functions.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
//DOM-IGNORE-END

#include <stdarg.h>
#include <string.h>

#include "system/fs/src/sys_fs_local.h"
#include "system/fs/sys_fs_media_manager.h"

// *****************************************************************************
/* Registration table for each native file system

  Summary:
    Defines the registration table for each native file system.

  Description:
    Defines the registration table for each native file system.

  Remarks:
    None
*/
static SYS_FS_REGISTRATION_TABLE gSYSFSObj[SYS_FS_MAX_FILE_SYSTEM_TYPE];

// *****************************************************************************
/* Mount point

  Summary:
    Defines the mount point required for mounting each volume.

  Description:
    Defines the mount point required for mounting each volume.

  Remarks:
    None
*/
static SYS_FS_MOUNT_POINT gSYSFSMountPoint[SYS_FS_VOLUME_NUMBER];

// *****************************************************************************
/* Current Mount point

  Summary:
    Defines the mount point currently being used.

  Description:
    Defines the mount point which will be used as default, in case the application
    do not specify the full path name along with the drive name.

  Remarks:
    None
*/
static SYS_FS_CURRENT_MOUNT_POINT  gSYSFSCurrentMountPoint;

// *****************************************************************************
/* File object

  Summary:
    Defines the File object for each file opened.

  Description:
    Defines the File object for each file opened on the system.

  Remarks:
    None
*/
static SYS_FS_OBJ gSYSFSFileObj[SYS_FS_MAX_FILES];

// *****************************************************************************
/* Directory object

  Summary:
    Defines the Directory object for each directory opened.

  Description:
    Defines the Directorye object for each directory opened on the system.

  Remarks:
    None
*/
static SYS_FS_DIR_OBJ  gSYSFSDirObj[SYS_FS_MAX_FILES];

/* File system object instance mutex */
static OSAL_MUTEX_DECLARE(gSysFsMutex);
/* Variable to hold the error value */
static SYS_FS_ERROR errorValue;

//******************************************************************************
/*Function:
    static bool SYS_FS_GetDisk
    (
        const char *path,
        SYS_FS_MOUNT_POINT **disk,
        uint8_t *buffer
    )

   Summary:
     Retrieves the disk from the name of the disk.

   Description:
     Retrieves the disk from the name of the disk.

   Remarks:
     None
***************************************************************************/

static bool SYS_FS_GetDisk
(
    const char *path,
    SYS_FS_MOUNT_POINT **disk,
    uint8_t *buffer
)
{
    SYS_FS_MOUNT_POINT *volume = NULL;
    const char *ptr = NULL;
    uint16_t pathLength = 0;
    uint8_t index = 0;
    uint8_t mountNameLength = 0;
    bool status = false;

    ptr = path;
    pathLength = (uint16_t)strlen (ptr);

    if (strncmp((const char*)path, (const char *)"/mnt/", 5) == 0)
    {
        ptr = path + 5;
        pathLength -= 5U;

        /* Start with 0th index and find an index that is free. */
        for (index = 0; index != SYS_FS_VOLUME_NUMBER; index++)
        {
            volume = &gSYSFSMountPoint[index];
            if (volume->inUse == true)
            {
                /* Find the volume with the matching "mountName". Ignore the
                 * first 5 chars --> "/mnt/". */
                mountNameLength = volume->mountNameLength;
                if (strncmp (ptr, volume->mountName, mountNameLength) == 0)
                {
                    /* Found the matching volume. */
                    *disk = volume;

                    ptr += (mountNameLength);
                    pathLength -= (mountNameLength);

                    status = true;
                    break;
                }
            }
        }

        if (!status)
        {
            /* Invalid volume. */
            errorValue = SYS_FS_ERROR_INVALID_NAME;
        }
    }
    else
    {
        /* Since the path does not contain the "mountName", assume the default
           volume. */
        if (gSYSFSCurrentMountPoint.inUse == true)
        {
            *disk = gSYSFSCurrentMountPoint.currentDisk;
            status = true;
        }
        else
        {
            errorValue = SYS_FS_ERROR_NO_FILESYSTEM;
        }
    }

    if ((status) && (buffer != NULL))
    {
        if ((pathLength + 3U) > SYS_FS_PATH_LEN_WITH_DISK_NUM)
        {
            errorValue = SYS_FS_ERROR_INVALID_NAME;
            status = false;
        }
        else
        {
            (void) memset(buffer, 0, (uint32_t)pathLength + 3U);

            /* Append "0:" before the file name. This is required for different disks
             * */
            *buffer = (*disk)->diskNumber + (uint8_t)'0';
             buffer++;
            *buffer = (uint8_t)':';
             buffer++;

            if (pathLength != 0U)
            {
                (void) memcpy((char *)buffer, (const char *)ptr, pathLength);
                pathLength ++;
            }

            buffer[pathLength] = (uint8_t)'\0';

            /* The status variable is already set to true. */
        }
    }

    return status;
}

//******************************************************************************
/*Function:
    static bool SYS_FS_StringWildCardCompare
    (
        const char * ptr1,
        const char *ptr2
    )

  Summary:
    Compares the 2 file names with wild character.

  Description:
    Compares the 2 file names with wild character. This is required for file
    search of a directory.

  Remarks:
    None
***************************************************************************/
static bool SYS_FS_StringWildCardCompare
(
    const char * ptr1,
    const char *ptr2
)
{
    do
    {
        if((*ptr1 != '?') && (*ptr1 != '*') && (*ptr1 != *ptr2))
        {
            return false;
        }
        else
        {
           if(*ptr1 == '*')
            {
                ptr1++;
                if(*ptr1 == '\0')
                {
                    return true;
                }
                else if(*ptr1 == '?')
                {
                    continue;
                }
                else
                {
                    // Find the same character in second string as well
                    while((*ptr1 != *ptr2) && (*ptr2 != '\0'))
                    {
                        ptr2++;
                    }
                    if(*ptr2 == '\0')
                    {
                        return false;
                    }
                }
            }
            else
            {
                ptr1++;
                ptr2++;
            }
        }
    }while(*ptr1 != '\0');

    if((*ptr1 == '\0') && (*ptr2 == '\0'))
    {
        return true;
    }
    return false;
}


//******************************************************************************
/*Function:
    SYS_FS_RESULT SYS_FS_Initialize
    (
        const void* initData
    )

  Summary:
    Initializes the file system abstraction layer (sys_fs layer).

  Description:
    This function initializes the abstraction layer (sys_fs layer) and sets up
    the necessary parameters.

  Remarks:
    See sys_fs.h for usage information.
***************************************************************************/

/* MISRA C-2012 Rule 11.8 deviated:1 Deviation record ID -  H3_MISRAC_2012_R_11_8_DR_1 */
SYS_FS_RESULT SYS_FS_Initialize
(
    const void* initData
)
{
    SYS_FS_REGISTRATION_TABLE *init = (SYS_FS_REGISTRATION_TABLE *)initData;
    uint8_t index = 0;

    if (init == NULL)
    {
        return SYS_FS_RES_FAILURE;
    }

    for (index = 0; index != SYS_FS_MAX_FILES; index++)
    {
        gSYSFSFileObj[index].inUse = false;
        gSYSFSFileObj[index].mountPoint = NULL;
        gSYSFSFileObj[index].nativeFSFileObj = 0U;
        (void) memset(gSYSFSFileObj[index].fileName, 0, SYS_FS_FILE_NAME_LEN);
        gSYSFSFileObj[index].errorValue = SYS_FS_ERROR_OK;

        gSYSFSDirObj[index].inUse = false;
        gSYSFSDirObj[index].mountPoint = NULL;
        gSYSFSDirObj[index].nativeFSDirObj = 0U;
        gSYSFSDirObj[index].errorValue = SYS_FS_ERROR_OK;
    }

    for (index = 0; index != SYS_FS_MAX_FILE_SYSTEM_TYPE; index++)
    {
        gSYSFSObj[index].nativeFileSystemType = init->nativeFileSystemType;
        gSYSFSObj[index].nativeFileSystemFunctions = init->nativeFileSystemFunctions;
        init++;
    }

    if (OSAL_MUTEX_Create(&gSysFsMutex) != OSAL_RESULT_SUCCESS)
    {
        return SYS_FS_RES_FAILURE;
    }

    for (index = 0; index != SYS_FS_VOLUME_NUMBER; index++)
    {
        if (OSAL_MUTEX_Create(&(gSYSFSMountPoint[index].mutexDiskVolume)) != OSAL_RESULT_SUCCESS)
        {
            return SYS_FS_RES_FAILURE;
        }
    }

    return SYS_FS_RES_SUCCESS;
}
/* MISRAC 2012 deviation block end */

// *****************************************************************************
/* Function:
    void SYS_FS_Tasks
    (
        void
    )

  Summary:
    Maintains the File System tasks and functionalities.

  Description:
    This function is used to run the various tasks and functionalities of
    sys_fs layer.

  Returns:
    See sys_fs.h for usage information.
*/

void SYS_FS_Tasks ( void )
{
    /* Task routine for media manager */
    SYS_FS_MEDIA_MANAGER_Tasks();
}

//******************************************************************************
/*Function:
    void SYS_FS_EventHandlerSet
    (
        const void* eventHandler,
        const uintptr_t context
    )

  Summary:
    Allows a client to identify an event handling function for the file system
    to call back when mount/unmount operation has completed.

  Description:
    This function allows a client to identify an event handling function for
    the File System to call back when mount/unmount operation has completed.
    The file system will pass mount name back to the client by calling
    "eventHandler".

  Returns:
    None

    See sys_fs.h for usage information.
***************************************************************************/
void SYS_FS_EventHandlerSet
(
    const void * eventHandler,
    const uintptr_t context
)
{
    SYS_FS_MEDIA_MANAGER_EventHandlerSet(eventHandler, context);
}

//******************************************************************************
/*Function:
    SYS_FS_RESULT SYS_FS_Mount
    (
        const char *devName,
        const char *mountName,
        SYS_FS_FILE_SYSTEM_TYPE filesystemtype,
        unsigned long mountflags,
        const void *data
    );

  Summary:
    Mounts the file system.

  Description:
    The mount command attaches the file system specified to a volume. The call
    to the mount should be non blocking in nature.  The application code has to
    allow the SYS_FS_Tasks to run periodically while calling the SYS_FS_Mount
    function. If the SYS_FS_Mount is called in a blocking mode, then the
    SYS_Tasks() never gets a chance to run and therefore, the media will not be
    analyzed and finally, the SYS_FS_Mount will never succeed.  This will
    result in a deadlock.

    There is no mechanism available for the application to know if the
    specified volume (devName) is really attached or not. The only available
    possibility is to keep trying to mount the volume (with the devname), until
    success is achieved or use the Automount feature.

    It is prudent that the application code implements a time-out mechanism
    while trying to mount a volume (by calling SYS_FS_Mount). The trial for
    mount should continue at least 10 times before before assuming that the
    mount will never succeed. This has to be done for every new volume to be
    mounted.

    Once the mount is successful the application needs to use SYS_FS_Error()
    API to know if the mount was successful with valid filesystem on media
    or not. If SYS_FS_ERROR_NO_FILESYSTEM is returned application needs to
    Format the media using the SYS_FS_DriveFormat() API before performing
    any operations.

    The standard names for volumes (devName) used in the MPLAB Harmony file
    system is as follows:
        NVM       - "nvm"    "media number" "volume number"
        SD card   - "mmcblk" "media number" "volume number"
        MSD       - "sd"     "media number" "volume number"

    Where, "media number" a, b, c... depends on the number of the type of
    connected media, and where, "volume number" 1, 2, 3... depends on the
    number of partitions in that media.

    The convention for assigning names to volumes is further described below
    with examples:

    If a SD card (with four partitions) is attached to the system, and assuming
    all four partitions are recognized, there will be four devNames:
      1. mmcblka1
      2. mmcblka2
      3. mmcblka3 and
      4. mmcblka4

    Subsequently, if NVM media is attached that has only one partition, the
    devname will be: nvma1.

    Later, if another SD card is attached to the system that has one partition,
    the devname will be mmcblkb1.

    Finally, there will be six volume names (or devNames), which are available
    for the application to be mounted and used for the file system.

  Remarks:
    See sys_fs.h for usage information.
***************************************************************************/

SYS_FS_RESULT SYS_FS_Mount
(
    const char *devName,
    const char *mountName,
    SYS_FS_FILE_SYSTEM_TYPE filesystemtype,
    unsigned long mountflags,
    const void *data
)
{
    int fileStatus = -1;
    SYS_FS_MOUNT_POINT *disk = NULL;
    SYS_FS_VOLUME_PROPERTY volumeProperty;
    uint8_t index = 0;
    uint8_t mountPoint = 0;
    OSAL_RESULT osalResult = OSAL_RESULT_FAIL;
    bool status = false;

    const char *ptr = NULL;

    (void)mountflags;
    (void)data;

    /* Validate the parameters. */
    if ((devName == NULL) || (mountName == NULL) || ((filesystemtype != FAT) && (filesystemtype != MPFS2) && (filesystemtype != LITTLEFS) && (filesystemtype != FILEX)))
    {
        errorValue = SYS_FS_ERROR_INVALID_PARAMETER;
        return SYS_FS_RES_FAILURE;
    }

    /* Check if the media has been attached, analyzed and allocated a volume. */
    if (SYS_FS_MEDIA_MANAGER_MediaStatusGet(devName) != true)
    {
        errorValue = SYS_FS_ERROR_NOT_READY;
        return SYS_FS_RES_FAILURE;
    }

    /* Clear the error value when mount is successful */
    errorValue = SYS_FS_ERROR_OK;

    /* Verify if the requested file system is supported by SYS_FS */
    for (index = 0; index != SYS_FS_MAX_FILE_SYSTEM_TYPE; index++)
    {
        if (gSYSFSObj[index].nativeFileSystemType == filesystemtype)
        {
            break;
        }
    }

    if (index >= SYS_FS_MAX_FILE_SYSTEM_TYPE)
    {
        /* The requested file system is not supported. */
        errorValue = SYS_FS_ERROR_FS_NOT_SUPPORTED;
        return SYS_FS_RES_FAILURE;
    }

    /* Fetch the properties of the volume from the media manager. */
    status = SYS_FS_MEDIA_MANAGER_VolumePropertyGet(devName, &volumeProperty);
    if (status == false)
    {
        errorValue = SYS_FS_ERROR_DISK_ERR;
        return SYS_FS_RES_FAILURE;
    }

    /* Check if the volume property matches. */
    if ((volumeProperty.fsType != filesystemtype) && (volumeProperty.fsType != UNSUPPORTED_FS))
    {
        errorValue = SYS_FS_ERROR_FS_NOT_MATCH_WITH_VOLUME;
        return SYS_FS_RES_FAILURE;
    }

    /* Acquire a mutex. */
    osalResult = OSAL_MUTEX_Lock(&gSysFsMutex, OSAL_WAIT_FOREVER);
    if (osalResult != OSAL_RESULT_SUCCESS)
    {
        errorValue = SYS_FS_ERROR_DENIED;
        return SYS_FS_RES_FAILURE;
    }

    /* Find a volume/mount point that is not in use. */
    status = false;
    for (mountPoint = 0; mountPoint != SYS_FS_VOLUME_NUMBER; mountPoint++)
    {
        disk = &gSYSFSMountPoint[mountPoint];
        if (disk->inUse == false)
        {
            status = true;
            break;
        }
    }

    if (status == false)
    {
        /* Release the acquired mutex. */
        (void) OSAL_MUTEX_Unlock (&gSysFsMutex);

        errorValue = SYS_FS_ERROR_NOT_ENOUGH_FREE_VOLUME;
        return SYS_FS_RES_FAILURE;
    }

    /* Populate the disk members. */
    disk->fsType = filesystemtype;
    disk->fsFunctions = gSYSFSObj[index].nativeFileSystemFunctions;

    /* Find the mount name length and save it for later use. */
    disk->mountNameLength = 0;
    ptr = (mountName + 5);
    while ((*ptr != '/') && (*ptr != '\0'))
    {
        ptr++;
        disk->mountNameLength ++;
    }

    disk->mountName = (mountName + 5);
    disk->diskNumber = (uint8_t)volumeProperty.volNumber;

    /* Acquire the volume mutex. */
    osalResult = OSAL_MUTEX_Lock(&(disk->mutexDiskVolume), OSAL_WAIT_FOREVER);
    if (osalResult != OSAL_RESULT_SUCCESS)
    {
        errorValue = SYS_FS_ERROR_DENIED;

        /* Release the acquired mutex. */
        (void) OSAL_MUTEX_Unlock (&gSysFsMutex);

        return SYS_FS_RES_FAILURE;
    }

    if (disk->fsFunctions->chdrive != NULL)
    {
        (void) disk->fsFunctions->chdrive(disk->diskNumber);
    }
    else
    {
        errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
    }

    if (disk->fsFunctions->mount != NULL)
    {
        fileStatus = disk->fsFunctions->mount(disk->diskNumber);
        errorValue = (SYS_FS_ERROR)fileStatus;
        if (fileStatus == (int)SYS_FS_ERROR_NO_FILESYSTEM)
        {
            fileStatus = 0;
        }
    }
    else
    {
        errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
        fileStatus = -1;
    }

    /* Release the acquired mutex. */
    (void) OSAL_MUTEX_Unlock (&(disk->mutexDiskVolume));

    /* Set the Disk in Use to true only when Mount is success */
    if (fileStatus == 0)
    {
        disk->inUse = true;

        /* Put the recently assigned disk as the current disk */
        gSYSFSCurrentMountPoint.inUse = true;
        gSYSFSCurrentMountPoint.currentDisk = disk;
    }

    /* Release the acquired mutex. */
    (void) OSAL_MUTEX_Unlock (&gSysFsMutex);

    return (fileStatus == 0) ? SYS_FS_RES_SUCCESS : SYS_FS_RES_FAILURE;
}

//******************************************************************************
/*Function:
    SYS_FS_RESULT SYS_FS_Unmount
    (
        const char *fname
    );

  Summary:
    Unmounts the file system.

  Description:
    This function removes (unmounts) the attachment of the volume from the file
    system.

  Remarks:
    See sys_fs.h for usage information.
***************************************************************************/

SYS_FS_RESULT SYS_FS_Unmount
(
    const char *fname
)
{
    int fileStatus = -1;
    uint32_t index = 0;
    OSAL_RESULT osalResult = OSAL_RESULT_FAIL;
    SYS_FS_MOUNT_POINT *disk = NULL;

    if (fname == NULL)
    {
        errorValue = SYS_FS_ERROR_INVALID_PARAMETER;
        return SYS_FS_RES_FAILURE;
    }

    /* Get disk number */
    if (SYS_FS_GetDisk(fname, &disk, NULL) == false)
    {
        /* "errorValue" contains the reason for failure. */
        return SYS_FS_RES_FAILURE;
    }

    /* Acquire the mutex. */
    osalResult = OSAL_MUTEX_Lock (&gSysFsMutex, OSAL_WAIT_FOREVER);
    if (osalResult != OSAL_RESULT_SUCCESS)
    {
        errorValue = SYS_FS_ERROR_DENIED;
        return SYS_FS_RES_FAILURE;
    }

    /* Acquire the mutex. */
    osalResult = OSAL_MUTEX_Lock (&(disk->mutexDiskVolume), OSAL_WAIT_FOREVER);
    if (osalResult != OSAL_RESULT_SUCCESS)
    {
        errorValue = SYS_FS_ERROR_DENIED;

        /* Release the mutex. */
        (void) OSAL_MUTEX_Unlock (&gSysFsMutex);

        return SYS_FS_RES_FAILURE;
    }

    if (disk->fsFunctions->unmount != NULL)
    {
        fileStatus = disk->fsFunctions->unmount(disk->diskNumber);
        errorValue = (SYS_FS_ERROR)fileStatus;
    }
    else
    {
        errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
    }

    (void) OSAL_MUTEX_Unlock (&(disk->mutexDiskVolume));

    if (fileStatus == 0)
    {
        for (index = 0; index != (uint32_t)SYS_FS_MAX_FILES; index++)
        {
            if (gSYSFSFileObj[index].mountPoint == disk)
            {
                gSYSFSFileObj[index].inUse = false;
            }

            if (gSYSFSDirObj[index].mountPoint == disk)
            {
                gSYSFSDirObj[index].inUse = false;
            }
        }

        disk->inUse = false;
        disk->mountName = NULL;
        disk->fsFunctions = NULL;
        disk->mountNameLength = 0;

        /* Reset the current mount point if it is set to the current disk. */
        if ((gSYSFSCurrentMountPoint.inUse == true) && (gSYSFSCurrentMountPoint.currentDisk == disk))
        {
            gSYSFSCurrentMountPoint.inUse = false;
        }
    }

    /* Release the acquired mutex. */
    (void) OSAL_MUTEX_Unlock (&gSysFsMutex);

    return (fileStatus == 0) ? SYS_FS_RES_SUCCESS : SYS_FS_RES_FAILURE;
}

//******************************************************************************
/* Function:
    SYS_FS_HANDLE SYS_FS_FileOpen
    (
        const char* fname,
        SYS_FS_FILE_OPEN_ATTRIBUTES attributes
    );

  Summary:
    Opens a file

  Description:
    This function opens a file with the requested attributes.

  Remarks:
    See sys_fs.h for usage information.
***************************************************************************/

SYS_FS_HANDLE SYS_FS_FileOpen
(
    const char *fname,
    SYS_FS_FILE_OPEN_ATTRIBUTES attributes
)
{
    int fileStatus = -1;
    uint16_t index = 0;
    uint8_t mode = 0;
    SYS_FS_OBJ *fileObj = NULL;
    SYS_FS_MOUNT_POINT *disk = NULL;
    uint8_t pathWithDiskNo[SYS_FS_PATH_LEN_WITH_DISK_NUM] = { 0 };
    uint8_t *ptr = NULL;
    OSAL_RESULT osalResult = OSAL_RESULT_FAIL;

    /* Get the disk from the name, and also append the disk number prior to the
     * file name like this "0:file.txt" */
    if (SYS_FS_GetDisk(fname, &disk, pathWithDiskNo) == false)
    {
        /* "errorValue" contains the reason for failure. */
        return SYS_FS_HANDLE_INVALID;
    }

    /* For MPFS file system, opening a file is possible only in "READ" mode.
     * TODO: These type of checks should be done by the native file system. */
    if ((disk->fsType == MPFS2) && (attributes != SYS_FS_FILE_OPEN_READ))
    {
        errorValue = SYS_FS_ERROR_DENIED;
        return SYS_FS_HANDLE_INVALID;
    }

    /* Acquire the mutex. */
    osalResult = OSAL_MUTEX_Lock(&gSysFsMutex, OSAL_WAIT_FOREVER);
    if (osalResult != OSAL_RESULT_SUCCESS)
    {
        errorValue = SYS_FS_ERROR_DENIED;
        return SYS_FS_HANDLE_INVALID;
    }

    /* Find a free file object. */
    for (index = 0; index < (uint16_t)SYS_FS_MAX_FILES; index ++)
    {
        fileObj = &gSYSFSFileObj[index];
        if (fileObj->inUse == false)
        {
            fileObj->inUse = true;
            fileObj->mountPoint = disk;
            break;
        }
    }

    /* Release the mutex. */
    (void) OSAL_MUTEX_Unlock(&gSysFsMutex);

    if (index >= (uint16_t)SYS_FS_MAX_FILES)
    {
        /* Could not find a free file object. */
        errorValue = SYS_FS_ERROR_TOO_MANY_OPEN_FILES;
        return SYS_FS_HANDLE_INVALID;
    }

    /* Save the file name for future use. Ignore the "0:/" */
    ptr = &pathWithDiskNo[3];
    if (pathWithDiskNo[2] != (uint8_t)'/')
    {
        /* Ignore the "0:" */
        ptr = &pathWithDiskNo[2];
    }

    for (index = 0; index < SYS_FS_FILE_NAME_LEN; index ++)
    {
        fileObj->fileName[index] = *ptr;
        if(*ptr++ == (uint8_t)'\0')
        {
            break;
        }
    }

    /* Acquire the mutex. */
    osalResult = OSAL_MUTEX_Lock(&(disk->mutexDiskVolume), OSAL_WAIT_FOREVER);
    if (osalResult != OSAL_RESULT_SUCCESS)
    {
        errorValue = SYS_FS_ERROR_DENIED;
        /* Mark the file object as free. */
        fileObj->inUse = false;
        return SYS_FS_HANDLE_INVALID;
    }

    mode = (uint8_t)attributes;

    errorValue = SYS_FS_ERROR_OK;

    if (disk->fsFunctions->open != NULL)
    {
        fileStatus = disk->fsFunctions->open((uintptr_t)&fileObj->nativeFSFileObj, (const char *)pathWithDiskNo, mode);

        errorValue = (SYS_FS_ERROR)fileStatus;
    }
    else
    {
        errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
    }

    /* Release the mutex. */
    (void) OSAL_MUTEX_Unlock (&(disk->mutexDiskVolume));

    if (fileStatus != 0)
    {
        /* Mark the file object as free. */
        fileObj->inUse = false;
    }

    return (fileStatus == 0) ? ((SYS_FS_HANDLE)fileObj) : SYS_FS_HANDLE_INVALID;
}

//******************************************************************************
/* Function:
    SYS_FS_RESULT SYS_FS_FileClose
    (
        SYS_FS_HANDLE handle
    );

  Summary:
    Closes a file.

  Description:
    This function closes an opened file.

  Remarks:
    See sys_fs.h for usage information.
***************************************************************************/
SYS_FS_RESULT SYS_FS_FileClose
(
    SYS_FS_HANDLE handle
)
{
    int fileStatus = -1;
    SYS_FS_OBJ *fileObj = (SYS_FS_OBJ *)handle;
    OSAL_RESULT osalResult = OSAL_RESULT_FAIL;

    /* Check if the handle is valid. */
    if (handle == SYS_FS_HANDLE_INVALID)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
        return SYS_FS_RES_FAILURE;
    }

    if (fileObj->inUse == false)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
        return SYS_FS_RES_FAILURE;
    }

    if (fileObj->mountPoint->fsFunctions->close == NULL)
    {
        fileObj->errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
        return SYS_FS_RES_FAILURE;
    }

    /* Clear the error. */
    fileObj->errorValue = SYS_FS_ERROR_OK;

    /* Acquire the volume mutex. */
    osalResult = OSAL_MUTEX_Lock(&(fileObj->mountPoint->mutexDiskVolume), OSAL_WAIT_FOREVER);
    if (osalResult != OSAL_RESULT_SUCCESS)
    {
        fileObj->errorValue = SYS_FS_ERROR_DENIED;
        return SYS_FS_RES_FAILURE;
    }

    fileStatus = fileObj->mountPoint->fsFunctions->close(fileObj->nativeFSFileObj);

    /* Release the acquired mutex. */
    (void) OSAL_MUTEX_Unlock(&(fileObj->mountPoint->mutexDiskVolume));

    if (fileStatus == 0)
    {
        /* Mark the file object as free. */
        fileObj->inUse = false;
        return SYS_FS_RES_SUCCESS;
    }
    else
    {
        fileObj->errorValue = (SYS_FS_ERROR)fileStatus;
        return SYS_FS_RES_FAILURE;
    }
}

//******************************************************************************
/*Function:
    bool SYS_FS_FileNameGet
    (
        SYS_FS_HANDLE handle,
        uint8_t* cName,
        uint16_t wLen
    );

  Summary:
    Reads the file name.

  Description:
    This function reads the file name of a file that is already open.

  Remarks:
    See sys_fs.h for usage information.
***************************************************************************/
bool SYS_FS_FileNameGet
(
    SYS_FS_HANDLE handle,
    uint8_t* cName,
    uint16_t wLen
)
{
    SYS_FS_OBJ *obj = (SYS_FS_OBJ *)handle;
    uint32_t index;

    if(handle == SYS_FS_HANDLE_INVALID)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
        return false;
    }

    if(obj->inUse == false)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
        return false;
    }

    if(wLen > SYS_FS_FILE_NAME_LEN)
    {
        wLen = SYS_FS_FILE_NAME_LEN;
    }

    for(index = 0;  index < wLen; index ++)
    {
        cName[index] = obj->fileName[index];
        /* break, in case end of string reached */
        if(obj->fileName[index] == (uint8_t)'\0')
        {
            break;
        }
    }

    return true;

}

//******************************************************************************
/* Function:
    size_t SYS_FS_FileRead
    (
        SYS_FS_HANDLE handle,
        void *buf,
        size_t nbyte
    );

  Summary:
    Read data from the file.

  Description:
    This function attempts to read nbyte bytes of data from the file associated
    with the file handle into the buffer pointed to by buf.

  Remarks:
    See sys_fs.h for usage information.
***************************************************************************/

size_t SYS_FS_FileRead
(
    SYS_FS_HANDLE handle,
    void *buffer,
    size_t nbyte
)
{
    int fileStatus = -1;
    SYS_FS_OBJ *fileObj = (SYS_FS_OBJ *)handle;
    uint32_t bytesRead = 0XFFFFFFFFU;
    OSAL_RESULT osalResult = OSAL_RESULT_FAIL;

    /* Check if the handle is valid. */
    if (handle == SYS_FS_HANDLE_INVALID)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
        return bytesRead;
    }

    /* Check if the file object is in use. */
    if (fileObj->inUse == false)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
        return bytesRead;
    }

    if (fileObj->mountPoint->fsFunctions->read_t == NULL)
    {
        fileObj->errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
        return bytesRead;
    }

    /* Acquire the volume mutex. */
    osalResult = OSAL_MUTEX_Lock(&(fileObj->mountPoint->mutexDiskVolume), OSAL_WAIT_FOREVER);
    if (osalResult != OSAL_RESULT_SUCCESS)
    {
        fileObj->errorValue = SYS_FS_ERROR_DENIED;
    }
    else
    {
        fileStatus = fileObj->mountPoint->fsFunctions->read_t(
                fileObj->nativeFSFileObj,
                buffer,
                nbyte,
                &bytesRead);

        /* Release the acquired mutex. */
        (void) OSAL_MUTEX_Unlock(&(fileObj->mountPoint->mutexDiskVolume));

        if (fileStatus != 0)
        {
            /* There was an error with the read operation. Update the error value.
             * */
            fileObj->errorValue = (SYS_FS_ERROR)fileStatus;
            bytesRead = 0XFFFFFFFFU;
        }
    }

    return bytesRead;
}

//******************************************************************************
/* Function:
    int SYS_FS_FileSeek
    (
        SYS_FS_HANDLE handle,
        int offset,
        SYS_FS_FILE_SEEK_CONTROL whence
    );

  Summary:
    Moves the file pointer by the requested offset.

  Description:
    This function sets the file pointer for a open file associated with the
    file handle, as follows:
      whence = SYS_FS_SEEK_SET - File offset is set to offset bytes from the
                                 beginning.
      whence = SYS_FS_SEEK_CUR - File offset is set to its current location
                                 plus offset.
      whence = SYS_FS_SEEK_END - File offset is set to the size of the file
                                 plus offset. The offset specified for this
                                 option should be negative for the file pointer
                                 to be valid.

    Trying to move the file pointer using SYS_FS_FileSeek, beyond the range of
    file will only cause the pointer to be moved to the last location of the
    file.

  Remarks:
    See sys_fs.h for usage information.
***************************************************************************/

int32_t SYS_FS_FileSeek
(
    SYS_FS_HANDLE handle,
    int32_t offset,
    SYS_FS_FILE_SEEK_CONTROL whence
)
{
    int fileStatus = -1;
    SYS_FS_OBJ *obj = (SYS_FS_OBJ *)handle;
    uint32_t tell = 0;
    uint32_t size = 0;
    uint32_t temp = 0;
    uint32_t offset1 = (uint32_t)offset;
    OSAL_RESULT osalResult = OSAL_RESULT_FAIL;

    /* Check if the handle is valid. */
    if (handle == SYS_FS_HANDLE_INVALID)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
        return -1;
    }

    /* Check if the file object is in use. */
    if (obj->inUse == false)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
        return -1;
    }

    if (obj->mountPoint->fsFunctions->seek == NULL)
    {
        /* The function is not supported in the native file system. */
        obj->errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
        return -1;
    }

    if (((whence == SYS_FS_SEEK_CUR) && (obj->mountPoint->fsFunctions->tell == NULL)) ||
        ((whence == SYS_FS_SEEK_END) && (obj->mountPoint->fsFunctions->size == NULL)))
    {
        /* The function is not supported in the native file system. */
        obj->errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
        return -1;
    }

    /* Clear out the error. */
    obj->errorValue = SYS_FS_ERROR_OK;

    /* Acquire the volume mutex. */
    osalResult = OSAL_MUTEX_Lock(&(obj->mountPoint->mutexDiskVolume), OSAL_WAIT_FOREVER);
    if (osalResult == OSAL_RESULT_SUCCESS)
    {
        /* SYS_FS_SEEK_SET case. */
        temp = offset1;

        if (whence == SYS_FS_SEEK_CUR)
        {
            tell = obj->mountPoint->fsFunctions->tell(obj->nativeFSFileObj);
            temp = (offset1 + tell);
        }
        else if (whence == SYS_FS_SEEK_END)
        {
            size = obj->mountPoint->fsFunctions->size(obj->nativeFSFileObj);
            temp = (offset1 + size);
        }
        else
        {
            /* Nothing to do */
        }

        fileStatus = obj->mountPoint->fsFunctions->seek(obj->nativeFSFileObj, temp);

        /* Release the acquired mutex. */
        (void) OSAL_MUTEX_Unlock(&(obj->mountPoint->mutexDiskVolume));

        if (fileStatus != 0)
        {
            obj->errorValue = (SYS_FS_ERROR)fileStatus;
            offset = -1;
        }
    }
    else
    {
        obj->errorValue = SYS_FS_ERROR_DENIED;
        offset = -1;
    }

    return offset;
}

//******************************************************************************
/*Function:
    int32_t SYS_FS_FileTell
    (
        SYS_FS_HANDLE handle
    );

  Summary:
    Obtains the file pointer position.

  Description:
    Obtains the current value of the file position indicator for the file
    pointed to by handle.

  Remarks:
    See sys_fs.h for usage information.
***************************************************************************/

int32_t SYS_FS_FileTell
(
    SYS_FS_HANDLE handle
)
{
    SYS_FS_OBJ *fileObj = (SYS_FS_OBJ *)handle;
    int fileStatus = -1;
    OSAL_RESULT osalResult = OSAL_RESULT_FAIL;

    /* Check if the handle is valid. */
    if (handle == SYS_FS_HANDLE_INVALID)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
        return -1;
    }

    /* Check if the file object is in use. */
    if (fileObj->inUse == false)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
        return -1;
    }

    if (fileObj->mountPoint->fsFunctions->tell == NULL)
    {
        fileObj->errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
        return -1;
    }

    /* Clear out the error. */
    fileObj->errorValue = SYS_FS_ERROR_OK;

    /* Acquire the volume mutex. */
    osalResult = OSAL_MUTEX_Lock(&(fileObj->mountPoint->mutexDiskVolume), OSAL_WAIT_FOREVER);
    if (osalResult == OSAL_RESULT_SUCCESS)
    {
        fileStatus = (int)fileObj->mountPoint->fsFunctions->tell(fileObj->nativeFSFileObj);

        /* Release the acquired mutex. */
        (void) OSAL_MUTEX_Unlock(&(fileObj->mountPoint->mutexDiskVolume));

        if (fileStatus < 0)
        {
            fileObj->errorValue = SYS_FS_ERROR_DISK_ERR;
        }
    }
    else
    {
        fileObj->errorValue = SYS_FS_ERROR_DENIED;
    }

    return fileStatus;
}

//******************************************************************************
/*Function:
    int32_t SYS_FS_FileSize
    (
        SYS_FS_HANDLE handle
    );

  Summary:
    Returns the size of the file in bytes.

  Description:
    This function returns the size of the file as pointed by the handle.

  Remarks:
    See sys_fs.h for usage information.
***************************************************************************/
int32_t SYS_FS_FileSize
(
    SYS_FS_HANDLE handle
)
{
    SYS_FS_OBJ *fileObj = (SYS_FS_OBJ *)handle;
    int fileStatus = -1;
    OSAL_RESULT osalResult = OSAL_RESULT_FAIL;

    /* Check if the handle is valid. */
    if (handle == SYS_FS_HANDLE_INVALID)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
        return -1;
    }

    /* Check if the file object is in use. */
    if (fileObj->inUse == false)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
        return -1;
    }

    if (fileObj->mountPoint->fsFunctions->size == NULL)
    {
        fileObj->errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
        return -1;
    }

    /* Clear out the error. */
    fileObj->errorValue = SYS_FS_ERROR_OK;

    /* Acquire the volume mutex. */
    osalResult = OSAL_MUTEX_Lock(&(fileObj->mountPoint->mutexDiskVolume), OSAL_WAIT_FOREVER);
    if (osalResult == OSAL_RESULT_SUCCESS)
    {
        fileStatus = (int)fileObj->mountPoint->fsFunctions->size(fileObj->nativeFSFileObj);
        /* Release the acquired mutex. */
        (void) OSAL_MUTEX_Unlock(&(fileObj->mountPoint->mutexDiskVolume));

        if (fileStatus < 0)
        {
            fileObj->errorValue = SYS_FS_ERROR_DISK_ERR;
        }
    }
    else
    {
        fileObj->errorValue = SYS_FS_ERROR_DENIED;
    }

    return fileStatus;
}

//******************************************************************************
/*Function:
    bool SYS_FS_FileEOF
    (
        SYS_FS_HANDLE handle
    );

  Summary:
    Checks for end of file.

  Description:
    Checks whether or not the file position indicator is at the end of the
    file.

  Remarks:
    See sys_fs.h for usage information.
***************************************************************************/
bool SYS_FS_FileEOF
(
    SYS_FS_HANDLE handle
)
{
    SYS_FS_OBJ *fileObj = (SYS_FS_OBJ *)handle;
    bool status = false;
    OSAL_RESULT osalResult = OSAL_RESULT_FAIL;

    /* Check if the handle is valid. */
    if (handle == SYS_FS_HANDLE_INVALID)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
        return false;
    }

    /* Check if the file fileObject is in use. */
    if (fileObj->inUse == false)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
        return false;
    }

    if (fileObj->mountPoint->fsFunctions->eof == NULL)
    {
        fileObj->errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
        return false;
    }

    /* Clear out the error. */
    fileObj->errorValue = SYS_FS_ERROR_OK;

    /* Acquire the volume mutex. */
    osalResult = OSAL_MUTEX_Lock(&(fileObj->mountPoint->mutexDiskVolume), OSAL_WAIT_FOREVER);
    if (osalResult == OSAL_RESULT_SUCCESS)
    {
        status = fileObj->mountPoint->fsFunctions->eof(fileObj->nativeFSFileObj);

        /* Release the acquired mutex. */
        (void) OSAL_MUTEX_Unlock(&(fileObj->mountPoint->mutexDiskVolume));
    }
    else
    {
        fileObj->errorValue = SYS_FS_ERROR_DENIED;
    }

    return status;
}

//******************************************************************************
/* Function:
    SYS_FS_RESULT SYS_FS_FileStat
    (
        const char *fname,
        SYS_FS_FSTAT *buf
    );

  Summary:
    Gets file status.

  Description:
    This function obtains information about a file associated with the file
    name, and populates the information in the structure pointed to by buf.
    This function can read the status of file regardless of whether a file is
    opened or not.

  Remarks:
    See sys_fs.h for usage information.
***************************************************************************/
SYS_FS_RESULT SYS_FS_FileStat
(
    const char *fname,
    SYS_FS_FSTAT *buf
)
{
    int fileStatus = -1;
    uint8_t pathWithDiskNo[SYS_FS_PATH_LEN_WITH_DISK_NUM] = { 0 };
    SYS_FS_MOUNT_POINT *disk = (SYS_FS_MOUNT_POINT *) NULL;
    OSAL_RESULT osalResult = OSAL_RESULT_FAIL;

    if ((fname == NULL) || (buf == NULL))
    {
        errorValue = SYS_FS_ERROR_INVALID_PARAMETER;
        return SYS_FS_RES_FAILURE;
    }

    /* Get disk number */
    if (SYS_FS_GetDisk(fname, &disk, pathWithDiskNo) == false)
    {
        /* "errorValue" contains the reason for failure. */
        return SYS_FS_RES_FAILURE;
    }

    if (disk->fsFunctions->fstat == NULL)
    {
        errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
        return SYS_FS_RES_FAILURE;
    }

    /* Clear out the error. */
    errorValue = SYS_FS_ERROR_OK;

    /* Acquire the volume mutex. */
    osalResult = OSAL_MUTEX_Lock(&(disk->mutexDiskVolume), OSAL_WAIT_FOREVER);
    if (osalResult == OSAL_RESULT_SUCCESS)
    {
        fileStatus = disk->fsFunctions->fstat((const char *)pathWithDiskNo, (uintptr_t)buf);
        errorValue = (SYS_FS_ERROR)fileStatus;

        /* Release the acquired mutex. */
        (void) OSAL_MUTEX_Unlock(&(disk->mutexDiskVolume));
    }
    else
    {
        errorValue = SYS_FS_ERROR_DENIED;
    }

    return (fileStatus == 0) ? SYS_FS_RES_SUCCESS : SYS_FS_RES_FAILURE;
}

//******************************************************************************
/*Function:
    SYS_FS_ERROR SYS_FS_Error
    (
        void
    );

  Summary:
    Returns the last error.

  Description:
    When a file system operation fails, the application can know the reason of
    failure by calling the SYS_FS_Error. This function only reports the errors
    which are not file (or file handle) specific. For example, for functions
    such as SYS_FS_Mount and SYS_FS_FileOpen, which do not take handle, any
    errors happening inside such function calls could be reported using
    SYS_FS_Error function. Even for functions, which take handle as its input
    parameters, the SYS_FS_Error function can be used to report the type of
    error for cases where the passed handle itself is invalid.

  Remarks:
    See sys_fs.h for usage information.
***************************************************************************/
SYS_FS_ERROR SYS_FS_Error
(
    void
)
{
    return errorValue;
}

//******************************************************************************
/*Function:
    SYS_FS_ERROR SYS_FS_FileError
    (
        SYS_FS_HANDLE handle
    );

  Summary:
    Returns the file specific error.

  Description:
    For file system functions which accepts valid handle, any error happening
    in those functions could be retrieved with SYS_FS_FileError. This function
    returns errors which are file specific.

    Please note that if an invalid handle is passed to a file system function,
    in such a case, SYS_FS_FileError will not return the correct type of error,
    as the handle was invalid. Therefore, it would be prudent to check the
    errors using the SYS_FS_Error function.

  Remarks:
    See sys_fs.h for usage information.
***************************************************************************/
SYS_FS_ERROR SYS_FS_FileError
(
    SYS_FS_HANDLE handle
)
{
    SYS_FS_OBJ *fileObj = (SYS_FS_OBJ *)handle;

    if (handle == SYS_FS_HANDLE_INVALID)
    {
        return SYS_FS_ERROR_INVALID_OBJECT;
    }

    if (fileObj->inUse == false)
    {
        return SYS_FS_ERROR_INVALID_OBJECT;
    }

    return fileObj->errorValue;
}

//******************************************************************************
/* Function:
    SYS_FS_HANDLE SYS_FS_DirOpen
    (
        const char* path
    );

  Summary:
    Open a directory

  Description:
    This function opens the requested directory.

  Remarks:
    See sys_fs.h for usage information.
***************************************************************************/
SYS_FS_HANDLE SYS_FS_DirOpen
(
    const char* path
)
{
    int fileStatus = (int)SYS_FS_ERROR_NOT_READY;
    uint8_t pathWithDiskNo[SYS_FS_PATH_LEN_WITH_DISK_NUM] = { 0 };
    SYS_FS_MOUNT_POINT *disk = (SYS_FS_MOUNT_POINT *) NULL;
    uint32_t index = 0;
    SYS_FS_DIR_OBJ *fileObj = NULL;
    OSAL_RESULT osalResult = OSAL_RESULT_FAIL;

    if (path == NULL)
    {
        errorValue = SYS_FS_ERROR_INVALID_PARAMETER;
        return SYS_FS_HANDLE_INVALID;
    }

    /* Get disk number */
    if (SYS_FS_GetDisk(path, &disk, pathWithDiskNo) == false)
    {
        /* "errorValue" contains the reason for failure. */
        return SYS_FS_HANDLE_INVALID;
    }

    if (disk->fsFunctions->openDir == NULL)
    {
        errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
        return SYS_FS_HANDLE_INVALID;
    }

    osalResult = OSAL_MUTEX_Lock((OSAL_MUTEX_HANDLE_TYPE *)&gSysFsMutex, OSAL_WAIT_FOREVER);
    if (osalResult == OSAL_RESULT_SUCCESS)
    {
        /* The data should be protected from simulateous access */
        for (index = 0; index < (uint32_t)SYS_FS_MAX_FILES; index ++)
        {
            if (gSYSFSDirObj[index].inUse == false)
            {
                gSYSFSDirObj[index].inUse = true;
                gSYSFSDirObj[index].mountPoint = disk;
                fileObj = &gSYSFSDirObj[index];
                break;
            }
        }
        (void) OSAL_MUTEX_Unlock(&gSysFsMutex);
    }

    if (fileObj == NULL)
    {
        errorValue = SYS_FS_ERROR_TOO_MANY_OPEN_FILES;
        return SYS_FS_HANDLE_INVALID;
    }

    errorValue = SYS_FS_ERROR_OK;
    osalResult = OSAL_MUTEX_Lock(&(fileObj->mountPoint->mutexDiskVolume), OSAL_WAIT_FOREVER);
    if (osalResult == OSAL_RESULT_SUCCESS)
    {
        fileStatus = disk->fsFunctions->openDir((uintptr_t)&fileObj->nativeFSDirObj,
                                                        (const char *)pathWithDiskNo);

        (void) OSAL_MUTEX_Unlock(&(fileObj->mountPoint->mutexDiskVolume));

        if (fileStatus == 0)
        {
            return ((SYS_FS_HANDLE)fileObj);
        }
        else
        {
            errorValue = (SYS_FS_ERROR)fileStatus;
            fileObj->inUse = false;
        }
    }

    return SYS_FS_HANDLE_INVALID;
}

//******************************************************************************
/* Function:
    SYS_FS_RESULT SYS_FS_DirClose
    (
        SYS_FS_HANDLE handle
    );

  Summary:
    Closes an opened directory.

  Description:
    This function closes a directory that was opened earlier opened with the
    SYS_FS_DirOpen function.

  Remarks:
    See sys_fs.h for usage information.
***************************************************************************/
SYS_FS_RESULT SYS_FS_DirClose
(
    SYS_FS_HANDLE handle
)
{
    int fileStatus = -1;
    SYS_FS_DIR_OBJ *fileObj = (SYS_FS_DIR_OBJ *)handle;
    OSAL_RESULT osalResult = OSAL_RESULT_FAIL;

    if (handle == SYS_FS_HANDLE_INVALID)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
        return SYS_FS_RES_FAILURE;
    }

    if (fileObj->inUse == false)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
        SYS_ASSERT(false,"File fileObject is not in use");
        return SYS_FS_RES_FAILURE;
    }

    if (fileObj->mountPoint->fsFunctions->closeDir == NULL)
    {
        fileObj->errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
        return SYS_FS_RES_FAILURE;
    }

    fileObj->errorValue = SYS_FS_ERROR_OK;

    osalResult = OSAL_MUTEX_Lock(&(fileObj->mountPoint->mutexDiskVolume), OSAL_WAIT_FOREVER);
    if (osalResult == OSAL_RESULT_SUCCESS)
    {
        fileStatus = fileObj->mountPoint->fsFunctions->closeDir(fileObj->nativeFSDirObj);
        (void) OSAL_MUTEX_Unlock(&(fileObj->mountPoint->mutexDiskVolume));

        if (fileStatus == 0)
        {
            /* Return the SYS_FS file system object. */
            fileObj->inUse = false;
            return SYS_FS_RES_SUCCESS;
        }
        else
        {
            fileObj->errorValue = (SYS_FS_ERROR)fileStatus;
        }
    }
    else
    {
        fileObj->errorValue = SYS_FS_ERROR_DENIED;
    }

    return SYS_FS_RES_FAILURE;
}

//******************************************************************************
/* Function:
    SYS_FS_RESULT SYS_FS_DirRead
    (
        SYS_FS_HANDLE handle,
        SYS_FS_FSTAT stat
    );

  Summary:
    Reads the files and directories of the specified directory.

  Description:
    This function reads the files and directories specified in the open
    directory.

  Remarks:
    See sys_fs.h for usage information.
***************************************************************************/
SYS_FS_RESULT SYS_FS_DirRead
(
    SYS_FS_HANDLE handle,
    SYS_FS_FSTAT *stat
)
{
    int fileStatus = -1;
    SYS_FS_DIR_OBJ *fileObj = (SYS_FS_DIR_OBJ *)handle;
    OSAL_RESULT osalResult = OSAL_RESULT_FAIL;

    if ((handle == SYS_FS_HANDLE_INVALID) || (stat == NULL))
    {
        errorValue = SYS_FS_ERROR_INVALID_PARAMETER;
        return SYS_FS_RES_FAILURE;
    }

    if (fileObj->inUse == false)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
        return SYS_FS_RES_FAILURE;
    }

    if (fileObj->mountPoint->fsFunctions->readDir == NULL)
    {
        fileObj->errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
        return SYS_FS_RES_FAILURE;
    }

    fileObj->errorValue = SYS_FS_ERROR_OK;
    osalResult = OSAL_MUTEX_Lock(&(fileObj->mountPoint->mutexDiskVolume), OSAL_WAIT_FOREVER);
    if(osalResult == OSAL_RESULT_SUCCESS)
    {
        fileStatus = fileObj->mountPoint->fsFunctions->readDir(fileObj->nativeFSDirObj, (uintptr_t)stat);

        (void) OSAL_MUTEX_Unlock(&(fileObj->mountPoint->mutexDiskVolume));

        fileObj->errorValue = (SYS_FS_ERROR)fileStatus;
    }
    else
    {
        fileObj->errorValue = SYS_FS_ERROR_DENIED;
    }

    return (fileStatus == 0) ? SYS_FS_RES_SUCCESS : SYS_FS_RES_FAILURE;
}

//******************************************************************************
/* Function:
    SYS_FS_RESULT SYS_FS_DirRewind
    (
        SYS_FS_HANDLE handle
    );

  Summary:
    Rewinds to the beginning of the directory.

  Description:
    This function rewinds the directory to the start. Once a search of
    directory or directory read is completed, the rewind function is used to
    begin searching the directory from the start.

  Remarks:
    See sys_fs.h for usage information.
***************************************************************************/
SYS_FS_RESULT SYS_FS_DirRewind
(
    SYS_FS_HANDLE handle
)
{
    int fileStatus = -1;
    SYS_FS_DIR_OBJ *fileObj = (SYS_FS_DIR_OBJ *)handle;
    OSAL_RESULT osalResult = OSAL_RESULT_FAIL;

    if (handle == SYS_FS_HANDLE_INVALID)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
        return SYS_FS_RES_FAILURE;
    }

    if (fileObj->inUse == false)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
        return SYS_FS_RES_FAILURE;
    }

    if (fileObj->mountPoint->fsFunctions->readDir == NULL)
    {
        fileObj->errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
        return SYS_FS_RES_FAILURE;
    }

    fileObj->errorValue = SYS_FS_ERROR_OK;
    osalResult = OSAL_MUTEX_Lock(&(fileObj->mountPoint->mutexDiskVolume), OSAL_WAIT_FOREVER);
    if(osalResult == OSAL_RESULT_SUCCESS)
    {
        fileStatus = fileObj->mountPoint->fsFunctions->readDir(fileObj->nativeFSDirObj, 0U);
        (void) OSAL_MUTEX_Unlock(&(fileObj->mountPoint->mutexDiskVolume));

        fileObj->errorValue = (SYS_FS_ERROR)fileStatus;
    }
    else
    {
        fileObj->errorValue = SYS_FS_ERROR_DENIED;
    }

    return (fileStatus == 0) ? SYS_FS_RES_SUCCESS : SYS_FS_RES_FAILURE;
}

//******************************************************************************
/* Function:
    SYS_FS_RESULT SYS_FS_DirSearch
    (
        SYS_FS_HANDLE handle,
        const char * name,
        SYS_FS_FILE_DIR_ATTR attr,
        SYS_FS_FSTAT *stat
    );

  Summary:
    Searches for a file or directory.

  Description:
    This function searches for the requested file or directory. The file or
    directory is specified in the attr parameter, which is of type
    SYS_FS_FILE_DIR_ATTR.

  Remarks:
    See sys_fs.h for usage information.
***************************************************************************/
SYS_FS_RESULT SYS_FS_DirSearch
(
    SYS_FS_HANDLE handle,
    const char * name,
    SYS_FS_FILE_DIR_ATTR attr,
    SYS_FS_FSTAT *stat
)
{
    bool workToDo = true;           // avoid unreachable code warning
    int fileStatus = -1;
    SYS_FS_DIR_OBJ *fileObj = (SYS_FS_DIR_OBJ *)handle;
    char *fileName = NULL;
    OSAL_RESULT osalResult = OSAL_RESULT_FAIL;
    if ((handle == SYS_FS_HANDLE_INVALID) || (name == NULL) || (stat == NULL))
    {
        errorValue = SYS_FS_ERROR_INVALID_PARAMETER;
        return SYS_FS_RES_FAILURE;
    }

    if (fileObj->inUse == false)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
        return SYS_FS_RES_FAILURE;
    }

    if (fileObj->mountPoint->fsFunctions->readDir == NULL)
    {
        errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
        return SYS_FS_RES_FAILURE;
    }

    while( workToDo )
    {
        errorValue = SYS_FS_ERROR_OK;
        osalResult = OSAL_MUTEX_Lock(&(fileObj->mountPoint->mutexDiskVolume), OSAL_WAIT_FOREVER);
        if (osalResult == OSAL_RESULT_SUCCESS)
        {
            fileStatus = fileObj->mountPoint->fsFunctions->readDir(fileObj->nativeFSDirObj, (uintptr_t)stat);
            (void) OSAL_MUTEX_Unlock(&(fileObj->mountPoint->mutexDiskVolume));

            if(fileStatus != 0)
            {
                errorValue = (SYS_FS_ERROR)fileStatus;
                return SYS_FS_RES_FAILURE;
            }
        }
        else
        {
            errorValue = SYS_FS_ERROR_DENIED;
            return SYS_FS_RES_FAILURE;
        }

        /* If we have come to end of directory */
        if (stat->lfname != NULL)
        {
            /* If LFN is Enabled but filename fits into Short file name */
            if ((stat->lfname[0] == '\0') && (stat->fname[0] == '\0'))
            {
                errorValue = SYS_FS_ERROR_NO_FILE;
                return SYS_FS_RES_FAILURE;
            }
        }
        else if (stat->fname[0] == '\0')
        {
            errorValue = SYS_FS_ERROR_NO_FILE;
            return SYS_FS_RES_FAILURE;
        }
        else
        {
            /* Nothing to do */
        }

        /* Firstly, match the file attribute with the requested attribute */
        if (((stat->fattrib & (uint8_t)attr) != 0U) ||
            (attr == SYS_FS_ATTR_FILE))
        {
            if((stat->lfname != NULL) && (stat->lfname[0] != '\0'))
            {
                /* File name is LFN */
                fileName = stat->lfname;
            }
            else
            {
                /* File name fits in 8.3 format */
                fileName = stat->fname;
            }

            if(SYS_FS_StringWildCardCompare(name, fileName) == true)
            {
                return SYS_FS_RES_SUCCESS;
            }
        }
    }

    errorValue = SYS_FS_ERROR_NO_FILE;
    return SYS_FS_RES_FAILURE;
}

//******************************************************************************
/*Function:
    SYS_FS_RESULT SYS_FS_FileStringGet
    (
        SYS_FS_HANDLE handle,
        char* buff,
        uint32_t len
    );

  Summary:
    Reads a string from the file into a buffer.

  Description:
    This function reads a string of specified length from the file into a
    buffer. The read operation continues until:
      1. '\n' is stored
      2. reached end of the file or
      3. the buffer is filled with len - 1 characters.
      The read string is terminated with a '\0'.

  Remarks:
    See sys_fs.h for usage information.
***************************************************************************/
SYS_FS_RESULT SYS_FS_FileStringGet
(
    SYS_FS_HANDLE handle,
    char* buff,
    uint32_t len
)
{
    SYS_FS_OBJ *fileObj = (SYS_FS_OBJ *)handle;
    char *ptr = NULL;
    OSAL_RESULT osalResult = OSAL_RESULT_FAIL;

    /* Check if the parameters are valid. */
    if ((handle == SYS_FS_HANDLE_INVALID) || (buff == NULL) || (len == 0U))
    {
        errorValue = SYS_FS_ERROR_INVALID_PARAMETER;
        return SYS_FS_RES_FAILURE;
    }

    /* Check if the file object is in use. */
    if (fileObj->inUse == false)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
        return SYS_FS_RES_FAILURE;
    }

    if (fileObj->mountPoint->fsFunctions->getstrn == NULL)
    {
        fileObj->errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
        return SYS_FS_RES_FAILURE;
    }

    /* Clear the error. */
    fileObj->errorValue = SYS_FS_ERROR_OK;

    /* Acquire the volume mutex. */
    osalResult = OSAL_MUTEX_Lock(&(fileObj->mountPoint->mutexDiskVolume), OSAL_WAIT_FOREVER);
    if (osalResult == OSAL_RESULT_SUCCESS)
    {
        ptr = fileObj->mountPoint->fsFunctions->getstrn(buff, len, fileObj->nativeFSFileObj);

        /* Release the acquired mutex. */
        (void) OSAL_MUTEX_Unlock(&(fileObj->mountPoint->mutexDiskVolume));

        if (ptr != NULL) /*(buff == ptr) */
        {
            return SYS_FS_RES_SUCCESS;
        }
        else
        {
            fileObj->errorValue = SYS_FS_ERROR_DISK_ERR;
        }
    }
    else
    {
        fileObj->errorValue = SYS_FS_ERROR_DENIED;
    }

    return SYS_FS_RES_FAILURE;
}

//******************************************************************************
/*Function:
    SYS_FS_RESULT SYS_FS_DirectoryChange
    (
        const char* path
    );

  Summary:
    Changes to a the directory specified.

  Description:
    This function changes the present directory to a new directory.

  Remarks:
    See sys_fs.h for usage information.
***************************************************************************/
SYS_FS_RESULT SYS_FS_DirectoryChange
(
    const char* path
)
{
    int fileStatus = -1;
    uint8_t pathWithDiskNo[SYS_FS_PATH_LEN_WITH_DISK_NUM] = { 0 };
    SYS_FS_MOUNT_POINT *disk = (SYS_FS_MOUNT_POINT *) NULL;
    OSAL_RESULT osalResult = OSAL_RESULT_FAIL;

    if (path == NULL)
    {
        errorValue = SYS_FS_ERROR_INVALID_PARAMETER;
        return SYS_FS_RES_FAILURE;
    }

    /* Get disk number */
    if (SYS_FS_GetDisk(path, &disk, pathWithDiskNo) == false)
    {
        /* "errorValue" contains the reason for failure. */
        return SYS_FS_RES_FAILURE;
    }

    if (disk->fsFunctions->chdir == NULL)
    {
        errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
        return SYS_FS_RES_FAILURE;
    }

    errorValue = SYS_FS_ERROR_OK;

    /* Acquire the volume mutex. */
    osalResult = OSAL_MUTEX_Lock(&(disk->mutexDiskVolume), OSAL_WAIT_FOREVER);
    if (osalResult == OSAL_RESULT_SUCCESS)
    {
        fileStatus = disk->fsFunctions->chdir((const char *)pathWithDiskNo);

        /* Release the acquired mutex. */
        (void) OSAL_MUTEX_Unlock(&(disk->mutexDiskVolume));
        errorValue = (SYS_FS_ERROR)fileStatus;
    }
    else
    {
        errorValue = SYS_FS_ERROR_DENIED;
    }

    return (fileStatus == 0) ? SYS_FS_RES_SUCCESS : SYS_FS_RES_FAILURE;
}

//******************************************************************************
/*Function:
    SYS_FS_RESULT SYS_FS_CurrentWorkingDirectoryGet
    (
        char *buff,
        uint32_t len
    );

  Summary:
    Gets the current working directory

  Description:
    This function gets the current working directory path along with the
    working drive.

  Remarks:
    See sys_fs.h for usage information.
***************************************************************************/
SYS_FS_RESULT SYS_FS_CurrentWorkingDirectoryGet
(
    char *buffer,
    uint32_t len
)
{
    SYS_FS_MOUNT_POINT *disk = NULL;
    int fileStatus = -1;
    char cwd[SYS_FS_CWD_STRING_LEN] = { 0 };
    char *ptr = NULL;
    OSAL_RESULT osalResult = OSAL_RESULT_FAIL;
    char str[] = "/mnt/";
    uint8_t i = 0U;

    if ((buffer == NULL) || (len == 0U))
    {
        errorValue = SYS_FS_ERROR_INVALID_PARAMETER;
        return SYS_FS_RES_FAILURE;
    }

    if (gSYSFSCurrentMountPoint.inUse == false)
    {
        errorValue = SYS_FS_ERROR_NO_FILESYSTEM;
        return SYS_FS_RES_FAILURE;
    }

    /* This is the current drive in sys_fs. For this current drive, get the
     * current working directory */
    disk = gSYSFSCurrentMountPoint.currentDisk;
    if (disk->fsFunctions->currWD == NULL)
    {
        errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
        return SYS_FS_RES_FAILURE;
    }

    osalResult = OSAL_MUTEX_Lock(&(disk->mutexDiskVolume), OSAL_WAIT_FOREVER);
    if (osalResult != OSAL_RESULT_SUCCESS)
    {
        errorValue = SYS_FS_ERROR_DENIED;
        return SYS_FS_RES_FAILURE;
    }

    fileStatus = disk->fsFunctions->currWD(buffer, len);
    (void) OSAL_MUTEX_Unlock(&(disk->mutexDiskVolume));

    errorValue = (SYS_FS_ERROR)fileStatus;

    if (fileStatus == 0)
    {
        ptr = buffer;

        /* Check if the first character of the returned buffer is a ASCII for digit */
        if ((*ptr >= '0') && (*ptr <= '9'))
        {
            /* Check if the current drive in native file system matches with
             * the current drive in sys_fs layer */
            if (disk->diskNumber == ((uint8_t)*ptr - (uint8_t)'0'))
            {
                /* Ignore the first two characters as they contain the driver number and the ':" */
                ptr += 2;
            }
            else
            {
                errorValue = SYS_FS_ERROR_INVALID_NAME;
                return SYS_FS_RES_FAILURE;
            }
        }

        if (len < (5U + (uint32_t)disk->mountNameLength + strlen(ptr)))
        {
            errorValue = SYS_FS_ERROR_NOT_ENOUGH_CORE;
            return SYS_FS_RES_FAILURE;
        }

        /* Copy the cwd name in a temporary buffer. */
        (void) strcpy (cwd, ptr);

        ptr = buffer;
        (void) memset (ptr, 0, len);

        for(i = 0U; str[i] !='\0' ; i++)
        {
            ptr[i] = str[i];
        }
        ptr += 5;

        (void) memcpy (ptr, disk->mountName, disk->mountNameLength);
        ptr += disk->mountNameLength;

        (void) memcpy (ptr, cwd, strlen(cwd));

        return SYS_FS_RES_SUCCESS;
    }
    else
    {
        return SYS_FS_RES_FAILURE;
    }
}

//******************************************************************************
/*Function:
    SYS_FS_RESULT SYS_FS_CurrentDriveGet
    (
        char* buffer
    );

  Summary:
    Gets the current drive

  Description:
    This function gets the present drive being used. The drive information is
    populated in the buffer.

  Remarks:
    See sys_fs.h for usage information.
***************************************************************************/
SYS_FS_RESULT SYS_FS_CurrentDriveGet
(
    char* buffer
)
{
    if (buffer == NULL)
    {
        errorValue = SYS_FS_ERROR_INVALID_PARAMETER;
        return SYS_FS_RES_FAILURE;
    }

    if(gSYSFSCurrentMountPoint.inUse == false)
    {
        errorValue = SYS_FS_ERROR_NO_FILESYSTEM;
        return SYS_FS_RES_FAILURE;
    }

    (void) strcpy(buffer, "/mnt/");
    (void) memcpy(buffer + 5, gSYSFSCurrentMountPoint.currentDisk->mountName, gSYSFSCurrentMountPoint.currentDisk->mountNameLength);

    return SYS_FS_RES_SUCCESS;
}

//******************************************************************************
/*Function:
    SYS_FS_RESULT SYS_FS_DriveLabelGet
    (
        const char* drive,
        char *buff,
        uint32_t *sn
    );

  Summary:
    Gets the drive label.

  Description:
    This function gets the label for the drive specified. If no drive is
    specified, the label for the current drive is obtained.

  Remarks:
    See sys_fs.h for usage information.
***************************************************************************/
SYS_FS_RESULT SYS_FS_DriveLabelGet
(
    const char* drive,
    char *buff,
    uint32_t *sn
)
{
    int fileStatus = -1;
    SYS_FS_MOUNT_POINT *disk = NULL;
    uint8_t pathWithDiskNo[3] = { 0 };
    OSAL_RESULT osalResult = OSAL_RESULT_FAIL;

    if (drive != NULL)
    {
        /* Get disk number */
        if (SYS_FS_GetDisk(drive, &disk, NULL) == false)
        {
            /* "errorValue" contains the reason for failure. */
            return SYS_FS_RES_FAILURE;
        }
    }
    else
    {
        if (gSYSFSCurrentMountPoint.inUse == false)
        {
            errorValue = SYS_FS_ERROR_NO_FILESYSTEM;
            return SYS_FS_RES_FAILURE;
        }

        disk = gSYSFSCurrentMountPoint.currentDisk;
    }

    if (disk->fsFunctions->getlabel == NULL)
    {
        errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
        return SYS_FS_RES_FAILURE;
    }

    /* Append "0:" before the file name. This is required for different disks
     * */
    pathWithDiskNo[0] = (uint8_t)disk->diskNumber + (uint8_t)'0';
    pathWithDiskNo[1] = (uint8_t)':';
    pathWithDiskNo[2] = (uint8_t)'\0';

    osalResult = OSAL_MUTEX_Lock(&(disk->mutexDiskVolume), OSAL_WAIT_FOREVER);
    if (osalResult == OSAL_RESULT_SUCCESS)
    {
        fileStatus = disk->fsFunctions->getlabel((const char *)pathWithDiskNo, buff, sn);
        (void) OSAL_MUTEX_Unlock(&(disk->mutexDiskVolume));
        errorValue = (SYS_FS_ERROR)fileStatus;
    }
    else
    {
        errorValue = SYS_FS_ERROR_DENIED;
    }

    return (fileStatus == 0) ? SYS_FS_RES_SUCCESS : SYS_FS_RES_FAILURE;
}
  size_t SYS_FS_FileWrite
(
    SYS_FS_HANDLE handle,
    const void *buffer,
    size_t nbyte
)
{
    SYS_FS_OBJ *fileObj = (SYS_FS_OBJ *)handle;

    /* Check if the handle is valid. */
    if (handle == SYS_FS_HANDLE_INVALID)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
    }
    else
    {
        /* The write operation is not supported by the Native FS. */
        fileObj->errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
    }

    return 0xFFFFFFFFU;
}

SYS_FS_RESULT SYS_FS_FileSync
(
    SYS_FS_HANDLE handle
)
{
    SYS_FS_OBJ *fileObj = (SYS_FS_OBJ *)handle;

    /* Check if the handle is valid. */
    if (handle == SYS_FS_HANDLE_INVALID)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
    }
    else
    {
        /* The write operation is not supported by the Native FS. */
        fileObj->errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
    }

    return SYS_FS_RES_FAILURE;
}

SYS_FS_RESULT SYS_FS_FileTruncate
(
    SYS_FS_HANDLE handle
)
{
     SYS_FS_OBJ *fileObj = (SYS_FS_OBJ *)handle;

    /* Check if the handle is valid. */
    if (handle == SYS_FS_HANDLE_INVALID)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
    }
    else
    {
        /* The write operation is not supported by the Native FS. */
        fileObj->errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
    }

    return SYS_FS_RES_FAILURE;
}

SYS_FS_RESULT SYS_FS_FileCharacterPut
(
    SYS_FS_HANDLE handle,
    char data
)
{
    SYS_FS_OBJ *fileObj = (SYS_FS_OBJ *)handle;

    /* Check if the handle is valid. */
    if (handle == SYS_FS_HANDLE_INVALID)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
    }
    else
    {
        /* The write operation is not supported by the Native FS. */
        fileObj->errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
    }

    return SYS_FS_RES_FAILURE;
}

SYS_FS_RESULT SYS_FS_FileStringPut
(
    SYS_FS_HANDLE handle,
    const char *string
)
{
    SYS_FS_OBJ *fileObj = (SYS_FS_OBJ *)handle;

    /* Check if the handle is valid. */
    if (handle == SYS_FS_HANDLE_INVALID)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
    }
    else
    {
        /* The write operation is not supported by the Native FS. */
        fileObj->errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
    }

    return SYS_FS_RES_FAILURE;
}

SYS_FS_RESULT SYS_FS_FilePrintf
(
    SYS_FS_HANDLE handle,
    const char *string,
    ...
)
{
    SYS_FS_OBJ *fileObj = (SYS_FS_OBJ *)handle;

    /* Check if the handle is valid. */
    if (handle == SYS_FS_HANDLE_INVALID)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
    }
    else
    {
        /* The write operation is not supported by the Native FS. */
        fileObj->errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
    }

    return SYS_FS_RES_FAILURE;
}

bool SYS_FS_FileTestError
(
    SYS_FS_HANDLE handle
)
{
    SYS_FS_OBJ *fileObj = (SYS_FS_OBJ *)handle;

    /* Check if the handle is valid. */
    if (handle == SYS_FS_HANDLE_INVALID)
    {
        errorValue = SYS_FS_ERROR_INVALID_OBJECT;
    }
    else
    {
        /* The write operation is not supported by the Native FS. */
        fileObj->errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;
    }

    return true;
}

SYS_FS_RESULT SYS_FS_DirectoryMake
(
    const char* path
)
{
    /* The write operation is not supported by the Native FS. */
    errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;

    return SYS_FS_RES_FAILURE;
}

SYS_FS_RESULT SYS_FS_FileDirectoryRemove
(
    const char* path
)
{
    /* The write operation is not supported by the Native FS. */
    errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;

    return SYS_FS_RES_FAILURE;
}

SYS_FS_RESULT SYS_FS_FileDirectoryModeSet
(
    const char* fname,
    SYS_FS_FILE_DIR_ATTR attr,
    SYS_FS_FILE_DIR_ATTR mask
)
{
    /* The write operation is not supported by the Native FS. */
    errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;

    return SYS_FS_RES_FAILURE;
}

SYS_FS_RESULT SYS_FS_FileDirectoryTimeSet
(
    const char* fname,
    SYS_FS_TIME *f_time
)
{
    /* The write operation is not supported by the Native FS. */
    errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;

    return SYS_FS_RES_FAILURE;
}

SYS_FS_RESULT SYS_FS_FileDirectoryRenameMove
(
    const char *oldPath,
    const char *newPath
)
{
    /* The write operation is not supported by the Native FS. */
    errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;

    return SYS_FS_RES_FAILURE;
}

SYS_FS_RESULT SYS_FS_CurrentDriveSet
(
    const char* path
)
{
    /* The write operation is not supported by the Native FS. */
    errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;

    return SYS_FS_RES_FAILURE;
}

SYS_FS_RESULT SYS_FS_DriveLabelSet
(
    const char *drive,
    const char *label
)
{
    /* The write operation is not supported by the Native FS. */
    errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;

    return SYS_FS_RES_FAILURE;
}

//******************************************************************************
SYS_FS_RESULT SYS_FS_DriveFormat
(
    const char* drive,
    const SYS_FS_FORMAT_PARAM* opt,
    void* work,
    uint32_t len
)
{
    /* The write operation is not supported by the Native FS. */
    errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;

    return SYS_FS_RES_FAILURE;
}

SYS_FS_RESULT SYS_FS_DrivePartition
(
    const char *path,
    const uint32_t partition[],
    void *work
)
{
    /* The write operation is not supported by the Native FS. */
    errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;

    return SYS_FS_RES_FAILURE;
}

SYS_FS_RESULT SYS_FS_DriveSectorGet
(
    const char* path,
    uint32_t *totalSectors,
    uint32_t *freeSectors
)
{
    /* The write operation is not supported by the Native FS. */
    errorValue = SYS_FS_ERROR_NOT_SUPPORTED_IN_NATIVE_FS;

    return SYS_FS_RES_FAILURE;
}


 /* MISRAC 2012 deviation block end */
/*************************************************************************
* END OF sys_fs.c
***************************************************************************/

