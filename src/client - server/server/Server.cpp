#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <stdio.h>
#include "Classes.h"
#include "Struct.h"
#include "Enum.h"
#include "Server.h"

#pragma comment(lib, "Ws2_32.lib")
using namespace std;

int server(bool* pflag, SOCKET* ClientConn,SOCKET* ServSock)
{
	if (*pflag)
	{
		*pflag = false;
		const short BUFF_SIZE = 1024;
		WSADATA wsData;

		int erStat = WSAStartup(MAKEWORD(2, 2), &wsData);

		/*if (erStat != 0) {
			cout << "Error WinSock version initializaion #";
			cout << WSAGetLastError();
		}
		else
			cout << "WinSock initialization is OK" << endl;*/

		*ServSock = socket(AF_INET, SOCK_STREAM, 0);

		/*if (ServSock == INVALID_SOCKET) {
			cout << "Error initialization socket # " << WSAGetLastError() << endl;
			closesocket(ServSock);
			WSACleanup();
		}
		else
			cout << "Server socket initialization is OK" << endl;*/

		in_addr ip_to_num;
		erStat = inet_pton(AF_INET, "127.0.0.1", &ip_to_num);
		/*if (erStat <= 0) {
			cout << "Error in IP translation to special numeric format" << endl;
		}*/

		sockaddr_in servInfo;
		ZeroMemory(&servInfo, sizeof(servInfo));

		servInfo.sin_family = AF_INET;
		servInfo.sin_addr = ip_to_num;
		servInfo.sin_port = htons(1234);

		erStat = bind(*ServSock, (sockaddr*)&servInfo, sizeof(servInfo));
		/*if (erStat != 0) {
			cout << "Error Socket binding to server info. Error # " << WSAGetLastError() << endl;
			closesocket(ServSock);
			WSACleanup();
		}
		else
			cout << "Binding socket to Server info is OK" << endl;*/

		erStat = listen(*ServSock, SOMAXCONN);

		if (erStat != 0) {
			cout << "Can't start to listen to. Error # " << WSAGetLastError() << endl;
			closesocket(*ServSock);
			WSACleanup();
		}
		else {
			cout << "Listening..." << endl;
		}

		sockaddr_in clientInfo;

		ZeroMemory(&clientInfo, sizeof(clientInfo));

		int clientInfo_size = sizeof(clientInfo);

		*ClientConn = accept(*ServSock, (sockaddr*)&clientInfo, &clientInfo_size);

		/*if (ClientConn == INVALID_SOCKET) {
			cout << "Client detected, but can't connect to a client. Error # " << WSAGetLastError() << endl;
			closesocket(ServSock);
			closesocket(ClientConn);
			WSACleanup();
		}
		else
			cout << "Connection to a client established successfully" << endl;

		vector <char> servBuff(BUFF_SIZE), clientBuff(BUFF_SIZE);
		short packet_size = 0;

		while (true) {
			packet_size = recv(ClientConn, servBuff.data(), servBuff.size(), 0);
			cout << "Client's message: " << servBuff.data() << endl;
		}*/
	}
	int state = 0;
	short packet_size = 0;
	while (true)
	{
		packet_size = recv(*ClientConn, (char*)&state, sizeof(state), 0);
		cout << "Client's message: " << state << endl;
		return state;
	}
	closesocket(*ServSock);
	closesocket(*ClientConn);
	WSACleanup();
}