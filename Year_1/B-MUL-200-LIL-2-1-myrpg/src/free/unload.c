/*
** EPITECH PROJECT, 2021
** unload.c
** File description:
** unload
*/

#include "my.h"
#include "framing_engine.h"

int unload_map(framing *lvl)
{
    if (lvl->map != NULL)
        lvl->map = free_str(lvl->map);
    sfSprite_Destroy(lvl->map_txt.sprite);
    sfTexture_destroy(lvl->map_txt.txt);
    return (0);
}

int unload_framing(framing *lvl)
{
    if (lvl->buffer != NULL)
        lvl->buffer = my_free(lvl->buffer);
    if (lvl->map != NULL)
        lvl->map = free_str(lvl->map);
    if (lvl->save_map != NULL)
        lvl->save_map = free_str(lvl->save_map);
    if (lvl->src_map != NULL)
        lvl->src_map = free_str(lvl->src_map);
    return (84);
}
