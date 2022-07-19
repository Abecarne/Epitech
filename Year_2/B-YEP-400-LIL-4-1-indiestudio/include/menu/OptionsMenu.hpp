/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** OptionsMenu.hpp
*/
#pragma once

#include "AGameState.hpp"
#include "Camera.hpp"
#include "Image.hpp"
#include "TextButton.hpp"
#include <mutex>

#define BACKGROUNDMODEL "assets/models/menu/menu.obj"

namespace bomberman {
    namespace menu {
        class OptionsMenu : public bomberman::core::AGameState {
            private:
                static OptionsMenu *_optionsMenuInstance;
                static std::mutex _mutex;

                Model _background;
                Vector3 _backgroundPos;
                bomberman::entities::CameraCustom _camera;
                bomberman::objects::Image _image;
                std::vector<bomberman::objects::Button> _backBtn;
                std::vector<bomberman::objects::TextButton> _buttons;

            protected:
                OptionsMenu() {}
                ~OptionsMenu() {}

            public:
                OptionsMenu(OptionsMenu &) = delete;
                void operator=(OptionsMenu const &) = delete;

                static OptionsMenu *getInstance()
                {
                    std::lock_guard<std::mutex> lock(_mutex);

                    if (_optionsMenuInstance == nullptr)
                        _optionsMenuInstance = new OptionsMenu();
                    return _optionsMenuInstance;
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
