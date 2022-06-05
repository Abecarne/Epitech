/*
** EPITECH PROJECT, 2022
** Pikmins
** File description:
** Characters.cpp
*/

#include "ACharacters.hpp"

std::string bomberman::entities::ACharacters::getChoosenModel(std::string typeModel, std::string skinModel)
{
    std::string fileName = typeModel + "_" + skinModel;

    return fileName;
}

std::string bomberman::entities::ACharacters::getChoosenSkin(std::string typeModel, std::string skinModel, bomberman::entities::ACharacters::characterColors skinColor)
{
    std::string fileName = typeModel + "_" + skinModel + "_" + std::to_string(skinColor);

    return fileName;
}

void bomberman::entities::ACharacters::initCharacterAnimations(std::string animation)
{
    std::string animationPath = std::string(CHARACTERS_FOLDERS).append("animations/" + animation + ".iqm");

    if (!FileExists(animationPath.c_str()))
        throw bomberman::core::Errors("[Characters Initialization]", "Animations file \"" + animationPath + "\" is not found!");
    _animations = LoadModelAnimations(animationPath.c_str(), &_animCount);
    for (unsigned int i = 0; i < _animCount; i++) {
        if (!IsModelAnimationValid(_characterModel, _animations[i]))
            throw bomberman::core::Errors("[Characters Initialization]", "Animations and models aren't compatible!");
    }
    _animFrameCounter = 0;
}

void bomberman::entities::ACharacters::initCharacterMesh(std::string typeModel, std::string skinModel, bomberman::entities::ACharacters::characterColors skinColor)
{
    std::string texturePath = std::string(CHARACTERS_FOLDERS).append("textures/" + getChoosenSkin(typeModel, skinModel, skinColor) + ".png");
    std::string modelPath = std::string(CHARACTERS_FOLDERS).append(getChoosenModel(typeModel, skinModel) + ".iqm");
    Texture2D texture;

    if (!FileExists(modelPath.c_str())) {
        throw bomberman::core::Errors("[Characters Initialization]", "Characters models \"" + modelPath + "\" is not found!");
    }
    _characterModel = LoadModel(modelPath.c_str());

    if (!FileExists(texturePath.c_str()))
        throw bomberman::core::Errors("[Characters Initialization]", "Characters texture \"" + texturePath + "\" is not found!");
    texture = LoadTexture(texturePath.c_str());

    if (_characterModel.boneCount == 0)
        throw bomberman::core::Errors("[Characters Initialization]", "Characters files is not found or don't have any armature!");

    SetMaterialTexture(&_characterModel.materials[0], MATERIAL_MAP_DIFFUSE, texture);
}

void bomberman::entities::ACharacters::reloadCharacter(std::string typeModel, std::string skinModel, bomberman::entities::ACharacters::characterColors skinColor, std::string animation)
{
    unloadCharacter();
    initCharacterMesh(typeModel, skinModel, skinColor);
    initCharacterAnimations(animation);
}

void bomberman::entities::ACharacters::unloadCharacter(void)
{
    for (unsigned int i = 0; i < _animCount; i++)
        UnloadModelAnimation(_animations[i]);
    RL_FREE(_animations);
    UnloadModel(_characterModel);
}

void bomberman::entities::ACharacters::renderCharacter(void)
{
    DrawModelEx(_characterModel, _characterPos, _rotationAxis, _rotationAngle, (Vector3){0.5f, 0.5f, 0.5f}, WHITE);
}

void bomberman::entities::ACharacters::moveCharacter(Vector3 newPosition, float rotationAngle)
{
    if (_characterActions != bomberman::entities::ACharacters::RUN)
        setCharacterAction(bomberman::entities::ACharacters::RUN);
    _characterModel.transform = MatrixRotateXYZ((Vector3){ DEG2RAD * 0, DEG2RAD * 0, DEG2RAD * rotationAngle });
    _characterPos = newPosition;
}

bool bomberman::entities::ACharacters::isCollision(Vector3 objectPos, Vector3 objectSize, Vector3 objectScale)
{
    BoundingBox playerBox = (BoundingBox){(Vector3){ _characterPos.x - _characterSize.x / 2,
                                                     _characterPos.y + 3.5f - _characterSize.y / 10,
                                                     _characterPos.z - _characterSize.z / 2},
                                          (Vector3){ _characterPos.x + _characterSize.x / 2,
                                                     _characterPos.y + _characterSize.y / 2,
                                                     _characterPos.z + _characterSize.z / 2}};
    BoundingBox otherObjects = (BoundingBox){(Vector3){ objectPos.x - (objectSize.x * objectScale.x) / 2,
                                                        objectPos.y - (objectSize.y * objectScale.y) / 2,
                                                        objectPos.z - (objectSize.z * objectScale.z) / 2},
                                             (Vector3){ objectPos.x + (objectSize.x * objectScale.x) / 2,
                                                        objectPos.y + (objectSize.y * objectScale.y) / 2,
                                                        objectPos.z + (objectSize.z * objectScale.z) / 2}};

    if (CheckCollisionBoxes(playerBox, otherObjects)) {
        return true;
    }
    return false;
}

Vector3 bomberman::entities::ACharacters::getCharacterPos(void)
{
    return _characterPos;
}

void bomberman::entities::ACharacters::setCharacterAction(bomberman::entities::ACharacters::actions action)
{
    _characterActions = action;
}

bomberman::entities::ACharacters::actions bomberman::entities::ACharacters::getCharacterAction(void)
{
    return _characterActions;
}

float bomberman::entities::ACharacters::getCharacterRotation(void)
{
    return _rotationAngle;
}