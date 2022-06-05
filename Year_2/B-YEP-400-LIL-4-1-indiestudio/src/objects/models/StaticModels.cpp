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
    _modelSize = (Vector3){box.max.x - box.min.x, box.max.y - box.min.y, box.max.z - box.min.z};
}

bomberman::models::StaticModels::StaticModels(Mesh mesh, Color color, Vector3 position = (Vector3){0.0f, 0.0f, 0.0f}, Vector3 scale = (Vector3){1.0f, 1.0f, 1.0f}, Vector3 rotationAxis = (Vector3){1.0f, 0.0f, 0.0f}, float rotationAngle = -90)
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
    _modelSize = (Vector3){box.max.x - box.min.x, box.max.y - box.min.y, box.max.z - box.min.z};
}

bomberman::models::StaticModels::~StaticModels(void)
{
    if (!_isMesh)
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