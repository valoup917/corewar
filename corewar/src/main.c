/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** vm main
*/

#include "corewar.h"

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}

int helper(void)
{
    my_putstr("USAGE\n./corewar [-dump nbr_cycle] [[-n prog_number]");
    my_putstr("[-a load_address] prog_name] ...\n");
    my_putstr("DESCRIPTION\n-dump nbr_cycle dumps the memory after");
    my_putstr(" the nbr_cycle execution (if the round isn’t\nalready over)");
    my_putstr(" with the following format: 32 bytes/line\n");
    my_putstr("in hexadecimal (A0BCDEFE1DD3...)\n");
    my_putstr("-n prog_number sets the next program’s number. By default, ");
    my_putstr("the first free number\nin the parameter order\n");
    my_putstr("-a load_address sets the next program’s loading address.");
    my_putstr("When no address is\nspecified, optimize the addresses so that");
    my_putstr(" the processes are as far\n");
    my_putstr("away from each other as possible. The addresses are MEM_SIZE");
    my_putstr(" modulo.\n");
    return (0);
}

int main(int argc, char **argv, char **env)
{

    if (argc < 2)
        return (84);
    if (!(*env))
        return 84;
    if (!my_strcmp(argv[1], "-h"))
        return (helper());
    set_all(argc, argv);
    return 0;
}