/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** asm
*/

#ifndef ASM_H
#define ASM_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

enum {
    LABEL,
    INSTRUCTION,
    IGNORE
};

enum {
    INSTR_CODE,
    ARG_CODE,
    BYTE_CODE,
    LABEL_CODE,
    TO_FIND
};

enum {
    REGISTER,
    DIRECT_VALUE,
    INDIRECT_VALUE
};

typedef struct file_s {
    int line;
    char *data;
    struct file_s *next;
} file_t;

typedef struct content_s {
    file_t *top;
    file_t *current;
} content_t;

typedef struct data_s {
    int d_type;
    int size;
    char *to_find;
    unsigned char *data;
    struct data_s *next;
} data_t;

static const char *reg = "01";
static const char *dir = "10";
static const char *ind = "11";

static const int ACC_R = 00400 | 00200 | 00040 | 00020 | 00004;

typedef struct header_s header_t;

void my_rev_list(file_t **begin);
char *clear_str(char *str);
int translate(char *filepath);
char *get_o_filepath(char *filepath);
int get_file(file_t **ptr, char *filepath);
char *get_arg_type(char *arg, content_t *info);
int pars_line(content_t *file, char *o_filepath);
int encode(char **av, data_t **prgm, content_t *info);
int error_msg(char *error, int line);
int get_instr_code(char **av);
int find_str(file_t *top, char *str);
char *get_arg_size(char **av, content_t *info, int instr_code);
void my_rev_list_data(data_t **begin);
int write_data(data_t **prgm, int value, int instruction);
int write_bytes(data_t **prgm, char *arg, int size);
int write_neg_bytes_in_buf(data_t **node, int value);
int write_bytes_in_buf(data_t **node, int value);
int write_arg(char **av, data_t **prgm, char *arg_size);
int add_label(data_t **prgm, char *label);
int add_to_find(data_t **prgm, char *arg);
int get_idx_label(data_t *prgm, char *to_find);
void split_by_bytes(data_t **node, char *nb, int mod);
char *move_nbr_in_str(char *nb);
int encode_label(data_t **prgm);
char *dec_to_bin(int nb, char *res);
int get_header(data_t **prgm, content_t *info, char *o_filepath);
void destroy_file(content_t *info);
void write_prgm_in_file(int fd, data_t *prgm);
void write_header_in_file(int fd, header_t *hd);
void write_comment_in_file(int fd, header_t *hd);
void destroy_content(content_t *info);
void destroy_data(data_t **ptr);
void destroy_arr(char **array);

#endif