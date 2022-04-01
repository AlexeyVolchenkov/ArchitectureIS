#include<iostream>
using namespace std;


class Camera {
public:
};

class PC {
public:
    void callUser() {}
    void callRobot() {}
    void graffitiDetect() {}
};

class Robot {
private:
    int charging;
public:
    void on() {}
    void off() {}
    void moveOn() {}
    void moveOff() {}
    void turnRight() {}
    void turnLeft() {}

};

class Hand {
public:
    void up() {}
    void down() {}
    void left() {}
    void right() {}
};

class Spray {
public:
    void on() {}
    void off() {}
};

class System {
private:
    Camera ca;
    PC pc;
    Robot robot;
    Hand ha;
    Spray sp;

public:
    void press_start() {
        robot.on();
    }

    void set_hand() {}

    void do_spray() {}

    void press_stop() {
        robot.off();
    }
};

int main() {
    System rob1;
    rob1.press_start();
    rob1.press_stop();
    cout << "Hello, leather bag!" << endl;
    return 0;
}