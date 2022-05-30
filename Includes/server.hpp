#pragma once

#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <poll.h>
#include <unistd.h>
#include <vector>
#include <map>
#include "colors.hpp"
#include "exceptions.hpp"
#include "wrappers.hpp"
#include "client.hpp"
#include "command.hpp"
#include "replies.hpp"

class Command;
class Reply;

class Server {
private:
	const std::string					port_;
	const std::string					password_;
	std::vector<pollfd>					connections_;
	std::vector<Client>					clients_;
	std::map<std::string, Command *>	commands_;
	std::map<int, Reply *>				replies_;

	void setupSocket();
	void createConnection();
	void closeConnection(unsigned int position);
	void *selector(const std::string &command, int type) const;

public:
	Server(char *port, char *password);
	~Server();
	void loop();

	void execute(std::string command, Client &client, int type);
	std::string getIp() { return clients_[0].getIp(); };
	bool findNick(std::string nick) const;
	std::string getPassword() const { return password_; };
	bool findUsername(std::string username) const;
};