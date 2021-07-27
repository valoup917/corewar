/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** lib
*/

#ifndef LIB_H
#define LIB_H

int my_strcmp(char const *s1, char const *s2);
void my_putstr(char const *str);
char my_strncmp(char const *s1, char const *s2, int n);
int isnumber(char *str);
char *my_strdup(char const *src);
int my_strlen(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
char **my_str_to_word_array(char *str);
int my_put_nbr(int nb, int fd);
int my_arrlen(char **av);
int my_atoi(char *str);
int bin_to_dec(char *num);
char *my_revstr(char *str);

#endif