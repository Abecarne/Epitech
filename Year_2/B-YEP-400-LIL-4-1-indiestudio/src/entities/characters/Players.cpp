/*
** EPITECH PROJECT, 2022
** Pikmins
** File description:
** Players.cpp
*/

#include "ACharacters.hpp"
#include "Players.hpp"
#include "GameAssets.hpp"

bomberman::entities::Players::Players(bomberman::entities::ACharacters::playerNum playerNum, std::string typeModel, std::string skinModel, bomberman::entities::ACharacters::characterColors skinColor, std::string animationModel, Vector3 pos) :
bomberman::entities::ACharacters()
{
    BoundingBox box;

    this->_stats = std::make_shared<bomberman::entities::CharacterStats>();
    if (!this->_stats)
        throw bomberman::core::Errors("[Player]", "Player stat can't be created!");
    this->_characterPos = pos;
    this->_rotationAxis = {0.0f, 0.0f, 0.0f};
    this->_characterActions = bomberman::entities::ACharacters::actions::IDLE;
    this->_playerNum = playerNum;
    this->_rotationAngle = 1;

    if (this->_playerNum == bomberman::entities::ACharacters::playerNum::PLAYER1 ||
        this->_playerNum == bomberman::entities::ACharacters::playerNum::PLAYER3)
        this->_rotationAxis = {90, 0, 0};
    else
       this-> _rotationAxis = {90, 180, 0};

    initCharacterMesh(typeModel, skinModel, skinColor);
    initCharacterAnimations(animationModel);
    box = GetModelBoundingBox(this->_characterModel);
    this->_characterSize = Vector3Subtract(box.max, box.min);
}

bomberman::entities::Players::~Players()
{
    this->unloadCharacter();
}

Vector4 bomberman::entities::Players::getNewDirection(bomberman::core::Time deltaTime, int action)
{
    float speed = this->_stats->getPlayerSpeed() * this->_stats->getPlayerSpeedBonus() * deltaTime;
    float oldRotation = this->getCharacterRotation().y;

    if (action == 0)
        return {speed, 0.0f, 0.0f, -90.0f};
    if (action == 2)
        return {0.0f, 0.0f, speed, 0.0f};
    if (action == 1)
        return {-speed, 0.0f, 0.0f, 90.0f};
    if (action == 3)
        return {0.0f, 0.0f, -speed, 180.0f};
    return {0.0f, 0.0f, 0.0f, oldRotation};
}

void bomberman::entities::Players::move(bomberman::core::Time deltaTime, int action)
{
    Vector3 actualPos = this->getCharacterPos();
    Vector4 newDir = this->getNewDirection(deltaTime, action);
    Vector3 newPos = bomberman::utils::Vector3AddVector4(actualPos, newDir);
    float oldRotation = newDir.w;

    if (!this->checkCollisionWithMap(newDir))
        this->moveCharacter(newPos, oldRotation);
}