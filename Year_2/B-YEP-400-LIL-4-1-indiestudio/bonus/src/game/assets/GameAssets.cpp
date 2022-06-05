/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** GameAssets.cpp
*/

#include "GameAssets.hpp"

bomberman::game::GameAssets::GameAssets(void)
{
    _map = nullptr;
    _skybox = nullptr;
    _gameBoard = nullptr;
}

bomberman::game::GameAssets::~GameAssets(void)
{

}

void bomberman::game::GameAssets::initMap(std::string mapFolder)
{
    _map = std::make_shared<bomberman::environment::Map>();

    if (!_map)
        bomberman::core::Errors("[GameAssets]", "Not enough memories!");
    _map->init(mapFolder);
}

void bomberman::game::GameAssets::initGameBoard(size_t width, size_t heigth, Vector3 pos, std::string floorMesh,
std::string destructibleMesh, std::string undestructibleMesh)
{
    _gameBoard = std::make_shared<bomberman::environment::GameBoard>();

    if (!_gameBoard)
        bomberman::core::Errors("[GameAssets]", "Not enough memories!");
    _gameBoard->init(width, heigth, pos, floorMesh, destructibleMesh, undestructibleMesh);
}

void bomberman::game::GameAssets::initSkyBox(bomberman::environment::Skybox::day_cycle state)
{
    _skybox = std::make_shared<bomberman::environment::Skybox>();

    if (!_skybox)
        bomberman::core::Errors("[GameAssets]", "Not enough memories!");
}

std::shared_ptr<bomberman::environment::Skybox> bomberman::game::GameAssets::getSkyBox(void)
{
    return _skybox;
}

std::shared_ptr<bomberman::environment::Map> bomberman::game::GameAssets::getMap(void)
{
    return _map;
}

std::shared_ptr<bomberman::environment::GameBoard> bomberman::game::GameAssets::getGameBoard(void)
{
    return _gameBoard;
}