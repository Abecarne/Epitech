/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** Core.cpp
*/
#include "raylib.h"
#include "MenuButton.hpp"
#include <string>
#include <iostream>

typedef void (*callback_t)(bomberman::core::GameEngine *engine);

bomberman::objects::MenuButton::MenuButton(std::string buttonTexture,
Vector2 position, float scale, callback_t callback)
{
    _hoverSound = LoadSound("assets/music/button_hover.wav");
    _clickSound = LoadSound("assets/music/button_click.wav");
    _buttonTexture = LoadTexture(buttonTexture.c_str());
    _leafTexture1 = LoadTexture(LEAFSELECTOR1);
    _leafTexture2 = LoadTexture(LEAFSELECTOR2);
    _width = (float)_buttonTexture.width;
    _height = (float)_buttonTexture.height;
    _origin = { _width / 2.0f * scale, _height / 2.0f * scale };
    _scale = scale;
    _alpha = 1.0f;
    _bounds = {
        position.x - _origin.x,
        position.y - _origin.y,
        _width * scale,
        _height * scale
    };
    _color = WHITE;
    _callback = callback;
}

void bomberman::objects::MenuButton::draw()
{
    DrawTextureEx(_buttonTexture, { _bounds.x, _bounds.y }, 0.0f, _scale, _color);
    for (size_t i = 0; i < _texts.size(); i++)
        _texts[i].drawText();
    if (_state != NORMAL)
        _alpha = 1.0f;
    else
        _alpha -= 0.03f;
    DrawTextureEx(
        _leafTexture1,
        { _bounds.x + _bounds.width + 40.0f,
        _bounds.y + _bounds.height / 2.0f - _leafTexture1.height * 0.15f / 2.0f },
        0.0f, 0.15f, Fade(WHITE, _alpha)
    );
    DrawTextureEx(
        _leafTexture2,
        { _bounds.x - _leafTexture2.width * 0.15f - 40.0f,
        _bounds.y + _bounds.height / 2.0f - _leafTexture2.height * 0.15f / 2.0f },
        0.0f, 0.15f, Fade(WHITE, _alpha)
    );
}

void bomberman::objects::MenuButton::hover(bool isSound)
{
    if (isSound && _state != bomberman::objects::HOVER)
        PlaySound(_hoverSound);
    _state = bomberman::objects::HOVER;
}

void bomberman::objects::MenuButton::press()
{
    _state = bomberman::objects::CLICKED;
}

void bomberman::objects::MenuButton::click(bool isSound, bomberman::core::GameEngine *engine)
{
    if (isSound)
        PlaySound(_clickSound);
    _callback(engine);
}

void bomberman::objects::MenuButton::released()
{
    _state = bomberman::objects::NORMAL;
}

void bomberman::objects::MenuButton::setText(int x, int y, std::string text, float size, Color color)
{
    Vector2 pos = {_bounds.x + x, _bounds.y + y};
    bomberman::text::Text textInstance(text, pos, size, color);

    _texts.push_back(textInstance);
}

void bomberman::objects::MenuButton::setColor(Color color)
{
    _color = color;
}

Rectangle bomberman::objects::MenuButton::getBounds()
{
    return _bounds;
}

float bomberman::objects::MenuButton::getWidth()
{
    return _bounds.width;
}

float bomberman::objects::MenuButton::getHeight()
{
    return _bounds.height;
}

void bomberman::objects::MenuButton::setCallback(callback_t callback)
{
    _callback = callback;
}