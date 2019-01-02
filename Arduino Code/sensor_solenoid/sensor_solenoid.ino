// command + shift + m

#include <Wire.h>
#include "SFE_ISL29125.h"

// Declare sensor object
SFE_ISL29125 RGB_sensor;

int pin = 4;
//int led = 3;

void setup()
{ 
  //pinMode(led, OUTPUT);
  //digitalWrite(led, HIGH);
 
  pinMode(pin, OUTPUT);

  // Initialize serial communication
  Serial.begin(115200);

  // Initialize the ISL29125 with simple configuration so it starts sampling
  if (RGB_sensor.init())
  {
    //Serial.println("Sensor Initialization Successful\n\r");
  }
}

// Read sensor values for each color and print them to serial monitor
void loop()
{
  // Read sensor values (16 bit integers)
  //delay(3000);
  unsigned long red = RGB_sensor.readRed();
  unsigned long green = RGB_sensor.readGreen();
  unsigned long blue = RGB_sensor.readBlue();

  //unsigned int red = map(RGB_sensor.readRed(), 0, 2000, 0, 255);
  //unsigned int green = map(RGB_sensor.readGreen(), 0, 2000, 0, 255);
  //unsigned int blue = map(RGB_sensor.readBlue(), 0, 2000, 0, 255);
  // 65535
  
  // Print out readings, change HEX to DEC if you prefer decimal output
  Serial.print("Red: "); Serial.print(red,DEC);
  Serial.println();
  Serial.print("Green: "); Serial.print(green,DEC);
  Serial.println();
  Serial.print("Blue: "); Serial.print(blue,DEC);
  Serial.println();
  //Serial.println();

  // if ((red >= 100) && (green >= 100) && (green > red) && (green > blue)) 
  // if ((red >= 95) && (red > blue) && (red > green))
  // if ((red <= 600) && (blue <= 600) && (green <= 600)) // funciona con oscuridad (negro)
  long resultado1 ;
      resultado1=blue - red;
  long resultado2 ;
      resultado2=blue - green;
  // if ((green > red) && (green > blue) && (green > 550) && (blue < 500) && (red < 450)) 
  if ((resultado1 > 100) && (resultado2 > 100)) {
      // action A
      long resultado ;
      resultado=blue - red;
      Serial.println(resultado);
      digitalWrite(pin, HIGH);
      Serial.println("HOLAAAAA");
      Serial.println();
    } 
     
  else 
  {
    // action B
    digitalWrite(pin, LOW);
  }
  
}
  
