/*
** EPITECH PROJECT, 2021
** clear_str
** File description:
** Clean String
*/

#include <stdbool.h>

char *move_str(char *str, int it)
{
    for (; str[it] != '\0'; it++)
        str[it] = str[it + 1];
    return (str);
}

char *clear_str(char *str)
{
    bool quote = false;

    while (str[0] == ' ')
        str += 1;
    for (int i = 0; str[i] != '\0' && str[i] != '"'; i++)
        if (str[i] == '\t')
            str[i] = ' ';
    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] == '"' && quote == false)
            quote = true;
        else if (str[j] == '"' && quote == true)
            quote = false;
        if (quote != true && str[j] == ' ' && (str[j + 1] == ' '
        || str[j + 1] == '\0' || str[j + 1] == ',')
        || j > 0 && str[j] == ' ' && str[j - 1] == ',') {
            str = move_str(str, j);
            j -= 1;
        }
    }
    return (str);
}
