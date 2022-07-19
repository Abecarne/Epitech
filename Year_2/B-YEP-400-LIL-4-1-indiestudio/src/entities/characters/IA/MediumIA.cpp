/*
** EPITECH PROJECT, 2022
** Pikmins
** File description:
** MediumIA.hpp
*/

#include "Bots.hpp"
#include "GameAssets.hpp"
#include "Game.hpp"
#include "Time.hpp"

bomberman::entities::CollisionType bomberman::entities::Bots::handleCollisionWithMap(Vector3 newPos)
{
    std::vector<std::shared_ptr<bomberman::models::StaticModels>> walls = gameAssetsInstance->getGameBoard()->getWallModels();
    std::vector<std::shared_ptr<bomberman::entities::LootBox>> lootBoxes = gameAssetsInstance->getGameBoard()->getLootBoxes();

    for (auto &wall : walls) {
        if (wall->isCollision(newPos, this->_characterSize, {0.5f, 0.5f, 0.5f}))
            return bomberman::entities::CollisionType::WALL;
    }
    for (auto &box : lootBoxes) {
        if (!box->isDestroyed() && box->getModel()->isCollision(newPos, this->_characterSize, {0.5f, 0.5f, 0.5f}))
            return bomberman::entities::CollisionType::LBOX;
    }
    return bomberman::entities::CollisionType::NONE;
}

// bomberman::entities::CollisionType bomberman::entities::Bots::handleCollisionWithMap(Vector4 newDir)
// {
//     std::vector<std::shared_ptr<bomberman::models::StaticModels>> walls = gameAssetsInstance->getGameBoard()->getWallModels();
//     std::vector<std::shared_ptr<bomberman::entities::LootBox>> lootBoxes = gameAssetsInstance->getGameBoard()->getLootBoxes();

//     for (auto &wall : walls) {
//         if (this->isCollision(bomberman::utils::Vector3SubVector4(wall->getPosition(), newDir), wall->getSize(), wall->getScale()))
//             return bomberman::entities::CollisionType::WALL;
//     }
//     for (auto &box : lootBoxes) {
//         if (!box->isDestroyed() && this->isCollision(bomberman::utils::Vector3SubVector4(box->getModel()->getPosition(), newDir), box->getModel()->getSize(), box->getModel()->getScale()))
//             return bomberman::entities::CollisionType::LBOX;
//     }
//     return bomberman::entities::CollisionType::NONE;
// }

void bomberman::entities::Bots::moveTo(std::vector<Vector4> possibleDirs)
{
    Vector3 actualPos = this->getCharacterPos();
    float minDistance = abs(bomberman::utils::Vector32DDistance(actualPos, this->_targetedPos));
    int minDirIndex = 0;

    if (bomberman::utils::Vector3isEqual2D(actualPos, this->_targetedPos))
        return;
    for (int i = 0; i < 4; i++) {
        Vector3 tempPos = bomberman::utils::Vector3AddVector4(actualPos, possibleDirs[i]);
        float tempDistance = abs(bomberman::utils::Vector32DDistance(tempPos, this->_targetedPos));
        if (tempDistance < minDistance) {
            minDistance = tempDistance;
            minDirIndex = i;
        }
    }

    Vector3 newPos = bomberman::utils::Vector3AddVector4(actualPos, possibleDirs[minDirIndex]);
    bomberman::entities::CollisionType collision = this->handleCollisionWithMap(newPos);

    if (collision == bomberman::entities::CollisionType::NONE)
        this->moveCharacter(newPos, possibleDirs[minDirIndex].w);
    else if (collision == bomberman::entities::CollisionType::LBOX && this->canPlaceBomb()) {
        this->placeBomb();
        for (int i = 0; i < this->_baseSafePos.size(); i++) {
            if (!this->_baseSafePos[i]->isCollision(this->getCharacterPos(), this->_characterSize, {0.5f, 0.5f, 0.5f}))
                this->_targetedPos = this->_baseSafePos[i]->getPosition();
        }
        this->_hasPlacedBomb = true;
        this->_hasPlacedBombTimer = GetTime();
    } else if (collision == bomberman::entities::CollisionType::WALL) {
        minDirIndex = std::rand() % 4;
        newPos = bomberman::utils::Vector3AddVector4(actualPos, possibleDirs[minDirIndex]);
        while (this->handleCollisionWithMap(newPos) != bomberman::entities::CollisionType::NONE) {
            minDirIndex = std::rand() % 4;
            newPos = bomberman::utils::Vector3AddVector4(actualPos, possibleDirs[minDirIndex]);
        }
        this->moveCharacter(newPos, possibleDirs[minDirIndex].w);
    }
}

void bomberman::entities::Bots::mediumIA(std::vector<Vector4> possibleDirs)
{
    if (!this->_targetedEntity || this->_targetedEntity->getCharacterAction() == bomberman::entities::ACharacters::AFTER_DEATH) {
        std::vector<std::shared_ptr<bomberman::entities::ACharacters>> allPlayableEntities = this->gameSceneInstance->getAllPlayableEntities();
        int randomEntityIndex = std::rand() % allPlayableEntities.size();
        while (allPlayableEntities[randomEntityIndex]->getPlayerNum() == this->_playerNum || allPlayableEntities[randomEntityIndex]->getCharacterAction() == bomberman::entities::ACharacters::AFTER_DEATH)
            randomEntityIndex = std::rand() % allPlayableEntities.size();
        this->_targetedEntity = allPlayableEntities[randomEntityIndex];
        this->_basePos = this->getCharacterPos();
        this->_targetedPos = this->gameAssetsInstance->getGameBoard()->getInvisibleBlockPosAtEntity(this->_targetedEntity);
        return;
    }

    if (this->_hasPlacedBomb == true && GetTime() - this->_hasPlacedBombTimer >= 6)
        this->_hasPlacedBomb = false;
    if (this->_hasPlacedBomb == false)
        this->_targetedPos = this->gameAssetsInstance->getGameBoard()->getInvisibleBlockPosAtEntity(this->_targetedEntity);
    this->moveTo(possibleDirs);
}