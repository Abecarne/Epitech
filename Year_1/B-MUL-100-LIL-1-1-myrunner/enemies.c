/*
** EPITECH PROJECT, 2020
** projets
** File description:
** help
*/

#include "include/struct.h"
#include "include/my.h"

void random_mob(int i)
{
    srand(time(NULL));
    int min = 1750;
    int max = 1750 * 2 - 100;

    if (i == 0)
        var.coo.mob.x = (rand() %  (max - min) + 1) + min;
    else if (i == 1)
        var.coo.mb2.x = (rand() % (max - min) + 1) + min;
    sfSprite_setPosition(var.sprite.mob, var.coo.mob);
    sfSprite_setPosition(var.sprite.mb2, var.coo.mb2);
}

void move_mob(void)
{
    int xfire = sfSprite_getPosition(var.sprite.ball).x;
    int yfire = sfSprite_getPosition(var.sprite.ball).y;

    if (sfTime_asMilliseconds(sfClock_getElapsedTime(var.clock.mv_mob)) > 5) {
        var.coo.mob.x -= 4;
        sfSprite_setPosition(var.sprite.mob, var.coo.mob);
        var.coo.mb2.x -= 5;
        sfSprite_setPosition(var.sprite.mb2, var.coo.mb2);
        sfClock_restart(var.clock.mv_mob);
    }
    if (var.coo.mob.x < -100 || ((xfire > var.coo.mob.x && var.fireball == 1) &&
    (yfire == 551))) {
        random_mob(0);
        var.text.change++;
    }
    if (var.coo.mb2.x < -100 || ((xfire > var.coo.mb2.x && var.fireball == 1) &&
    (yfire == 551))) {
        random_mob(1);
        var.text.change++;
    }
}

void change_mob(void)
{
    var.mob.height = 90;
    var.mob.width = 80;
    var.mob.left = 40 + var.change_mob * 90 - 90;
    var.mob.top = 15;
    sfSprite_setTexture(var.sprite.mob, var.tex.mob, sfFalse);
    sfSprite_setTextureRect(var.sprite.mob, var.mob);
    sfSprite_setPosition(var.sprite.mob, var.coo.mob);
    sfSprite_setTexture(var.sprite.mb2, var.tex.mob, sfFalse);
    sfSprite_setTextureRect(var.sprite.mb2, var.mob);
    sfSprite_setPosition(var.sprite.mb2, var.coo.mb2);
}

void update_mob(sfClock *clock, int tps)
{
    change_mob();
    if ((sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > tps)) {
        var.change_mob = (var.change_mob % 2) + 1;
        change_mob();
        sfClock_restart(clock);
    }
    move_mob();
}

void display_mob(sfRenderWindow *win, sfClock *clock)
{
    update_mob(clock, 200);
    sfRenderWindow_drawSprite(win, var.sprite.mob, NULL);
    sfRenderWindow_drawSprite(win, var.sprite.mb2, NULL);
}