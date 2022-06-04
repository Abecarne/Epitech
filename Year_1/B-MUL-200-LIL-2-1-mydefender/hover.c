/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** hover
*/

#include "include/defender.h"

int hover_menu(st_def *st)
{
    if (hover_play(st, st->spm.play) == 1)
        return (1);
    if (hover_opt(st, st->spm.option) == 1)
        return (1);
    if (hover_exit(st, st->spm.exit) == 1)
        return (1);
    return (0);
}

int hover_game(st_def *st)
{
    return (0);
}

int hover_pause(st_def *st)
{
    if (hover_resume(st, st->pause.resume) == 1)
        return (1);
    if (hover_main(st, st->pause.main) == 1)
        return (1);
    if (hover_exit(st, st->pause.exit) == 1)
        return (1);
    return (0);
}

int hover_end(st_def *st)
{
    return (0);
}

int hover_option(st_def *st)
{
    if (hover_main(st, st->text.menu) == 1)
        return (1);
    return (0);
}