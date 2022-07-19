/*
** EPITECH PROJECT, 2022
** Pikmins
** File description:
** Bombs.cpp
*/

#include "LootBox.hpp"
#include "Game.hpp"

bomberman::entities::LootBox::LootBox(std::string mesh, Vector3 position, float boxScale)
{
    Vector3 scale = { boxScale, boxScale, boxScale };
    Vector3 rotationAxis = { 1.0f, 0.0f, 0.0f };

    this->_gameInstance = bomberman::game::Game::getInstance();

    this->_isDestroyed = false;

    if (GetRandomValue(0, 1) == 1)
        this->_bonusType = (bomberman::entities::powerup::PowerUpType)GetRandomValue(1, 4);
    else
        this->_bonusType = bomberman::entities::powerup::PowerUpType::NOTHING;

    this->_model = std::make_shared<bomberman::models::StaticModels>(mesh, position, scale, rotationAxis, 0);
    if (!this->_model)
        bomberman::core::Errors("[Static Models]", "Not enough memories!");
}

bomberman::entities::LootBox::~LootBox()
{
    // Void
}

void bomberman::entities::LootBox::render(void)
{
    if (this->_isDestroyed == false)
        this->_model->renderModel();
}

void bomberman::entities::LootBox::destroyBox(void)
{
    if (_bonusType != bomberman::entities::powerup::PowerUpType::NOTHING)
        _gameInstance->addPowerUpToGame(_model->getPosition(), _bonusType);
    this->_isDestroyed = true;
}

std::shared_ptr<bomberman::models::StaticModels> bomberman::entities::LootBox::getModel(void)
{
    return _model;
}

bool bomberman::entities::LootBox::isDestroyed(void) const
{
    return this->_isDestroyed;
}