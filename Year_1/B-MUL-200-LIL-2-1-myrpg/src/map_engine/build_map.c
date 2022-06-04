/*
** EPITECH PROJECT, 2021
** build_map.c
** File description:
** build map
*/

#include "my.h"
#include "framing_engine.h"

int next_len(char *av)
{
    int i = 0;

    for (; av[i] != '\0' && av[i] != '\n'; i++);
    return (i);
}

int get_str_len(char *av)
{
    int len = 0;
    int size = 0;

    for (int i = 0; av[i] != '\0'; i += len + 1) {
        len = next_len(&av[i]);
        size++;
        if (av[i + len] == '\0')
            len--;
    }
    return (size);
}

int concat(char *dest, char *src)
{
    int i = 0;

    for (; src[i] != '\0' && src[i] != '\n'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (0);
}

int build_map(framing *lvl, char *buff, char *path)
{
    int size = get_str_len(buff);
    int len = 0;
    int j = 0;

    lvl->map = malloc(sizeof(char *) * (size + 1));
    if (lvl->map == NULL)
        return (unload_map(lvl));
    for (int i = 0; buff[i] != '\0'; i += len + 1) {
        len = next_len(&buff[i]);
        lvl->map[j] = malloc(sizeof(char) * (len + 1));
        if (lvl->map[j] == NULL || concat(lvl->map[j], &buff[i]) != 0)
            return (unload_map(lvl, 1));
        j++;
        if (buff[i + len] == '\0')
            len--;
    }
    lvl->map[j] = NULL;
    lvl->map[player_y][player_x] = 'P';
    return (prepare_txt(lvl, path));
}
