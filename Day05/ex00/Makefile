NAME = bureaucrat

SRCS = Bureaucrat.cpp main.cpp

O_DIR = obj

CC = clang++ -std=c++98

CFLAGS = -Wall -Wextra -Werror

OBJS = $(addprefix $(O_DIR)/, $(patsubst %.cpp, %.o, $(SRCS)))

HEADER = Bureaucrat.hpp

$(O_DIR)/%.o : %.cpp $(HEADER)
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