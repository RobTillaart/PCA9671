#pragma once
//
//    FILE: PCA9671.h
//  AUTHOR: Rob Tillaart
//    DATE: 2025-00-00
// VERSION: 0.1.0
// PURPOSE: Arduino library for the PCA9671, I2C 16-bit I/O expander
//     URL: https://github.com/RobTillaart/PCA9671
//


#include "Arduino.h"
#include "Wire.h"


#define PCA9671_LIB_VERSION         (F("0.1.0"))

//  ERROR CODES
//  values <> 0 are errors.
#define PCA9671_OK                  0x00
#define PCA9671_CRC_ERROR           0x01
#define PCA9671_NOT_READY           0x10
#define PCA9671_REQUEST_ERROR       0x11


class PCA9671
{
public:
  PCA9671(uint8_t address, TwoWire *wire = &Wire);

  bool     begin();
  bool     isConnected();
  uint8_t  getAddress();


  //       READ


  //       DEBUG
  int      getLastError();


private:
  uint8_t  _address;
  TwoWire* _wire;

  int      _command(uint8_t * arr, uint8_t size);
  int      _request(uint8_t * arr, uint8_t size);
  uint8_t  _crc8(uint8_t * arr, uint8_t size);

  uint8_t  _error;
};


//  -- END OF FILE --





