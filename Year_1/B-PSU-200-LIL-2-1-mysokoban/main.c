/*
** EPITECH PROJECT, 2021
** basics [WSL: fedora]
** File description:
** main
*/

#include "include/sokoban.h"

int breaking(char c)
{
    if (c == 27)
        return (1);
    return (0);
}

int game_loop(var_t *st)
{
    initscr();
    init_game(st);
    while ((COLS < st->nbc + 10) || (LINES < st->nbl + 5))
        check_len2();
    while ((st->input = getch()) != 27) {
        check_len(st);
        move(0, 0);
        if (breaking(st->input) == 1)
            break;
        if (st->input == ' ')
            reset(st);
        movement(st);
        refresh();
        if (check_end(st) == 1)
            break;
    }
    endwin();
    free_val(st);
    return (0);
}

int error(var_t *st)
{
    check_boxes(st);
    check_map(st);
    check_player(st);
    return (0);
}

void help(void)
{
    my_putstr("USAGE\n     ./my_sokoban map\nDESCRIPTION\n");
    my_putstr("     map  file representing the warehouse map, ");
    my_putstr("containing '#' for walls, \n          'P' for the player, ");
    my_putstr("'X' for boxes and 'O' for storage locations\n");
}

int main(int ac, char **av)
{
    var_t st;

    if (ac != 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h')
        help();
    init_struct(&st);
    load_map(av, &st);
    game_loop(&st);
    print_end(&st);
    return (0);
}