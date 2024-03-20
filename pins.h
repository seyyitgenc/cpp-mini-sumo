#ifndef _PINS_H_
#define _PINS_H_

#include <Arduino.h>

constexpr int PWMA = 3;
constexpr int AIN1 = 4;
constexpr int AIN2 = 5;

constexpr int PWMB = 6;
constexpr int BIN1 = 7;
constexpr int BIN2 = 8;

constexpr int OPPONENT_FL = 9;
constexpr int OPPONENT_FC = 10;
constexpr int OPPONENT_FR = 11;
constexpr int OPPONENT_RIGHT = 12;
constexpr int OPPONENT_LEFT = 13;

// note: under 1v is white, above is black
constexpr int LINE_FR = A1;
constexpr int LINE_FL = A2;
constexpr int LINE_BC = A3;

// NOTE: don't use these rn. these are faulty
constexpr int START_LED = 1;
constexpr int START_MODULE = 1;

#endif // _PINS_H_