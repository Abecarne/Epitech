/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** end
*/

#include "main.hpp"

void Pacman::setState(arcade::State new_state)
{
    state = new_state;
}

void Pacman::endGame(void)
{
    int food = 0;
    int ghost = 0;
    int perso = 0;

    for (size_t y = 0; y <= map.size(); y++) {
        for (size_t x = 0; x <= map[y].size(); x++) {
            if (map[y][x] == '.' || map[y][x] == 'O')
                food++;
            else if (map[y][x] == '1' || map[y][x] == '2' || map[y][x] == '3' || map[y][x] == '4')
                ghost++;
            else if (map[y][x] == 'P')
                perso++;
        }
    }
    if (perso == 0)
        setState(arcade::State::LOOSE);
    else if (perso == 1 && ghost == 0 && food == 0)
        setState(arcade::State::WIN);
}