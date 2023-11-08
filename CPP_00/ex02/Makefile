NAME	= job

SRCS	= $(wildcard *.cpp)
OBJS	= $(SRCS:.cpp=.o)

CXX			= c++
CXXFLAGS	= -std=c++98 -Wall -Werror -Wextra

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) -I ./

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
