#include <Arduino.h>
#include<Wire.h>

void setup(){
  Serial.begin(9600);
  Wire.begin();
  Serial.println("\nI2C Scanner");
}
void loop(){

  byte error;
  byte address;
  Serial.println("Scanning...");
  int nDevices = 0;

  for(address = 1; address < 127; address++){
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if(error == 0){
      Serial.print("I2C device found at address 0x");
      if(address < 16){
        Serial.print("0");
      }
      Serial.print(address,HEX);
      nDevices++;
    }
    else if(error == 4){
      Serial.print("Unknown error at address 0x");
      if(address < 16){
        Serial.print("0");
      }
      Serial.println(address,HEX);
    }
  }
  if(nDevices == 0){
    Serial.println("Could not detect any I2C devices\n");
  }
  else{
    Serial.println("done\n");
  }
  delay(5000);

}
