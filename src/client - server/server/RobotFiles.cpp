#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <stdio.h>
#include "Classes.h"
#include "Struct.h"
#include "Enum.h"
#include "Server.h"
using namespace std;


class Get
{
private:
public:
    virtual CEvent get_event() = 0;
};

class ConsoleGet : public Get
{
private:
public:
    CEvent get_event()
    {
        int input;
        cout << endl << "-------------------" << endl << "Введите номер комманды, которую хотите выполнить: ";
        cin >> input;
        return CEvent(input);
    }
};

class UTPGet : public Get
{
private:
    bool flag = true;
    bool* pflag = &flag;
    const short BUFF_SIZE = 1024;
    WSADATA wsData;

    SOCKET ClientConn, ServSock;
    SOCKET* pConn = &ClientConn;
    SOCKET* pSock = &ServSock;
    int erStat = WSAStartup(MAKEWORD(2, 2), &wsData);
    in_addr ip_to_num;
public:
    UTPGet()
    {
        ServSock = socket(AF_INET, SOCK_STREAM, 0);
        erStat = inet_pton(AF_INET, "127.0.0.1", &ip_to_num);
    }
    CEvent get_event()
    {
        cout << "------------------------" << endl;
        return server(pflag, pConn, pSock);
    }
};

int main()
{
	setlocale(LC_ALL, "ru");
    RobotStates Oleg;
    Get* state = new UTPGet();
    while (1)
    {
        Oleg.detectProcess(state->get_event());
    }
    return 0;
}