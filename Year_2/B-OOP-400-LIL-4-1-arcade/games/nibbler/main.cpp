/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** main
*/

#include <iostream>
#include "main.hpp"

arcade::game::AGameModule::~AGameModule() {};

Nibbler::Nibbler()
{
    std::cout << "Constructeur Nibbler" << std::endl;
    score = 0;
    state = arcade::State::RUNNING;
}

Nibbler::~Nibbler()
{
    std::cout << "Destructeur Nibbler" << std::endl;
}

std::string Nibbler::getGameName(void)
{
    return ("nibbler");
}

arcade::State Nibbler::getState(void)
{
    return (state);
}

int Nibbler::getScore(void)
{
    return (score);
}

void Nibbler::launch(std::string filemap)
{
    map = getMapFromFile(filemap);
}

void Nibbler::update(arcade::Keys inputKey)
{
    keyInput(inputKey);
    endGame();
}

MapType Nibbler::getMap(void)
{
    return (this->map);
}

void Nibbler::keyInput(arcade::Keys inputKey)
{
    switch (inputKey) {
        case arcade::Keys::UP:
            moveUp();
            break;
        case arcade::Keys::RIGHT:
            moveRight();
            break;
        case arcade::Keys::DOWN:
            moveDown();
            break;
        case arcade::Keys::LEFT:
            moveLeft();
            break;
        default:
            break;
    }
}

MapType Nibbler::getMapFromFile(std::string filepath)
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
        arcade::game::IGameModule *instance = new Nibbler();
        return instance;
    }

    void deleteInstance(arcade::game::IGameModule *instance)
    {
        delete instance;
    }
}