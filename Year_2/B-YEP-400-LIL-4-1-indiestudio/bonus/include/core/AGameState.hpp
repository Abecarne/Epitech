/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** GameState.hpp
*/
#pragma once

#include "GameEngine.hpp"

namespace bomberman {
    namespace core {
        class AGameState {
            public:
                virtual void init(bomberman::core::GameEngine *engine) = 0;
                virtual void cleanup() = 0;

                virtual void pause() = 0;
                virtual void resume() = 0;

                virtual void processInput(bomberman::core::GameEngine *engine) = 0;
                virtual void update(bomberman::core::GameEngine *engine,
                bomberman::core::Time deltaTime) = 0;
                virtual void render(bomberman::core::GameEngine *engine) = 0;

                virtual void changeState(bomberman::core::GameEngine *engine, bomberman::core::AGameState *state)
                {
                    engine->changeState(state);
                }
        };
    }
}