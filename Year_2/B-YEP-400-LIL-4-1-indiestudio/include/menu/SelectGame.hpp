/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** SelectGame.hpp
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
        class SelectGame : public bomberman::core::AGameState {
            private:
                static SelectGame *_selectGameInstance;
                static std::mutex _mutex;

                std::string _nb_players;
                std::string _difficulty;
                Model _background;
                Vector3 _backgroundPos;
                bomberman::entities::CameraCustom _camera;
                std::vector<bomberman::objects::Image> _images;
                std::vector<bomberman::objects::TextButton> _textButtons;
                std::vector<bomberman::objects::Button> _buttons;

            protected:
                SelectGame() {}
                ~SelectGame() {}

            public:
                SelectGame(SelectGame &) = delete;
                void operator=(SelectGame const &) = delete;

                static SelectGame *getInstance()
                {
                    std::lock_guard<std::mutex> lock(_mutex);

                    if (_selectGameInstance == nullptr)
                        _selectGameInstance = new SelectGame();
                    return _selectGameInstance;
                }

                void init(bomberman::core::GameEngine *engine);
                void initButtons(bomberman::core::GameEngine *engine);
                void initAssets(bomberman::core::GameEngine *engine);
                void cleanup();

                void pause();
                void resume();

                void processInput(bomberman::core::GameEngine *engine);
                void update(bomberman::core::GameEngine *engine,
                bomberman::core::Time deltaTime);
                void render(bomberman::core::GameEngine *engine);
        };
    }
}
