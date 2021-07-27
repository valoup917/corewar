/*
** EPITECH PROJECT, 2021
** encode_write
** File description:
** encode_write
*/

#include "asm.h"
#include "op.h"
#include "lib.h"
#include <stdbool.h>

int write_neg_bytes(data_t **prgm, int value, int size)
{
    char *nb = malloc(sizeof(char) * (size * 8 + 1));
    int i = 0;

    if (nb == NULL)
        return (-1);
    for (; i < size * 8; i++)
        nb[i] = '2';
    nb[i] = '\0';
    dec_to_bin(value, nb);
    my_revstr(nb);
    for (int i = 0; nb[i] != '\0'; i++)
        if (nb[i] == '2' || nb[i] == '0')
            nb[i] = '1';
        else
            nb[i] = '0';
    for (i = my_strlen(nb) - 1; i > 0 && nb[i] != '0' && value != -1; i--)
        nb[i] = '0';
    nb[i] = '1';
    split_by_bytes(prgm, nb, 1);
    return (0);
}

int write_bytes(data_t **prgm, char *arg, int size)
{
    int value = 0;
    int mod = 0;

    if (*arg == '%')
        arg += 1;
    if (*arg == ':')
        arg += 1;
    if (isnumber(arg))
        return (add_to_find(prgm, arg));
    value = my_atoi(arg);
    if (value < 0)
        return (write_neg_bytes(prgm, value, size));
    mod = value / 255 + 1;
    for (int i = 0; i < size - mod; i++)
        write_data(prgm, 0, ARG_CODE);
    for (int i = 0; i < mod; i++)
        if (i == 0) {
            write_data(prgm, value % 255, ARG_CODE);
            value -= value % 255;
        } else if (value / 255 > 0)
            write_data(prgm, 255, ARG_CODE);
    return (0);
}

int write_neg_bytes_in_buf(data_t **node, int value)
{
    char *res = malloc(sizeof(char) * (2 * 8 + 1));
    int i = 0;

    if (res == NULL)
        return (-1);
    for (; i < 2 * 8; i++)
        res[i] = '2';
    res[i] = '\0';
    dec_to_bin(value, res);
    my_revstr(res);
    move_nbr_in_str(res);
    for (int i = 0; res[i] != '\0'; i++)
        if (res[i] == '2' || res[i] == '0')
            res[i] = '1';
        else
            res[i] = '0';
    split_by_bytes(node, res, 0);
    free(res);
    return (0);
}

int write_bytes_in_buf(data_t **node, int value)
{
    int mod = value / 255 + 1;
    int i = 0;

    if (value < 0) {
        write_neg_bytes_in_buf(node, value);
        return (0);
    }
    for (; i < 2 - mod; i++)
        (*node)->data[i] = 0;
    for (int j = 0; i < 2; j++, i++) {
        if (j == 0) {
            (*node)->data[i] = value % 255;
            value -= value % 255;
        }
        if (value / 255 > 0)
            (*node)->data[i] = 255;
    }
    return (0);
}

int write_arg(char **av, data_t **prgm, char *arg_size)
{
    int nb = get_instr_code(av);

    arg_size[my_strlen(arg_size) - 2] = '\0';
    for (int i = 1; *arg_size != '\0'; i++) {
        if (nb >= 9 && nb <= 12 && my_strncmp(arg_size, reg, 2))
            write_bytes(prgm, av[i], T_DIR);
        else if (!my_strncmp(arg_size, reg, 2)) {
            av[i] += 1;
            write_data(prgm, my_atoi(av[i]), ARG_CODE);
        } else if (!my_strncmp(arg_size, dir, 2))
            write_bytes(prgm, av[i], T_IND);
        arg_size += 2;
    }
    return (0);
}