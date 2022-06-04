/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** main
*/

#include <iostream>
#include "main.hpp"

arcade::game::AGameModule::~AGameModule() {};

Centipede::Centipede()
{
    std::cout << "Constructeur Centipede" << std::endl;
    score = 0;
    state = arcade::State::RUNNING;
}

Centipede::~Centipede()
{
    std::cout << "Destructeur Centipede" << std::endl;
}

std::string Centipede::getGameName(void)
{
    return ("centipede");
}

arcade::State Centipede::getState(void)
{
    return (state);
}

int Centipede::getScore(void)
{
    return (0);
}

void Centipede::launch(std::string filemap)
{
    map = getMapFromFile(filemap);
}

void Centipede::keyInput(arcade::Keys inputKey)
{
    (void)inputKey;
}

MapType Centipede::getMap(void)
{
    return (this->map);
}

void Centipede::setPos(void)
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

void Centipede::update(arcade::Keys inputKey)
{
    if (inputKey == arcade::Keys::UP)
        moveUp();
    if (inputKey == arcade::Keys::DOWN)
        moveDown();
    if (inputKey == arcade::Keys::LEFT)
        moveLeft();
    if (inputKey == arcade::Keys::RIGHT)
        moveRight();
}

void Centipede::moveUp(void)
{
    if (map[posy - 1][posx] == ' ') {
        map[posy][posx] = ' ';
        map[posy - 1][posx] = 'P';
        posy--;
    }
}


void Centipede::moveDown(void)
{
    if (map[posy + 1][posx] == ' ') {
        map[posy][posx] = ' ';
        map[posy + 1][posx] = 'P';
        posy++;
    }
}


void Centipede::moveRight(void)
{
    setPos();
    if (map[posy][posx + 1] == ' ') {
        map[posy][posx] = ' ';
        map[posy][posx + 1] = 'P';
        posx++;
    }
}


void Centipede::moveLeft(void)
{
    setPos();
    if (map[posy][posx - 1] == ' ') {
        map[posy][posx] = ' ';
        map[posy][posx - 1] = 'P';
        posx--;
    }
}



MapType Centipede::getMapFromFile(std::string filepath)
{
    std::string tmp_map;
    std::string tmp;
    std::ifstream ifs(filepath);

    std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    tmp_map = content;

    for (size_t i = 0; i <= tmp_map.size(); i++) {
        if (tmp_map[i] == '\n' || tmp_map[i] == '\0') {
            map.push_back(tmp);
            tmp.clear();
        }
        tmp.push_back(tmp_map[i]);
    }
    return (map);
}

extern "C" {
    arcade::game::IGameModule *EntryPoint(void)
    {
        arcade::game::IGameModule *instance = new Centipede();
        return instance;
    }

    void deleteInstance(arcade::game::IGameModule *instance)
    {
        delete instance;
    }
}