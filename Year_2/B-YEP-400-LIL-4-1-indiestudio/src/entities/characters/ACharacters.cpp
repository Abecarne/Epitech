/*
** EPITECH PROJECT, 2022
** Pikmins
** File description:
** Characters.cpp
*/

#include "ACharacters.hpp"

#include "GameAssets.hpp"
#include "GameEngine.hpp"
#include "Game.hpp"
#include "Bombs.hpp"

/*
** Public functions
*/

bomberman::entities::ACharacters::ACharacters()
{
    this->gameAssetsInstance = bomberman::game::GameAssets::getInstance();
    this->gameSceneInstance = bomberman::game::Game::getInstance();

    _deathSound = LoadSound(PLAYER_DEATH_SOUND);
    _bonusSound = LoadSound(PLAYER_BONUS_SOUND);

    _engine = bomberman::core::GameEngine::getInstance();
}

void bomberman::entities::ACharacters::updateCharacter(void)
{
    bool wallFind = false;
    std::vector<std::shared_ptr<bomberman::entities::LootBox>> lootBoxes = gameAssetsInstance->getGameBoard()->getLootBoxes();

    if (this->_characterActions == bomberman::entities::ACharacters::actions::AFTER_DEATH)
        return;
    this->_characterModel.transform = MatrixRotateXYZ({DEG2RAD * this->_rotationAxis.x, DEG2RAD * this->_rotationAxis.y, DEG2RAD * this->_rotationAxis.z});
    this->_animFrameCounter++;
    UpdateModelAnimation(this->_characterModel, this->_animations[this->_characterActions], this->_animFrameCounter);
    if (this->_animFrameCounter >= this->_animations[this->_characterActions].frameCount) {
        this->_animFrameCounter = 0;
        if (this->_characterActions == bomberman::entities::ACharacters::actions::BEFORE_DEATH)
            this->_characterActions = bomberman::entities::ACharacters::actions::AFTER_DEATH;
    }

    for (auto box : lootBoxes) {
        if (this->isCollision(box->getModel()->getPosition(), box->getModel()->getSize(), box->getModel()->getScale()))
            wallFind = true;
    }
    _stats->updateWallPass(wallFind, gameAssetsInstance->getGameBoard()->getLootBoxes());
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
    if (_characterActions == bomberman::entities::ACharacters::actions::AFTER_DEATH)
        return;
    DrawModelEx(_characterModel, _characterPos, _rotationAxis, _rotationAngle, {0.5f, 0.5f, 0.5f}, WHITE);
}

void bomberman::entities::ACharacters::moveCharacter(Vector3 newPosition, float rotationAngle)
{
    _rotationAxis.y = rotationAngle;

    if (newPosition.x == _characterPos.x && newPosition.y == _characterPos.y && newPosition.z == _characterPos.z) {
        setCharacterAction(bomberman::entities::ACharacters::IDLE);
        return;
    }

    if (_characterActions != bomberman::entities::ACharacters::RUN)
        setCharacterAction(bomberman::entities::ACharacters::RUN);
    _characterPos = newPosition;
}

void bomberman::entities::ACharacters::moveCharacter(Vector3 newPosition)
{
    if (_characterActions != bomberman::entities::ACharacters::RUN)
        setCharacterAction(bomberman::entities::ACharacters::RUN);
    _characterPos = newPosition;
}

bool bomberman::entities::ACharacters::isCollision(Vector3 objectPos, Vector3 objectSize, Vector3 objectScale)
{
    BoundingBox playerBox = {
        {
            _characterPos.x - _characterSize.x / 5,
            _characterPos.y + 3.5f - _characterSize.y / 10,
            _characterPos.z - _characterSize.z / 5
        },
        {
            _characterPos.x + _characterSize.x / 5,
            _characterPos.y + _characterSize.y / 2,
            _characterPos.z + _characterSize.z / 5
        }
    };
    BoundingBox otherObjects = {
        {
            objectPos.x - (objectSize.x * objectScale.x) / 2,
            objectPos.y - (objectSize.y * objectScale.y) / 2,
            objectPos.z - (objectSize.z * objectScale.z) / 2
        },
        {
            objectPos.x + (objectSize.x * objectScale.x) / 2,
            objectPos.y + (objectSize.y * objectScale.y) / 2,
            objectPos.z + (objectSize.z * objectScale.z) / 2
        }
    };

    if (CheckCollisionBoxes(playerBox, otherObjects))
        return true;
    return false;
}

void bomberman::entities::ACharacters::applyGravity(vectorOfStaticModels floor)
{
    bool find = false;

    for (size_t i = 0; i < floor.size(); i++) {
        if (this->isCollision(bomberman::utils::Vector3ModifyY(floor[i]->getPosition(), 0.5f) , floor[i]->getSize(), floor[i]->getScale()))
            find = true;
    }
    if (!find)
        this->moveCharacter(bomberman::utils::Vector3ModifyY(this->getCharacterPos(), -0.5f));
}

void bomberman::entities::ACharacters::setCharacterRotation(float rotation)
{
    _rotationAxis.y = rotation;
}

Vector3 bomberman::entities::ACharacters::getCharacterPos(void)
{
    return _characterPos;
}

void bomberman::entities::ACharacters::setCharacterAction(bomberman::entities::ACharacters::actions action)
{
    if (action == bomberman::entities::ACharacters::actions::BEFORE_DEATH) {
        PlaySound(_deathSound);
        _animFrameCounter = 5;
    }
    _characterActions = action;
}

bomberman::entities::ACharacters::actions bomberman::entities::ACharacters::getCharacterAction(void)
{
    return _characterActions;
}

Vector3 bomberman::entities::ACharacters::getCharacterRotation(void)
{
    return _rotationAxis;
}

std::shared_ptr<bomberman::entities::CharacterStats> bomberman::entities::ACharacters::getCharacterStats(void)
{
    return _stats;
}

bomberman::entities::ACharacters::playerNum bomberman::entities::ACharacters::getPlayerNum(void)
{
    return this->_playerNum;
}


bool bomberman::entities::ACharacters::canPlaceBomb(void)
{
    if (this->_stats->getBombNumber() == 0)
        return false;
    this->_stats->removeBombNumber();
    return true;
}

void bomberman::entities::ACharacters::placeBomb(void)
{
    vectorOfStaticModels invisibleBlocks = this->gameAssetsInstance->getGameBoard()->getInvisibleBlock();

    float minDistance = abs(bomberman::utils::Vector32DDistance(this->getCharacterPos(), invisibleBlocks[0]->getPosition()));
    Vector3 minPos = invisibleBlocks[0]->getPosition();

    for (auto &block : invisibleBlocks) {
        float tempDistance = abs(bomberman::utils::Vector32DDistance(this->getCharacterPos(), block->getPosition()));
        if (tempDistance < minDistance) {
            minDistance = tempDistance;
            minPos = block->getPosition();
        }
    }
    this->gameSceneInstance->addBombsToGame(bomberman::utils::Vector3ModifyY(minPos, -2.0f), this->getCharacterStats()->getPlayerBombRange());


    // for (auto &block : invisibleBlocks) {
    //     if (this->isCollision(block->getPosition(), block->getSize(), block->getScale())) {
    //         this->gameSceneInstance->addBombsToGame(bomberman::utils::Vector3ModifyY(block->getPosition(), -2.0f), this->getCharacterStats()->getPlayerBombRange());
    //         break;
    //     }
    // }
}

void bomberman::entities::ACharacters::checkBombsDamage(std::vector<std::shared_ptr<bomberman::entities::Bombs>> allBombs)
{
    Vector3 size = this->gameAssetsInstance->getGameBoard()->getBlockSize();
    float scale = this->gameAssetsInstance->getGameBoard()->getScale();

    for (auto & bomb : allBombs) {
        std::vector<std::shared_ptr<bomberman::entities::Blast>> allBlasts = bomb->getBlasts();
        for (auto & blast : allBlasts) {
            if (this->isCollision(blast->getPosition(), size, {scale, scale, scale}))
                this->setCharacterAction(bomberman::entities::ACharacters::BEFORE_DEATH);
        }
    }
}

bool bomberman::entities::ACharacters::checkCollisionWithMap(Vector4 newDir)
{
    std::vector<std::shared_ptr<bomberman::models::StaticModels>> walls = gameAssetsInstance->getGameBoard()->getWallModels();
    std::vector<std::shared_ptr<bomberman::entities::LootBox>> lootBoxes = gameAssetsInstance->getGameBoard()->getLootBoxes();
    bool collide = false;

    for (auto box : lootBoxes)
        if (!box->isDestroyed() && !_stats->getWallPassUp())
            walls.push_back(box->getModel());
    for (auto obj : walls) {
        if (this->isCollision(bomberman::utils::Vector3SubVector4(obj->getPosition(), newDir), obj->getSize(), obj->getScale()))
            collide = true;
    }
    return collide;
}

bool bomberman::entities::ACharacters::checkPowerUpEffect(std::shared_ptr<bomberman::entities::powerup::APowerup> powerUp)
{
    Vector3 size = this->gameAssetsInstance->getGameBoard()->getBlockSize();
    float scale = this->gameAssetsInstance->getGameBoard()->getScale();

    if (this->isCollision(powerUp.get()->getPosition(), size, {scale, scale, scale})) {
        this->applyPowerUp(powerUp.get()->getPowerUpType());
        return (true);
    }
    return (false);
}

void bomberman::entities::ACharacters::applyPowerUp(bomberman::entities::powerup::PowerUpType powerUp)
{
    switch (powerUp) {
		case bomberman::entities::powerup::PowerUpType::BOMBUP:
			this->_stats->upgradeBombNumber();
            break;
			
		case bomberman::entities::powerup::PowerUpType::SPEEDUP:
            this->_stats->addPlayerSpeedBonus();
            break;
			
        case bomberman::entities::powerup::PowerUpType::FIREUP:
			this->_stats->addPlayerBombRange();
            break;
			
        case bomberman::entities::powerup::PowerUpType::WALLPASSUP:
			this->_stats->addWallPassUp();
            break;
			
        default:
            break;
    }
    PlaySound(_bonusSound);
}

/*
** Protected functions
*/

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