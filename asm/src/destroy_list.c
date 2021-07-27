/*
** EPITECH PROJECT, 2021
** destroy_list
** File description:
** destroy_list
*/

#include "asm.h"

void destroy_content(content_t *info)
{
    file_t *current = info->current;
    file_t *top = info->top;
    file_t *next;
    file_t *t_next;

    while (current != NULL) {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
        t_next = top->next;
        free(top->data);
        free(top);
        top = next;
    }
}

void destroy_data(data_t **ptr)
{
    data_t *current = *ptr;
    data_t *next;

    while (current != NULL) {
        next = current->next;
        if (current->data)
            free(current->data);
        if (current->to_find)
            free(current->to_find);
        free(current);
        current = next;
    }
}

void destroy_arr(char **array)
{
    for (int i = 0; array[i] != 0; i++)
        if (array[i])
            free(array[i]);
}