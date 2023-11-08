NAME	= Interface

SRCS	= $(wildcard *.cpp)
OBJS	= $(SRCS:.cpp=.o)

CXX			= c++
CXXFLAGS	= -std=c++98 -Wall -Werror -Wextra

HEADER	= $(wildcard *.hpp)

$(NAME): $(OBJS) $(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) 

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
