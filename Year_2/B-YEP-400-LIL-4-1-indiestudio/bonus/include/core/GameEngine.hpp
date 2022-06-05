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

#include <vector>

namespace bomberman {
    namespace core {
        class AGameState;

        class GameEngine {
            private:
                int _key;
                Vector2 _mousePoint;
                double _keepTime;
                std::vector<bomberman::core::AGameState *> _states;
                bomberman::game::GameAssets *_gameAssets;

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

                Vector2 getMouseCoordinates();

                void initGameAssets(void);
                void cleanGameEngine(void);
                bomberman::game::GameAssets *getGameAssets(void);
        };
    }
}