/*
** EPITECH PROJECT, 2020
** projets
** File description:
** help
*/

#include "include/struct.h"
#include "include/my.h"

void reload(void)
{
    if ((var.data.event.type == sfEvtMouseButtonPressed) && var.shoot == 0)
        if (var.data.event.key.code == sfMouseRight)
            var.shoot = 1;
}

void shoot(void)
{
    if ((var.data.event.type == sfEvtMouseButtonPressed))
        if (var.data.event.key.code == sfMouseLeft && var.shoot == 1) {
            sfMusic_play(var.music.fire);
            var.fireball = 1;
        }
}

void fireball(sfRenderWindow* window)
{
    var.coo.ball.y = sfSprite_getPosition(var.sprite.perso).y - 50;
    sfSprite_setPosition(var.sprite.ball, var.coo.ball);
    if (sfTime_asMicroseconds(sfClock_getElapsedTime(var.clock.ball)) > 1) {
        var.coo.ball.x += 10;
        sfSprite_setPosition(var.sprite.ball, var.coo.ball);
        sfRenderWindow_drawSprite(var.data.window, var.sprite.ball, NULL);
        sfClock_restart(var.clock.ball);
    }
    if (var.coo.ball.x > 1750) {
        var.coo.ball.x = 10;
        sfSprite_setPosition(var.sprite.ball, var.coo.ball);
        var.fireball = 0;
        var.shoot = 0;
    }
}
