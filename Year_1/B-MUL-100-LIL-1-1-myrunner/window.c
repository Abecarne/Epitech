/*
** EPITECH PROJECT, 2020
** projets
** File description:
** window
*/

#include "include/struct.h"

void play_music(void)
{
    sfMusic_play(var.music.back);
    sfMusic_setLoop(var.music.back, sfTrue);
}

void disp_all(void)
{
    sfRenderWindow_clear(var.data.window, sfBlue);
    background(var.data.window);
    display_floor(var.data.window, var.clock.floor);
    display_wall();
    display_perso(var.data.window, var.clock.perso);
    display_mob(var.data.window, var.clock.mob);
    score(var.data.window);
    if (var.fireball == 1 && var.shoot == 1)
        fireball(var.data.window);
    sfRenderWindow_display(var.data.window);
}

void main_loop(void)
{
    play_music();
    while (sfRenderWindow_isOpen(var.data.window)) {
        while (sfRenderWindow_pollEvent(var.data.window, &var.data.event)) {
            if (var.data.event.type == sfEvtClosed ||
                var.data.event.key.code == sfKeyEscape)
                sfRenderWindow_close(var.data.window);
            jump(var.data.window, var.data.event);
            shoot();
            reload();
        }
        disp_all();
        check_game();
    }
}

void open_window(void)
{
    var.data.mode.width = 1750;
    var.data.mode.height = 950;
    var.data.window = sfRenderWindow_create(var.data.mode, "Mario De Wish",
                                                            sfClose, NULL);
    sfWindow_setFramerateLimit(var.data.window, 144);
    var.game = 1;
    main_loop();
    sfMusic_stop(var.music.back);
    sfRenderWindow_destroy(var.data.window);
    destroy1();
    if (var.game == 0) {
        var.data.window2 = sfRenderWindow_create(var.data.mode, "Mario De Wish",
                                                            sfClose, NULL);
        sfWindow_setFramerateLimit(var.data.window2, 144);
        end();
    }
    destroy2();
    sfRenderWindow_destroy(var.data.window2);
}