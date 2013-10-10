// I2C device class (I2Cdev) demonstration Arduino sketch for MPU6050 class
// 10/7/2011 by Jeff Rowberg <jeff@rowberg.net>
// Updates should (hopefully) always be available at https://github.com/jrowberg/i2cdevlib
//
// Changelog:
//     2011-10-07 - initial release

/* ============================================
 I2Cdev device library code is placed under the MIT license
 Copyright (c) 2011 Jeff Rowberg
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ===============================================
 */

// Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// is used in I2Cdev.h
#include "Wire.h"

// I2Cdev and MPU6050 must be installed as libraries, or else the .cpp/.h files
// for both classes must be in the include path of your project
#include "I2Cdev.h"
#include "MPU6050.h"
// class default I2C address is 0x68
// specific I2C addresses may be passed as a parameter here
// AD0 low = 0x68 (default for InvenSense evaluation board)
// AD0 high = 0x69
MPU6050 accelgyro;
uint32_t timer;
int16_t tempRaw;
int16_t ax, ay, az;
int16_t axoff,ayoff,azoff;
int16_t gx, gy, gz;
int16_t gxoff, gyoff, gzoff;

void setup() {
  Wire.begin();
  Serial.begin(38400);
  accelgyro.initialize();
  
  //***********************************************************************************************************************************

  //******************************************************************calibrado********************************************************

  //***********************************************************************************************************************************

  for (int i=1; i<=100;i++) { 
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    gxoff+=gx;
    gyoff+=gy;
    gzoff+=gz;
    axoff+=ax;
    ayoff+=ay;
    azoff+=az;
  }
  gxoff=gxoff/100;
  gyoff=gyoff/100;
  gzoff=gzoff/100;
  axoff=axoff/100;
  ayoff=ayoff/100;
  ayoff=ayoff/100;  
#ifdef DEBUG     
  Serial.print("Gyro offset measured:");
  Serial.print(gxoff);
  Serial.print(",");   
  Serial.print(gyoff);
  Serial.print(",");      
  Serial.println(gyoff);    
#endif 
}

void loop() {

  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

}

