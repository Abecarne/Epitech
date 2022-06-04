/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** Options.cpp
*/
#include "raylib.h"
#include "Options.hpp"
#include <iostream>

bomberman::settings::Options::Options()
{
    _width = 1920;
    _height = 1080;
    _fps = 144;
    _title = "Pikmins";
}

size_t bomberman::settings::Options::getWindowWidth()
{
    return _width;
}

size_t bomberman::settings::Options::getWindowHeight()
{
    return _height;
}

size_t bomberman::settings::Options::getFps()
{
    return _fps;
}

double bomberman::settings::Options::getFramePerUpdate()
{
    return (1.0f / _fps) * 1000.0f;
}

char const *bomberman::settings::Options::getTitle()
{
    return _title.c_str();
}
