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
    bomberman::models::StaticModels modelTmp(undestructibleMesh, pos, {3.5f, 3.5f, 3.5f}, {0, 0, 0}, 0);

    _scale = 3.5f;
    _size = modelTmp.getSize();
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
    for (auto models : this->_floorModels)
        models->renderModel();
    for (auto models : this->_wallsModels)
        models->renderModel();
    for (auto models : this->_lootingBox)
        models->render();
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

    if ((size_t)getUndestructibleCount() <= _modelsCount) {
        _state = bomberman::environment::GameBoard::gameboardState::DESTRUCTIBLE;
        _modelsCount = 0;
        return;
    }

    for (int heigthCount = (_height / 2) * -1; heigthCount <= (int)_height / 2; heigthCount++) {
        for (int widthCount = (_width / 2) * -1; widthCount <= (int)_width / 2; widthCount++) {
            if (heigthCount == (int)(_height / 2) * -1 || heigthCount == (int)(_height / 2) || widthCount == (int)_width / 2 * -1 || widthCount == (int)(_width / 2) || (widthCount % 2 == 1 && heigthCount % 2 == 0)) {
                if (models == _modelsCount) {
                    _wallsModels.push_back(createStaticModel(_undestructibleBox,
                    {(_size.x * _scale) * (heigthCount + _position.x), (_size.y * _scale) + 1.5f, (_size.z * _scale) * (widthCount + _position.z)}));
                    _modelsCount++;
                    return;
                } else
                    models++;
            } else if (widthCount < 0 && ((widthCount * -1) % 2 == 1 && heigthCount % 2 == 0)) {
                if (models == _modelsCount) {
                    _wallsModels.push_back(createStaticModel(_undestructibleBox,
                    {(_size.x * _scale) * (heigthCount + _position.x), (_size.y * _scale) + 1.5f, (_size.z * _scale) * (widthCount + _position.z)}));
                    _modelsCount++;
                    return;
                } else
                    models++;
            }
        }
    }
}

bool bomberman::environment::GameBoard::isPlayerPosition(int width, int height)
{
    std::vector<std::pair<int, int>> playersPos = {{(_width / 2) * -1 + 1, (_height / 2) * -1 + 1}, {(_width / 2) * -1 + 2, (_height / 2) * -1 + 1}, {(_width / 2) * -1 + 1, (_height / 2) * -1 + 2},
                                                   {(_width / 2) * -1 + 1, (_height / 2) - 1}, {(_width / 2) * -1 + 1, (_height / 2) - 2}, {(_width / 2) * -1 + 2, (_height / 2) - 1},
                                                   {(_width / 2) - 1, (_height / 2) - 1}, {(_width / 2) - 1, (_height / 2) - 2}, {(_width / 2) - 2, (_height / 2) - 1},
                                                   {(_width / 2) - 1, (_height / 2) * -1 + 1}, {(_width / 2) - 1, (_height / 2) * -1 + 2}, {(_width / 2) - 2, (_height / 2) * -1 + 1}};

    for (auto pos : playersPos) {
        if (pos.first == width && pos.second == height)
            return true;
   }
    return false;
}

int bomberman::environment::GameBoard::getDestructibleCount(void)
{
    int count = 0;

    for (int heigthCount = (_height / 2) * -1; heigthCount <= (int)_height / 2; heigthCount++) {
        for (int widthCount = (_width / 2) * -1; widthCount <= (int)_width / 2; widthCount++) {
            if (isPlayerPosition(widthCount, heigthCount))
                continue;
            if (heigthCount == (int)(_height / 2) * -1 || heigthCount == (int)(_height / 2) || widthCount == (int)_width / 2 * -1 || widthCount == (int)(_width / 2) || (widthCount % 2 == 1 && heigthCount % 2 == 0))
                continue;
            if (widthCount < 0 && ((widthCount * -1) % 2 == 1 && heigthCount % 2 == 0))
                continue;
            count++;
        }
    }

    return count;
}

void bomberman::environment::GameBoard::createLootBox(std::string mesh, Vector3 position)
{
    std::shared_ptr<bomberman::entities::LootBox> lootBox;
    Vector3 scale = { _scale, _scale, _scale };
    Vector3 rotationAxis = { 1.0f, 0.0f, 0.0f };

    if (GetRandomValue(0, 1) == 1)
        return;

    lootBox = std::make_shared<bomberman::entities::LootBox>(mesh, position, _scale);

    if (!lootBox)
        throw bomberman::core::Errors("[LootBox]", "Can't create lootBox!");

    _lootingBox.push_back(lootBox);
}

void bomberman::environment::GameBoard::loadDestructibleBox(void)
{
    int count = 0;
    size_t models = 0;

    if ((size_t)getDestructibleCount() <= _modelsCount) {
        _state = bomberman::environment::GameBoard::gameboardState::INVISIBLE_BOX;
        _modelsCount = 0;
        return;
    }

    for (int heigthCount = (_height / 2) * -1; heigthCount <= (int)_height / 2; heigthCount++) {
        for (int widthCount = (_width / 2) * -1; widthCount <= (int)_width / 2; widthCount++) {
            if (isPlayerPosition(widthCount, heigthCount))
                continue;
            if (heigthCount == (int)(_height / 2) * -1 || heigthCount == (int)(_height / 2) || widthCount == (int)_width / 2 * -1 || widthCount == (int)(_width / 2) || (widthCount % 2 == 1 && heigthCount % 2 == 0))
                continue;
            if (widthCount < 0 && ((widthCount * -1) % 2 == 1 && heigthCount % 2 == 0))
                continue;
            if (models == _modelsCount) {
                createLootBox(LOOTING_BOX, {(_size.x * _scale) * (heigthCount + _position.x),
                (_size.y * _scale) + 1.5f, (_size.z * _scale) * (widthCount + _position.z)});
                _modelsCount++;
                return;
            } else
                models++;
        }
    }

}

bool bomberman::environment::GameBoard::isCorrectPos(Vector3 pos)
{
    for (auto block : _wallsModels) {
        if (pos.x == block->getPosition().x && pos.y == block->getPosition().y && pos.z == block->getPosition().z)
            return true;
    }
    return false;
}

void bomberman::environment::GameBoard::loadInvisibleBox(void)
{
    size_t models = 0;

    if ((_width * _height) <= _modelsCount) {
        _isFinish = true;
        _modelsCount = 0;
        return;
    }

    for (int heigthCount = (_height / 2) * -1; heigthCount <= (int)_height / 2; heigthCount++) {
        for (int widthCount = (_width / 2) * -1; widthCount <= (int)_width / 2; widthCount++) {
            if (models == _modelsCount) {
                if (!isCorrectPos({(_size.x * _scale) * (heigthCount + _position.x), (_size.y * _scale) + 1.5f, (_size.z * _scale) * (widthCount + _position.z)}))
                    _invisibleBox.push_back(createStaticModel({(_size.x * _scale) * (heigthCount + _position.x), (_size.y * _scale) + 1.5f, (_size.z * _scale) * (widthCount + _position.z)}));
                _modelsCount++;
                return;
            } else
                models++;
        }
    }
}

void bomberman::environment::GameBoard::loadNextFloorModels(void)
{
    size_t models = 0;

    if ((_width * _height) <= _modelsCount) {
        _state = bomberman::environment::GameBoard::gameboardState::UNDESTRUCTIBLE;
        _modelsCount = 0;
        return;
    }

    for (int heigthCount = (_height / 2) * -1; heigthCount <= (int)_height / 2; heigthCount++) {
        for (int widthCount = (_width / 2) * -1; widthCount <= (int)_width / 2; widthCount++) {
            if (models == _modelsCount) {
                _floorModels.push_back(createStaticModel(_floor, {(_size.x * _scale) * (heigthCount + _position.x),
                (_size.y), (_size.z * _scale) * (widthCount + _position.z)}));
                _modelsCount++;
                return;
            }
            models++;
        }
    }
}

bool bomberman::environment::GameBoard::getAssetsState(void)
{
    return this->_isFinish;
}

void bomberman::environment::GameBoard::loadNextModels(void)
{
    switch ((int)_state) {
        case (int)bomberman::environment::GameBoard::gameboardState::FLOOR:
            this->loadNextFloorModels();
            break;
        case (int)bomberman::environment::GameBoard::gameboardState::DESTRUCTIBLE:
            this->loadDestructibleBox();
            break;
        case (int)bomberman::environment::GameBoard::gameboardState::INVISIBLE_BOX:
            this->loadInvisibleBox();
            break;
        case (int)bomberman::environment::GameBoard::gameboardState::UNDESTRUCTIBLE:
            this->loadNextUndestructibleModels();
            break;
    }
}

std::shared_ptr<bomberman::models::StaticModels> bomberman::environment::GameBoard::createStaticModel(Vector3 position)
{
    Mesh box = GenMeshCube(this->_size.x, this->_size.y, this->_size.z);
    Vector3 scale = { 1, 1, 1 };
	Vector3 rotationAxis = { 1.0f, 0.0f, 0.0f };
    std::shared_ptr<bomberman::models::StaticModels> staticModel = std::make_shared<bomberman::models::StaticModels>(box, WHITE, position, scale, rotationAxis, 0.0);

    if (!staticModel)
        bomberman::core::Errors("[Static Models]", "Not enough memories!");
    return staticModel;
}

std::shared_ptr<bomberman::models::StaticModels> bomberman::environment::GameBoard::createStaticModel(std::string Mesh, Vector3 position)
{
    Vector3 scale = { _scale, _scale, _scale };
    Vector3 rotationAxis = { 1.0f, 0.0f, 0.0f };
    std::shared_ptr<bomberman::models::StaticModels> staticModel = std::make_shared<bomberman::models::StaticModels>(Mesh, position, scale, rotationAxis, 0);

    if (!staticModel)
        bomberman::core::Errors("[Static Models]", "Not enough memories!");
    return staticModel;
}

Vector3 bomberman::environment::GameBoard::getPosition(void)
{
    return this->_position;
}

int bomberman::environment::GameBoard::getWidth(void)
{
    return this->_width;
}

int bomberman::environment::GameBoard::getHeight(void)
{
    return this->_height;
}

Vector3 bomberman::environment::GameBoard::getBlockSize(void)
{
    return this->_size;
}

float bomberman::environment::GameBoard::getScale(void)
{
    return this->_scale;
}

std::vector<std::shared_ptr<bomberman::models::StaticModels>> bomberman::environment::GameBoard::getInvisibleBlock(void)
{
    return this->_invisibleBox;
}

std::vector<std::shared_ptr<bomberman::models::StaticModels>> bomberman::environment::GameBoard::getWallModels(void)
{
    return this->_wallsModels;
}

std::vector<std::shared_ptr<bomberman::models::StaticModels>> bomberman::environment::GameBoard::getFloorModels(void)
{
    return this->_floorModels;
}

std::vector<std::shared_ptr<bomberman::entities::LootBox>> &bomberman::environment::GameBoard::getLootBoxes(void)
{
    return this->_lootingBox;
}

Vector3 bomberman::environment::GameBoard::getInvisibleBlockPosAtEntity(std::shared_ptr<bomberman::entities::ACharacters> entity)
{
    for (auto block : this->_invisibleBox) {
        if (entity->isCollision(block->getPosition(), block->getSize(), block->getScale()))
            return block->getPosition();
    }
    return {-100, -100, -100};
}

Vector3 bomberman::environment::GameBoard::getInvisibleBlockPosAtEntity(bomberman::entities::ACharacters *entity)
{
    for (auto block : this->_invisibleBox) {
        if (entity->isCollision(block->getPosition(), block->getSize(), block->getScale()))
            return block->getPosition();
    }
    return {-100, -100, -100};
}
