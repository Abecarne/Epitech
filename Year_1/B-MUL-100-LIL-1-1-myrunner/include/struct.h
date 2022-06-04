/*
** EPITECH PROJECT, 2020
** Projets
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct textures
{
    sfTexture *floor;
    sfTexture *perso;
    sfTexture *bush;
    sfTexture *mountain;
    sfTexture *cloud;
    sfTexture *ball;
    sfTexture *mob;
} st_textures;

typedef struct sprites
{
    sfSprite *ball;
    sfSprite *floor;
    sfSprite *perso;
    sfSprite *wall;
    sfSprite *wall2;
    sfSprite *mob;
    sfSprite *mb2;
    sfSprite *bush1;
    sfSprite *bush2;
    sfSprite *bush3;
    sfSprite *mountain1;
    sfSprite *mountain2;
    sfSprite *mountain3;
    sfSprite *cloud1;
    sfSprite *cloud2;
    sfSprite *cloud3;
} st_sprites;

typedef struct musics
{
    sfMusic *back;
    sfMusic *jump;
    sfMusic *fire;
    sfMusic *death;
    sfMusic *mob;
    sfMusic *win;
}st_musics;

typedef struct speeds
{
    sfVector2f cloud;
    sfVector2f moutain;
    sfVector2f bush;
}st_speeds;

typedef struct positions
{
    sfVector2f perso;
    sfVector2f mob;
    sfVector2f mb2;
    sfVector2f wall;
    sfVector2f wall2;
    sfVector2f ball;
    sfVector2f cloud1;
    sfVector2f cloud2;
    sfVector2f cloud3;
    sfVector2f mountain1;
    sfVector2f mountain2;
    sfVector2f mountain3;
    sfVector2f bush1;
    sfVector2f bush2;
    sfVector2f bush3;
    sfVector2f text;
}st_positions;

typedef struct clocks
{
    sfClock *time;
    sfClock *ball;
    sfClock *total;
    sfClock *perso;
    sfClock *mob;
    sfClock *mv_mob;
    sfClock *floor;
    sfClock *cloud;
    sfClock *mountain;
    sfClock *bush;
}st_clocks;

typedef struct texts
{
    sfFont *font;
    sfText *score;
    sfText *value;
    sfText *win;
    sfText *lose;
    int change;
}st_text;

typedef struct data
{
    sfVideoMode mode;
    sfRenderWindow *window;
    sfRenderWindow *window2;
    sfEvent event;
}st_data;

typedef struct global
{
    st_textures tex;
    st_sprites sprite;
    st_musics music;
    st_speeds speed;
    st_positions coo;
    st_text text;
    st_clocks clock;
    st_data data;
    sfIntRect img;
    sfIntRect mob;
    int change_per;
    int change_mob;
    int direction;
    int game;
    int fireball;
    int shoot;
    int finish;
} global_t;

extern global_t var;

void help(void);
void print_interactions(void);
void play_music(void);
void open_window(void);
void display_floor(sfRenderWindow* window, sfClock *clock);
void display_perso(sfRenderWindow *win, sfClock *clock);
void timer(sfClock *clock, int max);
void jump(sfRenderWindow* window, sfEvent event);
void music_jump(void);
void background(sfRenderWindow *win);
void disp_cloud(sfRenderWindow *win);
void bushes(sfRenderWindow *win, sfClock *clock);
void mountains(sfRenderWindow *win, sfClock *clock);
void change_perso(void);
void update_perso(sfClock *clock, int tps);
void display_perso(sfRenderWindow *win, sfClock *clock);
void textures(void);
void sprites(void);
int music(void);
void positions(void);
void load(void);
void destroy(void);
void destroy1(void);
void destroy2(void);
void clocks(void);
void score(sfRenderWindow *win);
void texts(void);
void end();
int check_status(sfRenderWindow *win);
void sprites2(void);
void sprites3(void);
void disp_bush(sfRenderWindow *win);
void disp_mountain(sfRenderWindow *win);
void cloud1(sfRenderWindow *win, sfClock *clock);
void cloud2(sfRenderWindow *win, sfClock *clock);
void cloud3(sfRenderWindow *win, sfClock *clock);
void mountain1(sfRenderWindow *win, sfClock *clock);
void mountain2(sfRenderWindow *win, sfClock *clock);
void mountain3(sfRenderWindow *win, sfClock *clock);
void bush1(sfRenderWindow *win, sfClock *clock);
void bush2(sfRenderWindow *win, sfClock *clock);
void bush3(sfRenderWindow *win, sfClock *clock);
void fireball(sfRenderWindow* window);
void reload(void);
void change_mob(void);
void update_mob(sfClock *clock, int tps);
void display_mob(sfRenderWindow *win, sfClock *clock);
void random_mob(int i);
void display_wall(void);
void update_wall(void);
void change_wall(void);
void move_wall(void);
void random_wall(int i);
void shoot(void);

#endif /* !STRUCT_H_ */
