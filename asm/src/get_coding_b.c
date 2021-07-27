/*
** EPITECH PROJECT, 2021
** get_coding_b
** File description:
** get_coding_b
*/

#include "asm.h"
#include "op.h"
#include "lib.h"

int find_str(file_t *top, char *str)
{
    file_t *save = top;
    int len = 0;

    if (*str == ':')
        str += 1;
    else
        str += 2;
    len = my_strlen(str);
    while (save != NULL) {
        if (my_strncmp(save->data, str, len) == 0 &&
            my_strlen(save->data) > len && save->data[len] == LABEL_CHAR)
            return (1);
        save = save->next;
    }
    return (0);
}

int check_arg_type(char *tmp, int arg_type)
{
    int value = 0;

    if (!my_strcmp(tmp, "01"))
        value = 1;
    if (!my_strcmp(tmp, "10"))
        value = 2;
    if (!my_strcmp(tmp, "11"))
        value = 4;
    if ((arg_type & value) == 0)
        return (1);
    return (0);
}

char *get_arg_size(char **av, content_t *info, int instr_code)
{
    char *arg_size = malloc(sizeof(char) *
    (op_tab[instr_code - 1].nbr_args * 2 + 3));
    char *tmp;

    if (arg_size == NULL)
        return (NULL);
    arg_size[0] = '\0';
    for (int i = 1; av[i] != 0; i++) {
        tmp = get_arg_type(av[i], info);
        if (tmp == NULL
        || check_arg_type(tmp, op_tab[instr_code - 1].type[i - 1])) {
            error_msg("Invalid argument type", info->current->line);
            return (NULL);
        }
        my_strcat(arg_size, tmp);
    }
    my_strcat(arg_size, "00");
    return (arg_size);
}
