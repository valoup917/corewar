/*
** EPITECH PROJECT, 2021
** lib
** File description:
** my_strlen
*/

int my_strlen(const char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}