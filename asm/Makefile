##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## .
##

SRC	=	src/main.c	\
		src/clear_str.c	\
		src/translate.c	\
		src/op.c	\
		src/pars_line.c	\
		src/get_file.c	\
		src/encode.c	\
		src/encode_utils.c	\
		src/encode_write.c	\
		src/get_coding_b.c	\
		src/get_header.c	\
		src/write_in_file.c	\
		src/destroy_list.c	\
		src/arg_type.c

OBJ	=	$(SRC:.c=.o)

FLAGS = -Wall -Wextra

CPPFLAGS = -I./include/

LIB = -L../lib/ -lmy

NAME	=	asm

all:	$(NAME)

debug: CFLAGS += -g3
debug: re

$(NAME):	$(OBJ)
	make -C ../lib/my
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LIB)

clean:
	make clean -C ../lib/my
	rm -f $(OBJ)
	rm -f src/*~
	rm -f include/*~

fclean: clean
	make fclean -C ../lib/my
	rm -f $(NAME)
	rm -f \#*\#

re: fclean all

.PHONY: clean re fclean
