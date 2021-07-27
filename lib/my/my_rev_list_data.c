/*
** EPITECH PROJECT, 2021
** lib
** File description:
** my_rev_list_data
*/

#include "../../asm/include/asm.h"

int my_list_size_data(data_t **begin)
{
    int i = 0;
    data_t *save = *begin;

    for (; save != NULL; i++)
        save = save->next;
    return (i);
}

void my_rev_list_data(data_t **begin)
{
    data_t *crr = *begin;
    data_t *prev = NULL;
    data_t *nxt;
    int size = my_list_size_data(begin);

    for (int i = 0; i < size; i++) {
        nxt = crr->next;
        crr->next = prev;
        prev = crr;
        crr = nxt;
    }
    *begin = prev;
}