#pragma once
#include <stdio.h>
#include "winsock2.h"
#include "Ws2tcpip.h"
#pragma warning(disable: 4996)
#define WINSOCK_DEPRECATED_NO_WARINGS
#pragma comment(lib,"Ws2_32.lib")



class TCPServer
{
private:
	WSADATA wsaData;
	SOCKET ListenSocket, AcceptSocket;
	sockaddr_in service;

public:
	TCPServer();
	bool isConnection();
	SOCKET GetSocket();
	void ErrorHandling();
	~TCPServer();

};

