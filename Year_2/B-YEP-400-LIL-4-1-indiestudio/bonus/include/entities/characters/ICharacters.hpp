/*
** EPITECH PROJECT, 2022
** Pikmins
** File description:
** ICharacters.hpp
*/
#pragma once

#include <raylib.h>

namespace bomberman {

    namespace entities {

        class ICharacters {
            public:
                virtual ~ICharacters() = default;
                virtual void renderCharacter(void) = 0;
                virtual void updateCharacter(void) = 0;
                virtual bool isCollision(Vector3 objectPos, Vector3 objectSize, Vector3 objectScale) = 0;
        };

    };

};