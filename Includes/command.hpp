#pragma once

#include "client.hpp"
#include "server.hpp"
#include "wrappers.hpp"
#include <sstream>

class Server;

class Command {
public:
	Command() {;};
	virtual ~Command() {;};
	virtual void execute(Client &client, std::string &command) {;};
};

class Pass : public Command {
private:
	Server *server_;

public:
	Pass(Server *server) : Command(), server_(server) {;};
	~Pass() {;};
	void execute(Client &client, std::string &command);
};

class User : public Command {
private:
	Server *server_;

public:
	User(Server *server) : Command(), server_(server) {;};
	~User() {;};
	void execute(Client &client, std::string &command);
};

class Nick : public Command {
private:
	Server *server_;

public:
	Nick(Server *server) : Command(), server_(server) {;};
	~Nick() {;};
	void execute(Client &client, std::string &command);
};