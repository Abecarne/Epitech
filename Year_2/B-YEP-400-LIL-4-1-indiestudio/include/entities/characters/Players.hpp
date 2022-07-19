/*
** EPITECH PROJECT, 2022
** Pikmins
** File description:
** Players.hpp
*/

#pragma once

#include "ACharacters.hpp"
#include "Vector3Utils.hpp"

#include <raylib.h>

namespace bomberman
{
    namespace entities
    {
        class Players : public bomberman::entities::ACharacters
        {
            public:
                Players(bomberman::entities::ACharacters::playerNum playerNum, std::string typeModel = MODEL_RED_LEAF_PIKMIN, std::string skinModel = SKIN_DEFAULT, bomberman::entities::ACharacters::characterColors skinColor = bomberman::entities::ACharacters::characterColors::DEFAULT, std::string animationModel = ANIMATION_PIKMIN_DEFAULT, Vector3 pos = {0.0f, 0.0f, 0.0f});
                ~Players();

                Vector4 getNewDirection(bomberman::core::Time deltaTime, int action);
                void move(bomberman::core::Time deltaTime, int action);
        };
    };
};