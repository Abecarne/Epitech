/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** SelectMap.hpp
*/
#pragma once

#include "AGameState.hpp"
#include "Camera.hpp"
#include "TextButton.hpp"
#include "Image.hpp"
#include "Button.hpp"
#include <iostream>
#include <mutex>

#define BACKGROUNDMODEL "assets/models/menu/menu.obj"

namespace bomberman {
    namespace menu {
        class SelectMap : public bomberman::core::AGameState {
            private:
                static SelectMap *_selectMapInstance;
                static std::mutex _mutex;

                Model _background;
                Vector3 _backgroundPos;
                bomberman::entities::CameraCustom _camera;
                std::vector<bomberman::objects::Image> _images;
                std::vector<bomberman::objects::TextButton> _textButtons;
                std::vector<bomberman::objects::Button> _buttons;

            protected:
                SelectMap() {}
                ~SelectMap() {}

            public:
                SelectMap(SelectMap &) = delete;
                void operator=(SelectMap const &) = delete;

                static SelectMap *getInstance()
                {
                    std::lock_guard<std::mutex> lock(_mutex);

                    if (_selectMapInstance == nullptr)
                        _selectMapInstance = new SelectMap();
                    return _selectMapInstance;
                }

                void init(bomberman::core::GameEngine *engine);
                void initButtons(bomberman::core::GameEngine *engine);
                void initAssets(bomberman::core::GameEngine *engine);
                void cleanup();

                void pause();
                void resume();

                void processInput(bomberman::core::GameEngine *engine);
                void changeMap(bomberman::core::GameEngine *engine);
                void update(bomberman::core::GameEngine *engine,
                bomberman::core::Time deltaTime);
                void render(bomberman::core::GameEngine *engine);
        };
    }
}
