/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** main
*/

#include <iostream>
#include "main.hpp"

NewGame::NewGame()
{
}

NewGame::~NewGame()
{

}

std::string NewGame::getGameName(void)
{

}

arcade::State NewGame::getState(void)
{

}

int NewGame::getScore(void)
{

}

void NewGame::launch(std::string filemap)
{

}

void NewGame::keyInput(arcade::Keys inputKey)
{

}

MapType NewGame::getMap(void)
{

}

void NewGame::update(arcade::Keys inputKey)
{

}

MapType NewGame::getMapFromFile(std::string filepath)
{

}

extern "C" {
    arcade::game::IGameModule *EntryPoint(void)
    {
        arcade::game::IGameModule *instance = new NewGame();
        return instance;
    }

    void deleteInstance(arcade::game::IGameModule *instance)
    {
        delete instance;
    }
}