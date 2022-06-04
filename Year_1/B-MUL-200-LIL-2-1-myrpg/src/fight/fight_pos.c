/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** fight_pos
*/

#include "menu.h"

void init_pos_persos(st_main_menu *st)
{
    sfVector2f scale = {5, 5};
    st->spp->dospos.x = 220;
    st->spp->dospos.y = 120;
    st->spp->ennemipos.x = 1000;
    st->spp->ennemipos.y = 100;
    sfSprite_setPosition(st->spp->dos, st->spp->dospos);
    sfSprite_setPosition(st->spp->ennemi, st->spp->ennemipos);
    sfSprite_setScale(st->spp->dos, scale);
    sfSprite_setScale(st->spp->ennemi, scale);
}

void pos_text_fight(st_main_menu *st)
{
    st->ftxt->attackpos.x = 150;
    st->ftxt->attackpos.y = st->data->mode.height / 1.35;
    st->ftxt->skippos.x = st->data->mode.width / 3 + 150;
    st->ftxt->skippos.y = st->data->mode.height / 1.35;
    st->ftxt->runpos.x = 2 * (st->data->mode.width / 3) + 150;
    st->ftxt->runpos.y = st->data->mode.height / 1.35;
    st->ftxt->atk1pos.x = 380;
    st->ftxt->atk1pos.y = st->data->mode.height / 1.30;
    st->ftxt->comp1pos.x = 2 * (st->data->mode.width / 4) + 160;
    st->ftxt->comp1pos.y = st->data->mode.height / 1.42;
    st->ftxt->comp2pos.x = 2 * (st->data->mode.width / 4) + 160;
    st->ftxt->comp2pos.y = st->data->mode.height / 1.18;
    sfText_setPosition(st->ftxt->run, st->ftxt->runpos);
    sfText_setPosition(st->ftxt->skip, st->ftxt->skippos);
    sfText_setPosition(st->ftxt->atk1, st->ftxt->atk1pos);
    sfText_setPosition(st->ftxt->comp1, st->ftxt->comp1pos);
    sfText_setPosition(st->ftxt->comp2, st->ftxt->comp2pos);
    sfText_setPosition(st->ftxt->attack, st->ftxt->attackpos);
    init_pos_persos(st);
}

void color_text_fight(st_main_menu *st)
{
    sfText_setColor(st->ftxt->attack, sfWhite);
    sfText_setColor(st->ftxt->skip, sfWhite);
    sfText_setColor(st->ftxt->run, sfWhite);
    sfText_setColor(st->ftxt->comp1, sfWhite);
    sfText_setColor(st->ftxt->comp2, sfWhite);
    sfText_setColor(st->ftxt->atk1, sfWhite);
}

void init_text_fight(st_main_menu *st)
{
    st->ftxt->attack = sfText_create();
    st->ftxt->skip = sfText_create();
    st->ftxt->run = sfText_create();
    st->ftxt->atk1 = sfText_create();
    st->ftxt->comp1 = sfText_create();
    st->ftxt->comp2 = sfText_create();
    sfText_setFont(st->ftxt->attack, st->text.font);
    sfText_setFont(st->ftxt->skip, st->text.font);
    sfText_setFont(st->ftxt->run, st->text.font);
    sfText_setFont(st->ftxt->atk1, st->text.font);
    sfText_setFont(st->ftxt->comp1, st->text.font);
    sfText_setFont(st->ftxt->comp2, st->text.font);
    sfText_setString(st->ftxt->attack, "ATTACK");
    sfText_setString(st->ftxt->skip, "SKIP ROUND");
    sfText_setString(st->ftxt->run, "RUN AWAY");
    sfText_setString(st->ftxt->atk1, "ATTACK 1");
    sfText_setString(st->ftxt->comp1, "SKILL 1");
    sfText_setString(st->ftxt->comp2, "SKILL 2");
    pos_text_fight(st);
    color_text_fight(st);
}
