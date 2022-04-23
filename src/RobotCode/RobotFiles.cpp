#include <iostream>
#include "Classes.h"
#include "Struct.h"
#include "Enum.h"
using namespace std;

CEvent get_event()
{
    int input;
    cout << endl << "-------------------" << endl << "Введите номер комманды, которую хотите выполнить: ";
    cin >> input;
    return CEvent(input);

}
int main()
{
    setlocale(LC_ALL, "ru");

    RobotStates Oleg;
    while (1)
    {
        CEvent t = get_event();
        Oleg.detectProcess(t);
    }
    return 0;
}