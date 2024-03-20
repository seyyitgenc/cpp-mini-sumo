#include "sumo.h"

void Sumo::setup(){
    // driver setup
    _driver.attachMotor(Motor::LEFT);
    _driver.attachMotor(Motor::RIGHT);
    
    // sumo pin setup
    pinMode(OPPONENT_FL, OUTPUT);   
    pinMode(OPPONENT_FC, OUTPUT);   
    pinMode(OPPONENT_FR, OUTPUT);

    pinMode(OPPONENT_LEFT, OUTPUT);   
    pinMode(OPPONENT_RIGHT, OUTPUT);

    pinMode(LINE_FR, INPUT); // NOTE: maybe these can be output   
    pinMode(LINE_FL, INPUT); // NOTE: maybe these can be output   
    pinMode(LINE_BC, INPUT); // NOTE: maybe these can be output   

    // TODO: add start module and it's LED
}

// FIXME: THIS MUST BE REPLACED
constexpr int tempThresHold = 100; 

// TODO: test this out.
// FIXME: you may need to specify direction here
void Sumo::loop(){
    if (analogRead(LINE_FL) < tempThresHold){
        backoff();
        _searchDir ^= 1;
    }
    else if(analogRead(LINE_FR) < tempThresHold){
        backoff();
        _searchDir ^= 1;
    }// TODO: add back sensor aswell
    else{ // edge not detected
        if 
        (digitalRead(OPPONENT_FC)   == HIGH &&
        digitalRead(OPPONENT_FL)    == HIGH &&
        digitalRead(OPPONENT_FR)    == HIGH &&
        digitalRead(OPPONENT_LEFT)  == HIGH &&
        digitalRead(OPPONENT_RIGHT) == HIGH){
            search();
        }
        else{
            attack();
        }
    }
    // FIXME: placeholder for start module.
    if (digitalRead(START_MODULE) == 0){
        _driver.stop(Motor::LEFT);
        _driver.stop(Motor::RIGHT);
        while (1);
    }
}

void Sumo::search(){
    if (_searchDir == LEFT){
        _driver.forward(Motor::LEFT, 60);
        _driver.forward(Motor::RIGHT, 80);
    }
    else{
        _driver.forward(Motor::LEFT, 80);
        _driver.forward(Motor::RIGHT, 60);
    }
}

// TODO: test this delay and you may play with it's speed values
void Sumo::attack(){
    if (digitalRead(OPPONENT_FC) == LOW){
        _driver.forward(Motor::LEFT, 255);
        _driver.forward(Motor::RIGHT, 255);
    }
    else if (digitalRead(OPPONENT_FL) == LOW){
        _driver.forward(Motor::LEFT, 0);
        _driver.forward(Motor::RIGHT, 255);
    }
    else if (digitalRead(OPPONENT_FL) == LOW){
        _driver.forward(Motor::LEFT, 255);
        _driver.forward(Motor::RIGHT, 0);
    }
    else if (digitalRead(OPPONENT_LEFT) == LOW){
        _driver.reverse(Motor::LEFT, 100);
        _driver.forward(Motor::RIGHT, 100);
        delay(300);
    }
    else if (digitalRead(OPPONENT_RIGHT) == LOW){
        _driver.forward(Motor::LEFT, 100);
        _driver.reverse(Motor::RIGHT, 100);
        delay(300);
    }
}

void Sumo::backoff(){
    _driver.reverse(Motor::LEFT, 50);
    _driver.reverse(Motor::RIGHT, 50);
    delay(300);

    if (_searchDir == LEFT){
        _driver.reverse(Motor::LEFT, 50);
        _driver.forward(Motor::RIGHT, 50);
    }
    else{
        _driver.forward(Motor::LEFT, 50);
        _driver.reverse(Motor::RIGHT, 50);
    }
    delay(600);
    _driver.stop(Motor::LEFT);
    _driver.stop(Motor::RIGHT);
    delay(50);
}