/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** Game.hpp
*/
#pragma once

#include "Map.hpp"
#include "AGameState.hpp"
#include "PauseMenu.hpp"
#include "Chronometer.hpp"
#include "Bombs.hpp"
#include "Camera.hpp"
#include "Players.hpp"
#include "Bots.hpp"
#include "BombUp.hpp"
#include "FireUp.hpp"
#include "WallPassUp.hpp"
#include "SpeedUp.hpp"
#include "Image.hpp"
#include <mutex>

#define GAME_MUSIC "./assets/music/gameMusic.mp3"

namespace bomberman {

    namespace game {

        enum gameState {
            BEGIN,
            INGAME,
            SUDDEN_DEATH_MATCH,
            ENDGAME,
            ENDING
        };

        class Game : public bomberman::core::AGameState {
            private:
                // Threadsafe's singletons
                static Game *_gameInstance;
                static std::mutex _mutex;

                std::vector<bomberman::objects::Image> _bgText;

                bomberman::game::gameState _gameState;

                std::vector<std::shared_ptr<bomberman::entities::Bombs>> _allBombs;
                bomberman::environment::Map *_map;
                bomberman::environment::Skybox *_skybox;
                bomberman::environment::GameBoard *_gameboard;
                std::vector<std::shared_ptr<bomberman::entities::Players>> _allPlayers;
                std::vector<std::shared_ptr<bomberman::entities::Bots>> _allBots;
                std::vector<std::shared_ptr<bomberman::entities::ACharacters>> _allPlayableEntities;

                std::map<bomberman::game::gameState, void (bomberman::game::Game::*)(bomberman::core::GameEngine *)> _timerFcts;

                std::shared_ptr<bomberman::settings::Chronometer> _timer;
                float _startTime;
                bool _announcement;
                std::vector<std::shared_ptr<bomberman::entities::powerup::APowerup>> _allPowerUps;

                bomberman::entities::CameraCustom _camera;

                Sound _finishSound = LoadSound("./assets/music/FinishSound.mp3");
                Sound _clockSound = LoadSound("./assets/music/ClockCountDown.mp3");
                Sound _suddenDeathSound = LoadSound("./assets/music/SuddenDeath.mp3");

                void updateGameTime(bomberman::core::GameEngine *engine);

                void BeginGameTimeHandler(bomberman::core::GameEngine *engine);
                void InGameTimeHandler(bomberman::core::GameEngine *engine);
                void suddenDeathMatch(bomberman::core::GameEngine *engine);
                void EndGameTimeHandler(bomberman::core::GameEngine *engine);
                void EndingTimeHandler(bomberman::core::GameEngine *engine);

                void renderState(bomberman::core::GameEngine *engine);

                bool isPaused;

            protected:
                Game(void) {};
                ~Game(void) {};

            public:
                // Threadsafe's singletons
                Game(Game &) = delete;
                void operator=(Game const &) = delete;
                static Game *getInstance()
                {
                    std::lock_guard<std::mutex> lock(_mutex);

                    if (_gameInstance == nullptr)
                        _gameInstance = new Game();
                    return _gameInstance;
                }

                void init(bomberman::core::GameEngine *engine);
                void cleanup(void);
                void pause(void);
                void resume(void);

                void processInput(bomberman::core::GameEngine *engine);
                void update(bomberman::core::GameEngine *engine, bomberman::core::Time deltaTime);
                void render(bomberman::core::GameEngine *engine);

                void addBombsToGame(Vector3 position, size_t radiusBlast);

                std::vector<std::shared_ptr<bomberman::entities::ACharacters>> getAllPlayableEntities(void);
                void addPowerUpToGame(Vector3 position, bomberman::entities::powerup::PowerUpType bonusType);

        };

    };

};
