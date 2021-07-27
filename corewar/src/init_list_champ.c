/*
** EPITECH PROJECT, 2021
** init champ
** File description:
** .
*/

#include "corewar.h"
#include "op.h"

int nbr_champ_list(champ_t *champ)
{
    int a = 0;

    for (; champ; champ = champ->next)
        a++;
    return a;
}

int chop(int a, champ_t *champ)
{
    for (; champ; champ = champ->next) {
        if (a == champ->nbr) {
            return 1;
        }
    }
    return 0;
}

int choose_champ_nbr(champ_t *champ)
{
    int i = 0;

    if (!champ)
        return 1;
    for (int a = 1; a < 300; a++) {
        i = chop(a, champ);
        if (i == 0)
            return a;
    }
    return 0;
}

static champ_t *set_node_champ(int nbr, int pos, char *name)
{
    champ_t *champ = malloc(sizeof(champ_t));
    int i = 0;

    if (!champ)
        exit(84);
    champ->nbr = nbr;
    champ->pos = pos;
    champ->registre = malloc(sizeof(char *) * (REG_NUMBER + 1));
    for (; i != REG_NUMBER + 1; i++) {
        champ->registre[i] = malloc(sizeof(char) * REG_SIZE);
    }
    champ->registre[REG_NUMBER] = NULL;
    champ->name = malloc(sizeof(char) * my_strlen(name) + 1);
    my_strcpy(champ->name, name);
    champ->next = NULL;
    return champ;
}

champ_t *add_champ(champ_t *champ, int nbr, int pos, char *name)
{
    if (!nbr)
        nbr = choose_champ_nbr(champ);
    champ_t *new_champ = set_node_champ(nbr, pos, name);

    if (!champ)
        return new_champ;
    new_champ->next = champ;
    return new_champ;
}
