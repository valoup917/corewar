/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** compare 2 strings
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] != '\0' && s2[i] != '\0'; i++)
        if (s1[i] > s2[i] || s1[i] < s2[i])
            return (s1[i] - s2[i]);
    if (s1[i] == '\0' && s2[i] != '\0')
        return (10);
    if (s2[i] == '\0' && s1[i] != '\0')
        return (10);
    return (0);
}
