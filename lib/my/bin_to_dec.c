/*
** EPITECH PROJECT, 2021
** lib
** File description:
** bin_to_dec
*/

int my_strlen(char *str);

int bin_to_dec(char *num)
{
    int number = 0;
    int idx = my_strlen(num) - 1;
    int pwr = 1;

    for (int i = idx; i >= 0; i--) {
        if (num[i] == '1')
            number += pwr;
    pwr *= 2;
    }
    return (number);
}