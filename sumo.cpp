#include "sumo.h"

void Sumo::setup(){
    // driver setup
    _driver.attachMotor(Motor::LEFT);
    _driver.attachMotor(Motor::RIGHT);
    
    // sumo pin setup
    pinMode(OPPONENT_FL, INPUT);
    pinMode(OPPONENT_FC, INPUT);
    pinMode(OPPONENT_FR, INPUT);

    pinMode(OPPONENT_LEFT, INPUT);
    pinMode(OPPONENT_RIGHT, INPUT);

    pinMode(LINE_FR, INPUT);
    pinMode(LINE_FL, INPUT);
    pinMode(LINE_BC, INPUT);

    pinMode(START_MODULE, INPUT);
    pinMode(START_LED, OUTPUT);
    pinMode(DRIVER_STANDBY, OUTPUT);
}

// TODO: test this out.
void Sumo::loop(){
    digitalWrite(DRIVER_STANDBY, !digitalRead(START_MODULE));
    digitalWrite(START_LED, !digitalRead(START_MODULE));
    if (analogRead(LINE_FR) < THRESHOLD){
        _searchDir = LEFT;
        backoff();
    }
    else if (analogRead(LINE_FL) < THRESHOLD){
        _searchDir = RIGHT;
        backoff();
    }
    else if(analogRead(LINE_BC) < THRESHOLD){
        _searchDir = FORWARD;
        backoff();
    }
    else{ // edge not detected
        if 
        (digitalRead(OPPONENT_FC)   == LOW &&
        digitalRead(OPPONENT_FL)    == LOW &&
        digitalRead(OPPONENT_FR)    == LOW &&
        digitalRead(OPPONENT_LEFT)  == LOW &&
        digitalRead(OPPONENT_RIGHT) == LOW){
            search();
        }
        else{
            attack();
        }
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

void Sumo::attack(){
    if (digitalRead(OPPONENT_FC) == HIGH){
        _driver.forward(Motor::LEFT, 250);
        _driver.forward(Motor::RIGHT, 250);
    }
    else if(digitalRead(OPPONENT_FC) == HIGH && digitalRead(OPPONENT_FL)){
        _driver.reverse(Motor::LEFT, 100);
        _driver.forward(Motor::RIGHT, 100);
    }
    else if(digitalRead(OPPONENT_FC) == HIGH && digitalRead(OPPONENT_FR)){
        _driver.forward(Motor::LEFT, 0);
        _driver.reverse(Motor::RIGHT, 100);
    }
    else if (digitalRead(OPPONENT_FL) == HIGH){
        _driver.forward(Motor::LEFT, 250);
        _driver.reverse(Motor::RIGHT, 250);
    }
    else if (digitalRead(OPPONENT_FR) == HIGH){
        _driver.reverse(Motor::LEFT, 250);
        _driver.forward(Motor::RIGHT, 250);
    }
    else if (digitalRead(OPPONENT_LEFT) == HIGH){
        _driver.reverse(Motor::LEFT, 250);
        _driver.forward(Motor::RIGHT, 250);
        delay(10);
    }
    else if (digitalRead(OPPONENT_RIGHT) == HIGH){
        _driver.forward(Motor::LEFT, 250);
        _driver.reverse(Motor::RIGHT, 250);
    }
}

void Sumo::backoff(){
    if (_searchDir == LEFT){
        _driver.reverse(Motor::LEFT, 150);
        _driver.reverse(Motor::RIGHT, 150);
        delay (200);
        _driver.forward(Motor::LEFT, 150);
        _driver.reverse(Motor::RIGHT, 150);
        delay(30);
    }
    else if(_searchDir == RIGHT){
        _driver.reverse(Motor::LEFT, 150);
        _driver.reverse(Motor::RIGHT, 150);
        delay(200);
        _driver.reverse(Motor::LEFT, 150);
        _driver.forward(Motor::RIGHT, 150);
        delay(30);
    }
    if(_searchDir == FORWARD){
        _driver.forward(Motor::LEFT, 150);
        _driver.forward(Motor::RIGHT, 150);
        delay(200);
        _driver.reverse(Motor::LEFT, 150);
        _driver.forward(Motor::RIGHT, 150);
        delay(30);
    }
    _driver.stop(Motor::LEFT);
    _driver.stop(Motor::RIGHT);
    delay(50);
}