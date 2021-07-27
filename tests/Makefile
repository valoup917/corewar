##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile root minishell2
##

CC	=	gcc

SRC	=	../lib/my/my_putstr.c		\
		../lib/my/my_strdup.c		\
		../lib/my/my_strlen.c		\
		../lib/my/my_getnbr.c			\
		../lib/my/my_strcpy.c 		\
		../lib/my/my_strcmp.c 		\

SRC_VM	=	../corewar/src/set_memory.c 		\
		../corewar/src/parsing_args.c 		\
		../corewar/src/parsing_champ_orga.c 	\
		../corewar/src/parsing_champ.c 	\
		../corewar/src/read_champ.c 		\
		../corewar/src/init_list_champ.c 	\

SRC_TESTS	=	my_putstr_tests.c	\
			vm_test.c 			\
			my_strdup_tests.c	\

OBJ		= 	${SRC:.c=.o}

OBJ_TESTS	= 	${SRC_TESTS:.c=.o}

OBJ_VM	= 	${SRC_VM:.c=.o}

TESTS_NAME	=	unit_tests

CPPFLAGS	= 	-I./include

tests_run: LDFLAGS += -lcriterion --coverage

tests_run: fclean $(OBJ_TESTS) $(OBJ) $(OBJ_VM)
	$(CC) -o $(TESTS_NAME) $(OBJ) $(OBJ_TESTS) $(OBJ_VM) $(LDFLAGS)
	./$(TESTS_NAME)

clean:
	rm -f *.html
	rm -f $(OBJ)
	rm -f $(OBJ_TESTS)
	rm -f $(OBJ_VM)

fclean: clean
	rm -f $(NAME)
	rm -f $(TESTS_NAME)

re: fclean tests_run

.PHONY: clean fclean re tests_run
