/*
** EPITECH PROJECT, 2021
** map.c
** File description:
** Duo stumper 2
*/

#include "include/game.h"

int get_map_len(char *path)
{
    int fd = open(path, O_RDONLY);
    struct stat file;
    char *str = NULL;
    int len = 0;

    if (fd == -1)
        exit(my_putstr_error("Error : wrong filepath.\n"));
    stat(path, &file);
    str = malloc(sizeof(char) * file.st_size);
    read(fd, str, file.st_size);
    for (int a = 0; a < file.st_size; a++)
        if (str[a] == '\n')
            len++;
    for (int i = 0; i < file.st_size; i++)
        if (str[i] != '.' && str[i] != '\n' && str[i] != 'X')
            exit(my_putstr_error("Error : the map is invalid.\n"));
    return (len);
}

char **get_map_from_file(char *path)
{
    char **map = malloc(sizeof(char *) * (get_map_len(path) + 1));
    char *line = NULL;
    size_t size = 0;
    FILE *fp = fopen(path, "r");
    int i = 0;

    while (getline(&line, &size, fp) != -1) {
        map[i] = my_strcpy(line);
        i++;
    }
    map[get_map_len(path)] = NULL;
    for (int i = 0; map[i +  1] != NULL; i++)
        if (my_strlen(map[i]) != my_strlen(map[i + 1])) {
            my_putstr_error("Error : wrong map.\n");
            return (NULL);
        }
    return (map);
}

void print_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        printw("%s", map[i]);
}