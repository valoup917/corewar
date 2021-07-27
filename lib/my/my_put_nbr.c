/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** print number
*/

#include <unistd.h>

int my_put_nbr(int nb, int fd)
{
    int r = 0;

    if (nb < 0) {
        write(fd, "-", 1);
        nb *= -1;
    }
    if (nb >= 0) {
        if (nb >= 10) {
            r = (nb % 10);
            nb = (nb - r) / 10;
            my_put_nbr(nb, fd);
            r += 48;
            write(fd, &r, 1);
        } else {
            r = nb % 10 + 48;
            write(fd, &r, 1);
        }
    }
    return (0);
}
