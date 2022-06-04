/*
** EPITECH PROJECT, 2020
** framing_engine.h
** File description:
** framing engine
*/

#ifndef FRAMING_ENGINE_H
#define FRAMING_ENGINE_H

typedef struct sprite
{
    sfTexture *txt;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rect;
    int status;
    int animation;
    int x;
    int y;
    sfClock *clock;
    float rotate;
} sprite;

typedef struct framing {
    sfRenderWindow *win;
    char *buffer;
    char **map;
    char **save_map;
    char **map_src;
    int size[2];
    int map_height[2];
    int map_large[2];
    int paserelle[2][2][2];
    int player_x;
    int player_y;
    sprite map_txt;
    sprite player_txt;
    int exit;
    int selected_map;
    int key;
    int pressed;
    int next;
    int player_center_h;
    int player_center_v;
} framing;

#endif /* FRAMING_ */
