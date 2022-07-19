/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** TextButtons.cpp
*/
#include "raylib.h"
#include "TextButton.hpp"
#include <string>
#include <iostream>

typedef void (*callback_t)(bomberman::core::GameEngine *engine);

bomberman::objects::TextButton::TextButton(std::string text,
Vector2 position, float fontSize, callback_t callback)
{
    _width = (float)MeasureText(text.c_str(), fontSize);
    _height = 70.0f;
    _origin = { _width / 2.0f, _height / 2.0f };
    _fontSize = fontSize;
    _alpha = 1.0f;
    _bounds = {
        position.x - _width / 2.0f,
        position.y - _height / 3.0f,
        _width,
        _height
    };
    _color = WHITE;
    _callback = callback;
    _text = bomberman::text::Text(text, position, fontSize, WHITE);
}

void bomberman::objects::TextButton::draw()
{
    _text.drawText();
}

void bomberman::objects::TextButton::hover(bool isSound, bomberman::core::GameEngine *engine)
{
    if (isSound && _state != bomberman::objects::HOVER)
        PlaySound(engine->options.music.getHoverSound());
    _state = bomberman::objects::HOVER;
    _text.changeColor(LIGHTGRAY);
}

void bomberman::objects::TextButton::press()
{
    _state = bomberman::objects::CLICKED;
}

void bomberman::objects::TextButton::click(bool isSound, bomberman::core::GameEngine *engine)
{
    if (isSound)
        PlaySound(engine->options.music.getClickSound());
    _callback(engine);
}

void bomberman::objects::TextButton::released()
{
    _state = bomberman::objects::NORMAL;
    _text.changeColor(WHITE);
}

void bomberman::objects::TextButton::setColor(Color color)
{
    _color = color;
}

Rectangle bomberman::objects::TextButton::getBounds()
{
    return _bounds;
}

float bomberman::objects::TextButton::getWidth()
{
    return _bounds.width;
}

float bomberman::objects::TextButton::getHeight()
{
    return _bounds.height;
}

void bomberman::objects::TextButton::setCallback(callback_t callback)
{
    _callback = callback;
}