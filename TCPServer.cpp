#include "TCPServer.h"
#include "TCPServer.h"
// server init
TCPServer::TCPServer()
{
	//Winsock inicializalasa
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != NO_ERROR) {
		printf("Error at WSAStartup()\n");
		ErrorHandling();
	}

	//SOCKET letrehozasa, hogy lehessen csatlakozni a szerverhez
	ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ListenSocket == INVALID_SOCKET) {
		printf("Error at socket(): %ld\n", WSAGetLastError());
		ErrorHandling();
	}
	//SOCKET beallitasa
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = INADDR_ANY;//tudni fogadni barkitol
	service.sin_port = htons(27015);


	// TCP fogado(listening) SOCKET  beallitasa
	if (bind(ListenSocket, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR) {//
		printf("bind() failed. Error code :%d \n", WSAGetLastError());
		ErrorHandling();
	}

	if (listen(ListenSocket, 1) == SOCKET_ERROR) {
		printf("Error listening on socket.\n");
		ErrorHandling();
	}


	printf("Server Is Running\n");
}

SOCKET TCPServer::GetSocket() {
	return AcceptSocket;
}

bool TCPServer::isConnection() {
	printf("Waiting for  a client...\n");
	AcceptSocket = accept(ListenSocket, NULL, NULL);
	if (AcceptSocket == SOCKET_ERROR) {
		printf("Accept failed: %d\n", WSAGetLastError());
		ErrorHandling();
		return false;
	}
	printf("Client connected\n");
	return true;
}

void TCPServer::ErrorHandling() {
	closesocket(ListenSocket);
	closesocket(AcceptSocket);
	printf("Error at socket level\n");
	WSACleanup();
	exit(-1);
}
TCPServer:: ~TCPServer() {

}

