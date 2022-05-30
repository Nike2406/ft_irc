#include "wrappers.hpp"

int ft_socket() {
	int ret = socket(PF_INET, SOCK_STREAM, 0);
	if (ret < 0)
		throw socketException();
	return ret;
}

void ft_bind(int &socket, struct sockaddr_in &settings) {
	if (bind(socket, reinterpret_cast<const struct sockaddr *>(&settings), sizeof(settings)) < 0)
		throw bindException();
}

void ft_listen(int &socket) {
	if (listen(socket, 5) < 0)
		throw listenException();
}

void ft_fcntl(int &socket) {
	if (fcntl(socket, F_SETFL, O_NONBLOCK) < 0)
		throw fcntlException();
}

void ft_poll(std::vector<pollfd> &pollfds) {
	if (poll(&(*pollfds.begin()), pollfds.size(), 10) < 0)
		throw pollException();
}

int ft_accept(int socket, struct sockaddr_in &connectionData, socklen_t &addressLen) {
	int ret = accept(socket, reinterpret_cast<struct sockaddr *>(&connectionData), &addressLen);
	if (ret < 0)
		throw acceptException();
	return ret;
}

std::string ft_recv(int fd) {
	char buffer[511];
	memset(buffer, 0, 511);
	if (recv(fd, buffer, 510, 0) > 0)
		return std::string(buffer);
	return "";
}

void ft_send(int fd, std::string string) {
	send(fd, string.c_str(), string.size(), 0);
}