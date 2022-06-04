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
        class Image {
            private:
                float _width;
                float _height;
                std::vector<bomberman::text::Text> _texts;
                Texture2D _imageTexture;
                Vector2 _origin;
                float _scale;
                Rectangle _bounds;

            public:
                Image(std::string imageTexture, Vector2 position, float scale);

                void draw();
                void setText(int x, int y, std::string text, float size, Color color);

                Rectangle getBounds();
                float getWidth();
                float getHeight();
        };
    }
}