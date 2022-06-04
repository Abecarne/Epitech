/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-charly.le-corre
** File description:
** mallocs
*/

#include "menu.h"

void malloc_struct(st_main_menu *st)
{
    st->data = malloc(sizeof(st_data_window));
    st->music = malloc(sizeof(st_musics));
    st->ftxt = malloc(sizeof(st_fight_text));
    st->txm = malloc(sizeof(st_txm));
    st->spm = malloc(sizeof(st_spm));
    st->rect = malloc(sizeof(st_rect));
    st->posm = malloc(sizeof(st_posm));
    st->txg = malloc(sizeof(st_txg));
    st->spg = malloc(sizeof(st_spg));
    st->col = malloc(sizeof(st_col));
    st->spp = malloc(sizeof(st_sp_perso));
    st->txp = malloc(sizeof(st_tx_perso));
}