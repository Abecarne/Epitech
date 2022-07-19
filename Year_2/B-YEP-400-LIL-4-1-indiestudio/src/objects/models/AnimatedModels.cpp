/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** AnimatedModels.cpp
*/

#include "AnimatedModels.hpp"

bomberman::models::AnimatedModels::AnimatedModels(std::string modelFile, std::string animationFile, std::string textureFile, Vector3 position, Vector3 scale, Vector3 rotationAxis, float rotationAngle)
{
    BoundingBox box;

    _modelScale = scale;
    _modelPosition = position;
    _rotationAngle = rotationAngle;
    _rotationAxis = rotationAxis;
    _modelAction = bomberman::models::AnimatedModels::DEFAULT;
    _startedTime = GetTime();

    initModel(modelFile, textureFile);
    initAnimation(animationFile);

    box = GetModelBoundingBox(_model);
    _modelSize = {box.max.x - box.min.x, box.max.y - box.min.y, box.max.z - box.min.z};
}

bomberman::models::AnimatedModels::~AnimatedModels(void)
{
    unloadModel();
}

void bomberman::models::AnimatedModels::initModel(std::string modelFile, std::string textureFile)
{
    Texture2D texture;

    if (!FileExists(modelFile.c_str()))
        throw bomberman::core::Errors("[Model Init]", "Model \"" + modelFile + "\" doesn't exist!");
    if (!FileExists(textureFile.c_str()))
        throw bomberman::core::Errors("[Model Init]", "Texture \"" + textureFile + "\" doesn't exist!");
    _model = LoadModel(modelFile.c_str());
    texture = LoadTexture(textureFile.c_str());
    SetMaterialTexture(&_model.materials[0], MATERIAL_MAP_DIFFUSE, texture);
}

void bomberman::models::AnimatedModels::initAnimation(std::string animationFile)
{
    if (!FileExists(animationFile.c_str()))
        throw bomberman::core::Errors("[Characters Initialization]", "Animations file \"" + animationFile + "\" is not found!");
    _animations = LoadModelAnimations(animationFile.c_str(), &_animCount);
    for (unsigned int i = 0; i < _animCount; i++) {
        if (!IsModelAnimationValid(_model, _animations[i]))
            throw bomberman::core::Errors("[Characters Initialization]", "Animations and models aren't compatible!");
    }
    _animFrameCounter = 0;
}

bool bomberman::models::AnimatedModels::isCollision(Vector3 objectPos, Vector3 objectSize, Vector3 objectScale)
{
    BoundingBox actualObject = {{_modelPosition.x - (_modelSize.x * _modelScale.x) / 2,
                                                        _modelPosition.y - (_modelSize.y * _modelScale.y) / 2,
                                                        _modelPosition.z - (_modelSize.z * _modelScale.z) / 2},
                                             { _modelPosition.x + (_modelSize.x * _modelScale.x) / 2,
                                                        _modelPosition.y + (_modelSize.y * _modelScale.y) / 2,
                                                        _modelPosition.z + (_modelSize.z * _modelScale.z) / 2}};

    BoundingBox otherObjects = {{ objectPos.x - (objectSize.x * objectScale.x) / 2,
                                                        objectPos.y - (objectSize.y * objectScale.y) / 2,
                                                        objectPos.z - (objectSize.z * objectScale.z) / 2},
                                             { objectPos.x + (objectSize.x * objectScale.x) / 2,
                                                        objectPos.y + (objectSize.y * objectScale.y) / 2,
                                                        objectPos.z + (objectSize.z * objectScale.z) / 2}};

    if (CheckCollisionBoxes(actualObject, otherObjects))
        return true;
    return false;
}

void bomberman::models::AnimatedModels::unloadModel(void)
{
    for (unsigned int i = 0; i < _animCount; i++)
        UnloadModelAnimation(_animations[i]);
    RL_FREE(_animations);
    UnloadTexture(_model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture);
    UnloadModel(_model);
}

void bomberman::models::AnimatedModels::renderModel(void)
{
    DrawModelEx(_model, _modelPosition, _rotationAxis, _rotationAngle, _modelScale, WHITE);
}

void bomberman::models::AnimatedModels::updateModel(void)
{
    int randomValue;
    float deltaTime = GetTime() - _startedTime;

    if (deltaTime > 0.008) {
        _startedTime = GetTime();
        _animFrameCounter++;
    }
    UpdateModelAnimation(_model, _animations[_modelAction], _animFrameCounter);
    if (_animFrameCounter >= _animations[_modelAction].frameCount) {
        if (_modelAction == bomberman::models::AnimatedModels::DEFAULT) {
            randomValue = GetRandomValue(0, 10);
            if (randomValue == 0 && _animCount > 1)
                _modelAction = bomberman::models::AnimatedModels::ACTION1;
            else if (randomValue == 1 && _animCount > 2)
                _modelAction = bomberman::models::AnimatedModels::ACTION2;
            else
                _modelAction = bomberman::models::AnimatedModels::DEFAULT;
        } else
            _modelAction = bomberman::models::AnimatedModels::DEFAULT;
        _animFrameCounter = 0;
    }
}

void bomberman::models::AnimatedModels::setPosition(Vector3 position)
{
    _modelPosition = position;
}

Vector3 bomberman::models::AnimatedModels::getPosition(void)
{
    return _modelPosition;
}

Vector3 bomberman::models::AnimatedModels::getSize(void)
{
    return _modelSize;
}

Vector3 bomberman::models::AnimatedModels::getScale(void)
{
    return _modelScale;
}