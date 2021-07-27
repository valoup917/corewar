/*
** EPITECH PROJECT, 2021
** lib
** File description:
** my_arrlen
*/

int my_arrlen(char **av)
{
    int i = 0;

    for (; av[i] != 0; i++);
    return (i);
}