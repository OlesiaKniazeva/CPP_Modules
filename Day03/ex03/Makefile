NAME = Trap

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

CC = clang++ -std=c++98

HEADER = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp

CFLAGS = -glldb -Wall -Wextra -Werror -Wshadow -Wno-shadow

O_DIR = obj

OBJS = $(addprefix $(O_DIR)/, $(patsubst %.cpp,%.o, $(SRCS)))

$(O_DIR)/%.o:		%.cpp $(HEADER)
		@mkdir -p $(O_DIR)
		$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

all : $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		rm -rf $(O_DIR)

fclean: clean
		rm -rf $(NAME)

re: fclean all