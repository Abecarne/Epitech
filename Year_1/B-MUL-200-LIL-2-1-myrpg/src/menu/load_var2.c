/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** load_var2
*/

#include "menu.h"

int load_textures_perso(st_main_menu *st)
{
    st->txp->ennemi = sfTexture_createFromFile("res/sp/perso/en.png", sfFalse);
    if (!st->txp->ennemi)
        return (84);
    st->txp->perso = sfTexture_createFromFile("res/player.png", sfFalse);
    if (!st->txp->perso)
        return (84);
    st->txp->dos = sfTexture_createFromFile("res/sp/perso/dos.png", sfFalse);
    if (!st->txp->dos)
        return (84);
    return (0);
}