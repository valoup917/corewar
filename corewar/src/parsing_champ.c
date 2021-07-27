/*
** EPITECH PROJECT, 2021
** parisng champ
** File description:
** .
*/

#include "corewar.h"

int find_nbr(char **argv, int i, champ_t *champ)
{
    int nbr = 0;

    if (check_extension(argv[i - 1]))
        return 0;
    if (argv[i - 2][0] == '-' && argv[i - 2][1] == 'n') {
        nbr = my_getnbr(argv[i - 1]);
        for (; champ; champ = champ->next) {
            if (champ->nbr == nbr) {
                write(2, "You can't choose the same -n for two champs\n", 45);
                exit(84);
            }
        }
        return nbr;
    }
    return 0;
}

int find_n_pos(char **argv, int i)
{
    if (argv[i - 2][0] == '-' && argv[i - 2][1] == 'a')
        return 1;
    if (argv[i - 4][0] == '-' && argv[i - 4][1] == 'a')
        return 3;
    return 0;
}

int find_pos(char **argv, int i, champ_t *champ)
{
    int pos = 0;
    int a = find_n_pos(argv, i);

    if (check_extension(argv[i - 1]))
        return 0;
    if (a) {
        pos = my_getnbr(argv[i - a]);
        for (; champ; champ = champ->next) {
            if (champ->pos == pos) {
                write(2, "You can't choose the same -a for two champs\n", 45);
                exit(84);
            }
        }
        return pos;
    }
    return 0;
}