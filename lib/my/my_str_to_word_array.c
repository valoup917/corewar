/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** str to array
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void quote_status(char c, bool *quote)
{
    if (c == '"' && *quote == false)
        *quote = true;
    else if (c == '"' && *quote == true)
        *quote = false;
}

char **cpy_str_to_arr(char **arr, char *str)
{
    int j = 0;
    int k = 0;
    bool quote = false;

    for (int i = 0; str[i] != '\0'; i++) {
        quote_status(str[i], &quote);
        if ((str[i] != ' ' && str[i] != ',') || quote == true) {
            arr[j][k] = str[i];
            k += 1;
        } else {
            arr[j][k] = '\0';
            j += 1;
            k = 0;
        }
    }
    arr[j][k] = '\0';
    j += 1;
    arr[j] = NULL;
    return (arr);
}

char **str_to_arr(char **arr, char *str)
{
    int len = 0;
    int j = 0;
    bool quote = false;

    for (int i = 0; str[i] != '\0'; i++) {
        quote_status(str[i], &quote);
        if ((str[i] != ' ' && str[i] != ',') || quote == true)
            len += 1;
        else {
            arr[j] = malloc(sizeof(char) * (len + 1));
            j += 1;
        }
    }
    arr[j] = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < j - 1; i++)
        if (arr[j] == NULL)
            return (NULL);
    return (cpy_str_to_arr(arr, str));
}

char **my_str_to_word_array(char *str)
{
    int len = 0;
    char **arr;
    bool quote = false;

    for (int i = 0; str[i] != '\0'; i++) {
        quote_status(str[i], &quote);
        if ((str[i] == ' ' || str[i] == ',') && quote != true)
            len += 1;
    }
    if (quote == true)
        return (NULL);
    arr = malloc(sizeof(char *) * (len + 2));
    if (arr == NULL)
        return (NULL);
    return (str_to_arr(arr, str));
}