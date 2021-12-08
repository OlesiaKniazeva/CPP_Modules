NAME = megaphone

SRCS = megaphone.cpp

CC = clang++ -std=c++98

CFLAGS = -Wall -Wextra -Werror

OBJS = $(patsubst %.cpp,%.o, $(SRCS))

%.o:		%.cpp
		$(CC) $(CFLAGCS) -c $< -o $@ 

.PHONY: all clean fclean re

all : $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean: 
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all