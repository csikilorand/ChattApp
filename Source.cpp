#include <iostream>
#include "TcpServer.h"

const int BufLen = 1024;
char RecvBuf[BufLen];
int main() {
	int result;
	std::cout << "Hello world" << std::endl;
	TCPServer* server = new TCPServer();
	if (!server->isConnection()) {
		printf("Error at the client\n");
		return -1;

	}
	else {
		printf("Yep, client connected....\n");
		result = recv(server->GetSocket(), RecvBuf, BufLen, 0);
		printf("%d" ,result);
		std::cout<<"Got info from client:..."  << RecvBuf << std::endl;
		std::cout << server->GetSocket() << std::endl;
		std::cout << result << std::endl;

		


	}
	return 0;
	
}