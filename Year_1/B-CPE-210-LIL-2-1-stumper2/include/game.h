/*
** EPITECH PROJECT, 2021
** game.h
** File description:
** game
*/

#include "my.h"
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>

bool is_intarg(char *str);
void free_all(char **map);
int get_map_len(char *path);
char **get_map_from_file(char *path);
int check_null(int x, int y, char **map);
char **error_handling(int ac, char **av, char **map);
