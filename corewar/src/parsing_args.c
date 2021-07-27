/*
** EPITECH PROJECT, 2021
** parsing_args
** File description:
** .
*/

#include "corewar.h"

int check_int(char *str)
{
    if (my_strlen(str) > 10)
        return 1;
    if (my_strlen(str) == 10 && (str[0] > '2' || str[1] > '1' || str[2] > '7'
        || str[3] > '4' || str[4] > '8' || str[5] > '3' || str[6] > '6'
        || str[7] > '4' || str[8] > '7'))
        return 1;
    return 0;
}

int check_dump_string(char *str)
{
    for (unsigned int i = 0; str[i]; i += 1) {
        if (str[i] > '9' || str[i] < '0') {
            write(2, "bad arguments\n", 15);
            return 1;
        }
        if (check_int(str)) {
            write(2, "-dump cycle_nbr too big\n", 25);
            return 1;
        }
        if (my_getnbr(str) == 0) {
            write(2, "-dump can't be 0\n", 18);
            return 1;
        }
    }
    return 0;
}

static void pars_dump(char **argv, game_t *game, champ_t *champ)
{
    unsigned int i = 0;

    for (; argv[i]; i += 1) {
        if (!my_strcmp(argv[i], "-dump") && argv[i + 1])
            break;
    }
    if (!argv[i])
        return;
    i += 1;
    if (check_dump_string(argv[i])) {
        free_all(game, champ);
        exit(84);
    }
    game->dump_memory = my_getnbr(argv[i]);
}

champ_t *pars_arg(char **argv, game_t *game, champ_t *champ)
{
    pars_dump(argv, game, champ);
    champ = pars_champ(argv, game, champ);
    return champ;
}