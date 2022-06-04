/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** defender
*/

#ifndef DEFENDER_H_
#define DEFENDER_H_

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdio.h>
#include <stdlib.h>

/* ##########  Structures  ########## */
typedef struct colors
{
    sfColor main;
    sfColor sun;
}st_color;

typedef struct sprites_enemies
{
    sfSprite *zomb1;
    sfSprite *zomb2;
    sfSprite *zomb3;
    sfSprite *zomb4;
    sfVector2f pzomb1;
    sfVector2f pzomb2;
    sfVector2f pzomb3;
    sfVector2f pzomb4;
    sfIntRect rzomb1;
    sfIntRect rzomb2;
    sfIntRect rzomb3;
    sfIntRect rzomb4;
}st_spzomb;

typedef struct cloks_enemies
{
    sfClock *zomb1;
    sfClock *zomb2;
    sfClock *zomb3;
    sfClock *zomb4;
    sfClock *szomb1;
    sfClock *szomb2;
    sfClock *szomb3;
    sfClock *szomb4;
}st_clzomb;

typedef struct clocks
{
    sfClock *sun;
    sfClock *ssun;
    sfClock *pea;
    sfClock *dbl;
    sfClock *time;
    sfClock *zomb;
    sfClock *mine;
    sfClock *multi;
    sfClock *szomb;
}st_clocks;

typedef struct texture1
{
    sfTexture *fond;
    sfTexture *main;
    sfTexture *play;
    sfTexture *exit;
    sfTexture *option;
}st_textures_main;

typedef struct texture2
{
    sfTexture *bg;
    sfTexture *sun;
    sfTexture *zomb;
    sfTexture *garden;
    sfTexture *heart;
    sfTexture *pea;
    sfTexture *mine;
    sfTexture *dbl;
    sfTexture *multi;
}st_texture_game;

typedef struct sprite_main
{
    sfSprite *fond;
    sfSprite *main;
    sfSprite *play;
    sfSprite *exit;
    sfSprite *exit2;
    sfSprite *option;
}st_sprites_main;

typedef struct sprite_game
{
    sfSprite *bg;
    sfSprite *sun;
    sfSprite *sun2;
    sfSprite *zomb;
    sfSprite *garden;
    sfSprite *heart;
    sfSprite *pea;
    sfSprite *mine;
    sfSprite *dbl;
    sfSprite *multi;

}st_sprites_game;

typedef struct musics
{
    sfMusic *clic;
    sfMusic *stage;
    sfMusic *main_menu;
}st_music;

typedef struct icons
{
    int sunny;
    sfSprite *pea;
    sfSprite *multi;
    sfSprite *mine;
    sfSprite *dbl;
    sfSprite *sun;
    sfIntRect rpea;
    sfIntRect rdbl;
    sfIntRect rmulti;
    sfIntRect rmine;
    sfIntRect rsun;
    sfVector2f ppea;
    sfVector2f pdbl;
    sfVector2f pmine;
    sfVector2f pmulti;
    sfVector2f psun;
    sfVector2f psunny;
}st_icon;

typedef struct positions_menu
{
    sfVector2f fond;
    sfVector2f logo;
    sfVector2f play;
    sfVector2f exit;
    sfVector2f exit2;
    sfVector2f option;
}st_positions_menu;

typedef struct positions_game
{
    sfVector2f bg;
    sfVector2f sun;
    sfVector2f sun2;
    sfVector2f zomb;
    sfVector2f garden;
    sfVector2f heart;
    sfVector2f pea;
    sfVector2f mine;
    sfVector2f dbl;
    sfVector2f multi;
}st_positions_game;

typedef struct data
{
    sfEvent event;
    sfVideoMode mode;
    sfRenderWindow *wmain;
}st_data;

typedef struct rectangle
{
    sfIntRect bg;
    sfIntRect pea;
    sfIntRect sun;
    sfIntRect sun2;
    sfIntRect exit;
    sfIntRect play;
    sfIntRect zomb;
    sfIntRect exit2;
    sfIntRect option;
    sfIntRect garden;
}st_rectangle;

typedef struct texts
{
    sfFont *font;
    sfText *menu;
    sfText *title;
    sfText *parag1;
    sfText *parag2;
    sfText *parag3;
    sfText *parag4;
    sfText *life;
    sfText *pause;
    sfText *sun;
    sfVector2f menupos;
    sfVector2f titlepos;
    sfVector2f parag1pos;
    sfVector2f parag2pos;
    sfVector2f parag3pos;
    sfVector2f parag4pos;
    sfVector2f lifepos;
    sfVector2f pausepos;
    sfVector2f sunpos;
}st_text;

typedef struct pause
{
    sfText *main;
    sfText *exit;
    sfText *resume;
    sfVector2f mainpos;
    sfVector2f exitpos;
    sfVector2f resumepos;
}st_pause;

typedef struct nombers
{
    int nb;
    int nb1;
    int nb2;
    int nb3;
    int nb4;
    int nb5;
}st_nb_zomb;

typedef struct end
{
    sfText *defeat;
    sfText *victory;
    sfVector2f pdefeat;
    sfVector2f pvictory;
}st_end;
typedef struct defender
{
    st_end end;
    st_data data;
    st_text text;
    st_icon icon;
    st_color col;
    st_music music;
    st_clocks time;
    st_pause pause;
    st_spzomb spzomb;
    st_clzomb clzomb;
    st_rectangle rect;
    st_sprites_game spg;
    st_sprites_main spm;
    st_texture_game texg;
    st_textures_main texm;
    st_positions_game posg;
    st_positions_menu posm;
    st_nb_zomb nbz;
    int nb;
    int nbs;
    int win;
    int status;
    int **change;
    const char *name;
}st_def;


/* ##########  Prototypes  ########## */
/* ~~ Usage ~~ */
void help(void);

/* ~~ Loading / Initializing ~~ */
void init_var(st_def *st);
void init_txt(st_def *st);
void init_how(st_def *st);
void init_pos(st_def *st);
void init_create(st_def *st);
void load_sprites(st_def *st);
void load_sprites1(st_def *st);
void load_sprites2(st_def *st);
void load_sprites3(st_def *st);
int load_sprite_zomb(st_def *st);
int load_var(st_def *st);
int load_texts(st_def *st);
int load_musics(st_def *st);
int load_textures(st_def *st);
int load_textures2(st_def *st);
int load_textures3(st_def *st);

/* ~~ Loops ~~ */
int loop_end(st_def *st);
int loop_menu(st_def *st);
int loop_game(st_def *st);
int loop_pause(st_def *st);
int loop_option(st_def *st);

/* ~~ Display Scenes ~~ */
void sc_end(st_def *st);
void sc_menu(st_def *st);
void sc_pause(st_def *st);
void sc_option(st_def *st);
void disp_icons(st_def *st);
int sc_game(st_def *st);
int disp_zomb(sfClock *cl, sfSprite *sp, st_def *st);

/* ~~ Hover ~~ */
int hover_end(st_def *st);
int hover_menu(st_def *st);
int hover_game(st_def *st);
int hover_pause(st_def *st);
int hover_option(st_def *st);
int hover_main(st_def *st, sfText *sp);
int hover_opt(st_def *st, sfSprite *sp);
int hover_play(st_def *st, sfSprite *sp);
int hover_exit(st_def *st, sfSprite *sp);
int hover_resume(st_def *st, sfText *sp);
int hover_back_main(st_def *st, sfText *sp);
int hover_exit_pause(st_def *st, sfText *sp);
int hover_pause_game(st_def *st, sfText *sp);

/* ~~ Event ~~ */
void event_end(st_def *st);
void event_menu(st_def *st);
void event_pause(st_def *st);
int event_game(st_def *st);
int event_option(st_def *st);

/* ~~ Music ~~ */
void music_menu(st_def *st);
void music_game(st_def *st);
void music_pause(st_def *st);

/* ~~ Positions ~~ */
void positions1(st_def *st);
void positions2(st_def *st);
void positions3(st_def *st);
void positions4(st_def *st);
void positions5(st_def *st);
void positions6(st_def *st);
void positions7(st_def *st);
void init_positions(st_def *st);
void init_rect_icons(st_def *st);

/*~~ Free Variables ~~ */
void destroy1(st_def *st);
void destroy2(st_def *st);
int free_all(st_def *st);

/* ~~ Clocks ~~ */
void init_clocks(st_def *st);

/* ~~ Zombie ~~ */
void change_zomb(st_def *st);
void change_zomb1(st_def *st);
void change_zomb2(st_def *st);
void change_zomb3(st_def *st);
void change_zomb4(st_def *st);
int disp_zomb1(sfClock *cl, sfSprite *sp, st_def *st);
int disp_zomb2(sfClock *cl, sfSprite *sp, st_def *st);
int disp_zomb3(sfClock *cl, sfSprite *sp, st_def *st);
int disp_zomb4(sfClock *cl, sfSprite *sp, st_def *st);
void init_sp_zomb(st_def *st);
void pos_zomb(st_def *st);
void init_rect_zomb(st_def *st);

/* ~~ Sun ~~ */
void disp_sun(st_def *st);
void change_sun(st_def *st);
void move_sun(st_def *st);
void random_sun(st_def *st, sfSprite *sp, int i);
int click_sun(st_def *st, sfSprite *sun);

#endif /* !DEFENDER_H_ */
