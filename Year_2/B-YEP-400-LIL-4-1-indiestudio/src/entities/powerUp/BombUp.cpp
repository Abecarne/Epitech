/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Blast
*/

#include "BombUp.hpp"
#include "ACharacters.hpp"
#include <iostream>

bomberman::entities::powerup::BombUp::BombUp(Vector3 position)
{
	this->_position = position;
	this->_rotationAxis = { 180, -90, 30 };
	this->_rotationAngle = 0;
	this->_type = BOMBUP;

	this->initModel();
}

bomberman::entities::powerup::BombUp::~BombUp()
{
	UnloadModel(this->_model);
}

void bomberman::entities::powerup::BombUp::render(void)
{
	_model.transform = MatrixRotateXYZ({DEG2RAD * _rotationAxis.x, DEG2RAD * _rotationAxis.y, DEG2RAD * _rotationAxis.z});

	DrawModel(_model, _position, 2, WHITE);
}

void bomberman::entities::powerup::BombUp::updatePU(bomberman::core::Time deltaTime)
{
	updateAnimation(deltaTime);
}

bomberman::entities::powerup::PowerUpType bomberman::entities::powerup::BombUp::getPowerUpType(void)
{
	return (this->_type);
}

Vector3 bomberman::entities::powerup::BombUp::getPosition(void)
{
	return (this->_position);
}

void bomberman::entities::powerup::BombUp::initModel(void)
{
	if (!FileExists(BOMBUP_MODELS))
		throw bomberman::core::Errors("[PowerUp Initialization]", "PowerUp models \"" + std::string(BOMBUP_MODELS) + "\" is not found!");

	_model = LoadModel(BOMBUP_MODELS);
}

void bomberman::entities::powerup::BombUp::updateAnimation(bomberman::core::Time deltaTime)
{
	if (this->_rotationAxis.y < -360) {
		this->_rotationAxis.y = 360;
	}
	this->_rotationAxis.y -= deltaTime * 360 / 2;
}