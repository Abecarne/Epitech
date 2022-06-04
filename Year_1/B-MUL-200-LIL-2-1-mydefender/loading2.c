/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** loading2
*/

#include "include/defender.h"

int load_textures3(st_def *st)
{
    st->texg.multi = sfTexture_createFromFile("pic/pers/multi.png", NULL);
    if (!st->texg.multi)
        return (84);
    st->texg.dbl = sfTexture_createFromFile("pic/pers/double.png", NULL);
    if (!st->texg.dbl)
        return (84);
    return (0);
}