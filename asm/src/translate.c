/*
** EPITECH PROJECT, 2021
** translate
** File description:
** translate
*/

#include "asm.h"
#include "lib.h"
#include "op.h"

int error_msg(char *error, int line)
{
    write(2, "\033[31;1mError: \033[0m", 19);
    write(2, error, my_strlen(error));
    if (line != -1) {
        write(2, " line:", 6);
        my_put_nbr(line, 2);
    }
    write(2, "\n", 1);
    return (-1);
}

int get_instr_code(char **av)
{
    int instr_code = -1;

    for (int i = 0; op_tab[i].mnemonique != 0; i++)
        if (!my_strcmp(av[0], op_tab[i].mnemonique))
            instr_code = op_tab[i].code;
    return (instr_code);
}

int initialize_content(content_t **info, file_t *file)
{
    *info = malloc(sizeof(content_t));

    if (!info)
        return (-1);
    (*info)->current = file;
    my_rev_list(&(*info)->current);
    (*info)->top = (*info)->current;
    return (0);
}

int translate(char *filepath)
{
    char *o_filepath = get_o_filepath(filepath);
    file_t *file = NULL;
    content_t *info;

    if (!o_filepath)
        return (84);
    if (get_file(&file, filepath))
        return (84);
    if (initialize_content(&info, file) == -1)
        return (84);
    if (pars_line(info, o_filepath) == -1)
        return (84);
    destroy_content(info);
    free(o_filepath);
    return (0);
}