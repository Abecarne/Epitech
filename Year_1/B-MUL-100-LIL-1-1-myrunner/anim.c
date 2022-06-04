/*
** EPITECH PROJECT, 2020
** projets
** File description:
** animations
*/

#include "include/struct.h"
#include "include/my.h"

void jump(sfRenderWindow* window, sfEvent event)
{
    if ((event.key.type == sfEvtKeyPressed) && (event.key.code == sfKeySpace)) {
        if (sfMusic_getStatus(var.music.jump) == sfPlaying)
            sfMusic_stop(var.music.jump);
        sfMusic_play(var.music.jump);
        var.coo.perso.y = 501;
        sfSprite_setPosition(var.sprite.perso, var.coo.perso);
        sfRenderWindow_drawSprite(window, var.sprite.perso, NULL);
    }
    if ((event.type == sfEvtKeyReleased) && (event.key.code == sfKeySpace)) {
        var.coo.perso.y = 601;
        sfSprite_setPosition(var.sprite.perso, var.coo.perso);
        sfRenderWindow_drawSprite(window, var.sprite.perso, NULL);
    }
}
