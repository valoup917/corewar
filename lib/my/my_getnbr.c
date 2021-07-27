/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** .
*/

int my_getnbr(char *str)
{
    int nb = 0;
    int a = 1;
    int i = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            a = a * -1;
        i = i + 1;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
            i = i + 1;
        }
        else
            return (nb * a);
    }
    return (nb * a);
}
