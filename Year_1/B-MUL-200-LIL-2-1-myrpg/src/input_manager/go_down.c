/*
** EPITECH PROJECT, 2020
** go_right.c
** File description:
** go right
*/

#include "my.h"
#include "framing_engine.h"

void map_down(framing *lvl)
{
    int seconde = 1000000;
    int t = sfClock_getElapsedTime(lvl->player.clock).microseconds;
    int add = 0;

    if (t * seconde > 0.5)
        lvl->player.clock = sfClock_restart();
    for (int i = 0; i < 8; i++) {
        t = sfClock_getElapsedTime(lvl->player.clock).microseconds;
        if (t * seconde > 0.0625) {
            lvl->player_txt.animation = i % 4;
            lvl->player.clock = sfClock_restart();
            lvl->map_txt.y += 16;
        }
        draw_map(lvl);
    }
}

void player_down(framing *lvl)
{
    int seconde = 1000000;
    int t = sfClock_getElapsedTime(lvl->player.clock).microseconds;
    int add = 0;

    if (t * seconde > 0.5)
        lvl->player.clock = sfClock_restart();
    for (int i = 0; i < 8; i++) {
        t = sfClock_getElapsedTime(lvl->player.clock).microseconds;
        if (t * seconde > 0.0625) {
            lvl->player_txt.animation = i % 4;
            lvl->player.clock = sfClock_restart();
            lvl->player_txt.y += 16;
        }
        draw_map(lvl);
    }
}

void annim_down(framing *lvl)
{
    int h = lvl->map_height[lvl->selected_map];
    int pos = (8 * 128) - (h * 128);

    if (lvl->player_txt.y == 512)
        lvl->player_center_v = 1;
    else
        lvl->player_center_v = 0;
    if (lvl->map_txt.y == pos)
        player_down(lvl);
    if (lvl->map_txt.y > pos && lvl->player_center_v == 1)
        map_down(lvl);
}

int go_down(framing *lvl)
{
    int x = lvl->player_x;
    int y = lvl->player_y;

    lvl->player_txt.status = 0;
    if (x > 0 && lvl->save_map[y + 1][x] == ' ') {
        lvl->map[y][x] = lvl->save_map[y][x];
        lvl->map[y + 1][x] = 'P';
        lvl->player_x--;
        annim_down(lvl);
    }
    if (x > 0 && lvl->save_map[y + 1][x] != ' ') {
        lvl->map[y][x] = lvl->save_map[y][x];
        lvl->map[y + 1][x] = 'P';
        lvl->player_x--;
        other_action(lvl, x, y + 1);
    }
    return (0);
}
