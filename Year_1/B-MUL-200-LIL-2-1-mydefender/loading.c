/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** loading
*/

#include "defender.h"

int load_textures(st_def *st)
{
    st->texm.fond = sfTexture_createFromFile("pic/main/fond.jpg", NULL);
    if (!st->texm.fond)
        return (84);
    st->texm.main = sfTexture_createFromFile("pic/main/logo.png", NULL);
    if (!st->texm.main)
        return (84);
    st->texm.play = sfTexture_createFromFile("pic/main/menu.png", NULL);
    if (!st->texm.play)
        return (84);
    st->texm.option = sfTexture_createFromFile("pic/main/menu.png", NULL);
    if (!st->texm.option)
        return (84);
    st->texm.exit = sfTexture_createFromFile("pic/main/menu.png", NULL);
    if (!st->texm.exit)
        return (84);
    return (0);
}

int load_textures2(st_def *st)
{
    st->texg.bg = sfTexture_createFromFile("pic/game/bg.png", NULL);
    if (!st->texg.bg)
        return (84);
    st->texg.sun = sfTexture_createFromFile("pic/game/sun.png", NULL);
    if (!st->texg.sun)
        return (84);
    st->texg.mine = sfTexture_createFromFile("pic/pers/mine.png", NULL);
    if (!st->texg.mine)
        return (84);
    st->texg.zomb = sfTexture_createFromFile("pic/pers/zombie.png", NULL);
    if (!st->texg.zomb)
        return (84);
    st->texg.pea = sfTexture_createFromFile("pic/pers/pea.png", NULL);
    if (!st->texg.pea)
        return (84);
    st->texg.heart = sfTexture_createFromFile("pic/game/heart.png", NULL);
    if (!st->texg.heart)
        return (84);
    return (0);
}

int load_musics(st_def *st)
{
    st->music.main_menu = sfMusic_createFromFile("musics/main_menu.ogg");
    if (!st->music.main_menu)
        return (84);
    st->music.stage = sfMusic_createFromFile("musics/stage.ogg");
    if (!st->music.stage)
        return (84);
    st->music.clic = sfMusic_createFromFile("musics/clic.ogg");
    if (!st->music.clic)
        return (84);
    return (0);
}

int load_texts(st_def *st)
{
    st->text.font = sfFont_createFromFile("font/Pixeled.ttf");
    if (!st->text.font)
        return (84);
    return (0);
}

int load_var(st_def *st)
{
    st->name = "Plants. vs Zombies. (version Wish)";
    if (load_textures(st) == 84)
        return (84);
    if (load_textures2(st) == 84)
        return (84);
    if (load_textures3(st) == 84)
        return (84);
    if (load_musics(st) == 84)
        return (84);
    if (load_texts(st) == 84)
        return (84);
    load_sprites(st);
    return (0);
}
