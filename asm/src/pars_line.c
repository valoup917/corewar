/*
** EPITECH PROJECT, 2021
** pars_line
** File description:
** pars_line
*/

#include "asm.h"
#include "op.h"
#include "lib.h"

int cmp_by_str(char cmp, char const *str)
{
    int i = 0;

    for (; str[i] != '\0' && str[i] != cmp; i++);
    if (str[i] == '\0')
        return (1);
    return (0);
}

int get_token(char **av)
{
    int i = 0;
    int count = 0;

    if (!my_strcmp(av[0], "#") || !my_strcmp(av[0], NAME_CMD_STRING)
        || !my_strcmp(av[0], COMMENT_CMD_STRING))
        return (IGNORE);
    for (int i = 0; op_tab[i].mnemonique != 0; i++)
        if (!my_strcmp(av[0], op_tab[i].mnemonique))
            return (INSTRUCTION);
    for (; av[0][i] != '\0' && av[0][i] != LABEL_CHAR; i++)
        if (cmp_by_str(av[0][i], LABEL_CHARS))
            return (-1);
    for (int j = 0; av[0][j] != '\0'; j++)
        if (av[0][j] == LABEL_CHAR)
            count += 1;
    if (av[0][i] == LABEL_CHAR && count == 1)
        return (LABEL);
    return (-1);
}

int get_data(int token, char **av, data_t **prgm, content_t *info)
{
    if (token == INSTRUCTION)
        if (encode(av, prgm, info) == -1)
            return (-1);
    if (token == LABEL) {
        if (add_label(prgm, av[0]) == -1)
            return (-1);
        av += 1;
        if (av[0] != 0 && encode(av, prgm, info) == -1)
            return (-1);
    }
    return (0);
}

int compile(data_t *prgm, content_t *info, char *o_filepath)
{
    my_rev_list_data(&prgm);
    encode_label(&prgm);
    if (get_header(&prgm, info, o_filepath) == -1)
        return (-1);
    destroy_data(&prgm);
    return (0);
}

int pars_line(content_t *info, char *o_filepath)
{
    char **av = NULL;
    data_t *prgm = NULL;
    int token = 0;

    for (int i = 1; info->current != NULL; i++) {
        if (info->current->data[0] == '\0') {
            info->current = info->current->next;
            continue;
        }
        av = my_str_to_word_array(info->current->data);
        if (av == NULL)
            return (-1);
        token = get_token(av);
        if (token == -1)
            return (error_msg("Unknown command", i));
        if (token != IGNORE && get_data(token, av, &prgm, info) == -1)
            return (-1);
        info->current = info->current->next;
    }
    return (compile(prgm, info, o_filepath));
}
