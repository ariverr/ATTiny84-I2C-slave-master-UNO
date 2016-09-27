#include <Wire.h>

void setup()
{
  Wire.begin();
  Serial.begin(9600);
}

void loop()
{

  for(int x = 1; x < 4; x++)
  {
    Wire.requestFrom(x,1); //request from slave device
                           //address 1. expect 1 byte
    while(Wire.available())
    {
      int i = Wire.read();
      
      String rString = "";
      rString.concat(x);
      rString.concat(" value is ");
      rString.concat(i);
      Serial.println(rString);
    }
    delay(500);
  }
}
  
