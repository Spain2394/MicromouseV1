#include <Arduino.h>
#include <Wire.h>

const int MPU6050_addr=0x68;

int16_t rAcX,rAcY,rAcZ,rTmp,rGyX,rGyY,rGyZ;//raw values
float AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
float AcXcal,AcYcal,AcZcal,GyXcal,GyYcal,GyZcal; //calibration variables
double t,tx,pitch,roll,yaw;

void getAngle(int Ax,int Ay,int Az);
void calibrate();//should be called while unit is still

void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x6B);//PWR_MGMT_1 register
  Wire.write(0);//set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  pinMode(PC13, OUTPUT);
  Serial.begin(9600);
  Serial.println("Calibrating MPU6050...");
  calibrate();
}
void loop(){

  delay(500);
  digitalWrite(PC13, LOW);

  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false); //restarts transmission to I2C slave device
  Wire.requestFrom(MPU6050_addr,14); //request 14 registers in total

  //read accelerometer data
  rAcX=Wire.read()<<8|Wire.read(); // 0x3B (ACCEL_XOUT_H) 0x3C (ACCEL_XOUT_L)
  rAcY=Wire.read()<<8|Wire.read(); // 0x3D (ACCEL_YOUT_H) 0x3E (ACCEL_YOUT_L)
  rAcZ=Wire.read()<<8|Wire.read(); // 0x3F (ACCEL_ZOUT_H) 0x40 (ACCEL_ZOUT_L)
  AcX = (rAcX/16384.0)*9.81;
  AcY = (rAcY/16384.0)*9.81;
  AcZ = (rAcZ/16384.0)*9.81;

  //read temperature data
  rTmp=Wire.read()<<8|Wire.read(); // 0x41 (TEMP_OUT_H) 0x42 (TEMP_OUT_L)

  //read gyroscope data
  rGyX=Wire.read()<<8|Wire.read(); // 0x43 (GYRO_XOUT_H) 0x44 (GYRO_XOUT_L)
  rGyY=Wire.read()<<8|Wire.read(); // 0x45 (GYRO_YOUT_H) 0x46 (GYRO_YOUT_L)
  rGyZ=Wire.read()<<8|Wire.read(); // 0x47 (GYRO_ZOUT_H) 0x48 (GYRO_ZOUT_L)
  GyX = rGyX/131.0;
  GyY = rGyY/131.0;
  GyZ = rGyZ/131.0;

  //temperature calculation (NOTE CALIBRATED - should be fine though)
  tx = rTmp;
  t = tx/340 + 36.53; //equation for temperature in degrees C from datasheet

  //get pitch/roll
  getAngle(AcX+ AcXcal,AcY+ AcYcal,AcZ+ AcZcal);

  //printing values to serial port
  Serial.print("Angle: ");
  Serial.print("Pitch = "); Serial.print(pitch);
  Serial.print(" Roll = "); Serial.print(roll);
  Serial.print(" Yaw = "); Serial.println(yaw);

  Serial.print("Accelerometer: ");
  Serial.print("X = "); Serial.print(AcX + AcXcal);
  Serial.print(" Y = "); Serial.print(AcY + AcYcal);
  Serial.print(" Z = "); Serial.println(AcZ + AcZcal);

  Serial.print("Gyroscope: ");
  Serial.print("X = "); Serial.print(GyX + GyXcal);
  Serial.print(" Y = "); Serial.print(GyY + GyYcal);
  Serial.print(" Z = "); Serial.println(GyZ + GyZcal);

  Serial.print("Temperature in celsius = "); Serial.println(t);

  int raw_ir = analogRead(PA0);
  float voltage_ir = (float(raw_ir)/4096.0f)*3.3;
  Serial.print("IR = ");Serial.print(voltage_ir);

  Serial.println("\n");
  delay(500);
  digitalWrite(PC13,HIGH);

}
//function to convert accelerometer values into pitch and roll
void getAngle(int Ax,int Ay,int Az){
    double x = Ax;
    double y = Ay;
    double z = Az;

    pitch = atan(x/sqrt((y*y) + (z*z)))*(180.0/3.14); //pitch calculation
    roll = atan(y/sqrt((x*x) + (z*z)))*(180.0/3.14); //roll calculation
    yaw = atan(z/sqrt((x*x) + (z*z)))*(180.0/3.14); // yaw calculation
}
void calibrate(){

  for(int i = 0; i < 1000; ++i){
    Wire.beginTransmission(MPU6050_addr);
    Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H)
    Wire.endTransmission(false); //restarts transmission to I2C slave device
    Wire.requestFrom(MPU6050_addr,14); //request 14 registers in total

    //read accelerometer data
    rAcX=Wire.read()<<8|Wire.read(); // 0x3B (ACCEL_XOUT_H) 0x3C (ACCEL_XOUT_L)
    rAcY=Wire.read()<<8|Wire.read(); // 0x3D (ACCEL_YOUT_H) 0x3E (ACCEL_YOUT_L)
    rAcZ=Wire.read()<<8|Wire.read(); // 0x3F (ACCEL_ZOUT_H) 0x40 (ACCEL_ZOUT_L)
    AcX += (rAcX/16384.0)*9.81;
    AcY += (rAcY/16384.0)*9.81;
    AcZ += (rAcZ/16384.0)*9.81;
    //read temperature data
    rTmp=Wire.read()<<8|Wire.read(); // 0x41 (TEMP_OUT_H) 0x42 (TEMP_OUT_L)

    //read gyroscope data
    rGyX=Wire.read()<<8|Wire.read(); // 0x43 (GYRO_XOUT_H) 0x44 (GYRO_XOUT_L)
    rGyY=Wire.read()<<8|Wire.read(); // 0x45 (GYRO_YOUT_H) 0x46 (GYRO_YOUT_L)
    rGyZ=Wire.read()<<8|Wire.read(); // 0x47 (GYRO_ZOUT_H) 0x48 (GYRO_ZOUT_L)
    GyX += rGyX/131.0;
    GyY += rGyY/131.0;
    GyZ += rGyZ/131.0;
    delay(2);//make sure values are not read twice
  }

  AcX /= 1000;
  AcY /= 1000;
  AcZ /= 1000;
  GyX /= 1000;
  GyY /= 1000;
  GyZ /= 1000;

  while(abs(AcZ  + AcZcal - 9.81) > 0.01){
    if(AcZ  + AcZcal - 9.81 > 0.01){
      AcZcal-=0.001;
    }
    else{
      AcZcal+=0.001;
    }
  }
  while(abs(AcX  + AcXcal) > 0.01){
    if(AcX + AcXcal> 0.1){
      AcXcal-=0.001;
    }
    else{
      AcXcal+=0.001;
    }
  }
  while(abs(AcY  + AcYcal) > 0.01){
    if(AcY  + AcYcal> 0.01){
      AcYcal-=0.001;
    }
    else{
      AcYcal+=0.001;
    }
  }

  while(abs(GyX  + GyXcal) > 0.01){
    if(GyX + GyXcal> 0.01){
      GyXcal-=0.001;
    }
    else{
      GyXcal+=0.001;
    }
  }
  while(abs(GyY  + GyYcal) > 0.01){
    if(GyY  + GyYcal> 0.01){
      GyYcal-=0.001;
    }
    else{
      GyYcal+=0.001;
    }
  }
  while(abs(GyZ + GyZcal) > 0.01){
    if(GyZ  + GyZcal > 0.01){
      GyZcal-=0.001;
    }
    else{
      GyZcal+=0.001;
    }
  }
}
