#include "Hardware.h"


/*MPU6050 gyro accelerometer */

MPU6050::MPU6050(int addr) : addr(addr){
  this->accRaw = {0,0,0};
  this->acc = {0.0f,0.0f,0.0f};
  this->accOffsetRaw = {0,0,0};
  this->tempRaw = 0;
  this->temp = 0.0f;
  this->gyroRaw = {0,0,0};
  this->gyro = {0.0f,0.0f,0.0f};
  this->gyroOffsetRaw = {0,0,0};
  Wire.beginTransmission(this->addr);
  Wire.write(0x6B);//PWR_MGMT_1 register
  Wire.write(0);//set to zero (wakes up MPU6050)
  Wire.endTransmission(true);
}
void MPU6050::updateData(){
  Wire.beginTransmission(this->addr);
  Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false); //restarts transmission to I2C slave device
  Wire.requestFrom(this->addr,14); //request 14 registers in total

  //read accelerometer data
  this->accRaw.x=Wire.read()<<8|Wire.read(); // 0x3B (ACCEL_XOUT_H) 0x3C (ACCEL_XOUT_L)
  this->accRaw.y=Wire.read()<<8|Wire.read(); // 0x3D (ACCEL_YOUT_H) 0x3E (ACCEL_YOUT_L)
  this->accRaw.z=Wire.read()<<8|Wire.read(); // 0x3F (ACCEL_ZOUT_H) 0x40 (ACCEL_ZOUT_L)
  this->acc.x = ((this->accRaw.x + this->accOffsetRaw.x)/16384.0)*9.81;
  this->acc.y = ((this->accRaw.y + this->accOffsetRaw.y)/16384.0)*9.81;
  this->acc.z = ((this->accRaw.z + this->accOffsetRaw.z)/16384.0)*9.81;


  //read temperature data
  this->tempRaw=Wire.read()<<8|Wire.read(); // 0x41 (TEMP_OUT_H) 0x42 (TEMP_OUT_L)
  this->temp = this->tempRaw/340.00 + 36.53;

  //read gyroscope data
  this->gyroRaw.x=Wire.read()<<8|Wire.read(); // 0x43 (GYRO_XOUT_H) 0x44 (GYRO_XOUT_L)
  this->gyroRaw.y=Wire.read()<<8|Wire.read(); // 0x45 (GYRO_YOUT_H) 0x46 (GYRO_YOUT_L)
  this->gyroRaw.z=Wire.read()<<8|Wire.read(); // 0x47 (GYRO_ZOUT_H) 0x48 (GYRO_ZOUT_L)
  this->gyro.x = (this->gyroRaw.x + this->gyroOffsetRaw.x)/131.0;
  this->gyro.y = (this->gyroRaw.y + this->gyroOffsetRaw.y)/131.0;
  this->gyro.z = (this->gyroRaw.z + this->gyroOffsetRaw.z)/131.0;
}
void MPU6050::getRawAvgs(int numReadings, unsigned int readDelay, int64_3& accAvgRaw, int64_3& gyroAvgRaw){

  //this is done for my atom's sanity so I can minimize
  accAvgRaw.x = 0;
  accAvgRaw.y = 0;
  accAvgRaw.z = 0;
  gyroAvgRaw = {0,0,0};

  for(int i = 0; i < numReadings; ++i){
    this->updateData();
    accAvgRaw.x += this->accRaw.x;
    accAvgRaw.y += this->accRaw.y;
    accAvgRaw.z += this->accRaw.z;
    gyroAvgRaw.x += this->gyroRaw.x;
    gyroAvgRaw.y += this->gyroRaw.y;
    gyroAvgRaw.z += this->gyroRaw.z;
    delay(readDelay);//make sure values are not read twice and get wide range
  }

  accAvgRaw.x /= numReadings;
  accAvgRaw.y /= numReadings;
  accAvgRaw.z /= numReadings;
  gyroAvgRaw.x /= numReadings;
  gyroAvgRaw.y /= numReadings;
  gyroAvgRaw.z /= numReadings;
}
//NOTE execute only when unit is still
//TODO optimize and make numReadings and readDelay configurable
void MPU6050::calibrateRaw(int16_t accTolerance, int16_t gyroTolerance){
  Serial.println("Calibrating MPU6050...");
  int64_3 accAvgRaw = {0,0,0};
  int64_3 gyroAvgRaw = {0,0,0};
  int ready = 0;
  int step = 0;

  this->getRawAvgs(400,2,accAvgRaw,gyroAvgRaw);
  this->accOffsetRaw.x = -accAvgRaw.x;///accTolerance;
  this->accOffsetRaw.y = -accAvgRaw.y;///accTolerance;
  this->accOffsetRaw.z = 16384-accAvgRaw.z;///accTolerance;
  this->gyroOffsetRaw.x = -gyroAvgRaw.x;///gyroTolerance;
  this->gyroOffsetRaw.y = -gyroAvgRaw.y;///gyroTolerance;
  this->gyroOffsetRaw.z = -gyroAvgRaw.z;///gyroTolerance;
  int16_2 prevValueHeld[6] = {
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0}
  };

  while(ready != 6){
    this->getRawAvgs(200,2,accAvgRaw,gyroAvgRaw);//has an effect on offset accuracy
    Serial.print("step: ");Serial.print(step++);
    Serial.print(" offsetGood = ");
    ready = 0;

    if(accAvgRaw.x + this->accOffsetRaw.x == prevValueHeld[0].x){
      prevValueHeld[0].y++;
    }
    else{
      prevValueHeld[0].x = accAvgRaw.x + this->accOffsetRaw.x;
      prevValueHeld[0].y = 0;
    }
    if(accAvgRaw.y + this->accOffsetRaw.y == prevValueHeld[1].x){
      prevValueHeld[1].y++;
    }
    else{
      prevValueHeld[1].x = accAvgRaw.y + this->accOffsetRaw.y;
      prevValueHeld[1].y = 0;
    }
    if(accAvgRaw.z + this->accOffsetRaw.z - 16384 == prevValueHeld[2].x){
      prevValueHeld[2].y++;
    }
    else{
      prevValueHeld[2].x = accAvgRaw.z + this->accOffsetRaw.z - 16384;
      prevValueHeld[2].y = 0;
    }
    if(gyroAvgRaw.x + this->gyroOffsetRaw.x == prevValueHeld[3].x){
      prevValueHeld[3].y++;
    }
    else{
      prevValueHeld[3].x = gyroAvgRaw.x + this->gyroOffsetRaw.x;
      prevValueHeld[3].y = 0;
    }
    if(gyroAvgRaw.y + this->gyroOffsetRaw.y == prevValueHeld[4].x){
      prevValueHeld[4].y++;
    }
    else{
      prevValueHeld[4].x = gyroAvgRaw.y + this->gyroOffsetRaw.y;
      prevValueHeld[4].y = 0;
    }
    if(gyroAvgRaw.z + this->gyroOffsetRaw.z == prevValueHeld[5].x){
      prevValueHeld[5].y++;
    }
    else{
      prevValueHeld[5].x = gyroAvgRaw.z + this->gyroOffsetRaw.z;
      prevValueHeld[5].y = 0;
    }


    if(abs(accAvgRaw.x + this->accOffsetRaw.x) > accTolerance && prevValueHeld[0].y < 10){
      if(accAvgRaw.x + this->accOffsetRaw.x > 0){
        this->accOffsetRaw.x -= accTolerance;
      }
      else{
        this->accOffsetRaw.x += accTolerance;
      }
    }
    else{
     ready++;
     Serial.print(" acc.x ");
    }
    if(abs(accAvgRaw.y + this->accOffsetRaw.y) > accTolerance && prevValueHeld[1].y < 10){
      if(accAvgRaw.y + this->accOffsetRaw.y > 0){
        this->accOffsetRaw.y -= accTolerance;
      }
      else{
        this->accOffsetRaw.y += accTolerance;
      }
    }
    else{
     ready++;
     Serial.print(" acc.y ");
    }
    if(abs(accAvgRaw.z + this->accOffsetRaw.z - 16384) > accTolerance && prevValueHeld[2].y < 10){
      if(accAvgRaw.z + this->accOffsetRaw.z - 16384 > 0){
        this->accOffsetRaw.z -= accTolerance;
      }
      else{
        this->accOffsetRaw.z += accTolerance;
      }
    }
    else{
     ready++;
     Serial.print(" acc.z ");
    }

    if(abs(gyroAvgRaw.x + this->gyroOffsetRaw.x) > gyroTolerance && prevValueHeld[3].y < 10){
      if(gyroAvgRaw.x  + this->gyroOffsetRaw.x > 0){
        this->gyroOffsetRaw.x -= gyroTolerance;
      }
      else{
        this->gyroOffsetRaw.x += gyroTolerance;
      }
    }
    else{
     ready++;
     Serial.print(" gyro.x ");
    }
    if(abs(gyroAvgRaw.y  + this->gyroOffsetRaw.y) > gyroTolerance && prevValueHeld[4].y < 10){
      if(gyroAvgRaw.y  + this->gyroOffsetRaw.y > 0){
        this->gyroOffsetRaw.y -= gyroTolerance;
      }
      else{
        this->gyroOffsetRaw.y += gyroTolerance;
      }
    }
    else{
     ready++;
     Serial.print(" gyro.y ");
    }
    if(abs(gyroAvgRaw.z + this->gyroOffsetRaw.z) > gyroTolerance && prevValueHeld[5].y < 10){
      if(gyroAvgRaw.z  + this->gyroOffsetRaw.z > 0){
        this->gyroOffsetRaw.z -= gyroTolerance;
      }
      else{
        this->gyroOffsetRaw.z += gyroTolerance;
      }
    }
    else{
     ready++;
     Serial.print(" gyro.z ");
    }
    Serial.print("\n");
  }
}
void MPU6050::calibrate(int16_t accTolerance, int16_t gyroTolerance, uint16_t meanSetSize, uint8_t invariantOffsetLimit){
  Serial.println("Calibrating MPU6050...");
  int64_3 accAvgRaw = {0,0,0};
  int64_3 gyroAvgRaw = {0,0,0};
  int ready = 0;
  int step = 0;

  this->getRawAvgs(meanSetSize,2,accAvgRaw,gyroAvgRaw);
  this->accOffsetRaw.x = -accAvgRaw.x;///accTolerance;
  this->accOffsetRaw.y = -accAvgRaw.y;///accTolerance;
  this->accOffsetRaw.z = 16384-accAvgRaw.z;///accTolerance;
  this->gyroOffsetRaw.x = -gyroAvgRaw.x;///gyroTolerance;
  this->gyroOffsetRaw.y = -gyroAvgRaw.y;///gyroTolerance;
  this->gyroOffsetRaw.z = -gyroAvgRaw.z;///gyroTolerance;
  uint16_t zeroRelativeError[6] = {0,0,0,0,0,0};
  int16_t offsetChange[6] = {0,0,0,0,0,0};
  while(ready != 6){
    this->getRawAvgs(meanSetSize,2,accAvgRaw,gyroAvgRaw);//has an effect on offset accuracy
    Serial.print("step: ");Serial.print(step++);

    ready = 0;

    offsetChange[0] = -(accAvgRaw.x+this->accOffsetRaw.x)/accTolerance;
    offsetChange[1] = -(accAvgRaw.y+this->accOffsetRaw.y)/accTolerance;
    offsetChange[2] = (16384-(accAvgRaw.z+this->accOffsetRaw.z))/accTolerance;
    offsetChange[3] = -(gyroAvgRaw.x+this->gyroOffsetRaw.x)/gyroTolerance;
    offsetChange[4] = -(gyroAvgRaw.y+this->gyroOffsetRaw.y)/gyroTolerance;
    offsetChange[5] = -(gyroAvgRaw.z+this->gyroOffsetRaw.z)/gyroTolerance;

    if(offsetChange[0] != 0 && zeroRelativeError[0] < invariantOffsetLimit){
      zeroRelativeError[0] = 0;
      this->accOffsetRaw.x -= offsetChange[0];
    }
    else{
      zeroRelativeError[0]++;
      ready++;
    }
    if(offsetChange[1] != 0 && zeroRelativeError[1] < invariantOffsetLimit){
      zeroRelativeError[1] = 0;
      this->accOffsetRaw.y -= offsetChange[1];
    }
    else{
      zeroRelativeError[1]++;
      ready++;
    }
    if(offsetChange[2] != 0 && zeroRelativeError[2] < invariantOffsetLimit){
      zeroRelativeError[2] = 0;
      this->accOffsetRaw.z -= offsetChange[2];
    }
    else{
      zeroRelativeError[2]++;
      ready++;
    }
    if(offsetChange[3] != 0 && zeroRelativeError[3] < invariantOffsetLimit){
      zeroRelativeError[3] = 0;
      this->gyroOffsetRaw.x -= offsetChange[3];
    }
    else{
      zeroRelativeError[3]++;
      ready++;
    }
    if(offsetChange[4] != 0 && zeroRelativeError[4] < invariantOffsetLimit){
      zeroRelativeError[4] = 0;
      this->gyroOffsetRaw.y -= offsetChange[4];
    }
    else{
      zeroRelativeError[4]++;
      ready++;
    }
    if(offsetChange[5] != 0 && zeroRelativeError[5] < invariantOffsetLimit){
      zeroRelativeError[5] = 0;
      this->gyroOffsetRaw.z -= offsetChange[5];
    }
    else{
      zeroRelativeError[5]++;
      ready++;
    }
    Serial.print(" ready = ");Serial.println(ready);
  }
}
void MPU6050::printInfo(){
  Serial.print("acceleration = {");
  Serial.print(this->acc.x);
  Serial.print(",");Serial.print(this->acc.y);
  Serial.print(",");Serial.print(this->acc.z);
  Serial.println("}");
  Serial.print("gyroscope = {");
  Serial.print(this->gyro.x);
  Serial.print(",");Serial.print(this->gyro.y);
  Serial.print(",");Serial.print(this->gyro.z);
  Serial.println("}");
}


/*IR Receiver TEFT4300*/

IRReciever::IRReciever(){
  this->pin = 0;
  this->voltage = 0.0f;
  this->obstruction = false;
}
IRReciever::IRReciever(uint8 pin) : pin(pin){
  this->voltage = 0.0f;
  this->obstruction = false;
}
void IRReciever::update(){
  this->voltage = (float(analogRead(this->pin))/4096.0f)*5.0f;
  this->obstruction = !digitalRead(this->pin);
}


/*Custom Micromouse build from above components*/

Micromouse::Micromouse(unsigned int id, MPU6050* mpu) : id(id), mpu(mpu){
  this->velocity = {0.0f,0.0f,0.0f};
  this->pose.angle = {0.0f,0.0f,0.0f};
  this->pose.loc = {0.0f,0.0f,0.0f};
}
Micromouse::Micromouse(unsigned int id, MPU6050* mpu, uint8 receiverPins[6]) : id(id), mpu(mpu){
  this->velocity = {0.0f,0.0f,0.0f};
  this->pose.angle = {0.0f,0.0f,0.0f};
  this->pose.loc = {0.0f,0.0f,0.0f};
  for(int i = 0; i < 6; ++i){
    this->proximity[i] = IRReciever(receiverPins[i]);
  }
}

//NOTE this assumes body-frame never changes
//if it does then pose will be affected because acc.z - 9.81
void Micromouse::updatePose(float timeStep){
  this->mpu->updateData();
  this->pose.angle.x += this->mpu->gyro.x*timeStep;
  this->pose.angle.y += this->mpu->gyro.y*timeStep;
  this->pose.angle.z += this->mpu->gyro.z*timeStep;
  this->velocity.x += this->mpu->acc.x*timeStep;
  this->velocity.y += this->mpu->acc.y*timeStep;
  this->velocity.z += (this->mpu->acc.z - 9.81)*timeStep;
  this->pose.loc.x += this->velocity.x*timeStep;
  this->pose.loc.y += this->velocity.y*timeStep;
  this->pose.loc.z += this->velocity.z*timeStep;
}
void Micromouse::detectWalls(){
  for(int i = 0; i < 6; ++i){
    this->proximity[i].update();
  }
}
void Micromouse::printInfo(){
  Serial.print("location = {");
  Serial.print(this->pose.loc.x);
  Serial.print(",");Serial.print(this->pose.loc.y);
  Serial.print(",");Serial.print(this->pose.loc.z);
  Serial.println("}");
  Serial.print("angle = {");
  Serial.print(this->pose.angle.x);
  Serial.print(",");Serial.print(this->pose.angle.y);
  Serial.print(",");Serial.print(this->pose.angle.z);
  Serial.println("}");
  Serial.print("velocity = {");
  Serial.print(this->velocity.x);
  Serial.print(",");Serial.print(this->velocity.y);
  Serial.print(",");Serial.print(this->velocity.z);
  Serial.println("}");
  this->mpu->printInfo();
  Serial.print("walls = {");
  for(int i = 0; i < 6; ++i){
    Serial.print(this->proximity[i].obstruction);
    if(i != 5) Serial.print(",");
  }
  Serial.println("}");
}
