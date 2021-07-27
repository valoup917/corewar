/*
** EPITECH PROJECT, 2021
** parsing champ
** File description:
** .
*/

#include "corewar.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int check_extension(char const *champ)
{
    int max = my_strlen(champ);

    return (champ[max] == 'r' && champ[max - 1] == 'o'
    && champ[max - 2] == 'c' && champ[max - 3] == '.');
}

static int check_acces(char const *champ)
{
    int fd = open(champ, O_RDONLY);

    if (fd == -1) {
        write(2, "Can't open the champ: ", 23);
        write(2, champ, my_strlen(champ));
        write(2, "\n", 1);
        return 1;
    }
    if (check_extension(champ)) {
        write(2, champ, my_strlen(champ));
        write(2, " : Isn't a '.cor' file", 21);
        return 1;
    }
    close(fd);
    return 0;
}

champ_t *pars_champ(char **argv, game_t *game, champ_t *champ)
{
    int nbr = 0;
    int pos = 0;

    for (unsigned int i = 1; argv[i]; i += 1) {
        if (argv[i][0] == '-') {
            i += 1;
            continue;
        }
        else {
            if (check_acces(argv[i])) {
                free_all(game, champ);
                exit(84);
            }
            nbr = find_nbr(argv, i, champ);
            pos = find_pos(argv, i, champ);
            champ = add_champ(champ, nbr, pos, argv[i]);
        }
    }
    return champ;
}