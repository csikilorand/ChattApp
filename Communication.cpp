#include "Communication.h"

Communication::Communication() {

}
std::string Communication::getMessage(SOCKET& AcceptSocket) {
	recv(AcceptSocket, buffer, sizeof(buffer), 0);
	//printf("Received from client: ", buffer);
	return buffer;
}
void Communication::sendMessage(SOCKET& AcceptSocket, std::string message) {
	strcpy_s(buffer, message.c_str());
	send(AcceptSocket, buffer, sizeof(buffer), 0);
}
void Communication::sendMessage(SOCKET& AcceptSocket, char* Pmessage) {

}




Communication:: ~Communication() {

}