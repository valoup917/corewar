/*
** EPITECH PROJECT, 2021
** read champ
** File description:
** .
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "corewar.h"

char *read_champ(char *champ)
{
    char *buffer = malloc(sizeof(char) * 1000000);
    int fd = open(champ, O_RDONLY);

    if (!buffer)
        exit(84);
    if (fd == -1)
        exit(84);
    if (read(fd, buffer, 3000) <= 0)
        return my_strdup("c'est null");
    close(fd);
    return buffer;
}

void read_all(char **argv, champ_t *champ)
{
    for (;champ; champ = champ->next) {
        champ->instructions = read_champ(champ->name);
    }
    (void)argv;
    return;
}
