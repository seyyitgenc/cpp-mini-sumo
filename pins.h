#ifndef _PINS_H_
#define _PINS_H_

#include <Arduino.h>

constexpr int PWMA = 3;
constexpr int AIN1 = 4;
constexpr int AIN2 = 5;

constexpr int PWMB = 9;
constexpr int BIN1 = 8;
constexpr int BIN2 = 7;

constexpr int OPPONENT_FL = 12;
constexpr int OPPONENT_FC = 10;
constexpr int OPPONENT_FR = 11;
constexpr int OPPONENT_RIGHT = 13;
constexpr int OPPONENT_LEFT = 6;

// note: under 1v is white, above is black
constexpr int LINE_FR = A3;
constexpr int LINE_FL = A6;
constexpr int LINE_BC = A7;

// NOTE: don't use these rn. these are faulty
constexpr int START_LED = A1;
constexpr int DRIVER_STANDBY = A4;
constexpr int START_MODULE = 2;

#endif