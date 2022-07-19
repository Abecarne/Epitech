/*
** EPITECH PROJECT, 2022
** Pikmins
** File description:
** Bombs.cpp
*/

#include "Bombs.hpp"
#include "StaticModels.hpp"

bomberman::entities::Bombs::Bombs(Vector3 initialposition, size_t explosionRadius)
{
    this->gameAssetsInstance = bomberman::game::GameAssets::getInstance();

    this->_position = bomberman::utils::Vector3Floor(initialposition);
    this->_rotationAxis = {90, 0, 0};
    this->_rotationAngle = 0;
    this->_explosionRadius = explosionRadius;
    this->_renderBlastRadius = 0;
    this->_dirAvailable = {true, true, true, true};
    this->_state = bomberman::entities::Bombs::bombState::WAITING;

    this->_animFrameCounter = 0;
    this->_animationTime = GetTime();

    this->_explodingTimer = GetTime();
    this->_blastTexture = *this->gameAssetsInstance->getAllLoadedTextures().find("BLAST")->second;

    this->initModel(this->gameAssetsInstance->getAllLoadedTextures().find("BOMB")->second);
    this->initAnimations();
    this->_explosionSound = LoadSound("assets/music/explosion.mp3");
}

bomberman::entities::Bombs::~Bombs()
{

    std::cout << "AU REVOOOOOOOOOOOOIIIIRRRR" << std::endl;

    _allBlasts.clear();
    for (unsigned int i = 0; i < _animCount; i++)
        UnloadModelAnimation(_animations[i]);
    RL_FREE(_animations);
    UnloadModel(_model);
}

void bomberman::entities::Bombs::initModel(std::shared_ptr<Texture2D> texture)
{
    if (!FileExists(BOMBS_MODELS))
        throw bomberman::core::Errors("[Characters Initialization]", "Characters models \"" + std::string(BOMBS_MODELS) + "\" is not found!");

    _model = LoadModel(BOMBS_MODELS);

    if (_model.boneCount == 0)
        throw bomberman::core::Errors("[Characters Initialization]", "Characters files is not found or don't have any armature!");

    SetMaterialTexture(&_model.materials[0], MATERIAL_MAP_DIFFUSE, *texture);
}

void bomberman::entities::Bombs::initAnimations(void)
{
    _animCount = 0;

    if (!FileExists(BOMBS_ANIMATIONS))
        throw bomberman::core::Errors("[Characters Initialization]", "Animations file \"" + std::string(BOMBS_ANIMATIONS) + "\" is not found!");
    _animations = LoadModelAnimations(BOMBS_ANIMATIONS, &_animCount);
    for (unsigned int i = 0; i < _animCount; i++) {
        if (!IsModelAnimationValid(_model, _animations[i]))
            throw bomberman::core::Errors("[Characters Initialization]", "Animations and models aren't compatible!");
    }

    _animFrameCounter = 0;
}

bomberman::entities::Bombs::bombState bomberman::entities::Bombs::getState(void)
{
    return _state;
}

void bomberman::entities::Bombs::updateAnimation(void)
{
    float deltaTime = GetTime() - _animationTime;

    if (deltaTime > 0.03) {
        _animFrameCounter++;
        _animationTime = GetTime();
    }
    UpdateModelAnimation(_model, _animations[1], _animFrameCounter);
    if (_animFrameCounter >= _animations[1].frameCount)
        _animFrameCounter = 0;
}

std::vector<std::shared_ptr<bomberman::entities::Blast>> bomberman::entities::Bombs::getBlasts(void)
{
    return _allBlasts;
}

std::vector<Vector3> bomberman::entities::Bombs::getBlastPositionsForRadius(Vector3 blockSize, float blockScale)
{
    float offset = this->_renderBlastRadius * blockSize.x * blockScale;

    if (this->_renderBlastRadius == 0)
        return {this->_position};
    return {
        {this->_position.x + offset, this->_position.y, this->_position.z},
        {this->_position.x - offset, this->_position.y, this->_position.z},
        {this->_position.x, this->_position.y, this->_position.z + offset},
        {this->_position.x, this->_position.y, this->_position.z - offset}
    };
}

void bomberman::entities::Bombs::createBlastsForRadius(void)
{
    std::vector<std::shared_ptr<bomberman::models::StaticModels>> walls = this->gameAssetsInstance->getGameBoard()->getWallModels();
    std::vector<std::shared_ptr<bomberman::entities::LootBox>> &lootBoxes = this->gameAssetsInstance->getGameBoard()->getLootBoxes();
    Vector3 blockSize = this->gameAssetsInstance->getGameBoard()->getBlockSize();
    float blockScale = this->gameAssetsInstance->getGameBoard()->getScale();
    std::vector<Vector3> blastPositions = this->getBlastPositionsForRadius(blockSize, blockScale);

    for (int i = 0; i < blastPositions.size(); i++) {
        for (auto block : walls) {
            if (block->isCollision(blastPositions[i], blockSize, {blockScale - 1, blockScale - 1, blockScale - 1})) {
                this->_dirAvailable[i] = false;
                break;
            }
        }
        for (auto it = lootBoxes.begin(); this->_dirAvailable[i] && it != lootBoxes.end(); it++) {
            if (it->get()->isDestroyed())
                continue;
            if (it->get()->getModel()->isCollision(blastPositions[i], blockSize, {blockScale - 1, blockScale - 1, blockScale - 1})) {
                this->_allBlasts.push_back(std::make_shared<bomberman::entities::Blast>(this->_blastTexture, blastPositions[i], this->_renderBlastRadius));
                this->_dirAvailable[i] = false;
                it->get()->destroyBox();
                break;
            }
        }
        if (this->_dirAvailable[i] == true)
            this->_allBlasts.push_back(std::make_shared<bomberman::entities::Blast>(this->_blastTexture, blastPositions[i], this->_renderBlastRadius));
    }
}

void bomberman::entities::Bombs::update(void)
{
    float timePassed = GetTime() - this->_explodingTimer;

    this->_model.transform = MatrixRotateXYZ(bomberman::utils::Vector3MultiplyByValue(this->_rotationAxis, DEG2RAD));
    if (this->_state == bomberman::entities::Bombs::bombState::EXPLODING) {
        for (auto blast : this->_allBlasts)
            blast->update();
        if (timePassed > 1) {
            this->_state = bomberman::entities::Bombs::bombState::END;
            this->_explodingTimer = GetTime();
        }
    }
    if (this->_state == bomberman::entities::Bombs::bombState::WAITING) {
        this->updateAnimation();
        if (timePassed > 4) {
            this->_renderBlastTimer = GetTime();
            this->_explodingTimer = GetTime();
            this->_state = bomberman::entities::Bombs::bombState::EXPLODING;
            PlaySound(_explosionSound);
        }
    }
}

void bomberman::entities::Bombs::render(void)
{
    if (_state == bomberman::entities::Bombs::bombState::WAITING)
        DrawModel(_model, _position, 2, WHITE);
    else if (_state == bomberman::entities::Bombs::bombState::EXPLODING) {
        if (GetTime() - this->_renderBlastTimer >= 0.05 && this->_renderBlastRadius <= this->_explosionRadius) {
            this->_renderBlastTimer = GetTime();
            this->createBlastsForRadius();
            this->_renderBlastRadius++;
        }
        for (auto blast : this->_allBlasts)
            blast->render();
    }
}
