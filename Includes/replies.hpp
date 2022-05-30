#pragma once

#include "client.hpp"
#include "server.hpp"
#include "wrappers.hpp"
#include "repliesDefines.hpp"

class Server;

class Reply {
public:
	Reply() {;};
	virtual ~Reply() {;};
	virtual void execute(Client &client, std::string &command) {;};
};

class Err_NeedMoreParams : public Reply {
private:
	Server *server_;

public:
	Err_NeedMoreParams(Server *server) : Reply(), server_(server) {;};
	~Err_NeedMoreParams() {;};
	void execute(Client &client, std::string &command);
};

class Err_AlreadyRegistred : public Reply {
private:
	Server *server_;

public:
	Err_AlreadyRegistred(Server *server) : Reply(), server_(server) {;};
	~Err_AlreadyRegistred() {;};
	void execute(Client &client, std::string &command);
};

class Err_NoSuchNick : public Reply {
private:
	Server *server_;

public:
	Err_NoSuchNick(Server *server) : Reply(), server_(server) {;};
	~Err_NoSuchNick() {;};
	void execute(Client &client, std::string &command);
};

class Err_NoSuchChannel : public Reply {
private:
	Server *server_;

public:
	Err_NoSuchChannel(Server *server) : Reply(), server_(server) {;};
	~Err_NoSuchChannel() {;};
	void execute(Client &client, std::string &command);
};

class Err_CannotSendToChan : public Reply {
private:
	Server *server_;

public:
	Err_CannotSendToChan(Server *server) : Reply(), server_(server) {;};
	~Err_CannotSendToChan() {;};
	void execute(Client &client, std::string &command);
};

class Err_TooManyChannels : public Reply {
private:
	Server *server_;

public:
	Err_TooManyChannels(Server *server) : Reply(), server_(server) {;};
	~Err_TooManyChannels() {;};
	void execute(Client &client, std::string &command);
};

class Err_WasNoSuchNick : public Reply {
private:
	Server *server_;

public:
	Err_WasNoSuchNick(Server *server) : Reply(), server_(server) {;};
	~Err_WasNoSuchNick() {;};
	void execute(Client &client, std::string &command);
};

class Err_TooManyTargets : public Reply {
private:
	Server *server_;

public:
	Err_TooManyTargets(Server *server) : Reply(), server_(server) {;};
	~Err_TooManyTargets() {;};
	void execute(Client &client, std::string &command);
};

class Err_NoOrigin : public Reply {
private:
	Server *server_;

public:
	Err_NoOrigin(Server *server) : Reply(), server_(server) {;};
	~Err_NoOrigin() {;};
	void execute(Client &client, std::string &command);
};

class Err_NoRecipient : public Reply {
private:
	Server *server_;

public:
	Err_NoRecipient(Server *server) : Reply(), server_(server) {;};
	~Err_NoRecipient() {;};
	void execute(Client &client, std::string &command);
};

class Err_NoTextToSend : public Reply {
private:
	Server *server_;

public:
	Err_NoTextToSend(Server *server) : Reply(), server_(server) {;};
	~Err_NoTextToSend() {;};
	void execute(Client &client, std::string &command);
};

class Err_UnknownCommand : public Reply {
private:
	Server *server_;

public:
	Err_UnknownCommand(Server *server) : Reply(), server_(server) {;};
	~Err_UnknownCommand() {;};
	void execute(Client &client, std::string &command);
};

class Err_NoMOTD : public Reply {
private:
	Server *server_;

public:
	Err_NoMOTD(Server *server) : Reply(), server_(server) {;};
	~Err_NoMOTD() {;};
	void execute(Client &client, std::string &command);
};

class Err_NoAdminInfo : public Reply {
private:
	Server *server_;

public:
	Err_NoAdminInfo(Server *server) : Reply(), server_(server) {;};
	~Err_NoAdminInfo() {;};
	void execute(Client &client, std::string &command);
};

class Err_FileError : public Reply {
private:
	Server *server_;

public:
	Err_FileError(Server *server) : Reply(), server_(server) {;};
	~Err_FileError() {;};
	void execute(Client &client, std::string &command);
};

class Err_NoNickNameGiven : public Reply {
private:
	Server *server_;

public:
	Err_NoNickNameGiven(Server *server) : Reply(), server_(server) {;};
	~Err_NoNickNameGiven() {;};
	void execute(Client &client, std::string &command);
};

class Err_ErrOneUsNickname : public Reply {
private:
	Server *server_;

public:
	Err_ErrOneUsNickname(Server *server) : Reply(), server_(server) {;};
	~Err_ErrOneUsNickname() {;};
	void execute(Client &client, std::string &command);
};

class Err_NicknameInUse : public Reply {
private:
	Server *server_;

public:
	Err_NicknameInUse(Server *server) : Reply(), server_(server) {;};
	~Err_NicknameInUse() {;};
	void execute(Client &client, std::string &command);
};

class Err_NickCollision : public Reply {
private:
	Server *server_;

public:
	Err_NickCollision(Server *server) : Reply(), server_(server) {;};
	~Err_NickCollision() {;};
	void execute(Client &client, std::string &command);
};

class Err_UserNotInChannel : public Reply {
private:
	Server *server_;

public:
	Err_UserNotInChannel(Server *server) : Reply(), server_(server) {;};
	~Err_UserNotInChannel() {;};
	void execute(Client &client, std::string &command);
};

class Err_NotOnChannel : public Reply {
private:
	Server *server_;

public:
	Err_NotOnChannel(Server *server) : Reply(), server_(server) {;};
	~Err_NotOnChannel() {;};
	void execute(Client &client, std::string &command);
};

class Err_UserOnChannel : public Reply {
private:
	Server *server_;

public:
	Err_UserOnChannel(Server *server) : Reply(), server_(server) {;};
	~Err_UserOnChannel() {;};
	void execute(Client &client, std::string &command);
};

class Err_NoLogin : public Reply {
private:
	Server *server_;

public:
	Err_NoLogin(Server *server) : Reply(), server_(server) {;};
	~Err_NoLogin() {;};
	void execute(Client &client, std::string &command);
};

class Err_SummonDisabled : public Reply {
private:
	Server *server_;

public:
	Err_SummonDisabled(Server *server) : Reply(), server_(server) {;};
	~Err_SummonDisabled() {;};
	void execute(Client &client, std::string &command);
};

class Err_UsersDisabled : public Reply {
private:
	Server *server_;

public:
	Err_UsersDisabled(Server *server) : Reply(), server_(server) {;};
	~Err_UsersDisabled() {;};
	void execute(Client &client, std::string &command);
};

class Err_NotRegistered : public Reply {
private:
	Server *server_;

public:
	Err_NotRegistered(Server *server) : Reply(), server_(server) {;};
	~Err_NotRegistered() {;};
	void execute(Client &client, std::string &command);
};

class Err_NoPermForHost : public Reply {
private:
	Server *server_;

public:
	Err_NoPermForHost(Server *server) : Reply(), server_(server) {;};
	~Err_NoPermForHost() {;};
	void execute(Client &client, std::string &command);
};

class Err_PasswdMismatch : public Reply {
private:
	Server *server_;

public:
	Err_PasswdMismatch(Server *server) : Reply(), server_(server) {;};
	~Err_PasswdMismatch() {;};
	void execute(Client &client, std::string &command);
};

class Err_YoureBannedCreep : public Reply {
private:
	Server *server_;

public:
	Err_YoureBannedCreep(Server *server) : Reply(), server_(server) {;};
	~Err_YoureBannedCreep() {;};
	void execute(Client &client, std::string &command);
};

class Err_Keyset : public Reply {
private:
	Server *server_;

public:
	Err_Keyset(Server *server) : Reply(), server_(server) {;};
	~Err_Keyset() {;};
	void execute(Client &client, std::string &command);
};

class Err_NoPrivileges : public Reply {
private:
	Server *server_;

public:
	Err_NoPrivileges(Server *server) : Reply(), server_(server) {;};
	~Err_NoPrivileges() {;};
	void execute(Client &client, std::string &command);
};

class Err_ChanoprivsNeeded : public Reply {
private:
	Server *server_;

public:
	Err_ChanoprivsNeeded(Server *server) : Reply(), server_(server) {;};
	~Err_ChanoprivsNeeded() {;};
	void execute(Client &client, std::string &command);
};

class Err_CantKillServer : public Reply {
private:
	Server *server_;

public:
	Err_CantKillServer(Server *server) : Reply(), server_(server) {;};
	~Err_CantKillServer() {;};
	void execute(Client &client, std::string &command);
};

class Err_NoOperHost : public Reply {
private:
	Server *server_;

public:
	Err_NoOperHost(Server *server) : Reply(), server_(server) {;};
	~Err_NoOperHost() {;};
	void execute(Client &client, std::string &command);
};

class Err_UmodeUnknownFlag : public Reply {
private:
	Server *server_;

public:
	Err_UmodeUnknownFlag(Server *server) : Reply(), server_(server) {;};
	~Err_UmodeUnknownFlag() {;};
	void execute(Client &client, std::string &command);
};

class Err_UsersDontMatch : public Reply {
private:
	Server *server_;

public:
	Err_UsersDontMatch(Server *server) : Reply(), server_(server) {;};
	~Err_UsersDontMatch() {;};
	void execute(Client &client, std::string &command);
};