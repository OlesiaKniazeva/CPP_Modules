NAME = task

SRCS = main.cpp

O_DIR = obj

CC = clang++ #-std=c++98

CFLAGS = -glldb -Wall -Wextra -Werror

OBJS = $(addprefix $(O_DIR)/, $(patsubst %.cpp, %.o, $(SRCS)))

$(O_DIR)/%.o : %.cpp
		@mkdir -p $(O_DIR)
		$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		rm -rf $(O_DIR)

fclean: clean
		rm -rf $(NAME)

re : fclean all