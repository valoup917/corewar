/*
** EPITECH PROJECT, 2021
** set_memory
** File description:
** .
*/

#include "corewar.h"
#include "op.h"

void free_all(game_t *game, champ_t *champ)
{
    for (; champ; champ = champ->next) {
        free(champ);
        free(champ->name);
    }
    free(champ);
    free(game->memory);
    free(game);
}

void print_memory(char *memory)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        write(1, &memory[i], 1);
    }
    write(1, "\n", 1);
}

static game_t *set_memory_struct(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        exit(84);
    game->memory = malloc(sizeof(char) * MEM_SIZE);
    if (!game->memory)
        exit(84);
    for (int i = 0; i < MEM_SIZE; i += 1) {
        game->memory[i] = '0';
    }
    game->dump_memory = 0;
    game->memory[MEM_SIZE - 1] = '\0';
    return game;
}

void set_all(int argc, char **argv)
{
    (void)argc;
    game_t *game = set_memory_struct();
    champ_t *champ = NULL;

    champ = pars_arg(argv, game, champ);
    read_all(argv, champ);
    free_all(game, champ);
}