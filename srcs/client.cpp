#include "client.hpp"

Client::Client(int &fd, struct sockaddr_in &socketData) : fd_(fd), socketData_(socketData) {
	buffer_ = "";
	registered_ = false;
	password_ = "";
}

void Client::receive() {
	buffer_ += ft_recv(fd_);
}

void Client::parse() {
	unsigned int position;
	std::string result;
	while ((position = buffer_.find('\n')) != -1) {
		if (buffer_[position - 1] == '\r')
			result = buffer_.substr(0, position - 1);
		else
			result = buffer_.substr(0, position);
		commands_.push_back(result);
		buffer_.erase(buffer_.begin(), buffer_.begin() + position + 1);
	}
}

std::string Client::getCommand() {
	std::string ret;
	std::stringstream temp;
	if (!commands_.empty()) {
		ret = commands_[0];
		temp << commands_[0];
		temp >> currentCommand_;
		commands_.erase(commands_.begin());
	}
	else
		ret = "";
	return ret;
}