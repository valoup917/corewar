/*
** EPITECH PROJECT, 2021
** encode
** File description:
** encode
*/

#include "asm.h"
#include "op.h"
#include "lib.h"
#include <stdbool.h>

int write_data(data_t **prgm, int value, int instruction)
{
    data_t *byte = malloc(sizeof(data_t));

    if (byte == NULL)
        return (-1);
    byte->data = malloc(sizeof(char) * (2));
    if (byte->data == NULL)
        return (-1);
    byte->d_type = instruction;
    byte->data[0] = value;
    byte->data[1] = '\0';
    byte->to_find = NULL;
    byte->next = *prgm;
    *prgm = byte;
    return (0);
}

int encode_label(data_t **prgm)
{
    data_t *top = *prgm;
    int idx = 0;
    int start = 0;
    int i = 0;

    while (*prgm != NULL) {
        if ((*prgm)->d_type == INSTR_CODE)
            start = i;
        if ((*prgm)->d_type == ARG_CODE || (*prgm)->d_type == INSTR_CODE
            || (*prgm)->d_type == BYTE_CODE)
            i += 1;
        if ((*prgm)->d_type == TO_FIND)
            i += 2;
        if ((*prgm)->d_type == TO_FIND) {
            idx = get_idx_label(top, (*prgm)->to_find) - start;
            write_bytes_in_buf(prgm, idx); }
        *prgm = (*prgm)->next;
    }
    *prgm = top;
    return (0);
}

int encode(char **av, data_t **prgm, content_t *info)
{
    int instr_code = get_instr_code(av);
    char *arg_size;
    int len = 1;

    if (instr_code == -1)
        return (error_msg("Unknown command", info->current->line));
    if (!(op_tab[instr_code - 1].nbr_args == 1
        && op_tab[instr_code - 1].type[0] == 2))
        len += 1;
    if (op_tab[instr_code - 1].nbr_args != my_arrlen(av) - 1)
        return (error_msg("Invalid number of arguments", info->current->line));
    write_data(prgm, instr_code, INSTR_CODE);
    arg_size = get_arg_size(av, info, instr_code);
    if (arg_size == NULL)
        return (-1);
    if (len > 1)
        write_data(prgm, bin_to_dec(arg_size), BYTE_CODE);
    if (write_arg(av, prgm, arg_size) == -1)
        return (-1);
    return (0);
}