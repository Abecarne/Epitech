/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "my.h"
#include "framing_engine.h"

char *add_src_map(char *src, int x)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (dest == NULL)
        return (NULL);
    src[23] = x + 48;
    my_strcpy(dest, src);
    return (dest);
}

int load_src_map(framing *lvl)
{
    int i = 0;

    lvl->map_src = malloc(sizeof(char *) * (2 + 1));
    if (lvl->map_src == NULL)
        return (unload_framing(lvl));
    for (; i < 2; i++) {
        lvl->map_src[i] = add_src_map("src/map_engine/maps/mapx", i);
        if (lvl->map_src[i] == NULL)
            return (unload_framing(lvl));
    }
    lvl->map_src[i] = NULL;
    return (0);
}

int init_lvl(framing *lvl)
{
    lvl->exit = 0;
    lvl->size[0] = 1640;
    lvl->size[1] = 1000;
    lvl->map_height[0] = 40;
    lvl->map_height[2] = 48;
    lvl->map_large[0] = 40;
    lvl->map_large[1] = 48;
    lvl->player_y = 24;
    lvl->player_x = 19;
    lvl->src_map = NULL;
    lvl->map = NULL;
    lvl->save_map = NULL;
    lvl->buffer = NULL;
    if (load_src_map(lvl) != 0 || load_player(lvl) != 0
        || load_paserelle(lvl) != 0)
        return (84);
    return (0);
}
