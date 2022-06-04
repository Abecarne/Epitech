/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** CreateProfile.hpp
*/
#pragma once

#include "AGameState.hpp"
#include "Camera.hpp"
#include "Image.hpp"
#include "Button.hpp"
#include <mutex>

#define BACKGROUNDMODEL "assets/models/menu/menu.obj"

namespace bomberman {
    namespace menu {
        class CreateProfile : public bomberman::core::AGameState {
            private:
                static CreateProfile *_createMenuInstance;
                static std::mutex _mutex;

                bool _isOnText;
                int _key;
                int _letterCount;
                std::string pseudo;
                Model _background;
                Vector3 _backgroundPos;
                bomberman::entities::CameraCustom _camera;
                bomberman::objects::Image _image;
                std::vector<bomberman::objects::Button> _buttons;

            protected:
                CreateProfile() {}
                ~CreateProfile() {}

            public:
                CreateProfile(CreateProfile &) = delete;
                void operator=(CreateProfile const &) = delete;

                static CreateProfile *getInstance()
                {
                    std::lock_guard<std::mutex> lock(_mutex);

                    if (_createMenuInstance == nullptr)
                        _createMenuInstance = new CreateProfile();
                    return _createMenuInstance;
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
