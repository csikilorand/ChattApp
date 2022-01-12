#pragma once
#include <stdio.h>
#include "winsock2.h"
#include "Ws2tcpip.h"
#pragma comment(lib,"Ws2_32.lib")
#include <string>
class Communication
{
public:
	static const int BufLen = 20;
	char buffer[BufLen];
	Communication();
	void sendMessage(SOCKET& AcceptSocket, std::string message);
	void sendMessage(SOCKET& AcceptSocket, char* Pmeesage);
	~Communication();
	std::string getMessage(SOCKET& AcceptSocket);


};

