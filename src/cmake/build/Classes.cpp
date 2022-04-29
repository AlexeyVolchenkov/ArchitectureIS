#include "Classes.h"
#include "Struct.h"
#include "Enum.h"
void PC::callRobot()
{
	
}
void PC::callUser()
{

}
void PC::graffitiDetect()
{

}

void Robot::on()
{
	cout << "Robot start" << endl;
}
void Robot::off()
{
	cout << "Robot stop" << endl;
}
void Robot::moveOn()
{
	cout << "Robot start moving" << endl;
}
void Robot::moveOff()
{
	cout << "Robot stop moving" << endl;
}
void Robot::turnRight()
{

}
void Robot::turnLeft()
{

}

void Hand::up()
{

}
void Hand::down()
{

}
void Hand::right()
{

}
void Hand::left()
{

}

void Spray::on()
{
	cout << "start spray" << endl;
}
void Spray::off()
{
	cout << "stop spray" << endl;
}

void System::press_start()
{
    rob.on();
}
void System::move()
{
    rob.moveOn();
    rob.moveOff();
}
void System::waiting()
{
	
}
void System::setHand() 
{

}
void System::do_spray()
{
    sp.on();
    sp.off();
}
void System::rotating()
{
	
}
void System::press_stop()
{
    rob.off();
}

RobotStates::RobotStates()
{
    state = Estate::Off;
}
void RobotStates::detectProcess(CEvent e)
{
    if (charge > 0 && charge <= 100) {
        switch (state)
        {
        case Estate::Off:
            if (e.event == press_start1)
            {
                state = Estate::On;
                sys.press_start();
                cout << "ON - " << state << endl;
            }
            break;
        case Estate::On:
            if (e.event == waiting_command)
            {
                state = Estate::waiting;
                sys.waiting();
                cout << "Waiting - " << state << endl;
            }
            else if (e.event == on_error)
            {
                state = Estate::Error;
                cout << "Error - " << state << endl;
            }
            break;
        case Estate::waiting:
            if (e.event == press_stop1)
            {
                state = Estate::Off;
                sys.press_stop();
                cout << "OFF  - " << state << endl;
            }
            else if (e.event == receive_move)
            {
                state = Estate::move_forward;
                sys.move();
                cout << "Moving forward  - " << state << endl;
            }
            break;
        case Estate::move_forward:
            if (e.event == receive_turn)
            {
                state = Estate::turn_left;
                sys.rotating();
                cout << "Turn left  - " << state << endl;
            }
            else if (e.event == set_hand)
            {
                state = Estate::settingHand;
                sys.setHand();
                cout << "Move hand - " << state << endl;
            }
            else if (e.event == move_error)
            {
                state = Estate::Error;
                cout << "Error  - " << state << endl;
            }
            break;
        case Estate::turn_left:
            if (e.event == receive_clean)
            {
                state = Estate::cleaning;
                sys.do_spray();
                cout << "Cleaning  - " << state << endl;
            }
            else if (e.event == turn_error)
            {
                state = Estate::Error;
                cout << "Error  - " << state << endl;
            }
            break;
        case Estate::cleaning:
            if (e.event == clean_error)
            {
                state = Estate::Error;
                cout << "Error  - " << state << endl;
            }
            break;
        }
    }
    else if (charge <= 0) {
        state = Estate::Off;
        sys.press_stop();
    }
}