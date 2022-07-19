/*
** EPITECH PROJECT, 2022
** Pikmins
** File description:
** Bombs.hpp
*/
#pragma once

#include "raylib.h"
#include "StaticModels.hpp"
#include "Errors.hpp"
#include "APowerUp.hpp"

namespace bomberman {
    namespace game {
        class Game;
    };
};

#include <memory>
#include <iostream>

namespace bomberman {

    namespace entities {

        class LootBox {
            public:
                LootBox(std::string mesh, Vector3 position, float scale);
                ~LootBox();

                bomberman::game::Game *_gameInstance;

                void destroyBox(void);
                void render(void);
                std::shared_ptr<bomberman::models::StaticModels> getModel(void);
                bool isDestroyed(void) const;

            private:
                bomberman::entities::powerup::PowerUpType _bonusType;
                std::shared_ptr<bomberman::models::StaticModels> _model;
                bool _isDestroyed;
        };

    };

};
