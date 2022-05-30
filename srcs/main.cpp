#include <iostream>
#include "colors.hpp"
#include "exceptions.hpp"
#include "server.hpp"

int main(int argc, char **argv) {
	try {
		if (argc != 3)
			throw argumentsException();
		Server ircserv(argv[1], argv[2]);
		ircserv.loop();
	}
	catch (std::exception &e){
		std::cerr << RED << "Error: " << e.what() << std::endl << DEFAULT;
		return 1;
	}
}