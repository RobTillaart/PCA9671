
[![Arduino CI](https://github.com/RobTillaart/PCA9671/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/PCA9671/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/PCA9671/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/PCA9671/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/PCA9671/actions/workflows/jsoncheck.yml)
[![GitHub issues](https://img.shields.io/github/issues/RobTillaart/PCA9671.svg)](https://github.com/RobTillaart/PCA9671/issues)

[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/PCA9671/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/PCA9671.svg?maxAge=3600)](https://github.com/RobTillaart/PCA9671/releases)
[![PlatformIO Registry](https://badges.registry.platformio.org/packages/robtillaart/library/PCA9671.svg)](https://registry.platformio.org/libraries/robtillaart/PCA9671)


# PCA9671

Arduino library for the PCA9671, I2C 16-bit I/O expander.


## Description

**Experimental**

This library is to use the PCA9671 I2C 16-bit I/O expander.


Feedback as always is welcome.




### Related

- https://github.com/RobTillaart/PCF8575
- https://github.com/RobTillaart/PCA9685


### Tested

TODO: Test on Arduino UNO and ESP32


## I2C

The device has possible 64 addresses.

See datasheet.


### I2C multiplexing

Sometimes you need to control more devices than possible with the default
address range the device provides.
This is possible with an I2C multiplexer e.g. TCA9548 which creates up 
to eight channels (think of it as I2C subnets) which can use the complete 
address range of the device. 

Drawback of using a multiplexer is that it takes more administration in 
your code e.g. which device is on which channel. 
This will slow down the access, which must be taken into account when
deciding which devices are on which channel.
Also note that switching between channels will slow down other devices 
too if they are behind the multiplexer.

- https://github.com/RobTillaart/TCA9548


### I2C Performance

Only test **readSensor()** as that is the main function.


|  Clock     |  time (us)  |  Notes  |
|:----------:|:-----------:|:--------|
|   100 KHz  |             |  default 
|   200 KHz  |             |
|   300 KHz  |             |
|   400 KHz  |             |
|   500 KHz  |             |
|   600 KHz  |             |


TODO: run performance sketch on hardware.


## Interface

```cpp
#include "PCA9671.h"
```

### Constructor

- **PCA9671(uint8_t address, TwoWire \*wire = &Wire)** optional select I2C bus.
- **bool begin()** checks if device is visible on the I2C bus.
- **bool isConnected()** Checks if device address can be found on I2C bus.
- **uint8_t getAddress()** Returns the address set in the constructor.


### Read




### Debug

- **uint8_t getLastError()** returns last error of low level communication.


## Future

#### Must

- improve documentation
- get hardware to test

#### Should


#### Could


#### Wont


## Support

If you appreciate my libraries, you can support the development and maintenance.
Improve the quality of the libraries by providing issues and Pull Requests, or
donate through PayPal or GitHub sponsors.

Thank you,


