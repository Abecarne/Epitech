/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Blast
*/

#include "SpeedUp.hpp"
#include "ACharacters.hpp"
#include <iostream>

bomberman::entities::powerup::SpeedUp::SpeedUp(Vector3 position)
{
	this->_position = position;
	this->_rotationAxis = { 230, 0, 0 };
	this->_rotationAngle = 0;
	this->_type = SPEEDUP;

	this->initModel();
}

bomberman::entities::powerup::SpeedUp::~SpeedUp()
{
	UnloadModel(this->_model);
}

void bomberman::entities::powerup::SpeedUp::render(void)
{
	_model.transform = MatrixRotateXYZ({DEG2RAD * _rotationAxis.x, DEG2RAD * _rotationAxis.y, DEG2RAD * _rotationAxis.z});

	DrawModel(_model, _position, 0.5, WHITE);
}

void bomberman::entities::powerup::SpeedUp::updatePU(bomberman::core::Time deltaTime)
{
	updateAnimation(deltaTime);
}

bomberman::entities::powerup::PowerUpType bomberman::entities::powerup::SpeedUp::getPowerUpType(void)
{
	return (this->_type);
}

Vector3 bomberman::entities::powerup::SpeedUp::getPosition(void)
{
	return (this->_position);
}

void bomberman::entities::powerup::SpeedUp::initModel(void)
{
	if (!FileExists(SPEEDUP_MODELS))
		throw bomberman::core::Errors("[PowerUp Initialization]", "PowerUp models \"" + std::string(SPEEDUP_MODELS) + "\" is not found!");

	_model = LoadModel(SPEEDUP_MODELS);
}

void bomberman::entities::powerup::SpeedUp::updateAnimation(bomberman::core::Time deltaTime)
{
	if (this->_rotationAxis.y < -360) {
		this->_rotationAxis.y = 360;
	}
	this->_rotationAxis.y -= deltaTime * 360 / 2;
}