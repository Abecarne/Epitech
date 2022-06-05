/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** move
*/

#include "main.hpp"

void Pacman::setPos(void)
{
    for (size_t y = 0; y <= map.size(); y++) {
        for (size_t x = 0; x <= map[y].size(); x++) {
            if (map[y][x] == 'P') {
                posy = y;
                posx = x;
            }
        }
    }
}

void Pacman::moveUp(void)
{
    setPos();
    if (map[posy - 1][posx] != '#' && map[posy - 1][posx] != '\"' && map[posy - 1][posx] != '_') {
        map[posy - 1][posx] = 'P';   
        map[posy][posx] = ' ';
    }
    if (map[posy - 1][posx] == '.')
        score++;
    if (map[posy - 1][posx] == 'O')
        score += 100;
}

void Pacman::moveDown(void)
{
    setPos();
    if (map[posy + 1][posx] != '#' && map[posy + 1][posx] != '\"' && map[posy + 1][posx] != '_') {
        map[posy + 1][posx] = 'P';
        map[posy][posx] = ' ';
    }
    if (map[posy + 1][posx] == '.')
        score++;
    if (map[posy + 1][posx] == 'O')
        score += 100;
}

void Pacman::moveRight(void)
{
    setPos();
    if (map[posy][posx + 1] != '#' && map[posy][posx + 1] != '\"' && map[posy][posx + 1] != '_') {
        map[posy][posx + 1] = 'P';
        map[posy][posx] = ' ';
    }
    if (map[posy][posx + 1] == '.')
        score++;
    if (map[posy][posx + 1] == 'O')
        score += 100;
}

void Pacman::moveLeft(void)
{
    setPos();
    if (map[posy][posx - 1] != '#' && map[posy][posx - 1] != '\"' && map[posy][posx - 1] != '_') {
        map[posy][posx - 1] = 'P';
        map[posy][posx] = ' ';
    }
    if (map[posy][posx - 1] == '.')
        score++;
    if (map[posy][posx - 1] == 'O')
        score += 100;
}