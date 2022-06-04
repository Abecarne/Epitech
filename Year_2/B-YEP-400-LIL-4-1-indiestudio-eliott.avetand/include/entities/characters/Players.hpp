/*
** EPITECH PROJECT, 2022
** Pikmins
** File description:
** Players.hpp
*/
#pragma once

#include "ACharacters.hpp"
#include <raylib.h>

#define PLAYER_VELOCITY 0.5f

namespace bomberman {

    namespace entities {

        class Players : public bomberman::entities::ACharacters {
            private:

            public:
                Players(std::string typeModel = MODEL_RED_LEAF_PIKMIN, std::string skinModel = SKIN_DEFAULT, bomberman::entities::ACharacters::characterColors skinColor = bomberman::entities::ACharacters::characterColors::DEFAULT, std::string animationModel = ANIMATION_PIKMIN_DEFAULT, Vector3 pos = (Vector3){0.0f, 0.0f, 0.0f});
                ~Players();

                void updateCharacter(void);
        };

    };

};