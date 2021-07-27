##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Lib Makefile
##

SRC     =	my_strcmp.c	\
			my_putstr.c	\
			my_strncmp.c	\
			isnumber.c	\
			my_strcpy.c	\
			my_strcat.c	\
			my_strlen.c	\
			my_strdup.c	\
			my_rev_list.c	\
			my_str_to_word_array.c	\
			my_put_nbr.c	\
			my_arrlen.c	\
			my_atoi.c	\
			bin_to_dec.c	\
			my_rev_list_data.c	\
			dec_to_bin.c	\
			my_revstr.c

OBJ     =       $(SRC:.c=.o)

NAME    =       libmy.a

all: $(NAME)

$(NAME):        $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
clean:
	rm -f $(OBJ)
	rm -f *~

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)
	rm -f \#*\#

re: fclean all

.PHONY: clean
