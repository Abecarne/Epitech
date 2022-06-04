/*
** EPITECH PROJECT, 2021
** sem2 [WSL: Ubuntu-20.04]
** File description:
** player
*/

#include "include/matchstick.h"

int line(st_match *st)
{
    int inp = 0;
    size_t buf;
    bool valid = false;

    while (valid == false) {
        my_printf("Line: ");
        inp = getline(&st->player->line_input, &buf, stdin);
        if (inp == -1)
            return (1);
        st->player->line_input[my_strlen(st->player->line_input) - 1] = '\0';
        valid = valid_line(st);
        if (valid == true)
            st->player->line = my_getnbr(st->player->line_input);
    }
    return (0);
}

int match(st_match *st)
{
    int inp = 0;
    size_t buf;

    my_printf("Matches: ");
    inp = getline(&st->player->match_input, &buf, stdin);
    if (inp == -1) {
        st->status = -1;
        return (1);
    }
    st->player->match_input[my_strlen(st->player->match_input) - 1] = '\0';
    if (valid_match(st) == 1)
        st->player->match = my_getnbr((st->player->match_input));
    else
        return (1);
    return (0);
}

int remove_stick(st_match *st)
{
    int i = st->nbc - 2;
    int ind = 0;

    while (st->board[st->player->line][i] != '|') {
        if (i == 1)
            return (1);
        i--;
    }
    for (ind = 0; ind < st->player->match; ind++, i--) {
        st->board[st->player->line][i] = ' ';
    }
    st->stick_per_line[st->player->line - 1][1] -= st->player->match;
    st->max_stick -= st->player->match;
    return (0);
}

int turn_player(st_match *st)
{
    bool good_input = false;

    my_printf("Your turn:\n");
    while (good_input == false) {
        if (line(st) == 1)
            return (1);
        else if (match(st) == 0)
            good_input = true;
        if (st->status == -1)
            return (1);
    }
    remove_stick(st);
    if (st->player->line == 9) {
        my_printf("Player removed %d match(es) from line 9\n", st->player->match);
    } else {
        my_printf("Player removed %d match(es) from line %d\n",
                            st->player->match, st->player->line);
    }
    return (0);
}
