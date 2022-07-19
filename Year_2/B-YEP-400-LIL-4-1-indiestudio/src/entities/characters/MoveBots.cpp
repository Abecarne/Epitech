/*
** EPITECH PROJECT, 2022
** Tek 2 [WSL : Ubuntu-20.04]
** File description:
** MoveBots
*/

#include "Bots.hpp"
#include "GameAssets.hpp"

void bomberman::entities::Bots::move_up(std::vector<Vector4> possibleDirs)
{
    Vector4 newDir = possibleDirs[0];
    Vector3 actualPos = this->getCharacterPos();
    Vector3 newPos = bomberman::utils::Vector3AddVector4(actualPos, newDir);
    float oldRotation = newDir.w;

    if (!this->checkCollisionWithMap(newDir))
        this->moveCharacter(newPos, oldRotation);
}

void bomberman::entities::Bots::move_down(std::vector<Vector4> possibleDirs)
{
    Vector4 newDir = possibleDirs[1];
    Vector3 actualPos = this->getCharacterPos();
    Vector3 newPos = bomberman::utils::Vector3AddVector4(actualPos, newDir);
    float oldRotation = newDir.w;

    if (!this->checkCollisionWithMap(newDir))
        this->moveCharacter(newPos, oldRotation);
}

void bomberman::entities::Bots::move_left(std::vector<Vector4> possibleDirs)
{
    Vector4 newDir = possibleDirs[2];
    Vector3 actualPos = this->getCharacterPos();
    Vector3 newPos = bomberman::utils::Vector3AddVector4(actualPos, newDir);
    float oldRotation = newDir.w;

    if (!this->checkCollisionWithMap(newDir))
        this->moveCharacter(newPos, oldRotation);
}

void bomberman::entities::Bots::move_right(std::vector<Vector4> possibleDirs)
{
    Vector4 newDir = possibleDirs[3];
    Vector3 actualPos = this->getCharacterPos();
    Vector3 newPos = bomberman::utils::Vector3AddVector4(actualPos, newDir);
    float oldRotation = newDir.w;

    if (!this->checkCollisionWithMap(newDir))
        this->moveCharacter(newPos, oldRotation);
}