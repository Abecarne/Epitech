/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** StaticModels.cpp
*/

#include "StaticModels.hpp"
#include <iostream>


bomberman::models::StaticModels::StaticModels(std::string modelFile, Vector3 position, Vector3 scale, Vector3 rotationAxis, float rotationAngle)
{
    BoundingBox box;

    _isMesh = false;
    _modelPosition = position;
    _modelScale = scale;
    _rotationAxis = rotationAxis;
    _rotationAngle = rotationAngle;
    _color = WHITE;

    initModel(modelFile);

    box = GetModelBoundingBox(_model);
    _modelSize = {box.max.x - box.min.x, box.max.y - box.min.y, box.max.z - box.min.z};
}

bomberman::models::StaticModels::StaticModels(Mesh mesh, Color color, Vector3 position = {0.0f, 0.0f, 0.0f}, Vector3 scale = {1.0f, 1.0f, 1.0f}, Vector3 rotationAxis = {1.0f, 0.0f, 0.0f}, float rotationAngle = -90)
{
    BoundingBox box;

    _isMesh = true;
    _modelPosition = position;
    _modelScale = scale;
    _rotationAxis = rotationAxis;
    _rotationAngle = rotationAngle;
    _color = color;

    initModel(mesh);

    box = GetModelBoundingBox(_model);
    _modelSize = {box.max.x - box.min.x, box.max.y - box.min.y, box.max.z - box.min.z};
}

bomberman::models::StaticModels::~StaticModels(void)
{   
    unloadModel();
}

void bomberman::models::StaticModels::initModel(std::string modelFile)
{
    if (!FileExists(modelFile.c_str()))
        throw bomberman::core::Errors("[Model Init]", "Model \"" + modelFile + "\" doesn't exist!");
    _model = LoadModel(modelFile.c_str());
}

void bomberman::models::StaticModels::initModel(Mesh mesh)
{
    _model = LoadModelFromMesh(mesh);
}

bool bomberman::models::StaticModels::isCollision(Vector3 objectPos, Vector3 objectSize, Vector3 objectScale)
{
    BoundingBox actualObject = {{ _modelPosition.x - (_modelSize.x * _modelScale.x) / 2,
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

void bomberman::models::StaticModels::unloadModel(void)
{
    for (int textureCount = 0; textureCount < _model.materialCount; textureCount++)
        UnloadTexture(_model.materials[textureCount].maps[MATERIAL_MAP_DIFFUSE].texture);
    UnloadModel(_model);
}

void bomberman::models::StaticModels::renderModel(void)
{
    DrawModelEx(_model, _modelPosition, _rotationAxis, _rotationAngle, _modelScale, _color);
}

Vector3 bomberman::models::StaticModels::getPosition(void)
{
    return _modelPosition;
}

Vector3 bomberman::models::StaticModels::getSize(void)
{
    return _modelSize;
}

Vector3 bomberman::models::StaticModels::getScale(void)
{
    return _modelScale;
}