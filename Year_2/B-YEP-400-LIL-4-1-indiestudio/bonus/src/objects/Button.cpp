/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** Core.cpp
*/
#include "raylib.h"
#include "Button.hpp"
#include <string>
#include <iostream>

typedef void (*callback_t)(bomberman::core::GameEngine *engine);

bomberman::objects::Button::Button(std::string buttonTexture,
Vector2 position, float scale, callback_t callback)
{
    _buttonTexture = LoadTexture(buttonTexture.c_str());
    _width = (float)_buttonTexture.width / 4;
    _height = (float)_buttonTexture.height;
    _sourceRec = { 0.0f, 0.0f, (float)_width, (float)_height };
    _destRec = { position.x, position.y, _width * scale, _height * scale };
    _origin = { _width / 2.0f * scale, _height / 2.0f * scale };
    _bounds = {
        position.x - _origin.x,
        position.y - _origin.y,
        _width * scale,
        _height * scale
    };
    _callback = callback;
}

void bomberman::objects::Button::draw()
{
    DrawTexturePro(_buttonTexture, _sourceRec, _destRec, _origin, 0.0f, WHITE);
    for (size_t i = 0; i < _texts.size(); i++)
        _texts[i].drawText();
}

void bomberman::objects::Button::hover(bool isSound)
{
    if (isSound && _state != bomberman::objects::HOVER)
        PlaySound(_hoverSound);
    _state = bomberman::objects::HOVER;
    _sourceRec.x = _state * (_buttonTexture.width / 4);
}

void bomberman::objects::Button::press()
{
    _state = bomberman::objects::CLICKED;
    _sourceRec.x = _state * (_buttonTexture.width / 4);
}

void bomberman::objects::Button::click(bool isSound, bomberman::core::GameEngine *engine)
{
    _state = _state == bomberman::objects::NORMAL ? bomberman::objects::LOCKED : bomberman::objects::NORMAL;
    if (isSound)
        PlaySound(_clickSound);
    _callback(engine);
    _sourceRec.x = _state * (_buttonTexture.width / 4);
}

void bomberman::objects::Button::released()
{
    _state = bomberman::objects::NORMAL;
    _sourceRec.x = _state * (_buttonTexture.width / 4);
}

void bomberman::objects::Button::setText(int x, int y, std::string text, float size, Color color)
{
    Vector2 pos = {_bounds.x + x, _bounds.y + y};
    bomberman::text::Text textInstance(text, pos, size, color);

    _texts.push_back(textInstance);
}

Rectangle bomberman::objects::Button::getBounds()
{
    return _bounds;
}

float bomberman::objects::Button::getWidth()
{
    return _bounds.width;
}

float bomberman::objects::Button::getHeight()
{
    return _bounds.height;
}

void bomberman::objects::Button::setCallback(callback_t callback)
{
    _callback = callback;
}