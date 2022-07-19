/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** PauseMenu.hpp
*/
#pragma once

#include "AGameState.hpp"
#include "Camera.hpp"
#include "Image.hpp"
#include "MenuButton.hpp"
#include "MainMenu.hpp"
#include "Button.hpp"
#include <mutex>
#include <iostream>

#define LOADSAVEBTN "assets/img/plank.png"

namespace bomberman {
    namespace menu {
        class PauseMenu : public bomberman::core::AGameState {
            private:
                static PauseMenu *_pauseMenuInstance;
                static std::mutex _mutex;

                bomberman::objects::Image _bg;
                bomberman::objects::Image _image;
                std::vector<bomberman::objects::MenuButton> _buttons;

            protected:
                PauseMenu() {}
                ~PauseMenu() {}

            public:
                PauseMenu(PauseMenu &) = delete;
                void operator=(PauseMenu const &) = delete;

                static PauseMenu *getInstance()
                {
                    std::lock_guard<std::mutex> lock(_mutex);

                    if (_pauseMenuInstance == nullptr)
                        _pauseMenuInstance = new PauseMenu();
                    return _pauseMenuInstance;
                }

                void init(bomberman::core::GameEngine *engine);
                void initAssets(bomberman::core::GameEngine *engine);
                void initButtons(bomberman::core::GameEngine *engine);
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
