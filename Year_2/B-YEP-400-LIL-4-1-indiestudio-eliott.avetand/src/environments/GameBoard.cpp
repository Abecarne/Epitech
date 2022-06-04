/*
** EPITECH PROJECT, 2022
** Pikmins
** File description:
** BoardGame.cpp
*/

#include "GameBoard.hpp"
#include <iostream>

void bomberman::environment::GameBoard::init(size_t width, size_t height, Vector3 pos, std::string floorMesh, std::string destructibleMesh, std::string undestructibleMesh)
{
    _scale = 3.5f;
    _position = pos;
    _destructibleBox = destructibleMesh;
    _undestructibleBox = undestructibleMesh;
    _width = width;
    _height = height;
    _floor = floorMesh;
    _modelsCount = 0;
    _isFinish = false;
    _state = bomberman::environment::GameBoard::gameboardState::FLOOR;
}

void bomberman::environment::GameBoard::drawGameBoard(void)
{
    for (auto models : _gameBoardModels)
        models->renderModel();
}

int bomberman::environment::GameBoard::getUndestructibleCount(void)
{
    int count = 0;

    for (int heigthCount = (_height / 2) * -1; heigthCount <= (int)_height / 2; heigthCount++) {
        for (int widthCount = (_width / 2) * -1; widthCount <= (int)_width / 2; widthCount++) {
            if (heigthCount == (int)(_height / 2) * -1 || heigthCount == (int)(_height / 2) || widthCount == (int)_width / 2 * -1 || widthCount == (int)(_width / 2) || (widthCount % 2 == 1 && heigthCount % 2 == 0))
                count++;
            else if (widthCount < 0 && ((widthCount * -1) % 2 == 1 && heigthCount % 2 == 0))
                count++;
        }
    }
    return count;
}

void bomberman::environment::GameBoard::loadNextUndestructibleModels(void)
{
    size_t models = 0;
    bomberman::models::StaticModels modelTmp(_undestructibleBox, (Vector3){0, 0, 0}, (Vector3){_scale, _scale, _scale}, (Vector3){0, 0, 0}, 0);

    if ((size_t)getUndestructibleCount() <= _modelsCount) {
        _isFinish = true;
        return;
    }

    for (int heigthCount = (_height / 2) * -1; heigthCount <= (int)_height / 2; heigthCount++) {
        for (int widthCount = (_width / 2) * -1; widthCount <= (int)_width / 2; widthCount++) {
            if (heigthCount == (int)(_height / 2) * -1 || heigthCount == (int)(_height / 2) || widthCount == (int)_width / 2 * -1 || widthCount == (int)(_width / 2) || (widthCount % 2 == 1 && heigthCount % 2 == 0)) {
                if (models == _modelsCount) {
                    _gameBoardModels.push_back(createStaticModel(_undestructibleBox,
                    (Vector3){(modelTmp.getSize().x * _scale) * (heigthCount + _position.x), (modelTmp.getSize().y * _scale) + 20, (modelTmp.getSize().z * _scale) * (widthCount + _position.z)}));
                    _modelsCount++;
                    return;
                } else
                    models++;
            } else if (widthCount < 0 && ((widthCount * -1) % 2 == 1 && heigthCount % 2 == 0)) {
                if (models == _modelsCount) {
                    _gameBoardModels.push_back(createStaticModel(_undestructibleBox,
                    (Vector3){(modelTmp.getSize().x * _scale) * (heigthCount + _position.x), (modelTmp.getSize().y * _scale) + 20, (modelTmp.getSize().z * _scale) * (widthCount + _position.z)}));
                    _modelsCount++;
                    return;
                } else
                    models++;
            }
        }
    }
}

void bomberman::environment::GameBoard::loadNextFloorModels(void)
{
    size_t models = 0;
    bomberman::models::StaticModels modelTmp(_floor, (Vector3){0, 0, 0}, (Vector3){_scale, _scale, _scale}, (Vector3){0, 0, 0}, 0);

    if ((_width * _height) <= _modelsCount) {
        _state = bomberman::environment::GameBoard::gameboardState::UNDESTRUCTIBLE;
        _modelsCount = 0;
        return;
    }

    for (int heigthCount = (_height / 2) * -1; heigthCount <= (int)_height / 2; heigthCount++) {
        for (int widthCount = (_width / 2) * -1; widthCount <= (int)_width / 2; widthCount++) {
            if (models == _modelsCount) {
                _gameBoardModels.push_back(createStaticModel(_floor, (Vector3){(modelTmp.getSize().x * _scale) * (heigthCount + _position.x),
                    20 - (modelTmp.getSize().y), (modelTmp.getSize().z * _scale) * (widthCount + _position.z)}));
                _modelsCount++;
                return;
            }
            models++;
        }
    }
}

bool bomberman::environment::GameBoard::getAssetsState(void)
{
    return _isFinish;
}

void bomberman::environment::GameBoard::loadNextModels(void)
{
    switch ((int)_state) {
        case (int)bomberman::environment::GameBoard::gameboardState::FLOOR:
            loadNextFloorModels();
            break;
        case (int)bomberman::environment::GameBoard::gameboardState::UNDESTRUCTIBLE:
            loadNextUndestructibleModels();
            break;
    }
}

std::shared_ptr<bomberman::models::StaticModels> bomberman::environment::GameBoard::createStaticModel(std::string Mesh, Vector3 position)
{
    std::shared_ptr<bomberman::models::StaticModels> staticModel;

    staticModel = std::make_shared<bomberman::models::StaticModels>(Mesh, position, (Vector3){_scale, _scale, _scale}, (Vector3){1.0f, 0.0f, 0.0f}, 0);

    if (!staticModel)
        bomberman::core::Errors("[Static Models]", "Not enough memories!");

    return staticModel;
}

void bomberman::environment::GameBoard::initFloorMesh(size_t width, size_t heigth, std::string floorMesh)
{
    bomberman::models::StaticModels modelTmp(floorMesh, (Vector3){0, 0, 0}, (Vector3){_scale, _scale, _scale}, (Vector3){0, 0, 0}, 0);

    for (int heigthCount = (heigth / 2) * -1; heigthCount <= (int)heigth / 2; heigthCount++) {
        for (int widthCount = (width / 2) * -1; widthCount <= (int)width / 2; widthCount++)
            _gameBoardModels.push_back(createStaticModel(floorMesh, (Vector3){(modelTmp.getSize().x * _scale) * (heigthCount + _position.x),
                20 - (modelTmp.getSize().y), (modelTmp.getSize().z * _scale) * (widthCount + _position.z)}));
    }
}

void bomberman::environment::GameBoard::initDestructibleMesh(size_t width, size_t heigth, std::string destructibleMesh)
{
    // bomberman::models::StaticModels modelTmp(destructibleMesh, (Vector3){0, 0, 0}, (Vector3){0, 0, 0}, (Vector3){0, 0, 0}, 0);

    // for (size_t widthCount = 0; widthCount < width; widthCount++) {
    //     for (size_t heigthCount = 0; heigthCount < heigth; heigthCount++) {
    //         if (heigthCount == 0 || heigthCount == heigth - 1 || widthCount == 0 || widthCount == width - 1 || (widthCount % 2 == 0 && heigthCount % 2 == 0))
    //             continue;
    //         if (heigthCount == 2 && widthCount == 2)
    //             _gameBoardModels.insert(std::make_pair<bomberman::environment::GameBoard::gbBlockTypes,
    //                 std::shared_ptr<bomberman::models::StaticModels>>(bomberman::environment::GameBoard::gbBlockTypes::DESTRUCTIBLE,
    //                 createStaticModel(destructibleMesh, (Vector3){(modelTmp.getSize().x / 2) * (widthCount + 0), modelTmp.getSize().y + 0, (modelTmp.getSize().z / 2) * (heigthCount + 0)})));
    //     }
    // }
}

void bomberman::environment::GameBoard::initUndestructibleMesh(size_t width, size_t heigth, std::string undestructibleMesh)
{
    bomberman::models::StaticModels modelTmp(undestructibleMesh, (Vector3){0, 0, 0}, (Vector3){_scale, _scale, _scale}, (Vector3){0, 0, 0}, 0);

    for (int heigthCount = (heigth / 2) * -1; heigthCount <= (int)heigth / 2; heigthCount++) {
        for (int widthCount = (width / 2) * -1; widthCount <= (int)width / 2; widthCount++) {
            if (heigthCount == (int)(heigth / 2) * -1 || heigthCount == (int)(heigth / 2) || widthCount == (int)width / 2 * -1 || widthCount == (int)(width / 2) || (widthCount % 2 == 1 && heigthCount % 2 == 0))
                _gameBoardModels.push_back(createStaticModel(undestructibleMesh,
                (Vector3){(modelTmp.getSize().x * _scale) * (heigthCount + _position.x), (modelTmp.getSize().y * _scale) + 20, (modelTmp.getSize().z * _scale) * (widthCount + _position.z)}));
            else if (widthCount < 0 && ((widthCount * -1) % 2 == 1 && heigthCount % 2 == 0))
                _gameBoardModels.push_back(createStaticModel(undestructibleMesh,
                (Vector3){(modelTmp.getSize().x * _scale) * (heigthCount + _position.x), (modelTmp.getSize().y * _scale) + 20, (modelTmp.getSize().z * _scale) * (widthCount + _position.z)}));
        }
    }
}