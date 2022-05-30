NAME	= ircserv
CXX		= C++
#CXXFLAGS= -Wall -Werror -Wextra -std=c++98
SRC		= srcs/main.cpp \
		srcs/server.cpp \
		srcs/wrappers.cpp \
		srcs/command.cpp \
		srcs/client.cpp \
		srcs/replies.cpp
OBJ		= $(SRC:%.cpp=%.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $? -o $@ -Iincludes/

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./ircserv 4242 12345