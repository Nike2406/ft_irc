#pragma once

#include <netinet/in.h>
#include <sys/socket.h>
#include <iostream>
#include <arpa/inet.h>
#include <sstream>
#include "wrappers.hpp"

class Client {
private:
	int fd_;
	struct sockaddr_in socketData_;
	std::string buffer_;
	std::vector<std::string> commands_;
	std::string password_;
	std::string nick_;
	std::string username_;
	std::string realname_;
	bool registered_;

public:
	std::string currentCommand_;

	Client(int &fd, struct sockaddr_in &socketData);
	~Client() {;};
	int getFd() const { return fd_; };
	void receive();
	void parse();
	std::string getCommand();

//	setters
	void setPassword(std::string password) { password_ = password; };
	void setNick(std::string nick) { nick_ = nick; };
	void setRegister(bool registered) { registered_ = registered; };
	void setUsername(std::string username) { username_ = username; };
	void setRealname(std::string realname) { realname_ = realname; };

//	getters
	std::string getIp() { return inet_ntoa(socketData_.sin_addr); };
	bool getRegister() const { return registered_; };
	std::string getUsername() const { return username_; };
	std::string getNick() const { return nick_; };
	std::string getPassword() const { return password_; };
};