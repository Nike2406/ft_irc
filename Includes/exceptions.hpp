#pragma once

#include <iostream>

//EXAMPLE OF EXCEPTION:
//class (Error)Exception: public std::exception {
//	virtual const char* what() const throw() { return "<text>"; }
//};

class argumentsException: public std::exception {
	virtual const char* what() const throw() { return "Wrong number of arguments. Example: ./ircserv <port> <password>."; }
};

class portException: public std::exception {
	virtual const char* what() const throw() { return "Entered wrong port."; }
};

class socketException: public std::exception {
	virtual const char* what() const throw() { return "Socket not created."; }
};

class bindException: public std::exception {
	virtual const char* what() const throw() { return "Socket not binded."; }
};

class listenException: public std::exception {
	virtual const char* what() const throw() { return "Socket not listened."; }
};

class fcntlException: public std::exception {
	virtual const char* what() const throw() { return "Non block flag not setted."; }
};

class pollException: public std::exception {
	virtual const char* what() const throw() { return "Poll not done."; }
};

class acceptException: public std::exception {
	virtual const char* what() const throw() { return "Cannot connect to client."; }
};