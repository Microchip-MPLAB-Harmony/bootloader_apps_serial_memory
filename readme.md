---
title: Serial Memory Bootloader Applications
has_children: true
has_toc: false
nav_order: 1
---
[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# MPLAB® Harmony 3 Serial Memory Bootloader Application Examples

MPLAB® Harmony 3 is an extension of the MPLAB® ecosystem for creating
embedded firmware solutions for Microchip 32-bit SAM and PIC® microcontroller
and microprocessor devices. Refer to the following links for more information.

- [Microchip 32-bit MCUs](https://www.microchip.com/design-centers/32-bit)
- [Microchip 32-bit MPUs](https://www.microchip.com/design-centers/32-bit-mpus)
- [Microchip MPLAB X IDE](https://www.microchip.com/mplab/mplab-x-ide)
- [Microchip MPLAB Harmony](https://www.microchip.com/mplab/mplab-harmony)
- [Microchip MPLAB Harmony Pages](https://microchip-mplab-harmony.github.io/)

This repository contains the MPLAB® Harmony 3 Serial Memory Bootloader application examples

- [Release Notes](release_notes.md)
- [MPLAB® Harmony License](mplab_harmony_license.md)

To clone or download these application from Github,go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/bootloader_apps_serial_memory) and then click Clone button to clone this repo or download as zip file. This content can also be download using content manager by following [these instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki)

## Contents Summary

| Folder     | Description                                      |
| ---        | ---                                              |
| apps       | Serial Memory Bootloader example applications    |
| docs       | Applications help documentation                  |

## Bootloader Examples

The following applications are provided to demonstrate the Serial Memory bootloaders

| Name                                                                  | Description                                                        |
| --------                                                              | -----------                                                        |
| [I2C EEPROM Bootloader](apps/i2c_eeprom_bootloader/readme.md)         | This example application shows how to use the Serial Memory Bootloader Library to bootload an application from I2C EEPROM (AT24) to Internal Flash |
| [SPI EEPROM Bootloader](apps/spi_eeprom_bootloader/readme.md)         | This example application shows how to use the Serial Memory Bootloader Library to bootload an application from SPI EEPROM (AT25) to Internal Flash |
| [SPI Flash Bootloader](apps/spi_flash_bootloader/readme.md)           | This example application shows how to use the Serial Memory Bootloader Library to bootload an application from SPI Flash memory (SST26) to Internal Flash |
| [QSPI Flash Bootloader](apps/qspi_flash_bootloader/readme.md)         | This example application shows how to use the Serial Memory Bootloader Library to bootload an application from QSPI Flash memory (SST26) to Internal Flash |
| [FS SPI Flash Bootloader](apps/fs/spi/readme.md)                      | This example application shows how to use the File System Bootloader Library to bootload an application from SPI Flash memory (SST26) to Internal Flash |
| [FS QSPI Flash Bootloader](apps/fs/qspi/readme.md)                    | This example application shows how to use the File System Bootloader Library to bootload an application from QSPI Flash memory (SST26) to Internal Flash |


## Bootloader Library

Refer to [Bootloader Library Help](https://microchip-mplab-harmony.github.io/bootloader) for understanding
- Bootloader framework
- How the Bootloader library works
- Bootloader library configurations
- Bootloader memory layout

____

[![License](https://img.shields.io/badge/license-Harmony%20license-orange.svg)](https://github.com/Microchip-MPLAB-Harmony/bootloader_apps_serial_memory/blob/master/mplab_harmony_license.md)
[![Latest release](https://img.shields.io/github/release/Microchip-MPLAB-Harmony/bootloader_apps_serial_memory.svg)](https://github.com/Microchip-MPLAB-Harmony/bootloader_apps_serial_memory/releases/latest)
[![Latest release date](https://img.shields.io/github/release-date/Microchip-MPLAB-Harmony/bootloader_apps_serial_memory.svg)](https://github.com/Microchip-MPLAB-Harmony/bootloader_apps_serial_memory/releases/latest)
[![Commit activity](https://img.shields.io/github/commit-activity/y/Microchip-MPLAB-Harmony/bootloader_apps_serial_memory.svg)](https://github.com/Microchip-MPLAB-Harmony/bootloader_apps_serial_memory/graphs/commit-activity)
[![Contributors](https://img.shields.io/github/contributors-anon/Microchip-MPLAB-Harmony/bootloader_apps_serial_memory.svg)]()

____

[![Follow us on Youtube](https://img.shields.io/badge/Youtube-Follow%20us%20on%20Youtube-red.svg)](https://www.youtube.com/user/MicrochipTechnology)
[![Follow us on LinkedIn](https://img.shields.io/badge/LinkedIn-Follow%20us%20on%20LinkedIn-blue.svg)](https://www.linkedin.com/company/microchip-technology)
[![Follow us on Facebook](https://img.shields.io/badge/Facebook-Follow%20us%20on%20Facebook-blue.svg)](https://www.facebook.com/microchiptechnology/)
[![Follow us on Twitter](https://img.shields.io/twitter/follow/MicrochipTech.svg?style=social)](https://twitter.com/MicrochipTech)

[![](https://img.shields.io/github/stars/Microchip-MPLAB-Harmony/bootloader_apps_serial_memory.svg?style=social)]()
[![](https://img.shields.io/github/watchers/Microchip-MPLAB-Harmony/bootloader_apps_serial_memory.svg?style=social)]()