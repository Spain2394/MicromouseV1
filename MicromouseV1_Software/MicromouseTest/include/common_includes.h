#ifndef COMMON_INCLUDES_H
#define COMMON_INCLUDES_H

#include <Arduino.h>
#include <Wire.h>

struct int64_3{
  int64_t x;
  int64_t y;
  int64_t z;
};
struct int16_2{
  int16_t x;
  int16_t y;
};
struct int16_3{
  int16_t x;
  int16_t y;
  int16_t z;
};
struct float3{
  float x;
  float y;
  float z;
};
struct Pose{
  float3 loc;
  float3 angle;
};

#endif /* COMMON_INCLUDES_H */
