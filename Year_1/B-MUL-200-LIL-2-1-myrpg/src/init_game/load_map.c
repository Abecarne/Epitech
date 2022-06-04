/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "my.h"
#include "framing_engine.h"

int check_content(char *av)
{
    for (int i = 0; av[i] != '\0'; i++) {
        if (av[i] != 'X' && av[i] != ' ' && av[i] != '\n')
            return (my_put_error("Error: Invalid Map\n"));
    }
    return (0);
}

int build_save(framing *lvl)
{
    int size = 0;

    for (; lvl->map[size] != NULL; size++);
    lvl->save_map = malloc(sizeof(char *) * (size + 1));
    if (lvl->save_map == NULL)
        return (84);
    for (int i = 0; lvl->map[i] != NULL; i++) {
        lvl->save_map = malloc(sizeof(char) * (my_strlen(lvl->map[i]) + 1));
        if (lvl->save_map[i] == NULL)
            return (84);
        my_strcpy(lvl->save_map[i], lvl->map[i]);
        lvl->save_map[i + 1] = NULL;
    }
    return (0);
}

int load_map(framing *lvl, int src)
{
    int fd = open(path, O_RDONLY);

    if (fd == -1)
        return (my_put_error("Error: Map can't be open\n"));
    lvl->buffer = malloc(sizeof(char) * (lvl->size[src] + 1));
    if (lvl->buffer == NULL)
        return (unload_map(lvl, 0));
    read(fd, lvl->buffer, lvl->size[src]);
    lvl->buffer[lvl->size[src]] = '\0';
    close(fd);
    if (check_content(lvl->buffer) != 0 ||
        build_map(lvl, lvl->buffer, path) != 0 || build_save(lvl) != 0)
        return (unload_framing(lvl));
    lvl->buffer = my_free(lvl->buffer);
    lvl->map[lvl->player_y][lvl->player_x] = 'P';
    return (0);
}
