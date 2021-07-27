/*
** EPITECH PROJECT, 2021
** encode_utils
** File description:
** encode_utils
*/

#include "asm.h"
#include "op.h"
#include "lib.h"

int add_label(data_t **prgm, char *label)
{
    data_t *ptr = malloc(sizeof(data_t));

    if (ptr == NULL)
        return (-1);
    ptr->data = my_strdup(label);
    if (ptr->data == NULL)
        return (-1);
    ptr->d_type = LABEL_CODE;
    ptr->to_find = NULL;
    ptr->next = *prgm;
    *prgm = ptr;
    return (0);
}

int add_to_find(data_t **prgm, char *arg)
{
    data_t *element = malloc(sizeof(data_t));

    if (element == NULL)
        return (-1);
    element->to_find = my_strdup(arg);
    if (element->to_find == NULL)
        return (-1);
    element->data = malloc(sizeof(char) * (2 + 1));
    if (element->data == NULL)
        return (-1);
    element->size = 2;
    element->d_type = TO_FIND;
    element->next = *prgm;
    *prgm = element;
    return (0);
}

int get_idx_label(data_t *prgm, char *to_find)
{
    data_t *ptr = prgm;
    int len = my_strlen(to_find);
    int i = 0;

    while (ptr != NULL) {
        if (ptr->d_type == INSTR_CODE || ptr->d_type == ARG_CODE
            || ptr->d_type == BYTE_CODE)
            i += 1;
        if (ptr->to_find != NULL)
            i += 2;
        if (ptr->data != NULL && my_strlen(ptr->data) >= len &&
            !my_strncmp(to_find, ptr->data, len))
            return (i);
        ptr = ptr->next;
    }
    return (-1);
}

void split_by_bytes(data_t **node, char *nb, int mod)
{
    char bit;
    int dec;
    int tmp;

    for (int i = 0; *nb != '\0'; i++) {
        bit = nb[8];
        nb[8] = '\0';
        tmp = bin_to_dec(nb);
        if (mod == 0)
            (*node)->data[i] = tmp;
        else
            write_data(node, tmp, ARG_CODE);
        nb[8] = bit;
        nb += 8;
    }
}

char *move_nbr_in_str(char *nb)
{
    int i = 0;
    int len = my_strlen(nb) - 1;

    for (; nb[i] != '\0' && nb[i + 1] != '2'; i++);
    for (int j = 0; i >= 0; i--, j++)
        nb[len - j] = nb[i];
    for (int i = 0; nb[i] != '\0' && nb[i] != '2'; i++)
        nb[i] = '2';
    return (nb);
}
