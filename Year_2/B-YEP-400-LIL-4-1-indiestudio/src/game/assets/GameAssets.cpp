/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** GameAssets.cpp
*/

#include "GameAssets.hpp"
#include <iostream>

bomberman::game::GameAssets *bomberman::game::GameAssets::_instance {nullptr};

bomberman::game::GameAssets::GameAssets(void)
{
    _map = nullptr;
    _skybox = nullptr;
    _gameBoard = nullptr;
}

bomberman::game::GameAssets::~GameAssets(void)
{
    _bots.clear();
    _players.clear();
}

void bomberman::game::GameAssets::initMap(std::string mapFolder)
{
    _map = std::make_shared<bomberman::environment::Map>();

    if (!_map)
        throw bomberman::core::Errors("[GameAssets]", "Not enough memories!");
    _map->init(mapFolder);
}

void bomberman::game::GameAssets::initGameBoard(size_t width, size_t heigth, Vector3 pos, std::string floorMesh,
std::string destructibleMesh, std::string undestructibleMesh)
{
    _gameBoard = std::make_shared<bomberman::environment::GameBoard>();

    if (!_gameBoard)
        throw bomberman::core::Errors("[GameAssets]", "Not enough memories!");
    _gameBoard->init(width, heigth, pos, floorMesh, destructibleMesh, undestructibleMesh);
}

void bomberman::game::GameAssets::initSkyBox(void)
{
    _skybox = std::make_shared<bomberman::environment::Skybox>();

    if (!_skybox)
        throw bomberman::core::Errors("[GameAssets]", "Not enough memories!");
}

void bomberman::game::GameAssets::initPlayer(bomberman::entities::ACharacters::playerNum playerNum, std::string typeModel, std::string skinModel, bomberman::entities::ACharacters::characterColors skinColor, std::string animationModel)
{
    Vector3 gameBoardPos = this->_gameBoard->getPosition();

    float leftPos = (gameBoardPos.x - (((_gameBoard->getHeight() - 1) / 2) * (_gameBoard->getBlockSize().x * _gameBoard->getScale())) + ((_gameBoard->getBlockSize().x * _gameBoard->getScale()) / 2)) + (_gameBoard->getBlockSize().x * _gameBoard->getScale()) / 2;
    float rightPos = (gameBoardPos.x + (((_gameBoard->getHeight() - 1) / 2) * (_gameBoard->getBlockSize().x * _gameBoard->getScale())) - ((_gameBoard->getBlockSize().x * _gameBoard->getScale() / 2))) - (_gameBoard->getBlockSize().x * _gameBoard->getScale()) / 2;
    float topPos = (gameBoardPos.y - (((_gameBoard->getWidth() - 1) / 2) * (_gameBoard->getBlockSize().y * _gameBoard->getScale())) + ((_gameBoard->getBlockSize().y * _gameBoard->getScale() / 2))) + (_gameBoard->getBlockSize().x * _gameBoard->getScale()) / 2;
    float bottomPos = (gameBoardPos.y + (((_gameBoard->getWidth() - 1) / 2) * (_gameBoard->getBlockSize().y * _gameBoard->getScale())) - ((_gameBoard->getBlockSize().y * _gameBoard->getScale() / 2))) - (_gameBoard->getBlockSize().x * _gameBoard->getScale()) / 2;

    float y_axis = _gameBoard->getPosition().y + (_gameBoard->getBlockSize().y * _gameBoard->getScale());

    std::map<bomberman::entities::ACharacters::playerNum, Vector3> posInfos = {{bomberman::entities::ACharacters::playerNum::PLAYER1, {rightPos, y_axis, topPos}},
                                                                               {bomberman::entities::ACharacters::playerNum::PLAYER2, {rightPos, y_axis, bottomPos}},
                                                                               {bomberman::entities::ACharacters::playerNum::PLAYER3, {leftPos, y_axis, topPos}},
                                                                               {bomberman::entities::ACharacters::playerNum::PLAYER4, {leftPos, y_axis, bottomPos}}};
    Vector3 pos = {0, 0, 0};

    for (auto it = posInfos.begin(); it != posInfos.end(); ++it) {
        if (it->first == (int)playerNum)
            pos = it->second;
    }

    std::shared_ptr<bomberman::entities::Players> player = std::make_shared<bomberman::entities::Players>(playerNum, typeModel, skinModel, skinColor, animationModel, pos);

    if (!player)
        throw bomberman::core::Errors("[GameAssets]", "Not enough memories!");

    _players.push_back(player);
}

void bomberman::game::GameAssets::initNewTexture(std::string textureName, std::string texturePath)
{
    std::shared_ptr<Texture2D> newTexture;

    if (!FileExists(texturePath.c_str()))
        throw bomberman::core::Errors("[GameAssets]", texturePath + " doesn't exist!");

    newTexture = std::make_shared<Texture2D>();

    if (!newTexture)
        throw bomberman::core::Errors("[GameAssets]", "Not enough memories!");

    *newTexture = LoadTexture(texturePath.c_str());

    _loadedTexture.insert({textureName, newTexture});
}

std::map<std::string, std::shared_ptr<Texture2D>> bomberman::game::GameAssets::getAllLoadedTextures(void)
{
    return _loadedTexture;
}

void bomberman::game::GameAssets::cleanUp(void)
{
    _instance = nullptr;
}

void bomberman::game::GameAssets::initBots(bomberman::entities::ACharacters::playerNum playerNum, std::string typeModel, std::string skinModel, bomberman::entities::ACharacters::characterColors skinColor, std::string animationModel, bomberman::entities::BotDifficulty difficulty)
{
    Vector3 gameBoardPos = this->_gameBoard->getPosition();

    float leftPos = (gameBoardPos.x - (((_gameBoard->getHeight() - 1) / 2) * (_gameBoard->getBlockSize().x * _gameBoard->getScale())) + ((_gameBoard->getBlockSize().x * _gameBoard->getScale()) / 2)) + (_gameBoard->getBlockSize().x * _gameBoard->getScale()) / 2;
    float rightPos = (gameBoardPos.x + (((_gameBoard->getHeight() - 1) / 2) * (_gameBoard->getBlockSize().x * _gameBoard->getScale())) - ((_gameBoard->getBlockSize().x * _gameBoard->getScale() / 2))) - (_gameBoard->getBlockSize().x * _gameBoard->getScale()) / 2;
    float topPos = (gameBoardPos.y - (((_gameBoard->getWidth() - 1) / 2) * (_gameBoard->getBlockSize().y * _gameBoard->getScale())) + ((_gameBoard->getBlockSize().y * _gameBoard->getScale() / 2))) + (_gameBoard->getBlockSize().x * _gameBoard->getScale()) / 2;
    float bottomPos = (gameBoardPos.y + (((_gameBoard->getWidth() - 1) / 2) * (_gameBoard->getBlockSize().y * _gameBoard->getScale())) - ((_gameBoard->getBlockSize().y * _gameBoard->getScale() / 2))) - (_gameBoard->getBlockSize().x * _gameBoard->getScale()) / 2;

    float y_axis = _gameBoard->getPosition().y + (_gameBoard->getBlockSize().y * _gameBoard->getScale());

    std::map<bomberman::entities::ACharacters::playerNum, Vector3> posInfos = {{bomberman::entities::ACharacters::playerNum::PLAYER1, {rightPos, y_axis, topPos}},
                                                                               {bomberman::entities::ACharacters::playerNum::PLAYER2, {rightPos, y_axis, bottomPos}},
                                                                               {bomberman::entities::ACharacters::playerNum::PLAYER3, {leftPos, y_axis, topPos}},
                                                                               {bomberman::entities::ACharacters::playerNum::PLAYER4, {leftPos, y_axis, bottomPos}}};

    Vector3 pos = {0, 0, 0};

    for (auto it = posInfos.begin(); it != posInfos.end(); ++it) {
        if (it->first == (int)playerNum)
            pos = it->second;
    }

    std::shared_ptr<bomberman::entities::Bots> bot = std::make_shared<bomberman::entities::Bots>(playerNum, typeModel, skinModel, skinColor, animationModel, pos, difficulty);

    if (!bot)
        throw bomberman::core::Errors("[GameAssets]", "Not enough memories!");

    _bots.push_back(bot);
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

std::vector<std::shared_ptr<bomberman::entities::Bots>> bomberman::game::GameAssets::getBots(void)
{
    return _bots;
}

std::vector<std::shared_ptr<bomberman::entities::Players>> bomberman::game::GameAssets::getPlayers(void)
{
    return _players;
}

size_t bomberman::game::GameAssets::getNbrPlayers(void)
{
    return _nbrPlayers;
}

size_t bomberman::game::GameAssets::getNbrBots(void)
{
    return _nbrBots;
}