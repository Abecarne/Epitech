/*
** EPITECH PROJECT, 2021
** sem2 [WSL: Ubuntu-20.04]
** File description:
** bot
*/

#include "include/matchstick.h"

int remove_max(st_match *st, int i, int j, int cpt)
{
    if (cpt >= st->max || cpt >= st->max_stick)
        return (0);
    else {
        st->board[i][j] = ' ';
        st->stick_per_line[i - 1][1] -= 1;
        st->max_stick--;
        st->bot->line = i;
        st->bot->match++;
    }
    return (0);
}

void ai_remove(st_match *st)
{
    int cpt = 0;
    st->bot->match = 0;

    for (int i = 0; st->board[i] != NULL; i++) {
        for (int j = st->nbc - 1; j != 0; j--) {
            if (st->board[i][j] == '|') {
                remove_max(st, i, j, cpt);
                cpt++;
            }
        }
        if (cpt != 0)
            break;
    }
}

void turn_ai(st_match *st)
{
    my_printf("AI's turn...\n");
    ai_remove(st);
    if (st->bot->line == 9) {
        my_printf("AI removed %d match(es) from line 9\n", st->bot->match);
    } else {
        my_printf("AI removed %d match(es) from line %d\n",
                            st->bot->match, st->bot->line);
    }
}