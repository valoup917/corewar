##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## .
##

all:
		make -C corewar/
		make -C asm/

clean:
	make clean -C corewar/
	make clean -C asm/
	make clean -C tests/

fclean:
	make fclean -C corewar/
	make fclean -C asm/
	make fclean -C tests/

tests_run:
	make -C tests/

re: fclean all

.PHONY: all clean fclean re
