/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** Options.hpp
*/
#pragma once

#include <cstddef>
#include <string>
#include <map>
#include "Music.hpp"

namespace bomberman {
    namespace settings {
        class Options {
            private:
                size_t _width;
                size_t _height;
                size_t _fps;
                std::string _title;

            public:
                Options();

                size_t getWindowWidth();
                size_t getWindowHeight();
                size_t getFps();
                double getFramePerUpdate();
                char const *getTitle();

                bomberman::settings::RaylibMusic music;
        };
    }
}