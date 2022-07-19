/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** Text.hpp
*/
#pragma once

#include <string>
#include "raylib.h"

namespace bomberman {
    namespace text {
        class Text {
            private:
                std::string _text;
                Vector2 _pos;
                float _fontSize;
                Color _color;
                Font _font;

            public:
                Text(std::string text = "", Vector2 position = { 0.0f, 0.0f }, float fontsize = 10.0f, Color color = WHITE, std::string font = "./assets/font/pikmin.ttf");

                void drawText();
                void changeText(std::string text);
                void changeColor(Color color);
        };
    }
}