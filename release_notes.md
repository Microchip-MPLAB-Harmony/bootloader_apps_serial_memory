![Microchip logo](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_logo.png)
![Harmony logo small](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_mplab_harmony_logo_small.png)

# Microchip MPLAB® Harmony 3 Release Notes

## Serial Memory Bootloader Applications Release v3.3.0

### New Features

- This release includes support of
    - I2C EEPROM Bootloader Applications for PIC32CM GC00 and PIC32CX MT family of 32-bit microcontrollers
    - QSPI Flash Bootloader Applications for PIC32CK GC01, PIC32CZ CA70, PIC32WM BZ6 and WBZ351 family of 32-bit microcontrollers
    - FS QSPI Flash Bootloader Applications for PIC32CK GC01, PIC32CZ CA70 and PIC32WM BZ6 family of 32-bit microcontrollers

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
    | PIC32MM                        | [PIC32MM USB Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320107) |    | Yes |    |    |    |    |
    | PIC32CZ CA                     | [PIC32CZ-CA80 Curiosity Ultra board](https://www.microchip.com/en-us/development-tool/ea61x20a) |    |    |    |  Yes  |    |  Yes  |
    | WBZ451                         | [PIC32CX-BZ2 and WBZ451 Curiosity Board](https://www.microchip.com/en-us/development-tool/EA71C53A) |    |    |    |  Yes  |    |  Yes  |
    | PIC32CK GC01                   | [PIC32CK GC Curiosity Ultra board](https://www.microchip.com/en-us/development-tool/ev44p93a)          |    |    |    |  Yes  |    |  Yes  |
    | PIC32CM GC00                   | [PIC32CM GC Curiosity Pro board](https://www.microchip.com/en-us/development-tool/EA36K74A)            | Yes |    |    |    |    |       |
    | PIC32CZ CA70                   | [PIC32CZ-CA70 Curiosity Ultra board](https://www.microchip.com/en-us/development-tool/ev56t44a)        |    |    |    |  Yes  |    |  Yes  |
    | PIC32WM BZ6                    | [PIC32WM BZ6 Curiosity]()                                                                              |    |    |    |  Yes  |    |  Yes  |
    | WBZ351                         | [PIC32CX-BZ3 and WBZ35x Curiosity Board](https://www.microchip.com/en-us/development-tool/ev19j06a)    |    |    |    |  Yes  |    |       |
    | PIC32CX MT                     | [PIC32CXMTSH-DB Evaluation Kit](https://www.microchip.com/en-us/development-tool/ev84m21a)             | Yes |    |    |    |    |       |

- **NA:** Lack of product capability

### Known Issues

- N/A

### Development Tools

- [MPLAB® X IDE v6.25](https://www.microchip.com/mplab/mplab-x-ide)
- MPLAB® X IDE plug-ins:
  - MPLAB® Code Configurator (MCC) v5.5.2
- [MPLAB® XC32 C/C++ Compiler v4.60](https://www.microchip.com/mplab/compilers)


## Serial Memory Bootloader Applications Release v3.2.1

### Bug Fixes
- Regenerated and tested app progammer application examples

### Development Tools
- Same as v3.2.0 release

## Serial Memory Bootloader Applications Release v3.2.0

### New Features

- This release includes support of
    - QSPI Flash and FS QSPI Flash Bootloader Applications for PIC32CZ CA family of 32-bit microcontrollers
    - QSPI Flash and FS QSPI Flash Bootloader Applications for PIC32CX-BZ2 and WBZ45 family of 32-bit microcontrollers

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
    | PIC32MM                        | [PIC32MM USB Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320107) |    | Yes |    |    |    |    |
    | PIC32CZ CA                     | [PIC32CZ-CA80 Curiosity Ultra board](https://www.microchip.com/en-us/development-tool/ea61x20a) |    |    |    |  Yes  |    |  Yes  |
    | WBZ451                         | [PIC32CX-BZ2 and WBZ451 Curiosity Board](https://www.microchip.com/en-us/development-tool/EA71C53A) |    |    |    |  Yes  |    |  Yes  |

- **NA:** Lack of product capability

### Known Issues

- N/A

### Development Tools

- [MPLAB® X IDE v6.15](https://www.microchip.com/mplab/mplab-x-ide)
- MPLAB® X IDE plug-ins:
  - MPLAB® Code Configurator (MCC) v5.4.1
- [MPLAB® XC32 C/C++ Compiler v4.35](https://www.microchip.com/mplab/compilers)


## Serial Memory Bootloader Applications Release v3.1.0

### New Features

- This release includes support of
    - SPI EEPROM Bootloader Applications for PIC32MM

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
    | PIC32MM                        | [PIC32MM USB Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320107) |    | Yes |    |    |    |    |

- **NA:** Lack of product capability

### Known Issues

- N/A

### Development Tools

* [MPLAB® X IDE v6.05](https://www.microchip.com/mplab/mplab-x-ide)
* [MPLAB® XC32 C/C++ Compiler v4.20](https://www.microchip.com/mplab/compilers)
* MPLAB® X IDE plug-ins:
  * MPLAB® Code Configurator (MCC) v5.1.17


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

