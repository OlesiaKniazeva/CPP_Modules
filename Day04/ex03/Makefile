NAME = task

SRCS = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
O_DIR = obj

CC = clang++ -std=c++98

CFLAGS = -glldb -Wall -Wextra -Werror

OBJS = $(addprefix $(O_DIR)/, $(patsubst %.cpp, %.o, $(SRCS)))

HEADER = ICharacter.hpp AMateria.hpp Character.hpp \
				 Cure.hpp Ice.hpp MateriaSource.hpp \
				 IMateriaSource.hpp

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