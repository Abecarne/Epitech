/*
** EPITECH PROJECT, 2020
** projets
** File description:
** perso
*/

#include "include/struct.h"
#include "include/my.h"

void defeat(void)
{
    sfMusic_play(var.music.death);
    var.coo.text.x = 770;
    var.coo.text.y = 460;
    sfRenderWindow_setFramerateLimit(var.data.window2, 30);
    while (sfRenderWindow_isOpen(var.data.window2)) {
        while (sfRenderWindow_pollEvent(var.data.window, &var.data.event)) {
            if (var.data.event.type == sfEvtClosed ||
            var.data.event.key.code == sfKeyEscape)
                    sfRenderWindow_close(var.data.window);
        }
        sfRenderWindow_clear(var.data.window2, sfWhite);
        sfText_setString(var.text.win, "YOU LOSE !");
        sfText_setFillColor(var.text.win, sfBlack);
        sfText_setPosition(var.text.win, var.coo.text);
        sfRenderWindow_drawText(var.data.window2, var.text.win, NULL);
        sfWindow_display(var.data.window2);
    }
}

void victory(void)
{
    sfMusic_play(var.music.win);
    var.coo.text.x = 770;
    var.coo.text.y = 460;
    sfRenderWindow_setFramerateLimit(var.data.window2, 30);
    while (sfRenderWindow_isOpen(var.data.window2)) {
        while (sfRenderWindow_pollEvent(var.data.window, &var.data.event)) {
            if (var.data.event.type == sfEvtClosed ||
                var.data.event.key.code == sfKeyEscape)
                    sfRenderWindow_close(var.data.window);
        }
        sfRenderWindow_clear(var.data.window2, sfWhite);
        sfText_setString(var.text.win, "VICTORY !");
        sfText_setFillColor(var.text.win, sfBlack);
        sfText_setPosition(var.text.win, var.coo.text);
        sfRenderWindow_drawText(var.data.window2, var.text.win, NULL);
        sfWindow_display(var.data.window2);
    }
}

void score(sfRenderWindow *win)
{
    sfVector2f score;
    sfVector2f value;

    score.x = 1500;
    score.y = 50;
    value.x = 1500;
    value.y = 100;
    var.text.font = sfFont_createFromFile("font/Pixeled.ttf");
    var.text.score = sfText_create();
    var.text.value = sfText_create();
    sfText_setFont(var.text.score, var.text.font);
    sfText_setFont(var.text.value, var.text.font);
    sfText_setString(var.text.score, "SCORE");
    sfText_setString(var.text.value, int_to_char(var.text.change));
    sfText_setPosition(var.text.score, score);
    sfText_setPosition(var.text.value, value);
    sfRenderWindow_drawText(win, var.text.score, NULL);
    sfRenderWindow_drawText(win, var.text.value, NULL);
}

void end(void)
{
    if (var.finish == 0)
        victory();
    else if (var.finish == 1)
        defeat();
}