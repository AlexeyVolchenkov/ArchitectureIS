#pragma once
#include <iostream>
#include "Enum.h"
#include "Struct.h"
using namespace std;

class Camera {
public:
};

class PC {
public:
    void callUser();
    void callRobot();
    void graffitiDetect();
};

class Robot {
private:
    int charging;
public:
    void on();
    void off();
    void moveOn();
    void moveOff();
    void turnRight();
    void turnLeft();
};

class Hand {
public:
    void up();
    void down();
    void left();
    void right();
};

class Spray {
public:
    void on();
    void off();
};

class System {
private:
    Camera cam;
    PC pc;
    Hand hand;
    Robot rob;
    Spray sp;
public:
    void press_start();
    void move();
    void waiting();
    void setHand();
    void do_spray();
    void rotating();
    void press_stop();
};

class RobotStates
{
private:
    int charge = 50;
    Estate state;
    System sys;

public:
    RobotStates();
    void detectProcess(CEvent e);
};