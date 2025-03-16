//
//    FILE: PCA9671_demo.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: test basic behaviour and performance
//     URL: https://github.com/RobTillaart/PCA9671


#include "PCA9671.h"


PCA9671 pca(64);


void setup()
{
  while(!Serial);
  Serial.begin(115200);
  Serial.println();
  Serial.println(__FILE__);
  Serial.print("PCA9671_LIB_VERSION: ");
  Serial.println(PCA9671_LIB_VERSION);
  Serial.println();

  Wire.begin();
  pca.begin();
}


void loop()
{

  delay(2000);
}


//  -- END OF FILE --
