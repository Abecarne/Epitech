/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Blast
*/

#include "WallPassUp.hpp"
#include "ACharacters.hpp"
#include <iostream>

bomberman::entities::powerup::WallPassUp::WallPassUp(Vector3 position)
{
	this->_position = position;
	this->_rotationAxis = { -90, 0, 30 };
	this->_rotationAngle = 0;
	this->_type = WALLPASSUP;

	this->initModel();
}

bomberman::entities::powerup::WallPassUp::~WallPassUp()
{
	UnloadModel(this->_model);
}

void bomberman::entities::powerup::WallPassUp::render(void)
{
	_model.transform = MatrixRotateXYZ({DEG2RAD * _rotationAxis.x, DEG2RAD * _rotationAxis.y, DEG2RAD * _rotationAxis.z});

	DrawModel(_model, _position, 0.2, WHITE);
}

void bomberman::entities::powerup::WallPassUp::updatePU(bomberman::core::Time deltaTime)
{
	updateAnimation(deltaTime);
}

bomberman::entities::powerup::PowerUpType bomberman::entities::powerup::WallPassUp::getPowerUpType(void)
{
	return (this->_type);
}

Vector3 bomberman::entities::powerup::WallPassUp::getPosition(void)
{
	return (this->_position);
}

void bomberman::entities::powerup::WallPassUp::initModel(void)
{
	if (!FileExists(WALLPASSUP_MODELS))
		throw bomberman::core::Errors("[PowerUp Initialization]", "PowerUp models \"" + std::string(WALLPASSUP_MODELS) + "\" is not found!");

	_model = LoadModel(WALLPASSUP_MODELS);
}

void bomberman::entities::powerup::WallPassUp::updateAnimation(bomberman::core::Time deltaTime)
{
	if (this->_rotationAxis.y < -360) {
		this->_rotationAxis.y = 360;
	}
	this->_rotationAxis.y -= deltaTime * 360 / 2;
}