/*
** EPITECH PROJECT, 2021
** write_in_file
** File description:
** write_in_file
*/

#include "asm.h"
#include "op.h"

void write_comment_in_file(int fd, header_t *hd)
{
    int len = 0;
    int nb = 0;

    if (hd->prog_size % 255 > 0)
        len = hd->prog_size / 255 + 1;
    else
        len = hd->prog_size / 255;
    for (int i = 0; i < 4 - len; i++)
        write(fd, &nb, len);
    write(fd, &(hd->prog_size), len);
    for (int i = 0; i < COMMENT_LENGTH; i++)
        write(fd, &(hd->comment[i]), 1);
    write(fd, "\0\0\0\0", 4);
}

void write_header_in_file(int fd, header_t *hd)
{
    int nb = 0;
    int len = 0;

    write(fd, "\0", 1);
    nb = COREWAR_EXEC_MAGIC;
    write(fd, &nb, 3);
    for (int i = 0; i < PROG_NAME_LENGTH; i++)
        write(fd, &(hd->prog_name[i]), 1);
    write(fd, "\0\0\0\0", 4);
    write_comment_in_file(fd, hd);
}

void write_prgm_in_file(int fd, data_t *prgm)
{
    if (prgm->d_type == LABEL_CODE)
        return;
    if (prgm->d_type == TO_FIND) {
        for (int i = 0; i < prgm->size; i++)
            write(fd, &(prgm->data[i]), 1);
    } else
        write(fd, &(prgm->data[0]), 1);
}