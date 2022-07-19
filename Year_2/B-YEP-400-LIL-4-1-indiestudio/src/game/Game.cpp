/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** Game.cpp
*/

#include "Game.hpp"

bomberman::game::Game *bomberman::game::Game::_gameInstance {nullptr};
std::mutex bomberman::game::Game::_mutex;

void bomberman::game::Game::init(bomberman::core::GameEngine *engine)
{
    this->_map = engine->getGameAssets()->getMap().get();
    this->_skybox = engine->getGameAssets()->getSkyBox().get();
    this->_gameboard = engine->getGameAssets()->getGameBoard().get();

    this->_allPlayers = engine->getGameAssets()->getPlayers();
    this->_allBots = engine->getGameAssets()->getBots();

    this->_gameState = bomberman::game::BEGIN;
    this->_startTime = 0;
    this->_announcement = false;
    this->isPaused = false;

    this->_timer = std::make_shared<bomberman::settings::Chronometer>(0, 3);

    this->_timerFcts = {{bomberman::game::gameState::BEGIN, &bomberman::game::Game::BeginGameTimeHandler},
                        {bomberman::game::gameState::INGAME, &bomberman::game::Game::InGameTimeHandler},
                        {bomberman::game::gameState::SUDDEN_DEATH_MATCH, &bomberman::game::Game::suddenDeathMatch},
                        {bomberman::game::gameState::ENDGAME, &bomberman::game::Game::EndGameTimeHandler},
                        {bomberman::game::gameState::ENDING, &bomberman::game::Game::EndingTimeHandler}};

    if (!this->_timer)
        throw bomberman::core::Errors("[Game]", "Not enough memories!");

    this->_bgText.push_back(bomberman::objects::Image("assets/img/plank.png", { engine->options.getWindowWidth() / 2.0f, engine->options.getWindowHeight() / 2.0f}, 0.5f));
    this->_bgText[0].setText(this->_bgText[0].getWidth() / 2.0f, this->_bgText[0].getHeight() / 2.0f - 60, "", 120, WHITE);

    this->_bgText.push_back(bomberman::objects::Image("assets/img/plank.png", { engine->options.getWindowWidth() / 2.0f, 60}, 0.25f));
    this->_bgText[1].setText(this->_bgText[1].getWidth() / 2.0f, this->_bgText[1].getHeight() / 2.0f - 25, "", 50, WHITE);

    this->_bgText.push_back(bomberman::objects::Image("assets/img/plank.png", { engine->options.getWindowWidth() / 2.0f, engine->options.getWindowHeight() / 2.0f}, 0.5f));
    this->_bgText[2].setText(this->_bgText[2].getWidth() / 2.0f, this->_bgText[2].getHeight() / 2.0f - 50, "SUDDEN DEATH", 90, WHITE);

    this->_timer->start();
    this->_allPlayableEntities.assign(this->_allPlayers.begin(), this->_allPlayers.end());
    this->_allPlayableEntities.insert(this->_allPlayableEntities.end(), this->_allBots.begin(), this->_allBots.end());

    this->_camera.setPosition(-110.0f, 180.0f, 0.0f);
    this->_camera.setTarget(10.0f, 0.0f, 0.0f);
    this->_camera.setUp(0.0f, 1.0f, 0.0f);
    SetCameraMode(*_camera.getCamera(), CAMERA_PERSPECTIVE);

    if (!this->_map || !this->_skybox ||!this->_gameboard)
        bomberman::core::Errors("[Game]", "Not enough memories!");

    engine->options.music.changeMusic(GAME_MUSIC);
}

void bomberman::game::Game::cleanup(void)
{
    _allBombs.clear();
    _allBots.clear();
    _allPlayers.clear();
    _allPowerUps.clear();
}

void bomberman::game::Game::pause(void)
{
    //void
}

void bomberman::game::Game::resume(void)
{
    //void
}

void bomberman::game::Game::suddenDeathMatch(bomberman::core::GameEngine *engine)
{
    if (_timer->isOver()) {
        this->_gameState = bomberman::game::gameState::ENDGAME;
        if (engine->options.music.isSoundActive())
            PlaySound(_finishSound);
        _startTime = 0;
        this->_timer->reStart(0, 4);
        return;
    }

    if (GetTime() - _startTime > 2 && _announcement == true) {
        _announcement = false;
        _startTime = GetTime();
    }

    if (_startTime == 0 && _timer->getTime()["seconds"] == "04" && this->_timer.get()->getTime()["minutes"] == "0")
        _startTime = GetTime();

    if (_startTime == 0)
        return;

    if ((GetTime() - _startTime) > 1 && _announcement == false) {
        if (engine->options.music.isSoundActive())
            PlaySound(_clockSound);
        _startTime = GetTime();
    }
}

void bomberman::game::Game::BeginGameTimeHandler(bomberman::core::GameEngine *engine)
{
    if (_startTime == 0) {
        if (engine->options.music.isSoundActive())
            PlaySound(_clockSound);
    }

    if (_timer->isOver()) {
        _startTime = 0;
        this->_gameState = bomberman::game::gameState::INGAME;
        this->_timer->reStart(3, 0);
        return;
    }

    if (_startTime == 0 && _timer->getTime()["seconds"] == "03")
        _startTime = GetTime();

    if ((GetTime() - _startTime) > 1) {
        _startTime = GetTime();
        if (engine->options.music.isSoundActive())
            PlaySound(_clockSound);
    }
}

void bomberman::game::Game::InGameTimeHandler(bomberman::core::GameEngine *engine)
{
    std::vector<std::shared_ptr<bomberman::entities::ACharacters>> allPlayableEntities;

    if (_timer->isOver()) {

        allPlayableEntities.insert(allPlayableEntities.end(), this->_allPlayers.begin(), this->_allPlayers.end());
        allPlayableEntities.insert(allPlayableEntities.end(), this->_allBots.begin(), this->_allBots.end());

        this->_gameState = bomberman::game::gameState::SUDDEN_DEATH_MATCH;
        if (engine->options.music.isSoundActive())
            PlaySound(_suddenDeathSound);
        _startTime = GetTime();
        _announcement = true;
        this->_timer->reStart(0, 30);

        for (auto entity : allPlayableEntities) {
            entity->getCharacterStats()->maxPlayerBombRange();
            entity->getCharacterStats()->maxPlayerSpeedBonus();
        }
        return;
    }

    if (_startTime == 0 && _timer->getTime()["seconds"] == "04" && this->_timer.get()->getTime()["minutes"] == "0")
        _startTime = GetTime();

    if (_startTime == 0)
        return;

    if ((GetTime() - _startTime) > 1) {
        if (engine->options.music.isSoundActive())
            PlaySound(_clockSound);
        _startTime = GetTime();
    }
}

void bomberman::game::Game::EndingTimeHandler(bomberman::core::GameEngine *engine)
{

}

void bomberman::game::Game::EndGameTimeHandler(bomberman::core::GameEngine *engine)
{
    if (_timer->isOver()) {
        engine->options.music.changeMusic("./assets/music/menu.mp3");
        engine->changeState(bomberman::menu::MainMenu::getInstance());
        engine->cleanGameAssets();
    }
}

void bomberman::game::Game::addBombsToGame(Vector3 position, size_t radiusBlast)
{
    std::shared_ptr<bomberman::entities::Bombs> newBomb = std::make_shared<bomberman::entities::Bombs>(position, radiusBlast);

    if (!newBomb)
        throw bomberman::core::Errors("[Game]", "Not enough memories!");
    this->_allBombs.push_back(newBomb);
}

void bomberman::game::Game::processInput(bomberman::core::GameEngine *engine)
{
    int index = 0;
    std::vector<std::shared_ptr<bomberman::models::StaticModels>> invisibleBox = engine->getGameAssets()->getGameBoard()->getInvisibleBlock();

    if (IsKeyPressed(KEY_ESCAPE)) {
        _timer->stopTimer();
        engine->pushState(bomberman::menu::PauseMenu::getInstance());
        this->isPaused = true;

    }
    if (this->_gameState == bomberman::game::gameState::BEGIN || _gameState > bomberman::game::gameState::SUDDEN_DEATH_MATCH)
        return;

    for (auto player : this->_allPlayers) {
        if (player->getCharacterAction() == bomberman::entities::ACharacters::actions::BEFORE_DEATH ||
            player->getCharacterAction() == bomberman::entities::ACharacters::actions::AFTER_DEATH)
            continue;
        if (IsKeyDown(engine->options.getActions()[index][bomberman::settings::Actions::BOMB]) && player->canPlaceBomb())
            player->placeBomb();
        index++;
    }
}

void bomberman::game::Game::updateGameTime(bomberman::core::GameEngine *engine)
{
    std::vector<bomberman::game::gameState> allGameState = {bomberman::game::gameState::BEGIN, bomberman::game::gameState::INGAME, bomberman::game::gameState::SUDDEN_DEATH_MATCH, bomberman::game::gameState::ENDGAME, bomberman::game::gameState::ENDING};

    for (size_t i = 0; i < allGameState.size(); i++) {
        if (allGameState[i] == _gameState)
            (this->*_timerFcts[_gameState])(engine);
    }
}

void bomberman::game::Game::addPowerUpToGame(Vector3 position, bomberman::entities::powerup::PowerUpType bonusType)
{
    if (bonusType == bomberman::entities::powerup::PowerUpType::NOTHING)
        return;

    if (bonusType == bomberman::entities::powerup::PowerUpType::BOMBUP) {
        std::shared_ptr<bomberman::entities::powerup::BombUp> newBombUp;

        newBombUp = std::make_shared<bomberman::entities::powerup::BombUp>(position);
        if (!newBombUp)
            throw bomberman::core::Errors("[Game]", "Not enough memories!");
        _allPowerUps.push_back(newBombUp);
    }

    if (bonusType == bomberman::entities::powerup::PowerUpType::FIREUP) {
        std::shared_ptr<bomberman::entities::powerup::FireUp> newFireUp;

        newFireUp = std::make_shared<bomberman::entities::powerup::FireUp>(position);
        if (!newFireUp)
            throw bomberman::core::Errors("[Game]", "Not enough memories!");
        _allPowerUps.push_back(newFireUp);
    }

    if (bonusType == bomberman::entities::powerup::PowerUpType::WALLPASSUP) {
        std::shared_ptr<bomberman::entities::powerup::WallPassUp> newWallPassUp;

        newWallPassUp = std::make_shared<bomberman::entities::powerup::WallPassUp>(position);
        if (!newWallPassUp)
            throw bomberman::core::Errors("[Game]", "Not enough memories!");
        _allPowerUps.push_back(newWallPassUp);
    }

    if (bonusType == bomberman::entities::powerup::PowerUpType::SPEEDUP) {
        std::shared_ptr<bomberman::entities::powerup::SpeedUp> newSpeedUp;

        newSpeedUp = std::make_shared<bomberman::entities::powerup::SpeedUp>(position);
        if (!newSpeedUp)
            throw bomberman::core::Errors("[Game]", "Not enough memories!");
        _allPowerUps.push_back(newSpeedUp);
    }
}

void bomberman::game::Game::update(bomberman::core::GameEngine *engine, bomberman::core::Time deltaTime)
{
    int nbPlayersAlive = 0;
    int index = 0;
    int action = -1;
    std::vector<std::shared_ptr<bomberman::entities::ACharacters>> allPlayableEntities;
    vectorOfStaticModels floorBlocks = engine->getGameAssets()->getGameBoard()->getFloorModels();

    allPlayableEntities.insert(allPlayableEntities.end(), this->_allPlayers.begin(), this->_allPlayers.end());
    allPlayableEntities.insert(allPlayableEntities.end(), this->_allBots.begin(), this->_allBots.end());

    if (this->isPaused == true) {
        this->_timer->continueTimer();
        this->isPaused = false;
    }

    for (auto & entity : allPlayableEntities) {
        action = -1;
        entity->updateCharacter();
        if (entity->getCharacterAction() == bomberman::entities::ACharacters::actions::AFTER_DEATH ||
        entity->getCharacterAction() == bomberman::entities::ACharacters::actions::BEFORE_DEATH)
            continue;
        if (_gameState == bomberman::game::gameState::BEGIN || _gameState > bomberman::game::gameState::SUDDEN_DEATH_MATCH)
            continue;
        entity->applyGravity(floorBlocks);
        entity->getCharacterStats()->updateBombTimer();
        if (IsKeyDown(engine->options.getActions()[index][bomberman::settings::Actions::LEFT]))
            action = bomberman::settings::Actions::LEFT;
        if (IsKeyDown(engine->options.getActions()[index][bomberman::settings::Actions::RIGHT]))
            action = bomberman::settings::Actions::RIGHT;
        if (IsKeyDown(engine->options.getActions()[index][bomberman::settings::Actions::FORWARD]))
            action = bomberman::settings::Actions::FORWARD;
        if (IsKeyDown(engine->options.getActions()[index][bomberman::settings::Actions::BACKWARD]))
            action = bomberman::settings::Actions::BACKWARD;

        entity->move(deltaTime, action);
        entity->checkBombsDamage(this->_allBombs);
        for (int i = 0; i < _allPowerUps.size(); i++)
            if (entity->checkPowerUpEffect(_allPowerUps[i]) == true) {
                _allPowerUps.erase(_allPowerUps.begin() + i);
            }
        index++;
    }
    for (auto & powerUp : _allPowerUps)
        powerUp->updatePU(deltaTime);

    updateGameTime(engine);
    _timer->update();
    for (auto & entity : allPlayableEntities) {
        if (entity.get()->getCharacterAction() == bomberman::entities::ACharacters::actions::RUN ||
            entity.get()->getCharacterAction() == bomberman::entities::ACharacters::actions::IDLE ||
            entity.get()->getCharacterAction() == bomberman::entities::ACharacters::actions::BOMB)
            nbPlayersAlive++;
    }
    if (nbPlayersAlive <= 1 && _gameState != bomberman::game::gameState::ENDGAME)
       this->_timer.get()->reStart(0, 0);

    if (_allBombs.size() == 0)
        return;
    for (auto it = _allBombs.begin(); it != _allBombs.end(); ++it) {
        if (it->get()->getState() == bomberman::entities::Bombs::bombState::END) {
            _allBombs.erase(it);
            break;
        }
        it->get()->update();
    }
}

void bomberman::game::Game::renderState(bomberman::core::GameEngine *engine)
{
    int playerNbr = 0;
    int winner = 0;

    if (this->_gameState == bomberman::game::gameState::BEGIN)
        DrawText(this->_timer->getTime()["seconds"].c_str(), GetScreenWidth() / 2 - this->_timer->getTime()["seconds"].length() * 30, GetScreenHeight() / 2, 120, RED);
    if (this->_gameState == bomberman::game::gameState::INGAME || this->_gameState == bomberman::game::gameState::SUDDEN_DEATH_MATCH) {
        this->_bgText[1].changeText(this->_timer.get()->getTime()["minutes"] + ":" + this->_timer.get()->getTime()["seconds"], 0);
        this->_bgText[1].draw();
    }
    if (this->_gameState == bomberman::game::gameState::SUDDEN_DEATH_MATCH) {
        if (_announcement)
            this->_bgText[2].draw();
    }
    if (this->_gameState == bomberman::game::gameState::ENDGAME) {
        for (auto bot : _allBots) {
            if (bot->getCharacterAction() != bomberman::entities::ACharacters::actions::BEFORE_DEATH && bot->getCharacterAction() != bomberman::entities::ACharacters::actions::AFTER_DEATH) {
                playerNbr++;
                winner = (int)bot->getPlayerNum() + 1;
            }
        }

        for (auto player : _allPlayers) {
            if (player->getCharacterAction() != bomberman::entities::ACharacters::actions::BEFORE_DEATH && player->getCharacterAction() != bomberman::entities::ACharacters::actions::AFTER_DEATH) {
                playerNbr++;
                winner = (int)player->getPlayerNum() + 1;
            }
        }

        if (playerNbr > 1 || playerNbr == 0)
            this->_bgText[0].changeText("DRAW", 0);
        else
            this->_bgText[0].changeText("PLAYER " + std::to_string(winner) + " WIN", 0);
        this->_bgText[0].draw();
    }
}

void bomberman::game::Game::render(bomberman::core::GameEngine *engine)
{
    (void)engine;

    BeginDrawing();

        ClearBackground(SKYBLUE);
        BeginMode3D(*_camera.getCamera());
            _skybox->drawSkybox();
            _map->renderMap();
            _gameboard->drawGameBoard();
            for (auto & powerUp : _allPowerUps)
                powerUp->render();
            for (auto & bot : _allBots)
                bot->renderCharacter();
            for (auto & player : _allPlayers)
                player->renderCharacter();
            for (auto & bomb : _allBombs)
                bomb->render();
        EndMode3D();

        renderState(engine);

    EndDrawing();
}

std::vector<std::shared_ptr<bomberman::entities::ACharacters>> bomberman::game::Game::getAllPlayableEntities(void)
{
    return this->_allPlayableEntities;
}