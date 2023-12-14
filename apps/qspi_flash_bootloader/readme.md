---
parent: Serial Memory Bootloader Applications
title: QSPI Flash Bootloader
has_children: false
has_toc: false
nav_order: 5
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

To clone or download these application from Github,go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/bootloader_apps_serial_memory) and then click Clone button to clone this repo or download as zip file. This content can also be download using content manager by following [these instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki)

# QSPI Flash Bootloader

This example application shows how to use the Serial Memory Bootloader Library to bootload an application from QSPI Flash memory (SST26) to Internal Flash.

### Serial Memory Bootloader Applications Block Diagram

![serial_mem_btl_block_diagram](../docs/images/serial_mem_btl_block_diagram.png)

### Bootloader Application

- This is a bootloader application which resides from
    - The starting location of the flash memory region for SAM devices

    - The starting location of the Boot flash memory region for PIC32MZ devices
        - Uses a Custom linker script **btl.ld** to place it in Boot flash memory

**Performs Below Operation:**

1. Sets up the QSPI Flash (SST26) using the SST26 driver and QSPI/SQI peripheral Library

2. Checks if a firmware update is required by reading the **MetaData** stored in the last sector of QSPI Flash
    - If Firmware update is required then it jumps to **Step 4**

3. If there was no firmware update request through **MetaData**, then it checks for any trigger implemented in application main()
    - Here we use the On-board Switch to force trigger firmware update.

    - If no trigger is found then it jumps to **Step 7**

4. If firmware update is required then it
    - Reads the **programmer application** binary stored from start of QSPI flash memory **(0x0)**

    - Programs the read binary to application space in Internal Flash

5. Once programming is done it generates a CRC32 value over programmed space and verifies it against the CRC32 stored in QSPI Flash MetaData
    - If CRC32 verification fails it goes into Error State

6. If CRC32 verification is successful, It clears the **firmware update required flag** in the QSPI Flash MetaData and **triggers a Soft Reset**
    - After reset, bootloader starts from **Step 1** through **Step 3** to do firmware update check and then jump to **Step 7**

7. If there was no firmware update required then it
    - Calls the SYS_Deinitialize() function which releases the resources used. **This Function is device specific and has to be implemented based on application requirement**

    - **Jumps to application space to run the programmer application**

### Programmer Application

- This is a QSPI Flash programmer application which resides from
    - The end of bootloader size in device flash memory for SAM devices

    - The start of Program Flash memory for PIC32MZ devices
        - Uses a Custom linker script **app_mz.ld** to place it in Program flash memory

- It will be loaded into **internal flash memory** from **QSPI Flash Memory** by bootloader application

- It blinks an LED every 500Ms and has capabilty to program QSPI Flash memory (SST26) using SST26 Driver and QSPI/SQI peripheral Library

- It uses the Virtual Com port of the device (EDBG port or External USB to UART converters) to receive the binary to be programmed in QSPI Flash from host PC
    - As the application running in internal flash should have capability to program QSPI Flash memory, we send the **programmer application binary itself** via UART to be programmed in QSPI Flash Memory

- It calls the APP_INPUT_Tasks() function which receives the binary to be programmed into QSPI flash memory over UART channel
    - It uses the UART bootloader protocol but is updated to run along with other tasks

- Once the binary is received and programmed from start location of QSPI Flash memory it generates a CRC32 value over programmed QSPI Flash space and verifies it against the CRC32 sent from host PC

    - It Also Updates the CRC32 value received in the QSPI Flash MetaData used by bootloader

    - If CRC32 verification fails it goes into Error State then resets the APP_INPUT_Tasks() state to receive new binary

- If verification is successful then it
    - Waits for one of below user event to update the **MetaData** and **trigger bootloader** via soft reset to program new binary in Internal Flash **OR**
        - A Switch press **OR**
        - A Reboot command from Host PC

    - Waits for a new binary to be programmed in QSPI Flash memory.

## Development Kits
The following table provides links to documentation on how to build and run QSPI Flash bootloader on different development kits

| Development Kit |
|:---------|
|[PIC32CZ-CA80 Curiosity Ultra board](docs/readme_pic32cz_ca80_curiosity_ultra.md) |
|[PIC32MZ Embedded Graphics with Stacked DRAM (DA) Starter Kit (Crypto)](docs/readme_pic32mz_das_sk.md) |
|[PIC32MZ Embedded Connectivity with FPU (EF) Starter Kit](docs/readme_pic32mz_ef_sk.md) |
|[SAM E54 Xplained Pro Evaluation Kit](docs/readme_sam_e54_xpro.md) |
|[SAM E70 Xplained Ultra Evaluation Kit](docs/readme_sam_e70_xult.md) |
|[WBZ451 Curiosity Development Board](docs/readme_wbz451_curiosity.md) |

