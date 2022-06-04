/*
** EPITECH PROJECT, 2020
** projets
** File description:
** perso
*/

#include "include/struct.h"
#include "include/my.h"

void clocks(void)
{
    var.clock.time = sfClock_create();
    var.clock.total = sfClock_create();
    var.clock.perso = sfClock_create();
    var.clock.floor = sfClock_create();
    var.clock.cloud = sfClock_create();
    var.clock.mountain = sfClock_create();
    var.clock.bush = sfClock_create();
    var.clock.mob = sfClock_create();
    var.clock.ball = sfClock_create();
    var.clock.mv_mob = sfClock_create();
    var.text.change = 0;
    var.finish = 2;
}

void texts(void)
{
    var.text.font = sfFont_createFromFile("font/Pixeled.ttf");
    var.text.score = sfText_create();
    var.text.value = sfText_create();
    var.text.win = sfText_create();
    var.text.lose = sfText_create();
    sfText_setFont(var.text.score, var.text.font);
    sfText_setFont(var.text.value, var.text.font);
    sfText_setFont(var.text.win, var.text.font);
    sfText_setFont(var.text.lose, var.text.font);
    var.text.change = 0;
    var.coo.ball.x = 10;
    var.coo.ball.y = 595;
    var.coo.mob.x = 1600;
    var.coo.mob.y = 594;
    var.coo.mb2.x = 2500;
    var.coo.mb2.y = 594;
    var.coo.wall.x = 1900;
    var.coo.wall.y = 614;
    var.coo.wall2.x = 2800;
    var.coo.wall2.y = 614;
}

void positions(void)
{
    var.coo.perso.x = 50;
    var.coo.perso.y = 601;
    var.coo.cloud1.x = 0;
    var.coo.cloud1.y = 10;
    var.coo.cloud2.x = 840;
    var.coo.cloud2.y = 10;
    var.coo.cloud3.x = 1680;
    var.coo.cloud3.y = 0;
    var.coo.mountain1.x = 0;
    var.coo.mountain1.y = 322;
    var.coo.mountain2.x = 840;
    var.coo.mountain2.y = 322;
    var.coo.mountain3.x = 1680;
    var.coo.mountain3.y = 322;
    var.coo.bush1.x = 0;
    var.coo.bush1.y = 407;
    var.coo.bush2.x = 840;
    var.coo.bush2.y = 407;
    var.coo.bush3.x = 1680;
    var.coo.bush3.y = 407;
}
