//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2025-03-16
// PURPOSE: unit tests for the PCA9671 library
//     URL: https://github.com/RobTillaart/PCA9671
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// https://github.com/Arduino-CI/arduino_ci/blob/master/cpp/unittest/Assertion.h#L33-L42
// ----------------------------
// assertEqual(expected, actual)
// assertNotEqual(expected, actual)
// assertLess(expected, actual)
// assertMore(expected, actual)
// assertLessOrEqual(expected, actual)
// assertMoreOrEqual(expected, actual)
// assertTrue(actual)
// assertFalse(actual)
// assertNull(actual)
// assertNotNull(actual)

#include <ArduinoUnitTests.h>


#include "Arduino.h"
#include "PCA9671.h"


unittest_setup()
{
  fprintf(stderr, "PCA9671_LIB_VERSION: %s\n", (char *) PCA9671_LIB_VERSION);
}


unittest_teardown()
{
}


unittest(test_constants)
{
  assertEqual(PCA9671_OK           , 0x00);
  assertEqual(PCA9671_CRC_ERROR    , 0x01);
  assertEqual(PCA9671_NOT_READY    , 0x10);
  assertEqual(PCA9671_REQUEST_ERROR, 0x11);
}


unittest(test_constructor)
{
  PCA9671 pca(64);

  assertEqual(acd.getAddress(), 64);
}


unittest_main()


//  -- END OF FILE --

