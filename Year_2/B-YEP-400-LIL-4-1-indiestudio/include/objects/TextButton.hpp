/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** Button.hpp
*/
#pragma once

#include <string>
#include <vector>
#include "Button.hpp"
#include "GameEngine.hpp"

namespace bomberman {
    namespace objects {
        class TextButton {
            typedef void (*callback_t)(bomberman::core::GameEngine *engine);

            private:
                float _width;
                float _height;
                float _fontSize;
                float _alpha;
                bomberman::text::Text _text;
                Rectangle _bounds;
                Vector2 _origin;
                buttonState _state;
                Color _color;

            public:
                TextButton(std::string text, Vector2 position, float scale, callback_t callback);

                callback_t _callback;
                void draw();
                void hover(bool isSound, bomberman::core::GameEngine *engine);
                void press();
                void click(bool isSound, bomberman::core::GameEngine *engine);
                void released();

                void setCallback(callback_t callback);
                void setColor(Color color);

                Rectangle getBounds();
                float getWidth();
                float getHeight();
        };
    }
}