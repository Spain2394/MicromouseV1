#include "Wire.h"

const int MPU6050_addr=0x68;
#define HIST_SIZE 200

int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

float aax[HIST_SIZE];
float aay[HIST_SIZE];
float aaz[HIST_SIZE];

float agx[HIST_SIZE];
float agy[HIST_SIZE];
float agz[HIST_SIZE];

int16_t AcXcal,AcYcal,AcZcal,GyXcal,GyYcal,GyZcal; //calibration variables


int since = millis();
int timestep = 0;

void setup() {

  delay(5000);
  Wire.begin();
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x6B);//PWR_MGMT_1 register
  Wire.write(0);//set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);

  pinMode(PC13, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  //read accelerometer data
  AcX=Wire.read()<<8|Wire.read(); // 0x3B (ACCEL_XOUT_H) 0x3C (ACCEL_XOUT_L)
  AcY=Wire.read()<<8|Wire.read(); // 0x3D (ACCEL_YOUT_H) 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read(); // 0x3F (ACCEL_ZOUT_H) 0x40 (ACCEL_ZOUT_L)

  //read temperature data
  Tmp=Wire.read()<<8|Wire.read(); // 0x41 (TEMP_OUT_H) 0x42 (TEMP_OUT_L)

  //read gyroscope data
  GyX=Wire.read()<<8|Wire.read(); // 0x43 (GYRO_XOUT_H) 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read(); // 0x45 (GYRO_YOUT_H) 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read(); // 0x47 (GYRO_ZOUT_H) 0x48 (GYRO_ZOUT_L)

  aax[timestep] = AcX + AcXcal;
  aay[timestep] = AcY + AcYcal;
  aaz[timestep] = AcZ + AcZcal;
  agx[timestep] = GyX + GyXcal;
  agy[timestep] = GyY + GyYcal;
  agz[timestep] = GyZ + GyZcal;

  if (millis() - since < 180000) return;

  if (AcX + AcXcal > 0) AcXcal--; else AcXcal++;
  if (AcY + AcYcal > 0) AcYcal--; else AcYcal++;
  if (AcZ + AcZcal > 16384) AcZcal--; else AcZcal++;
  if (GyX + GyXcal > 0) GyXcal--; else GyXcal++;
  if (GyY + GyYcal > 0) GyYcal--; else GyYcal++;
  if (GyZ + GyZcal > 0) GyZcal--; else GyZcal++;

  timestep++;
  if (timestep >= HIST_SIZE) {
      timestep = 0;
  }
  Serial.print("Accelerometer: ");
  Serial.print("X = "); Serial.print(AcX + AcXcal);
  Serial.print(" Y = "); Serial.print(AcY + AcYcal);
  Serial.print(" Z = "); Serial.println(AcZ + AcZcal - 16384);

  Serial.print("Gyroscope: ");
  Serial.print("X = "); Serial.print(GyX + GyXcal);
  Serial.print(" Y = "); Serial.print(GyY + GyYcal);
  Serial.print(" Z = "); Serial.println(GyZ + GyZcal);
  delay(200);
}
