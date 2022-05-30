#pragma once

#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <fcntl.h>
#include <poll.h>
#include <vector>
#include <unistd.h>
#include "exceptions.hpp"

int ft_socket();
void ft_bind(int &socket, struct sockaddr_in &settings);
void ft_listen(int &socket);
void ft_fcntl(int &socket);
void ft_poll(std::vector<pollfd> &pollfds);
int ft_accept(int socket, struct sockaddr_in &connectionData, socklen_t &addressLen);
std::string ft_recv(int fd);
void ft_send(int fd, std::string string);