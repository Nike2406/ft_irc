#include "server.hpp"

Server::Server(char *port, char *password) : port_(std::string(port)), password_(std::string(password)) {
	if (std::stoi(port_) < 0 || std::stoi(port_) > 65535 || std::to_string(std::stoi(port_)) != port_)
		throw portException();

	setupSocket();

	commands_["PASS"] = new Pass(this);
	commands_["USER"] = new User(this);
	commands_["NICK"] = new Nick(this);

	replies_[ERR_NEEDMOREPARAMS] = new Err_NeedMoreParams(this);
}

void Server::setupSocket() {
	struct sockaddr_in socketSettings = {0, AF_INET, htons(std::stoi(port_)), {INADDR_ANY}};
	int connectionSocket = ft_socket();

	ft_fcntl(connectionSocket);
	ft_bind(connectionSocket, socketSettings);
	ft_listen(connectionSocket);
	Client server(connectionSocket, socketSettings);
	clients_.push_back(server);
	pollfd serverPollfd = {connectionSocket, POLLIN, 0};
	connections_.push_back(serverPollfd);
}

Server::~Server() {
	// TODO check leaks
	for (unsigned int i = 0; i < connections_.size(); i++)
		close(connections_[i].fd);
}

void Server::createConnection() {
	pollfd newConnection = {0, POLLIN, 0};
	struct sockaddr_in connectionData = {0};
	socklen_t addressLen = sizeof(connectionData);

	newConnection.fd = ft_accept(clients_[0].getFd(), connectionData, addressLen);
	ft_fcntl(newConnection.fd);
	Client newClient(newConnection.fd, connectionData);
	connections_.push_back(newConnection);
	clients_.push_back(newClient);
	std::cout << GREEN << "Accepted connection from " << newClient.getIp() << "!" << DEFAULT << std::endl;
}

void Server::closeConnection(unsigned int position) {
	close(connections_[position].fd);
	connections_.erase(connections_.begin() + position);
	std::cout << YELLOW << "Connection with " << clients_[position].getIp() << " closed!" << DEFAULT << std::endl;
	clients_.erase(clients_.begin() + position); // positin -> Client
}

void *Server::selector(const std::string &command, int type) const {
	void *function;
	if (type == 1) {
		std::map<std::string, Command *>::const_iterator it = commands_.begin();
		for (; it != commands_.end(); it++) {
			if (command.find(it->first) == 0)
				return it->second;
		}
	}
	else if (type == 2) {
		std::map<int, Reply *>::const_iterator it = replies_.begin();
		for (; it != replies_.end(); it++) {
			if (std::stoi(command) == it->first)
				return it->second;
		}
	}
	return NULL;
}

void Server::execute(std::string command, Client &client, int type) {
	if (type == 1) {
		Command *func = (Command *)selector(command, 1);
		if (func != NULL)
			func->execute(client, command);
	}
	else if (type == 2) {
		Reply *func = (Reply *) selector(command, 2);
		if (func != NULL)
			func->execute(client, command);
	}
}

bool Server::findNick(std::string nick) const {
	for (unsigned int i = 0; i < clients_.size(); i++) {
		if (clients_[i].getNick() == nick)
			return true;
	}
	return false;
}

bool Server::findUsername(std::string username) const {
	for (unsigned int i = 0; i < clients_.size(); i++) {
		if (clients_[i].getUsername() == username)
			return true;
	}
	return false;
}

void Server::loop() {
	while (1) {
		ft_poll(connections_);
		for (unsigned int i = 0; i < connections_.size(); i++){
			if ((connections_[i].revents & POLLIN) == POLLIN) {
				if (i == 0) {
					createConnection();
					connections_[0].revents = 0;
				}
				else {
					clients_[i].receive();
					clients_[i].parse();
					std::string temp;
					while ((temp = clients_[i].getCommand()).size() > 0)
						execute(temp, clients_[i], 1);
					if ((connections_[i].revents & POLLHUP) == POLLHUP) {
						closeConnection(i);
					}
				}
			}
		}
	}
}