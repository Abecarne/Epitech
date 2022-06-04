/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-charly.le-corre
** File description:
** menu
*/

#ifndef MENU_H_
#define MENU_H_

#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics.h>
#include "../include/my.h"

/* Menu principal */
typedef struct textures_main
{
    sfTexture *bg;
    sfTexture *btn;
}st_txm;

typedef struct sprites_main
{
    sfSprite *bg;
    sfSprite *play;
    sfSprite *option;
    sfSprite *exit;
}st_spm;

typedef struct entity
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
}st_entity;

typedef struct textures_game
{
    sfTexture *win;
    sfTexture *loose;
    sfTexture *bg;
}st_txg;

typedef struct sprites_game
{
    sfSprite *win;
    sfSprite *loose;
    sfSprite *bg;
}st_spg;

typedef struct texture_rect
{
    sfIntRect play;
    sfIntRect option;
    sfIntRect exit;
    sfIntRect presume;
    sfIntRect pinventory;
    sfIntRect popt;
    sfIntRect pexit;
}st_rect;

typedef struct colors
{
    sfColor option;
    sfColor pause;
    sfColor fight;
    sfColor attack;
    sfColor main;
    sfColor rect;
}st_col;

typedef struct text_fight
{
    sfText *attack;
    sfText *skip;
    sfText *run;
    sfText *atk1;
    sfText *comp1;
    sfText *comp2;
    sfVector2f attackpos;
    sfVector2f skippos;
    sfVector2f runpos;
    sfVector2f atk1pos;
    sfVector2f comp1pos;
    sfVector2f comp2pos;
}st_fight_text;

typedef struct musics
{
    sfMusic *clic;
    sfMusic *fight;
    sfMusic *back;
    sfMusic *main;
}st_musics;

typedef struct positions_main
{
    sfVector2f play;
    sfVector2f option;
    sfVector2f exit;
}st_posm;

typedef struct data_window
{
    sfEvent event;
    sfVideoMode mode;
    sfWindow *win;
    sfRenderWindow *wmain;
    char *name;
}st_data_window;

typedef struct texts
{
    sfFont *font;
    sfText *menu;
    sfText *play;
    sfText *resume;
    sfText *inventory;
    sfText *option;
    sfText *exit;
    sfText *trou;
    sfVector2f troupos;
    sfVector2f menupos;
    sfVector2f playpos;
    sfVector2f resumepos;
    sfVector2f inventorypos;
    sfVector2f optionpos;
    sfVector2f exitpos;
}st_text;

/* ~~ perso ~~ */
typedef struct tx_perso
{
    sfTexture *ennemi;
    sfTexture *perso;
    sfTexture *dos;
}st_tx_perso;

typedef struct sprites_perso
{
    sfRectangleShape *rect;
    sfVector2f origin1;
    sfVector2f size;
    sfSprite *ennemi;
    sfSprite *perso;
    sfSprite *dos;
    sfVector2f ennemipos;
    sfVector2f persopos;
    sfVector2f dospos;
}st_sp_perso;

typedef struct main_menu
{
    st_data_window *data;
    st_fight_text *ftxt;
    st_musics *music;
    st_entity *ent;
    st_txm *txm;
    st_txg *txg;
    st_tx_perso *txp;
    st_sp_perso *spp;
    st_spm *spm;
    st_spg *spg;
    st_col *col;
    st_rect *rect;
    st_posm *posm;
    st_text text;
    int a;
    int status;
    int sc;
}st_main_menu;

/* ~~ Main Menu */
int main_menu(void);

/* ~~ Supplies ~~ */
void help(void);

/* ~~  Fight ~~ */
void buff_anim(st_main_menu *st);
int enemi_inbound(st_main_menu *st);
void get_attacked(st_main_menu *st, sfSprite *sp);
void charge_anim(st_main_menu *st, sfSprite *att, sfSprite *def);

/* ~~ Textes ~~ */
void init_template(st_main_menu *st);
void init_text_menu(st_main_menu *st);
void init_text_pause(st_main_menu *st);
void init_text_fight(st_main_menu *st);

/* ~~ Loadings ~~ */
int load_var(st_main_menu *st);
int load_musics(st_main_menu *st);
int load_sprites(st_main_menu *st);
int load_textures(st_main_menu *st);
void malloc_struct(st_main_menu *st);
int load_textures_perso(st_main_menu *st);

/* ~~ Initialization ~~ */
void init_var(st_main_menu *st);
void init_txt(st_main_menu *st);
void init_color(st_main_menu *st);
void init_struct(st_main_menu *st);
void init_window(st_main_menu *st);
void init_sprites(st_main_menu *st);
void init_positions(st_main_menu *st);

/* ~~ Musics ~~ */
void music_end(st_main_menu *st);
void music_menu(st_main_menu *st);
void music_game(st_main_menu *st);
void music_pause(st_main_menu *st);
void music_fight(st_main_menu *st);
void music_option(st_main_menu *st);
void music_attack(st_main_menu *st);

/* ~~ Loops ~~ */
int loop_end(st_main_menu *st);
int loop_menu(st_main_menu *st);
int loop_game(st_main_menu *st);
int loop_fight(st_main_menu *st);
int loop_pause(st_main_menu *st);
int loop_fight(st_main_menu *st);
int loop_attack(st_main_menu *st);
int loop_option(st_main_menu *st);

/* ~~ Loops Loops ~~ */
int loop_menu_loop(st_main_menu *st);
int loop_game_loop(st_main_menu *st);
int loop_pause_loop(st_main_menu *st);
int loop_option_loop(st_main_menu *st);
int loop_end_loop(st_main_menu *st);
int loop_fight_loop(st_main_menu *st);
int loop_attack_loop(st_main_menu *st);

/* ~~ Events ~~ */
int event_end(st_main_menu *st);
int event_menu(st_main_menu *st);
int event_game(st_main_menu *st);
int event_pause(st_main_menu *st);
int event_fight(st_main_menu *st);
int event_option(st_main_menu *st);
int event_attack(st_main_menu *st);

/* ~~ Hovers ~~ */
int hover_menu(st_main_menu *st);
int hover_pause(st_main_menu *st);
int hover_fight(st_main_menu *st);
int hover_option(st_main_menu *st);
int hover_select_attack(st_main_menu *st);
int hover_attack(st_main_menu *st, sfText *sp);
int hover_popt(st_main_menu *st, sfText *sp);
int hover_atk1(st_main_menu *st, sfText *sp);
int hover_comp2(st_main_menu *st, sfText *sp);
int hover_comp1(st_main_menu *st, sfText *sp);
int hover_pexit(st_main_menu *st, sfText *sp);
int hover_opt(st_main_menu *st, sfSprite *sp);
int hover_oopt(st_main_menu *st, sfText *sp);
int hover_oplay(st_main_menu *st, sfText *sp);
int hover_play(st_main_menu *st, sfSprite *sp);
int hover_exit(st_main_menu *st, sfSprite *sp);
int hover_presume(st_main_menu *st, sfText *sp);
int hover_runaway(st_main_menu *st, sfText *sp);
int hover_pinventory(st_main_menu *st, sfText *sp);
int hover_skip_round(st_main_menu *st, sfText *sp);

/* ~~ Display ~~ */
void scene_end(st_main_menu *st);
void scene_menu(st_main_menu *st);
void scene_game(st_main_menu *st);
void scene_pause(st_main_menu *st);
void scene_fight(st_main_menu *st);
void scene_option(st_main_menu *st);
void scene_attack(st_main_menu *st);

/* ~~ Destroy / Free ~~ */
void free_all(st_main_menu *st);

#endif /* !MENU_H_ */
