NAME	= btc

SRCS	= $(wildcard *.cpp)
OBJS	= $(SRCS:.cpp=.o)

CXX			= c++
CXXFLAGS	= -std=c++98 -Wall -Werror -Wextra -fsanitize=address

HEADER	= $(wildcard *.hpp)

%.o: %.cpp $(HEADER) Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) 

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
