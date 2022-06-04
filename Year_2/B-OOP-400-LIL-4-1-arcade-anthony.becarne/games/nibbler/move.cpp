/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** move
*/

#include "main.hpp"

void Nibbler::setPos(void)
{
    for (size_t y = 0; y <= map.size(); y++) {
        for (size_t x = 0; x <= map[y].size(); x++) {
            if (map[y][x] == 'S') {
                posy = y;
                posx = x;
            }
        }
    }
}

void Nibbler::moveUp(void)
{
    setPos();
    if (map[posy - 1][posx] == '#') {
        setState(arcade::State::LOOSE);
    }
    else if (map[posy - 1][posx] == 'F') {
        map[posy - 1][posx] = 'S';
        map[posy][posx] = ' ';
        score += 10;
    }
    map[posy - 1][posx] = 'S';
    map[posy][posx] = ' ';
}

void Nibbler::moveDown(void)
{
    setPos();
    if (map[posy + 1][posx] == '#') {
        setState(arcade::State::LOOSE);
    }
    else if (map[posy + 1][posx] == 'F') {
        map[posy + 1][posx] = 'S';
        map[posy][posx] = ' ';
        score += 10;
    }
    map[posy + 1][posx] = 'S';
    map[posy][posx] = ' ';
}

void Nibbler::moveRight(void)
{
    setPos();
    if (map[posy][posx + 1] == '#') {
        setState(arcade::State::LOOSE);
    }
    else if (map[posy ][posx + 1] == 'F') {
        map[posy][posx + 1] = 'S';
        map[posy][posx] = ' ';
        score += 10;
    }
    map[posy][posx + 1] = 'S';
    map[posy][posx] = ' ';
}

void Nibbler::moveLeft(void)
{
    setPos();
    if (map[posy][posx - 1] == '#') {
        setState(arcade::State::LOOSE);
    }
    else if (map[posy ][posx + 1] == 'F') {
        map[posy][posx + 1] = 'S';
        map[posy][posx] = ' ';
        score += 10;
    }
    map[posy][posx + 1] = 'S';
    map[posy][posx] = ' ';
}