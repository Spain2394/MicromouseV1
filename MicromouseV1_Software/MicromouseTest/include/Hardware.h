#ifndef HARDWARE_H
#define HARDWARE_H
#include "common_includes.h"

/*MPU6050 gyro accelerometer */

struct MPU6050{
  //NOTE evaluate minimization of this struct
  int16_3 accRaw;
  int16_3 accOffsetRaw;
  float3 acc;
  int16_t tempRaw;
  float temp;
  int16_3 gyroRaw;
  int16_3 gyroOffsetRaw;
  float3 gyro;
  int addr;

  MPU6050(int addr);
  void updateData();

  void getRawAvgs(int numReadings, unsigned int readDelay, int64_3& accAvgRaw, int64_3& gyroAvgRaw);
  //NOTE execute only when unit is still
  //TODO optimize and make numReadings and readDelay configurable
  void calibrateRaw(int16_t accTolerance, int16_t gyroTolerance);
  void calibrate(int16_t accTolerance, int16_t gyroTolerance, uint16_t meanSetSize, uint8_t invariantOffsetLimit);
  void printInfo();
};

/*IR Receiver TEFT4300*/

struct IRReciever{
  uint8 pin;
  float voltage;
  bool obstruction;
  IRReciever();
  IRReciever(uint8 pin);
  void update();
};

/*Custom Micromouse build from above components*/

struct Micromouse{
  unsigned int id;
  Pose pose;
  float3 velocity;
  MPU6050* mpu;
  IRReciever proximity[6];
  Micromouse(unsigned int id, MPU6050* mpu);
  Micromouse(unsigned int id, MPU6050* mpu, uint8 receiverPins[6]);

  //NOTE this assumes body-frame never changes
  //if it does then pose will be affected because acc.z - 9.81
  void updatePose(float timeStep);
  void detectWalls();
  void printInfo();
};

#endif /* HARDWARE_H */
