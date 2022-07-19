/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Blast
*/

#include "FireUp.hpp"
#include "ACharacters.hpp"
#include <iostream>

bomberman::entities::powerup::FireUp::FireUp(Vector3 position)
{
	this->_position = position;
	this->_rotationAxis = { 0, 0, 30 };
	this->_rotationAngle = 0;
	this->_type = FIREUP;

	this->initModel();
}

bomberman::entities::powerup::FireUp::~FireUp()
{
	UnloadModel(this->_model);
}

void bomberman::entities::powerup::FireUp::render(void)
{
	_model.transform = MatrixRotateXYZ({DEG2RAD * _rotationAxis.x, DEG2RAD * _rotationAxis.y, DEG2RAD * _rotationAxis.z});

	DrawModel(_model, _position, 0.4, WHITE);
}

void bomberman::entities::powerup::FireUp::updatePU(bomberman::core::Time deltaTime)
{
	updateAnimation(deltaTime);
}

bomberman::entities::powerup::PowerUpType bomberman::entities::powerup::FireUp::getPowerUpType(void)
{
	return (this->_type);
}

Vector3 bomberman::entities::powerup::FireUp::getPosition(void)
{
	return (this->_position);
}

void bomberman::entities::powerup::FireUp::initModel()
{
	if (!FileExists(FIREUP_MODELS))
		throw bomberman::core::Errors("[PowerUp Initialization]", "PowerUp models \"" + std::string(FIREUP_MODELS) + "\" is not found!");

	_model = LoadModel(FIREUP_MODELS);
}

void bomberman::entities::powerup::FireUp::updateAnimation(bomberman::core::Time deltaTime)
{
	if (this->_rotationAxis.y < -360) {
		this->_rotationAxis.y = 360;
	}
	this->_rotationAxis.y -= deltaTime * 360 / 2;
}