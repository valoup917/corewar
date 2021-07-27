/*
** EPITECH PROJECT, 2020
** my_rev_list
** File description:
** reverse a list from file_t
*/

#include <stdio.h>
#include "../../asm/include/asm.h"

int my_list_size(file_t **begin)
{
    int i = 0;
    file_t *save = *begin;

    for (; save != NULL; i++)
        save = save->next;
    return (i);
}

void my_rev_list(file_t **begin)
{
    file_t *crr = *begin;
    file_t *prev = NULL;
    file_t *nxt;
    int size = my_list_size(begin);

    for (int i = 0; i < size; i++) {
        nxt = crr->next;
        crr->next = prev;
        prev = crr;
        crr = nxt;
    }
    *begin = prev;
}
