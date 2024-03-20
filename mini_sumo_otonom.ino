#include "sumo.h"

Sumo sumo;

void setup(){
    // Serial.begin(9600);
    sumo.setup();
}

void loop(){
    sumo.loop();
}