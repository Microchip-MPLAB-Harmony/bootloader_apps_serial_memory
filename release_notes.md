---
title: Release notes
nav_order: 99
---

![Microchip logo](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_logo.png)
![Harmony logo small](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_mplab_harmony_logo_small.png)

# Microchip MPLAB® Harmony 3 Release Notes

## Serial Memory Bootloader Applications Release v3.0.0

### New Features

- This release includes support of
    - I2C EEPROM Bootloader Applications
    - SPI EEPROM Bootloader Applications
    - SPI Flash Bootloader Applications
    - QSPI Flash Bootloader Applications
    - File System based SPI Flash Bootloader Applications
    - File System based QSPI Flash Bootloader Applications

### Development kit and demo application support
- The following table provides bootloader demo applications available for different development kits.

    | Product Family                 | Development Kits | I2C EEPROM | SPI EEPROM | SPI Flash | QSPI Flash | FS SPI Flash | FS QSPI Flash    |
    | ------------------------------ | ---------------- | ---------- | ---------- | --------- | ---------- | ------------ | ---------------- |
    | SAM D21/DA1                    | [SAM D21 Xplained Pro Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails.aspx?PartNO=ATSAMD21-XPRO)   | Yes | Yes |     | NA  |     | NA  |
    | SAM D5x/E5x                    | [SAM E54 Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/ATSAME54-XPRO)               |     |     |     | Yes |     | Yes |
    | SAM E70/S70/V70/V71            | [SAM E70 Xplained Ultra Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails.aspx?PartNO=ATSAME70-XULT)   |     |     |     | Yes |     | Yes |
    | PIC32MZ EF                     | [PIC32MZ Embedded Connectivity with FPU (EF) Starter Kit](https://www.microchip.com/Developmenttools/ProductDetails/Dm320007)                    |     |     |     | Yes |     |     |
    | PIC32MZ EF                     | [Curiosity PIC32MZ EF 2.0 Development Board](https://www.microchip.com/developmenttools/ProductDetails/DM320209)                    |     |     |     |     |     | Yes |
    | PIC32MZ DA                     | [PIC32MZ Embedded Graphics with Stacked DRAM (DA) Starter Kit (Crypto)](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320010-C)                  |     |     |     | Yes |     |     |
    | PIC32MZ W1                     | [PIC32 WFI32E Curiosity Board](https://www.microchip.com/Developmenttools/ProductDetails/EV12F11A)                                                                                       |     |     | Yes |     | Yes |     |

- **NA:** Lack of product capability

### Known Issues

- N/A

### Development Tools

* [MPLAB® X IDE v5.50](https://www.microchip.com/mplab/mplab-x-ide)
* [MPLAB® XC32 C/C++ Compiler v3.00](https://www.microchip.com/mplab/compilers)
* MPLAB® X IDE plug-ins:
    * MPLAB® Harmony 3 Launcher v3.6.4 and above.

