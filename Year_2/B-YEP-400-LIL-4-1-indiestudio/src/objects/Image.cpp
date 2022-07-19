/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** Core.cpp
*/
#include "raylib.h"
#include "Image.hpp"
#include <string>
#include <iostream>

bomberman::objects::Image::Image(std::string imageTexture, Vector2 position, float scale)
{
    _imageTexture = LoadTexture(imageTexture.c_str());
    _width = (float)_imageTexture.width;
    _height = (float)_imageTexture.height;
    _scale = scale;
    _origin = { _width / 2.0f * scale, _height / 2.0f * scale };
    _bounds = {
        position.x - _origin.x,
        position.y - _origin.y,
        _width * scale,
        _height * scale
    };
}

void bomberman::objects::Image::draw()
{
    DrawTextureEx(_imageTexture, { _bounds.x, _bounds.y }, 0.0f, _scale, WHITE);
    for (size_t i = 0; i < _texts.size(); i++)
        _texts[i].drawText();
}

void bomberman::objects::Image::setText(int x, int y, std::string text, float size, Color color)
{
    Vector2 pos = {_bounds.x + x, _bounds.y + y};
    bomberman::text::Text textInstance(text, pos, size, color);

    _texts.push_back(textInstance);
}

void bomberman::objects::Image::changeText(std::string text, int index)
{
    _texts[index].changeText(text);
}

Rectangle bomberman::objects::Image::getBounds()
{
    return _bounds;
}

float bomberman::objects::Image::getWidth()
{
    return _bounds.width;
}

float bomberman::objects::Image::getHeight()
{
    return _bounds.height;
}

void bomberman::objects::Image::changePosition(Vector2 position)
{
    _bounds = {
        position.x - _origin.x,
        position.y - _origin.y,
        _bounds.width,
        _bounds.height
    };
}