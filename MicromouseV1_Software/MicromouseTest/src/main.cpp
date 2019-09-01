#include "common_includes.h"
#include "Hardware.h"

Micromouse* mouse  = nullptr;

void setup(){
  pinMode(PC13, OUTPUT);
  Serial.begin(9600);
  Wire.begin();
  MPU6050* mpu = new MPU6050(0x68);
  Serial.println("Calibrating MPU6050...");
  mpu->calibrate(2,1,100,5);
  //should order from left to right or clockwise
  uint8 irReceiverPins[6] = {PA0,PA0,PA0,PA0,PA0,PA0};
  mouse = new Micromouse(0,mpu,irReceiverPins);
}
void loop(){
  digitalWrite(PC13, LOW);
  delay(100);
  digitalWrite(PC13, HIGH);
  mouse->updatePose(0.2);//this update gyro,acc,velocity,pose.loc,and pose.angle
  mouse->detectWalls();
  mouse->printInfo();
  Serial.print("\n");
  delay(100);
}
