/*
** EPITECH PROJECT, 2022
** Pikmins
** File description:
** Bots.hpp
*/

#include "Bots.hpp"
#include "GameAssets.hpp"

typedef void (bomberman::entities::Bots::*MovementArray)(std::vector<Vector4> dirs);

bomberman::entities::Bots::Bots(bomberman::entities::ACharacters::playerNum playerNum, std::string typeModel, std::string skinModel, bomberman::entities::ACharacters::characterColors skinColor, std::string animationModel, Vector3 pos, bomberman::entities::BotDifficulty difficulty) :
bomberman::entities::ACharacters()
{
    BoundingBox box;

    this->_difficulty = difficulty;
    this->_targetedEntity = nullptr;
    this->_hasPlacedBomb = false;
    this->_basePos = pos;
    this->_baseSafePos = this->getSafePos();
    this->_stats = std::make_shared<bomberman::entities::CharacterStats>();
    if (!this->_stats)
        throw bomberman::core::Errors("[Bot]", "Bot stat can't be created!");
    this->_characterPos = pos;
    this->_rotationAxis = {0.0f, 1.0f, 1.0f};
    this->_characterActions = bomberman::entities::ACharacters::actions::IDLE;
    this->_playerNum = playerNum;

    if (this->_playerNum == bomberman::entities::ACharacters::playerNum::PLAYER1 ||
    this->_playerNum == bomberman::entities::ACharacters::playerNum::PLAYER3)
        this->_rotationAxis = {90, 0, 0};
    else
        this->_rotationAxis = {90, 180, 0};

    this->_rotationAngle = 1;
    this->initCharacterMesh(typeModel, skinModel, skinColor);
    this->initCharacterAnimations(animationModel);
    box = GetModelBoundingBox(_characterModel);
    this->_characterSize = Vector3Subtract(box.max, box.min);
}

bomberman::entities::Bots::~Bots()
{
    unloadCharacter();
}

void bomberman::entities::Bots::newDir(int newMove, std::vector<Vector4> possibleDirs, bomberman::core::Time deltaTime)
{
    int bomb = 0;
    if (newMove > 3)
        return;
    bomb = std::rand() % 20;
    MovementArray moves[4] = {&bomberman::entities::Bots::move_up, &bomberman::entities::Bots::move_down,
    &bomberman::entities::Bots::move_left, &bomberman::entities::Bots::move_right};
    MovementArray func = moves[newMove];
    if (bomb == 1 && this->_difficulty == bomberman::entities::EASY) {
        this->easyAI(possibleDirs, deltaTime);
    }
    for (int i = 0; i < 10; i++) {
        (this->*func)(possibleDirs);
    }
}

void bomberman::entities::Bots::move(bomberman::core::Time deltaTime, int action)
{
    float speed = this->_stats->getPlayerSpeed() * this->_stats->getPlayerSpeedBonus() * deltaTime;
    std::vector<Vector4> possibleDirs = {
        {speed, 0, 0, -90},
        {-speed, 0, 0, 90},
        {0, 0, speed, 0},
        {0, 0, -speed, 180},
    };

    if (this->_difficulty == bomberman::entities::EASY)
        this->newDir(std::rand() % 100, possibleDirs, deltaTime);
    else if (this->_difficulty == bomberman::entities::MEDIUM)
        this->mediumIA(possibleDirs);
}

vectorOfStaticModels bomberman::entities::Bots::getSafePos(void)
{
    vectorOfStaticModels invBlocks = this->gameAssetsInstance->getGameBoard()->getInvisibleBlock();
    auto wall = this->gameAssetsInstance->getGameBoard()->getWallModels()[0];
    Vector3 size = wall->getSize();
    Vector3 scale = wall->getScale();
    vectorOfStaticModels ret;
    std::vector<Vector3> surroundings = {
        {this->_basePos.x + (size.x * scale.x), this->_basePos.y, this->_basePos.z},
        {this->_basePos.x - (size.x * scale.x), this->_basePos.y, this->_basePos.z},
        {this->_basePos.x, this->_basePos.y, this->_basePos.z + (size.x * scale.x)},
        {this->_basePos.x, this->_basePos.y, this->_basePos.z - (size.x * scale.x)}
    };

    for (auto dir : surroundings) {
        for (auto &block : invBlocks) {
            if (block->isCollision(dir, size, scale)) {
                ret.push_back(block);
                break;
            }
        }
    }
    return ret;
}
