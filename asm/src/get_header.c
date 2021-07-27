/*
** EPITECH PROJECT, 2021
** get_header
** File description:
** get_header
*/

#include "asm.h"
#include "op.h"
#include "lib.h"

int hd_get_content(char *str, header_t *hd, int line)
{
    char **av = my_str_to_word_array(str);

    if (av == NULL)
        return (-1);
    if (!my_strcmp(av[0], ".name") && my_arrlen(av) == 2) {
        if (my_strlen(av[1]) - 2 > PROG_NAME_LENGTH)
            return (error_msg("The progam name is too long", line));
        av[1] += 1;
        av[1][my_strlen(av[1]) - 1] = '\0';
        my_strcpy(hd->prog_name, av[1]);
    } else if (!my_strcmp(av[0], ".comment") && my_arrlen(av) == 2) {
        if (my_strlen(av[1]) - 2 > COMMENT_LENGTH)
            return (error_msg("The progam comment is too long", line));
        av[1] += 1;
        av[1][my_strlen(av[1]) - 1] = '\0';
        my_strcpy(hd->comment, av[1]);
    } else
        return (error_msg("Invalid instruction", line));
    free(av);
    return (0);
}

int get_name_comment(content_t *info, header_t *hd)
{
    file_t *top = info->top;
    int tmp = 0;

    while (top->next != NULL) {
        if (!my_strncmp(top->data, ".name", 5)) {
            hd_get_content(top->data, hd, top->line);
            tmp += 1;
        } else if (!my_strncmp(top->data, ".comment", 8)) {
            hd_get_content(top->data, hd, top->line);
            tmp += 2;
        }
        if (tmp == 2)
            return (error_msg("Name must be before comment", top->line));
        top = top->next;
    }
    if (tmp != 3)
        return (error_msg("Missing name or comment instruction", -1));
    return (0);
}

void get_prgm_size(data_t **prgm, header_t *hd)
{
    data_t *top = *prgm;
    int i = 0;

    while (*prgm != NULL) {
        if ((*prgm)->d_type == ARG_CODE || (*prgm)->d_type == INSTR_CODE
            || (*prgm)->d_type == BYTE_CODE)
            i += 1;
        if ((*prgm)->d_type == TO_FIND)
            i += (*prgm)->size;
        *prgm = (*prgm)->next;
    }
    *prgm = top;
    hd->prog_size = i;
}

int get_header(data_t **prgm, content_t *info, char *o_filepath)
{
    header_t hd;
    int fd = 0;
    data_t *tmp = *prgm;

    if (get_name_comment(info, &hd) == -1)
        return (-1);
    for (int i = my_strlen(hd.prog_name); i < PROG_NAME_LENGTH; i++)
        hd.prog_name[i] = '\0';
    for (int i = my_strlen(hd.comment); i < COMMENT_LENGTH; i++)
        hd.comment[i] = '\0';
    get_prgm_size(prgm, &hd);
    fd = open(o_filepath, O_CREAT | O_TRUNC | O_RDWR, ACC_R);
    if (fd == -1)
        return (error_msg("Probleme with open", 0));
    write_header_in_file(fd, &hd);
    while (tmp != NULL) {
        write_prgm_in_file(fd, tmp);
        tmp = tmp->next;
    }
    return (0);
}