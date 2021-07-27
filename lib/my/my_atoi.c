/*
** EPITECH PROJECT, 2020
** my_atoi
** File description:
** str to int
*/

#include <stdbool.h>

int my_atoi(char const *str)
{
    int result = 0;
    bool neg = false;
    int i = 0;

    if (str[0] == '-') {
        neg = true;
        i += 1;
    }
    for (; str[i] != '\0'; i++)
        result = result * 10 + (str[i] - 48);
    if (neg == true)
        result *= -1;
    return (result);
}
