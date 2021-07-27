##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CC = gcc

SRC =	src/set_memory.c 		\
		src/parsing_args.c 		\
		src/parsing_champ_orga.c 	\
		src/parsing_champ.c 	\
		src/read_champ.c 		\
		src/init_list_champ.c 	\
		../lib/my/my_getnbr.c			\
		../lib/my/my_strcpy.c 		\
		../lib/my/my_strlen.c 		\
		../lib/my/my_strcmp.c 		\
		../lib/my/my_strdup.c		\

SRC_MAIN = 	src/main.c 		\

OBJ = $(SRC:.c=.o)

OBJ_MAIN = $(SRC_MAIN:.c=.o)

CFLAGS = -Wall -Wextra -pedantic

CPPFLAGS = -I./include

RM	=	rm -f

NAME = corewar

debug: CFLAGS += -g3
debug: re

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_MAIN)

clean:
	$(RM) $(OBJ) $(OBJ_MAIN)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re