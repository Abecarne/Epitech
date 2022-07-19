/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** Text.cpp
*/
#include "Text.hpp"

bomberman::text::Text::Text(std::string text, Vector2 position, float fontsize, Color color, std::string font)
{
    _text = text;
    _pos = position;
    _fontSize = fontsize;
    _color = color;
    _font = LoadFont(font.c_str());
}

void bomberman::text::Text::drawText()
{
    char const *text = _text.c_str();

    DrawTextEx(
        _font,
        _text.c_str(),
        {_pos.x - MeasureText(text, _fontSize) / 2.0f, _pos.y},
        _fontSize,
        1,
        _color
    );
}

void bomberman::text::Text::changeText(std::string text)
{
    _text = text;
}

void bomberman::text::Text::changeColor(Color color)
{
    _color = color;
}