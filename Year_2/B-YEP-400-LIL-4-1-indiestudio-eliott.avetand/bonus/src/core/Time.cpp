/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** Time.cpp
*/
#include "raylib.h"
#include "Time.hpp"

bomberman::core::Time::Time(double time = 0.0f)
{
    _time = time;
    _lastTime = 0.0f;
    _deltaTime = 0.0f;
}

bomberman::core::Time::operator float() const
{
    return _time;
}

double bomberman::core::Time::getSeconds() const
{
    return _time;
}

double bomberman::core::Time::getMilliseconds() const
{
    return _time * 1000;
}
