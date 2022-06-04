/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** Menu.cpp
*/
#include "raylib.h"
#include "Camera.hpp"

bomberman::entities::CameraCustom::CameraCustom()
{
    _camera.position = (Vector3){ 0.0f, 350.0f, 0.0f };
    _camera.target = (Vector3){ 0.0f, 80.0f, 0.0f };
    _camera.up = (Vector3){ 0.0f, 1.6f, 0.0f };
    _camera.fovy = 45.0f;
    _camera.projection = CAMERA_PERSPECTIVE;
    _moveSpeed = 5.0f;
}

Camera3D *bomberman::entities::CameraCustom::getCamera()
{
    return &_camera;
}

float bomberman::entities::CameraCustom::getMoveSpeed()
{
    return _moveSpeed;
}

Vector3 bomberman::entities::CameraCustom::getPosition()
{
    return _camera.position;
}

Vector3 bomberman::entities::CameraCustom::getTarget()
{
    return _camera.target;
}

Vector3 bomberman::entities::CameraCustom::getUp()
{
    return _camera.up;
}

float bomberman::entities::CameraCustom::getFovy()
{
    return _camera.fovy;
}

void bomberman::entities::CameraCustom::setMoveSpeed(float moveSpeed)
{
    _moveSpeed = moveSpeed;
}

void bomberman::entities::CameraCustom::setPosition(float x, float y, float z)
{
    _camera.position = (Vector3){ x, y, z };
}

void bomberman::entities::CameraCustom::setTarget(float x, float y, float z)
{
    _camera.target = (Vector3){ x, y, z };
}

void bomberman::entities::CameraCustom::setUp(float x, float y, float z)
{
    _camera.up = (Vector3){ x, y, z };
}

void bomberman::entities::CameraCustom::setFovy(float fovy)
{
    _camera.fovy = fovy;
}
