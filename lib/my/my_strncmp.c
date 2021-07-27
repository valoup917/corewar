/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** compare 2 strings from pos
*/

char my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (; i < n && s1[i] != '\0' && s2[i] != '\0'; i++)
        if (s1[i] > s2[i] || s1[i] < s2[i])
            return (s1[i] - s2[i]);
    if (i != n)
        return (10);
    return 0;
}
