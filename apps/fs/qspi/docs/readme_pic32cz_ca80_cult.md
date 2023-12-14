---
grand_parent: Serial Memory Bootloader Applications
parent: FS QSPI Flash Bootloader
title: Building and Running on PIC32CZ CA80 Evaluation Board
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# Building and Running the File System based QSPI Flash Bootloader applications

## Downloading and building the application

To clone or download this application from Github,go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/bootloader_apps_serial_memory) and then click Clone button to clone this repo or download as zip file. This content can also be download using content manager by following [these instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki)

Path of the application within the repository is **apps/fs/qspi/**

To build the application, refer to the following table and open the project using its IDE.

### Bootloader Application

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| bootloader/pic32cz_ca80_cult.X    | MPLABX Project for [PIC32CZ CA80 Evaluation Board](https://www.microchip.com/en-us/development-tool/ea61x20a)|


### Programmer application

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| app_programmer/pic32cz_ca80_cult.X    | MPLABX Project for [PIC32CZ CA80 Evaluation Board](https://www.microchip.com/en-us/development-tool/ea61x20a)|

## Setting up [PIC32CZ CA80 Evaluation Board](https://www.microchip.com/en-us/development-tool/ea61x20a)

- To run the demo, the following additional hardware are required:
    - One [microSD click](https://www.mikroe.com/microsd-click)

    - One micro SD Card

- Install the [microSD click](https://www.mikroe.com/microsd-click) on to the **mikroBUS Header** of the device

- Connect the Debug USB port on the board to the computer using a micro USB cable

## Running the Application

1. Open the bootloader project *bootloader/pic32cz_ca80_cult.X* in the IDE

2. Make sure that the *app_programmer/pic32cz_ca80_cult.X* is added as a loadable project to bootloader application
    - As the QSPI Flash memory may not have any valid binary **required by bootloader** for the first time, Adding the **app_programmer as loadable** allows MPLAB X to create a **unified hex file** and program both these applications in their respective memory locations based on their linker script configurations

    ![mplab_loadable_pic32cz_ca80](./images/mplab_loadable_pic32cz_ca80.png)

3. Open the Terminal application (Ex.:Tera Term) on the computer to get programmer application messages through UART once loaded
4. Configure the serial port settings as follows:
    - Baud : 115200
    - Data : 8 Bits
    - Parity : None
    - Stop : 1 Bit
    - Flow Control : None

5. Build and program the **bootloader application** using the IDE

6. Once programming is done bootloader starts execution and directly jumps to application space to **run the programmer application**
    - **LED1** starts blinking indicating that the **programmer application** is running and you should see below output on the console

        ![fs_serial_mem_console_bootup](./images/fs_serial_mem_console_bootup.png)

7. Open the programmer application project *app_programmer/pic32cz_ca80_cult.X* in the IDE

8. Update **app_programmer/firmware/src/app_monitor.c** to update printf message from **Serial Memory** to **QSPI Flash Memory** as below

    ```c
    printf("\r\n###### File System (QSPI Flash Memory) Programmer Application Running ######\r\n");
    ```

9. Clean and Build the project to generate the binary **(Do not program the binary)**

10. Copy the generated application binary file to a sdcard from the Host PC
    - *\<harmony3_path\>/bootloader_apps_serial_memory/apps/fs/qspi/app_programmer/pic32cz_ca80_cult.X/dist/pic32cz_ca80_cult/production/pic32cz_ca80_cult.X.production.bin*

11. Rename the copied application binary file to **image.bin**

12. Insert the sdcard with the application binary **image.bin** in the sdcard slot of the device
13. Following snapshot shows output of successfully copying the **programmer application** binary to QSPI Flash Memory
    - **LED1** should still be blinking

        ![fs_serial_mem_console_copying_sam_e54](./images/fs_serial_mem_console_copying_sam_e54.png)

14. Remove the sdcard from the sdcard slot

15. Press and hold the Switch **SW0** to trigger Bootloader from programmer application and you should see below output

    ![fs_serial_mem_console_trigger_sam_e54](./images/fs_serial_mem_console_trigger_sam_e54.png)

16. Once Firmware Update is successful **LED1** should start blinking indicating updated programmer application running and you should see below output on the console

    ![fs_serial_mem_console_updated_sam_e54](./images/fs_serial_mem_console_updated_sam_e54.png)

## Additional Steps (Optional)
- To bootload any other application refer to [Application Configurations](../../../docs/readme_configure_application_sam.md)
    - **Note that this application should have programming capabilities to QSPI Flash Memory**
    - Change the place vector table from FCR_BFM to FCR_PFM memory

	![mplab_loadable_pic32cz_ca80](./images/mplab_place_vector_table.png)

- Once done repeat the applicable steps mentioned in [Running The Application](#running-the-application)
