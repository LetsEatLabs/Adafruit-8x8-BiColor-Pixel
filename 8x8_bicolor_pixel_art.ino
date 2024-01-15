/*************************************************** 
  This is a library for our I2C LED Backpacks

  Designed specifically to work with the Adafruit LED Matrix backpacks 
  ----> http://www.adafruit.com/products/872
  ----> http://www.adafruit.com/products/871
  ----> http://www.adafruit.com/products/870

  These displays use I2C to communicate, 2 pins are required to 
  interface. There are multiple selectable I2C addresses. For backpacks
  with 2 Address Select pins: 0x70, 0x71, 0x72 or 0x73. For backpacks
  with 3 Address Select pins: 0x70 thru 0x77

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include "Adafruit_GFX.h"
#include "Adafruit_LEDBackpack.h"
#include "pixels.h"

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();

void setup() {
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");
  
  matrix.begin(0x70);  // pass in the address
}

void loop() {

  int al = sizeof(imgs)/sizeof(imgs[0]);

  for (int t=0; t<al; t++) {
    int row = 0;
    int col = 0;

    // Clear the matrix
    matrix.clear();

    // Get the image from the image array
    String img = imgs[t];

    // For each character in the array
    for (int i=0; i<img.length(); i++) {
      
      if (img.charAt(i) == *"0") {
        col++;
        continue;
      }

      if (img.charAt(i) == *"1") {
        matrix.drawPixel(row, col, LED_GREEN);
        col++;
        continue;
      }

      if (img.charAt(i) == *"2") {
        matrix.drawPixel(row, col, LED_RED);
        col++;
        continue;
      }

      if (img.charAt(i) == *"3") {
        matrix.drawPixel(row, col, LED_YELLOW);
        col++;
        continue;
      }

      if (img.charAt(i) == *" ") {
        row++;
        col = 0;
        continue;
      } 
    }
    
    matrix.writeDisplay();  // write the changes we just made to the display
    delay(500);

  }

}
