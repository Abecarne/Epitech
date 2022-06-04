/*
** EPITECH PROJECT, 2022
** Pikmins
** File description:
** Players.cpp
*/

#include "Players.hpp"

bomberman::entities::Players::Players(std::string typeModel, std::string skinModel, bomberman::entities::ACharacters::characterColors skinColor, std::string animationModel, Vector3 pos)
{
    BoundingBox box;

    _characterPos = pos;
    _rotationAxis = (Vector3){1.0f, 0.0f, 0.0f};
    _rotationAngle = -90;
    _characterActions = bomberman::entities::ACharacters::actions::IDLE;

    initCharacterMesh(typeModel, skinModel, skinColor);
    initCharacterAnimations(animationModel);

    box = GetModelBoundingBox(_characterModel);
    _characterSize = (Vector3){box.max.x - box.min.x, box.max.y - box.min.y, box.max.z - box.min.z};
}

bomberman::entities::Players::~Players()
{
    unloadCharacter();
}

void bomberman::entities::Players::updateCharacter(void)
{
    _animFrameCounter++;
    UpdateModelAnimation(_characterModel, _animations[_characterActions], _animFrameCounter);
    if (_animFrameCounter >= _animations[_characterActions].frameCount)
        _animFrameCounter = 0;
}