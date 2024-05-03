#pragma once
#include "motor_driver.h"

constexpr int LEFT = 0;
constexpr int RIGHT = 1;
constexpr int FORWARD = 2;
constexpr int BACKWARD = 3;
constexpr int THRESHOLD = 300;

class Sumo
{
public:
    Sumo() = default;
    ~Sumo() = default;
    void setup();
    void loop();
    void search();
    void attack();
    void backoff();
private:
    MotorDriver _driver;
    int _searchDir = LEFT; 
};