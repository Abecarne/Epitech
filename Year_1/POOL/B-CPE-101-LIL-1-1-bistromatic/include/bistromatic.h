/*
** EPITECH PROJECT, 2020
** B-CPE-101-LIL-1-1-bistromatic-anthony.becarne
** File description:
** bistromatic
*/

#define OP_OPEN_PARENT_IDX  0
#define OP_CLOSE_PARENT_IDX 1
#define OP_PLUS_IDX         2
#define OP_SUB_IDX          3
#define OP_NEG_IDX          3
#define OP_MULT_IDX         4
#define OP_DIV_IDX          5
#define OP_MOD_IDX          6

#define EXIT_USAGE    84
#define EXIT_BASE     84
#define EXIT_SIZE_NEG 84
#define EXIT_MALLOC   84
#define EXIT_READ     84
#define EXIT_OPS      84

#define SYNTAX_ERROR_MSG "syntax error"
#define ERROR_MSG        "error"

typedef struct variable {
    int l1;
    int l2;
    int l_max;
    int l_min;
    int i;
    int k;
    int ret;
    int tmp;
    int end;
} var_t;

char *eval_expr(char *str);
char *bistro(char **av, char *expr, int size);
char *change_str(char *str, char *base, char const *ref);
int error_same_base_op(char **av);
int error_paren(char *buff);
int do_check_error(char **av, char *buff);