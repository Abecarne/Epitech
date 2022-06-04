/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** main
*/

#include "main.hpp"

arcade::game::AGameModule::~AGameModule() {};

// ~~~~~~ Beginning of member functions ~~~~~~

Pacman::Pacman()
{
    std::cout << "Constructeur Pacman" << std::endl;
    score = 0;
    state = arcade::State::RUNNING;
}

Pacman::~Pacman()
{
    std::cout << "Destructeur Pacman" << std::endl;
}

std::string Pacman::getGameName(void)
{
    return ("pacman");
}

arcade::State Pacman::getState(void)
{
    return (state);
}

int Pacman::getScore(void)
{
    return (score);
}

void Pacman::launch(std::string filemap)
{
    map = getMapFromFile(filemap);
    time.start();
}

void Pacman::update(arcade::Keys inputKey)
{
    if (time.NowSeconds() >= 10) {
        this->startGhost = 1;
        time.stop();
    }
    if (startGhost == 1)
        moveGhost();
    keyInput(inputKey);
    endGame();
}

MapType Pacman::getMap(void)
{
    return (this->map);
}

void Pacman::keyInput(arcade::Keys inputKey)
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

MapType Pacman::getMapFromFile(std::string filepath)
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

// ~~~~~~ End of member functions ~~~~~~

extern "C" {
    arcade::game::IGameModule *EntryPoint(void)
    {
        arcade::game::IGameModule *instance = new Pacman();
        return instance;
    }

    void deleteInstance(arcade::game::IGameModule *instance)
    {
        delete instance;
    }
}