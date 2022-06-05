/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** Button.hpp
*/
#pragma once

#include <string>
#include <vector>
#include "GameEngine.hpp"
#include "Text.hpp"

namespace bomberman {
    namespace objects {
        enum buttonState {
            NORMAL,
            HOVER,
            CLICKED,
            LOCKED
        };

        class Button {
            typedef void (*callback_t)(bomberman::core::GameEngine *engine);

            private:
                float _width;
                float _height;
                std::vector<bomberman::text::Text> _texts;
                Texture2D _buttonTexture;
                Rectangle _sourceRec;
                Rectangle _destRec;
                Rectangle _bounds;
                Vector2 _origin;
                buttonState _state;
                Sound _hoverSound = LoadSound("assets/music/button_hover.wav");
                Sound _clickSound = LoadSound("assets/music/button_click.wav");

            public:
                Button(std::string buttonTexture, Vector2 position, float scale, callback_t callback);

                callback_t _callback;
                void draw();
                void hover(bool isSound);
                void press();
                void click(bool isSound, bomberman::core::GameEngine *engine);
                void released();
                void setText(int x, int y, std::string text, float size, Color color);
                void setCallback(callback_t callback);

                Rectangle getBounds();
                float getWidth();
                float getHeight();
        };
    }
}