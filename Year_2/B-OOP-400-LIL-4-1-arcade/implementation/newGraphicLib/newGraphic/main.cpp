/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** main
*/

#include <iostream>
#include "main.hpp"

NewGraphic::NewGraphic()
{
}

NewGraphic::~NewGraphic()
{

}

std::string NewGraphic::getGameName(void)
{

}

arcade::State NewGraphic::getState(void)
{

}

int NewGraphic::getScore(void)
{

}

void NewGraphic::launch(std::string filemap)
{

}

void NewGraphic::keyInput(arcade::Keys inputKey)
{

}

MapType NewGraphic::getMap(void)
{

}

void NewGraphic::update(arcade::Keys inputKey)
{

}

MapType NewGraphic::getMapFromFile(std::string filepath)
{

}

extern "C" {
    arcade::game::IGameModule *EntryPoint(void)
    {
        arcade::game::IGameModule *instance = new NewGraphic();
        return instance;
    }

    void deleteInstance(arcade::game::IGameModule *instance)
    {
        delete instance;
    }
}