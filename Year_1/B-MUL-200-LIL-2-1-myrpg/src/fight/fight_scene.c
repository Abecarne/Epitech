/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** fight_scene
*/

#include "menu.h"

void scene_fight(st_main_menu *st)
{
    sfRenderWindow_clear(st->data->wmain, sfTransparent);
    sfRenderWindow_drawSprite(st->data->wmain, st->spg->bg, NULL);
    sfRenderWindow_drawSprite(st->data->wmain, st->spp->dos, NULL);
    sfRenderWindow_drawSprite(st->data->wmain, st->spp->ennemi, NULL);
    sfRenderWindow_drawRectangleShape(st->data->wmain, st->spp->rect, NULL);
    sfRenderWindow_drawText(st->data->wmain, st->ftxt->attack, NULL);
    sfRenderWindow_drawText(st->data->wmain, st->ftxt->skip, NULL);
    sfRenderWindow_drawText(st->data->wmain, st->ftxt->run, NULL);
    sfRenderWindow_display(st->data->wmain);
}

void scene_attack(st_main_menu *st)
{
    sfRenderWindow_clear(st->data->wmain, sfTransparent);
    sfRenderWindow_drawSprite(st->data->wmain, st->spg->bg, NULL);
    sfRenderWindow_drawSprite(st->data->wmain, st->spp->dos, NULL);
    sfRenderWindow_drawSprite(st->data->wmain, st->spp->ennemi, NULL);
    sfRenderWindow_drawRectangleShape(st->data->wmain, st->spp->rect, NULL);
    sfRenderWindow_drawText(st->data->wmain, st->ftxt->atk1, NULL);
    sfRenderWindow_drawText(st->data->wmain, st->ftxt->comp1, NULL);
    sfRenderWindow_drawText(st->data->wmain, st->ftxt->comp2, NULL);
    sfRenderWindow_display(st->data->wmain);
}