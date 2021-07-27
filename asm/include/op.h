/*
** EPITECH PROJECT, 2021
** B-CPE-201-PAR-2-1-corewar-valentin.fouillet
** File description:
** op
*/

#ifndef _OP_H_
#define _OP_H_

static const int MEM_SIZE = (6 * 1024);
/* modulo of the index < */
static const int IDX_MOD = 512;
/* this may not be changed 2^*IND_SIZE */
static const int MAX_ARGS_NUMBER = 4;

static const char COMMENT_CHAR = '#';
static const char LABEL_CHAR = ':';
static const char DIRECT_CHAR = '%';
static const char SEPARATOR_CHAR = ',';

static const char *LABEL_CHARS = "abcdefghijklmnopqrstuvwxyz_0123456789";

static const char *NAME_CMD_STRING = ".name";
static const char *COMMENT_CMD_STRING = ".comment";

/*
** regs
*/

/* r1 <--> rx */
static const int REG_NUMBER = 16;

/*
**
*/

/* register */
static const int T_REG = 1;
/* direct  (ld  #1,r1  put 1 into r1) */
static const int T_DIR = 2;
/* indirect always relative ( ld 1,r1 put what's in
the address (1+pc) into r1 (4 bytes )) */
static const int T_IND = 4;
/* LABEL */
static const int T_LAB = 8;

typedef struct op_s
{
    char *mnemonique;
    char nbr_args;
    char type[4];
    char code;
    int nbr_cycles;
    char *comment;
} op_t;

/*
** size (in bytes)
*/
static int IND_SIZE = 2;
static int DIR_SIZE = 4;
static int REG_SIZE = 4;

/*
** op_tab
*/
extern op_t op_tab[];

/*
** header
*/
static const int PROG_NAME_LENGTH = 128;
static const int COMMENT_LENGTH = 2048;
static const int COREWAR_EXEC_MAGIC = 0xea83f3;

typedef struct header_s
{
    char prog_name[128 + 1];
    int prog_size;
    char comment[2048 + 1];
} header_t;

/*
** live
*/

/* number of cycle before being declared dead */
static const int CYCLE_TO_DIE = 1536;
static const int CYCLE_DELTA = 5;
static const int NBR_LIVE = 40;

#endif
