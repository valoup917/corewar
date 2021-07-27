/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** .
*/

#ifndef COREWAR
#define COREWAR

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h> // a supprimer

typedef struct game_s
{
    int dump_memory;
    char *memory;
} game_t;

typedef struct champ_s
{
    char **registre;
    int nbr;
    int pos;
    char *name;
    char *instructions;
    struct champ_s *next;
} champ_t;

// DEFINITIONS

// lib
char *my_strcpy(char *dest, char const *src);
int my_getnbr(char *str);
int my_strlen(const char *str);
char *my_strdup(char const *src);
int my_strcmp(char const *s1, char const *s2);

// parsing_champs_orga.c
champ_t *pars_champ(char **argv, game_t *game, champ_t *champ);
int check_extension(char const *champ);

// parsing_champs.c
int find_nbr(char **argv, int i, champ_t *champ);
int find_n_pos(char **argv, int i);
int find_pos(char **argv, int i, champ_t *champ);

// parsing_args.c
int check_dump_string(char *str);
champ_t *pars_arg(char **argv, game_t *game, champ_t *champ);

// set_memory.c
void free_all(game_t *game, champ_t *champ);
void print_memory(char *memory);
void set_all(int argc, char **argv);

//init_list_champ.c
champ_t *add_champ(champ_t *champ, int nbr, int pos, char *name);

// read_champ.c
char *read_champ(char *champ);
void read_all(char **argv, champ_t *champ);

#endif /* !COREWAR */