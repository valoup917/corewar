/*
** EPITECH PROJECT, 2021
** arg_type
** File description:
** arg_type
*/

#include "asm.h"
#include "op.h"
#include "lib.h"

char *check_indir(char *arg, content_t *info)
{
    if (arg[0] == LABEL_CHAR) {
        if (!find_str(info->top, arg)) {
            error_msg("Unknown label", info->current->line);
            return (NULL);
        }
        return ("11");
    }
    arg += 1;
    if (isnumber(arg)) {
        error_msg("Invalid value", info->current->line);
        return (NULL);
    }
    return ("11");
}

char *check_dir(char *arg, content_t *info)
{
    arg += 1;
    if (arg[0] == LABEL_CHAR && !find_str(info->top, arg)) {
        error_msg("Unknown label", info->current->line);
        return (NULL);
    }
    if (arg[0] != LABEL_CHAR) {
        if (isnumber(arg)) {
            error_msg("Invalid direct value", info->current->line);
            return (NULL);
        }
    }
    return ("10");
}

char *get_arg_type(char *arg, content_t *info)
{
    int value = 0;

    if (arg[0] == 'r') {
        arg += 1;
        value = my_atoi(arg);
        if (value > REG_NUMBER || value < 1) {
            error_msg("Invalid register number", info->current->line);
            return (NULL);
        }
        return ("01");
    } else if (arg[0] == '%') {
        return (check_dir(arg, info));
    } else if (arg[0] == ':' || !isnumber(arg))
        return (check_indir(arg, info));
    return (NULL);
}