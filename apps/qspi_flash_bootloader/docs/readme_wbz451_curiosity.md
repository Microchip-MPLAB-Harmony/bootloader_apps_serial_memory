---
grand_parent: Serial Memory Bootloader Applications
parent: QSPI Flash Bootloader
title: Building and Running on WBZ451 Curiosity Development Board
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# Building and Running the QSPI Flash Bootloader applications

## Downloading and building the application

To clone or download this application from Github,go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/bootloader_apps_serial_memory) and then click Clone button to clone this repo or download as zip file. This content can also be download using content manager by following [these instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki)

Path of the application within the repository is **apps/qspi_flash_bootloader/**

To build the application, refer to the following table and open the project using its IDE.

### Bootloader Application

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| bootloader/firmware/wbz451_curiosity.X   | MPLABX Project for [WBZ451 Curiosity Development Board](https://www.microchip.com/en-us/development-tool/ev96b94a)|


### Programmer application

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| app_programmer/firmware/wbz451_curiosity.X   | MPLABX Project for [WBZ451 Curiosity Development Board](https://www.microchip.com/en-us/development-tool/ev96b94a)|

## Setting up [WBZ451 Curiosity Development Board](https://www.microchip.com/en-us/development-tool/ev96b94a)

- Connect the Debug USB port on the board to the computer using a micro USB cable

## Setting up the host script

- Refer to [UART Host Script Help](../../../tools/docs/readme_uart_host.md) for setting up the **uart_host.py** utility used to send the application binary from host PC
    - There will be no reset command sent from host after programming by default.
    
    - Reboot command has to be sent separately only after successful programming to trigger bootloader from **programmer application**

## Running the Application

1. Open the bootloader project *bootloader/firmware/wbz451_curiosity.X* in the IDE

2. Make sure that the *app_programmer/firmware/wbz451_curiosity.X* is added as a loadable project to bootloader application
    - As the QSPI Flash memory may not have any valid binary **required by bootloader** for the first time, Adding the **app_programmer as loadable** allows MPLAB X to create a **unified hex file** and program both these applications in their respective memory locations based on their linker script configurations

    ![mplab_loadable_wbz451_curiosity](./images/mplab_loadable_pic32cxbz_wbz451.png)

3. Build and program the **bootloader application** using the IDE

4. Once programming is done bootloader starts execution and directly jumps to application space to **run the programmer application**
    - **RGB_LED (GREEN)** starts blinking every **500ms** indicating that the **programmer application** is running

5. Open the programmer application project *app_programmer/firmware/wbz451_curiosity.X* in the IDE

6. Update **app_programmer/firmware/src/app.c** to reduce the LED blink duration from **500ms** to **100ms** as below

    ```c
    APP_TIMER_DelayMs(100);
    ```

7. Clean and Build the project to generate the binary **(Do not program the binary)**

8. Run the **uart_host.py** from command prompt to program the **updated programmer application binary** in QSPI Flash memory

        python <harmony3_path>/bootloader_apps_serial_memory/tools/uart_host.py -v -i <COM PORT> -d wbz451 -a 0x1000000 -f <harmony3_path>/bootloader_apps_serial_memory/apps/qspi_flash_bootloader/app_programmer/firmware/wbz451_curiosity.X/dist/wbz451_curiosity/production/wbz451_curiosity.X.production.bin
9. Following snapshot shows output of successfully programming the **programmer application**
    - **RGB_LED (GREEN)** should still be blinking every **500ms**

    ![uart_host_output_program](../../../tools/docs/images/uart_host_output_program.png)

10. Run the **uart_host.py** from command prompt to send a **Reboot** command. This command Updates **MetaData** and **triggers Bootloader** to program the **updated binary from QSPI Flash to Internal Flash**

        python <harmony3_path>/bootloader_apps_serial_memory/tools/uart_host.py -v -i <COM PORT> -r

    ![uart_host_output_reboot](../../../tools/docs/images/uart_host_output_reboot.png)

11. Once Firmware Update is successful **RGB_GREEN_LED** should start blinking every **100ms** indicating updated programmer application running
    - If there was any error you may need to power cycle the device to retry firmware upgrade

12. Update **app_programmer/firmware/src/app.c** to revert LED blink duration to **500ms** from **100ms** as below

    ```c
    APP_TIMER_DelayMs(500);
    ```

13. Clean and Build the project to generate the binary **(Do not program the binary)**

14. Repeat Step 8-9.
    - You should see **RGB_LED (GREEN)** still blinking every **100ms**

15. Press the Switch **SW2** to Update **MetaData** and **trigger Bootloader** to program the **updated binary from QSPI Flash to Internal Flash**

16. Once Firmware Update is successful **RGB_LED (GREEN)** should start blinking every **500ms** indicating updated programmer application running
    - If there was any error you may need to power cycle the device to retry firmware upgrade

## Additional Steps (Optional)
- To bootload any other application refer to [Application Configurations](../../docs/readme_configure_application_sam.md)
    - **Note that this application should have programming capabilities to QSPI Flash Memory**

- Once done repeat the applicable steps mentioned in [Running The Application](#running-the-application)
