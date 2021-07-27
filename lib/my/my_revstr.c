/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** .
*/

int my_strlen(char const *str);

void my_swap_char(char *a, char *b)
{
    char c = *a;

    *a = *b;
    *b = c;
}

char *my_revstr(char *str)
{
    int len = my_strlen(str) - 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (i >= len - i)
            return (str);
        my_swap_char(&str[i], &str[len - i]);
    }
    return (str);
}
