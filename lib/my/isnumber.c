/*
** EPITECH PROJECT, 2021
** lib
** File description:
** isnumber
*/

#include <stddef.h>

int isnumber(char *str)
{
    if (str == NULL)
        return (1);
    for (int i = 0; str[i] != '\0'; i++)
        if (!(str[i] >= '0' && str[i] <= '9' || str[i] == '-'))
            return (1);
    return (0);
}