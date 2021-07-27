/*
** EPITECH PROJECT, 2021
** lib
** File description:
** dec_to_bin
*/

#include <stdbool.h>
#include <stdlib.h>

char *dec_to_bin(int nb, char *res)
{
    bool neg = false;

    if (nb < 0) {
        neg = true;
        nb *= -1;
    }
    if (res == NULL)
        return (NULL);
    for (int i = 0; nb > 0; i++) {
        res[i] = (nb % 2) + '0';
        nb /= 2;
    }
    return (res);
}