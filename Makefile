NAME = bsq
SRC = main.c map_prepare.c solver.c utilities.c
OBJFILES= $(SRC:.c=.o)
COMPILER = gcc
FLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJFILES)
	$(COMPILER) -o $(NAME) $(OBJFILES) -Iincludes $(FLAGS)

clean:
	rm -f $(OBJFILES)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean