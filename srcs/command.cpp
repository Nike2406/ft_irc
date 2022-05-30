#include "command.hpp"


void Pass::execute(Client &client, std::string &command) {
	std::string password;
	if (command.size() > 5) {
		if (*(command.begin() + 5) == ':')
			password = command.substr(6);
		else
			password = command.substr(5);
	}
	if (password.empty())
		server_->execute(std::to_string(ERR_NEEDMOREPARAMS), client, 2); // friendly execute to Class
	if (client.getRegister())
		server_->execute(std::to_string(ERR_ALREADYREGISTRED), client, 2);
	else
		client.setPassword(password);
}

void User::execute(Client &client, std::string &command) {

	std::stringstream string;
	std::string garbage;
	std::string username;
	std::string hostname = client.getIp();
	std::string servername = "ircserv";
	std::string realname;
	string << command;
	string >> garbage >> username >> garbage >> garbage >> realname;
	if (username.empty())
		server_->execute(std::to_string(ERR_NEEDMOREPARAMS), client, 2);
	if (server_->findUsername(username))
		server_->execute(std::to_string(ERR_ALREADYREGISTRED), client, 2);
	client.setUsername(username);
	if (!realname.empty())
		client.setRealname(realname);
	if (!client.getRegister() && !client.getNick().empty() && client.getPassword() == server_->getPassword()) {
		client.setRegister(true);
		ft_send(client.getFd(), ":" + server_->getIp() + " " + std::to_string(422) + " " + client.getNick() + " : no MOTD\r\n");
//		ft_send(client.getFd(), ":" + server_->getIp() + " " + std::to_string(376) + " " + client.getNick() + " :- MOTD end\r\n");
	}
}

void Nick::execute(Client &client, std::string &command) {
	std::string nick = command.substr(5);
	if (nick.empty())
		ft_send(client.getFd(), ":No nickname given\r\n");
	if (!server_->findNick(nick))
		client.setNick(nick);
	else {
		ft_send(client.getFd(), nick + ": Nickname collision KILL\r\n");
	}
	if (!client.getRegister() && !client.getUsername().empty() && client.getPassword() == server_->getPassword()) {
		client.setRegister(true);
		ft_send(client.getFd(), ":" + server_->getIp() + " " + std::to_string(422) + " " + client.getNick() + " : no MOTD\r\n");
//		ft_send(client.getFd(), ":" + server_->getIp() + " " + std::to_string(376) + " " + client.getNick() + " :- MOTD end\r\n");
	}
}
