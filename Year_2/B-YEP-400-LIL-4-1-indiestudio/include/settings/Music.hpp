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
                Sound _hoverSound;
                Sound _clickSound;
                int _soundVolume;
                int _musicVolume;
                bool _isSoundActive;
                bool _isMusicActive;
                float _oldMusicTime;

            public:
                RaylibMusic();

                void update();

                void toggleMusic(bool isActive);
                void toggleSound(bool isActive);

                bool isSoundActive();
                bool isMusicActive();

                void changeMusic(std::string musicPath);
                void rechangeMusic(std::string musicPath);

                Music getMusicStream();
                Sound getClickSound();
                Sound getHoverSound();

                int getMusicVolume();
                int getSoundVolume();

                void increaseMusic();
                void increaseSound();
                void decreaseMusic();
                void decreaseSound();
        };
    }
}
