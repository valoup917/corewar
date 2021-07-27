/*
** EPITECH PROJECT, 2021
** asm
** File description:
** main
*/

#include "lib.h"
#include "asm.h"

int helper(void)
{
    my_putstr("USAGE\n./asm file_name[.s]\n");
    my_putstr("DESCRIPTION\nfile_name file in assembly language to be ");
    my_putstr("converted into file_name.cor, an executable in ");
    my_putstr("the Virtual Machine.\n");
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (!my_strcmp(av[1], "-h"))
        return (helper());
    if (translate(av[1]))
        return (84);
}