/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Blast
*/

#include "Blast.hpp"
#include <iostream>

bomberman::entities::Blast::Blast(Texture2D texture, Vector3 position, int distanceFromBomb)
{
    this->_pos = position;
    this->_rotationAxis = {90, 0, 0};
    this->_distanceFromBomb = distanceFromBomb;

    this->_animationTime = GetTime();
    this->_animFrameCounter = 0;

    this->initModel(texture);
    this->initAnimations();
}

bomberman::entities::Blast::~Blast(void)
{
    for (unsigned int i = 0; i < _animCount; i++)
        UnloadModelAnimation(_animations[i]);
    RL_FREE(_animations);
    UnloadModel(_model);
}

void bomberman::entities::Blast::render(void)
{
    _model.transform = MatrixRotateXYZ({DEG2RAD * _rotationAxis.x, DEG2RAD * _rotationAxis.y, DEG2RAD * _rotationAxis.z});
    DrawBoundingBox(this->_boundingBox, GREEN);
    DrawModel(_model, _pos, 6, WHITE);
}

void bomberman::entities::Blast::initAnimations(void)
{
    _animCount = 0;

    if (!FileExists(BLAST_ANIMATIONS))
        throw bomberman::core::Errors("[Characters Initialization]", "Animations file \"" + std::string(BLAST_ANIMATIONS) + "\" is not found!");
    _animations = LoadModelAnimations(BLAST_ANIMATIONS, &_animCount);
    for (unsigned int i = 0; i < _animCount; i++) {
        if (!IsModelAnimationValid(_model, _animations[i]))
            throw bomberman::core::Errors("[Characters Initialization]", "Animations and models aren't compatible!");
    }

    _animFrameCounter = 0;
}

void bomberman::entities::Blast::initModel(Texture2D texture)
{
    if (!FileExists(BLAST_MODELS))
        throw bomberman::core::Errors("[Characters Initialization]", "Characters models \"" + std::string(BLAST_MODELS) + "\" is not found!");

    _model = LoadModel(BLAST_MODELS);

    if (_model.boneCount == 0)
        throw bomberman::core::Errors("[Characters Initialization]", "Characters files is not found or don't have any armature!");

    SetMaterialTexture(&_model.materials[0], MATERIAL_MAP_DIFFUSE, texture);

    this->_boundingBox = GetModelBoundingBox(_model);
    this->_size = {_boundingBox.max.x - _boundingBox.min.x, _boundingBox.max.y - _boundingBox.min.y, _boundingBox.max.z - _boundingBox.min.z};
    this->_boundingBox = {
        {
            this->_pos.x - (this->_size.x * 1) / 2,
            this->_pos.y - (this->_size.y * 1) / 2,
            this->_pos.z - (this->_size.z * 1) / 2
        },
        {
            this->_pos.x + (this->_size.x * 1) / 2,
            this->_pos.y + (this->_size.y * 1) / 2,
            this->_pos.z + (this->_size.z * 1) / 2
        }
    };
}

void bomberman::entities::Blast::updateAnimation(void)
{
    float deltaTime = GetTime() - _animationTime;

    if (deltaTime > 0.0001) {
        _animFrameCounter++;
        _animationTime = GetTime();
    }

    UpdateModelAnimation(_model, _animations[0], _animFrameCounter);
    if (_animFrameCounter >= _animations[0].frameCount)
        _animFrameCounter = 0;
}

void bomberman::entities::Blast::update(void)
{
    updateAnimation();
}

Vector3 bomberman::entities::Blast::getPosition(void)
{
    return _pos;
}