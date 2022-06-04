/*
** EPITECH PROJECT, 2020
** projets
** File description:
** perso
*/

#include "include/struct.h"
#include "include/my.h"

void background(sfRenderWindow *win)
{
    disp_cloud(win);
    disp_mountain(win);
    disp_bush(win);
}

void disp_cloud(sfRenderWindow *win)
{
    cloud1(win, var.clock.cloud);
    cloud2(win, var.clock.cloud);
    cloud3(win, var.clock.cloud);
}

void disp_mountain(sfRenderWindow *win)
{
    mountain1(win, var.clock.mountain);
    mountain2(win, var.clock.mountain);
    mountain3(win, var.clock.mountain);
}

void disp_bush(sfRenderWindow *win)
{
    bush1(win, var.clock.bush);
    bush2(win, var.clock.bush);
    bush3(win, var.clock.bush);
}
