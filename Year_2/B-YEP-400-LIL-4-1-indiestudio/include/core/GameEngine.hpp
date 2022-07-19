/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** Core.hpp
*/
#pragma once

#include "Time.hpp"
#include "Options.hpp"
#include "Map.hpp"
#include "GameAssets.hpp"
#include <mutex>

#include <vector>

namespace bomberman {
    namespace objects {
        class Image;
    }
    namespace core {
        class AGameState;
        class GameEngine {
            private:
                int _key;
                Vector2 _mousePoint;
                Texture2D _image;
                double _keepTime;
                bool _shouldClose;
                std::vector<bomberman::core::AGameState *> _states;
                bomberman::game::GameAssets *_gameAssets;

                static GameEngine *_gameEngineInstance;
                static std::mutex _mutex;

            public:
                bomberman::settings::Options options;

                void init();
                void cleanup();

                void changeState(bomberman::core::AGameState *state);
                void pushState(bomberman::core::AGameState *state);
                void popState();

                void processInput();
                void update(bomberman::core::Time deltaTime);
                void render();
                void gameLoop();
                void drawCursor();

                Vector2 getMouseCoordinates();
                void shouldClose();

                void initGameAssets(void);
                void cleanGameEngine(void);
                bomberman::game::GameAssets *getGameAssets(void);
                void cleanGameAssets(void);

                static GameEngine *getInstance()
                {
                    std::lock_guard<std::mutex> lock(_mutex);

                    if (_gameEngineInstance == nullptr)
                        _gameEngineInstance = new GameEngine();
                    return _gameEngineInstance;
                }
        };
    }
}