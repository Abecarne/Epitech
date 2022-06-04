/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** minishell
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* Structure */
typedef struct minishell
{
    int a;
    int round;
    int builtin;
    int cm;
    int status;
    int return_value;
    char ***arg;
    char **env;
    char *input;
    char *current;
    char *previous;
}st_minishell;

/* Ptr sur fonctions */
typedef void (*command)(st_minishell *);

/* Clean */
char *clean_input(const char *str);

/* Init */
int breaker(st_minishell *st);
int error_handler(int ac, char **av);
int init_struct(st_minishell *st, char **env);

/* Modif */
char **parse(char *str);
int is_empty_line(char *str);
void rm_backslash(st_minishell *st);
char ***triple_parse(st_minishell *st);

/* cd */
void exec_cd(st_minishell *st);
void next_step(st_minishell *st);

/* Env */
void exec_env(st_minishell *st);
int error_setenv(st_minishell *st);
int error_unsetenv(st_minishell *st);
void exec_setenv(st_minishell *st);
void exec_unsetenv(st_minishell *st);
char *change_var(char *dest, char *src);
char **delete_var(st_minishell *st, char **src);
char **replace_var(st_minishell *st, char **copie);
int existing_var(const char *check, const char *s2);
char **create_var(st_minishell *st, char **tab, char *src);

/* Basic exec */
int execute(st_minishell *st);
char *check_valid_input(char *str);
void exec_builtin(st_minishell *st);
int check_builtin(st_minishell *st);

/* Path handling */
char **path(char **env);
int is_symbol(st_minishell *st);
char *create(char *path, char *cmd);
char *get_path(st_minishell *st, char **cmd);

/* Pipes */
int nb_pipe(char **tab);
void multi_pipe(st_minishell *st);
void pipe_handler(st_minishell *st);
char **get_cmd(st_minishell *st, char *src);
char **get_next_cmd(st_minishell *st, char *src);
void exec_cmd(st_minishell *st, char **cmd, int fd);
void simple_pipe(st_minishell *st, char **cmd1, int *fd, int status);
void special_pipe(st_minishell *st, char **cmd, int *fd, int status);
void prepare_pipe(st_minishell *st, char **cmd1, char **cmd2);

/* Redir */
int left_redir(st_minishell *st);
int many_redir(st_minishell *st);
int right_redir(st_minishell *st);
int symbol_redir(st_minishell *st);
int missing_name(st_minishell *st);
int ambiguous_cmd(st_minishell *st);
void double_right(st_minishell *st, char **cmd1, char **cmd2);
void simple_right(st_minishell *st, char **cmd1, char **cmd2);

#endif /* !MINISHELL_H_ */