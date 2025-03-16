//
//    FILE: PCA9671.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2025-03-16
// VERSION: 0.1.0
// PURPOSE: Arduino library for the PCA9671, I2C 16-bit I/O expander
//     URL: https://github.com/RobTillaart/PCA9671



#include "PCA9671.h"


PCA9671::PCA9671(uint8_t address, TwoWire *wire)
{
  _address = address;
  _wire = wire;
  _error = 0;
}


bool PCA9671::begin()
{
  //  reset variables
  _error = 0;

  if (! isConnected())
  {
    return false;
  }
  return true;
}


bool PCA9671::isConnected()
{
  _wire->beginTransmission(_address);
  return (_wire->endTransmission() == 0);
}


uint8_t PCA9671::getAddress()
{
  return _address;
}


/////////////////////////////////////////////
//
//  READ  
//





/////////////////////////////////////////////
//
//  DEBUG
//
int PCA9671::getLastError()
{
  int e = _error;
  _error = 0;
  return e;
}


///////////////////////////////////////////////
//
//  PRIVATE
//

int PCA9671::_command(uint8_t * arr, uint8_t size)
{
  _wire->beginTransmission(_address);
  for (uint8_t i = 0; i < size; i++)
  {
    _wire->write(arr[i]);
  }
  _error = _wire->endTransmission();
  return _error;
}


int PCA9671::_request(uint8_t * arr, uint8_t size)
{
  uint8_t bytes = _wire->requestFrom(_address, size);
  if (bytes == 0)
  {
    _error = -1;
    return _error;
  }
  if (bytes < size)
  {
    _error = -2;
    return _error;
  }

  for (uint8_t i = 0; i < size; i++)
  {
    arr[i] = _wire->read();
  }
  _error = 0;
  return _error;
}


//  -- END OF FILE --

