/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** Menu.hpp
*/
#pragma once

#include "raylib.h"
#include <map>
#include <string>

namespace bomberman {
    namespace settings {
        class RaylibMusic {
            private:
                Music _music;
                bool _isSoundActive;

            public:
                RaylibMusic();

                void toggleMusic();
                void toggleSound();

                bool isSoundActive();
                Music getMusicStream();
        };
    }
}
