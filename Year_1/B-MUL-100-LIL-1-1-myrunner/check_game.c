/*
** EPITECH PROJECT, 2021
** projets
** File description:
** check_game
*/

#include "include/struct.h"

void checking1(void)
{

    if (var.coo.wall.x < var.coo.perso.x + 20 &&
    var.coo.wall.x > var.coo.perso.x && var.coo.perso.y == 601) {
        var.game = 0;
        var.finish = 1;
        sfRenderWindow_close(var.data.window);
    }
    if (var.coo.wall2.x < var.coo.perso.x + 20 &&
    var.coo.wall2.x > var.coo.perso.x && var.coo.perso.y == 601) {
        var.game = 0;
        var.finish = 1;
        sfRenderWindow_close(var.data.window);
    }

}

void checking2(void)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(var.clock.total)) > 120 ||
        var.text.change == 50) {
        var.game = 0;
        var.finish = 0;
        sfRenderWindow_close(var.data.window);
    }
    if ((var.coo.perso.x > var.coo.mob.x ||
    var.coo.perso.x > var.coo.mb2.x) && var.coo.perso.y == 601) {
        var.game = 0;
        var.finish = 1;
        sfRenderWindow_close(var.data.window);
    }
}

void check_game(void)
{
    checking1();
    checking2();
}

