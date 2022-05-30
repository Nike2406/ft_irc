#include "replies.hpp"


void Err_NeedMoreParams::execute(Client &client, std::string &command) {
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_NEEDMOREPARAMS) + " " + client.getIp() + " " + client.currentCommand_ + " :Not enough parameters\r\n");
}

void Err_AlreadyRegistred::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_ALREADYREGISTRED) + " " + client.getNick() + " :You may not reregister\r\n");
}

void Err_NoSuchNick::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_NOSUCHNICK) + " " + client.getNick() + " " + client.getNick() + " :No such nick/channel\r\n");
}

void Err_NoSuchChannel::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_NOSUCHCHANNEL) + " " + client.getNick() + " " + "TODO chnnal name" + " :No such channel\r\n");
}

void Err_CannotSendToChan::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_CANNOTSENDTOCHAN) + " " + client.getNick() + " " + "TODO chnnal name" + " :Cannot send to channel\r\n");
}

void Err_TooManyChannels::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_TOOMANYCHANNELS) + " " + client.getNick() + " " + "TODO chnnal name" + " :You have joined too many channels\r\n");
}

void Err_WasNoSuchNick::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_WASNOSUCHNICK) + " " + client.getNick() + " " + client.getNick() + " :There was no such nickname\r\n");
}

void Err_TooManyTargets::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_TOOMANYTARGETS) + " " + client.getNick() + " " + "TODO target" + " :Duplicate recipients. No message delivered\r\n");
}

void Err_NoOrigin::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_NOORIGIN) + " " + client.getNick() + " " + " :No origin specified\r\n");
}

void Err_NoRecipient::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_NORECIPIENT) + " " + client.getNick() + " " + " :No recipient given" + client.getCommand() + "\r\n");
}

void Err_NoTextToSend::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_NOTEXTTOSEND) + " " + client.getNick() + " " + " :No text to send\r\n");
}

void Err_UnknownCommand::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_UNKNOWNCOMMAND) + " " + client.getNick() + " " + client.getCommand() + " :Unknown command\r\n");
}

void Err_NoMOTD::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_NOMOTD) + " " + client.getNick() + " :MOTD File is missing\r\n");
}

void Err_NoAdminInfo::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_NOADMININFO) + " " + client.getNick() + " TODO Server_Name" + " :No administrative info available\r\n");
}

void Err_FileError::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_FILEERROR) + " " + client.getNick() + " :File error doing" + "TODO <file op> on <file>\r\n");
}

void Err_NoNickNameGiven::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_NONICKNAMEGIVEN) + " " + client.getNick() + " :No nickname given\r\n");
}

void Err_ErrOneUsNickname::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_ERRONEUSNICKNAME) + " " + client.getNick()+ " " + client.getNick() + " :Erroneus nickname\r\n");
}

void Err_NicknameInUse::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_NICKNAMEINUSE) + " " + client.getNick()+ " " + client.getNick() + " :Nickname is already in use\r\n");
}

void Err_NickCollision::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_NICKCOLLISION) + " " + client.getNick()+ " " + client.getNick() + " :Nickname collision KILL\r\n");
}

void Err_UserNotInChannel::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_USERNOTINCHANNEL) + " " + client.getNick() + " " + client.getNick() + " " + "TODO get Channel" + " :They aren't on that channel\r\n");
}

void Err_NotOnChannel::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_NOTONCHANNEL) + " " + client.getNick() + " " + "TODO get Channel" + " :You're not on that channel\r\n");
}

void Err_UserOnChannel::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_USERONCHANNEL) + " " + client.getNick() + " " + client.getNick() + " " + "TODO get Channel" + " :is already on channel\r\n");
}

void Err_NoLogin::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_NOLOGIN) + " " + client.getNick() + " " + client.getNick() + " :User not logged in\r\n");
}

void Err_SummonDisabled::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_SUMMONDISABLED) + " " + client.getNick() + " :SUMMON has been disabled\r\n");
}

void Err_UsersDisabled::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_USERSDISABLED) + " " + client.getNick() + " :USERS has been disabled\r\n");
}

void Err_NotRegistered::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_NOTREGISTERED) + " " + client.getNick() + " :You have not registered\r\n");
}

void Err_NoPermForHost::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_NOPERMFORHOST) + " " + client.getNick() + " :Your host isn't among the privileged\r\n");
}

void Err_PasswdMismatch::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_PASSWDMISMATCH) + " " + client.getNick() + " :Password incorrect\r\n");
}

void Err_YoureBannedCreep::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_YOUREBANNEDCREEP) + " " + client.getNick() + " :You are banned from this server\r\n");
}

// after goes joins chennal with modificators
void Err_Keyset::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_KEYSET) + " " + client.getNick() + " " + "TODO Channel " + " :Channel key already set\r\n");
}

void Err_NoPrivileges::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_NOPRIVILEGES) + " " + client.getNick() + " :Permission Denied- You're not an IRC operator\r\n");
}

void Err_ChanoprivsNeeded::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_CHANOPRIVSNEEDED) + " " + client.getNick() + " " + "TODO Channel " + " :You're not channel operator\r\n");
}

void Err_CantKillServer::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_CANTKILLSERVER) + " " + client.getNick() + " " + " :You cant kill a server!\r\n");
}

void Err_NoOperHost::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_NOOPERHOST) + " " + client.getNick() + " " + " :No O-lines for your host\r\n");
}

void Err_UmodeUnknownFlag::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_UMODEUNKNOWNFLAG) + " " + client.getNick() + " " + " :Unknown MODE flag\r\n");
}

void Err_UsersDontMatch::execute(Client &client, std::string &command){
	ft_send(client.getFd(), "ircserv " + std::to_string(ERR_USERSDONTMATCH) + " " + client.getNick() + " " + " :Cant change mode for other users\r\n");
}