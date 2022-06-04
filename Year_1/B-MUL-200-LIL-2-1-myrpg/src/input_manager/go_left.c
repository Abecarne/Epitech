/*
** EPITECH PROJECT, 2020
** go_right.c
** File description:
** go right
*/

#include "my.h"
#include "framing_engine.h"

void map_left(framing *lvl)
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
            lvl->map_txt.x += 16;
        }
        draw_map(lvl);
    }
}

void player_left(framing *lvl)
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
            lvl->player_txt.x += 16;
        }
        draw_map(lvl);
    }
}

void annim_left(framing *lvl)
{
    int l = lvl->map_large[lvl->selected_map];
    int pos = (15 * 128) - (l * 128);

    if (lvl->player_txt.x == 896)
        lvl->player_center_h = 1;
    else
        lvl->player_center_h = 0;
    if (lvl->map_txt.x == pos)
        player_left(lvl);
    if (lvl->map_txt.x > pos && lvl->player_center_h == 1)
        map_left(lvl);
}

int go_left(framing *lvl)
{
    int x = lvl->player_x;
    int y = lvl->player_y;

    lvl->player_txt.status = 1;
    if (x > 0 && lvl->save_map[y][x - 1] == ' ') {
        lvl->map[y][x] = lvl->save_map[y][x];
        lvl->map[y][x - 1] = 'P';
        lvl->player_x--;
        annim_left(lvl);
    }
    if (x > 0 && lvl->save_map[y][x - 1] != ' ') {
        lvl->map[y][x] = lvl->save_map[y][x];
        lvl->map[y][x - 1] = 'P';
        lvl->player_x--;
        other_action(lvl, x - 1, y);
    }
    return (0);
}
