##
## EPITECH PROJECT, 2024
## qua qua
## File description:
## Makefile
##


SRC     =	./lib/my/in_game.c	\
			./lib/my/set_value.c	\
			./lib/my/clock.c	\
			./lib/my/free_memory.c

OBJ     =	$(SRC:.c=.o)

NAME    =	my_hunter

CFLAGS  =  	-W -Wall -Wextra

CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window


$(NAME)	:	$(OBJ)
			ar rc libmy.a $(OBJ)
	gcc src/duck_hunter.c -o $(NAME) -lmy -L./ -I./include $(CSFML) $(CFLAGS)
all :	$(NAME)

clean:
	rm $(OBJ)
	rm libmy.a

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
