#pragma once
#include <iostream>
using namespace std;


enum Estate
{
    Off = 0,
    On = 1,
    Error = 2,
    waiting = 3,
    move_forward = 4,
    turn_left = 5,
    cleaning = 6,
    settingHand = 7,
};
enum Event
{
    none = 0,
    press_start1 = 1,
    press_stop1 = 2,
    waiting_command = 3,
    receive_move = 4,
    receive_turn = 5,
    receive_clean = 6,
    on_error = 7,
    move_error = 8,
    turn_error = 9,
    clean_error = 10,
    set_hand = 11,
};