/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** end
*/

#include "main.hpp"

void Nibbler::setState(arcade::State new_state)
{
    state = new_state;
}

void Nibbler::endGame(void)
{
    int fruit = 0;

    for (size_t y = 0; y <= map.size(); y++) {
        for (size_t x = 0; x <= map[y].size(); x++) {
            if (map[y][x] == 'F')
                fruit++;
                break;
        }
    }
    if (fruit == 0)
        setState(arcade::State::WIN);
}