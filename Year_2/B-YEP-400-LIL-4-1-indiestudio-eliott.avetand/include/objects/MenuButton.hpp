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

#define LEAFSELECTOR1 "assets/img/leafSelector1.png"
#define LEAFSELECTOR2 "assets/img/leafSelector2.png"

namespace bomberman {
    namespace objects {
        class MenuButton {
            typedef void (*callback_t)(bomberman::core::GameEngine *engine);

            private:
                float _width;
                float _height;
                float _scale;
                float _alpha;
                std::vector<bomberman::text::Text> _texts;
                Texture2D _buttonTexture;
                Texture2D _leafTexture1;
                Texture2D _leafTexture2;
                Rectangle _bounds;
                Vector2 _origin;
                buttonState _state;
                Color _color;
                Sound _hoverSound;
                Sound _clickSound;

            public:
                MenuButton(std::string buttonTexture, Vector2 position, float scale, callback_t callback);

                callback_t _callback;
                void draw();
                void hover(bool isSound);
                void press();
                void click(bool isSound, bomberman::core::GameEngine *engine);
                void released();

                void setText(int x, int y, std::string text, float size, Color color);
                void setCallback(callback_t callback);
                void setColor(Color color);

                Rectangle getBounds();
                float getWidth();
                float getHeight();
        };
    }
}