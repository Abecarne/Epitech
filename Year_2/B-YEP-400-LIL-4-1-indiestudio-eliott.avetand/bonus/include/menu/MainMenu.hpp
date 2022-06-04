/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** MainMenu.hpp
*/
#pragma once

#include "AGameState.hpp"
#include "Camera.hpp"
#include "Button.hpp"
#include <mutex>

namespace bomberman {
    namespace menu {
        class MainMenu : public bomberman::core::AGameState {
            private:
                static MainMenu *_mainMenuInstance;
                static std::mutex _mutex;

                Model _background;
                Vector3 _backgroundPos;
                bomberman::entities::CameraCustom _camera;
                std::vector<bomberman::objects::Button> _buttons;

            protected:
                MainMenu() {}
                ~MainMenu() {}

            public:
                MainMenu(MainMenu &) = delete;
                void operator=(MainMenu const &) = delete;

                static MainMenu *getInstance()
                {
                    std::lock_guard<std::mutex> lock(_mutex);

                    if (_mainMenuInstance == nullptr)
                        _mainMenuInstance = new MainMenu();
                    return _mainMenuInstance;
                }

                void init(bomberman::core::GameEngine *engine);
                void initButton(bomberman::core::GameEngine *engine);
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
