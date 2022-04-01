#include<iostream>
using namespace std;

class Engine {
public:
    void on() {}
    void off() {}
};

class Camera {
public:
    void get_cleaner(int* cl_x, int* cl_y) {}
    void get_dirt(int* d_x, int* d_y, bool* up_or_dw) {}
};

class Place {
public:
    void move(int cl_x, int cl_y, int d_x, int d_y) {}
};

class Hand {
public:
    void up() {}
    void down() {}
};

class Spray {
public:
    void on() {}
    void off() {}
};

class System {
private:
    int cl_x, cl_y;
    int d_x, d_y;
    bool up_or_dw;
    Engine en;
    Camera cm;
    Place pl;
    Hand hd;
    Spray sp;

public:
    void start_robot() {
        en.on();
    }

    void set_coord() {
        cm.get_cleaner(&cl_x, &cl_y);
        cm.get_dirt(&d_x, &d_y, &up_or_dw);
        pl.move(cl_x, cl_y, d_x, d_y);
    }

    void set_hand() {
        if (up_or_dw)
            hd.up();
        else
            hd.down();
    }

    void do_spray() {
        sp.on();
        sp.off();
    }

    void stop_robot() {
        en.off();
    }
};

int main() {
    System test;
    test.start_robot();
    test.set_coord();
    test.set_hand();
    test.do_spray();
    test.stop_robot();
    cout << "Hello, leather bag" << endl;
    return 0;
}