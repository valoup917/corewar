/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** concat 2 strings
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int y = my_strlen(dest);

    for (int j = 0; src[j] != '\0'; j++) {
        dest[y] = src[j];
        y++;
    }
    dest[y] = '\0';
    return (dest);
}
