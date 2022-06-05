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
#include <mutex>

#define BACKGROUNDMODEL "assets/models/menu/menu.obj"

namespace bomberman {
    namespace menu {
        class CreateProfile : public bomberman::core::AGameState {
            private:
                static CreateProfile *_saveMenuInstance;
                static std::mutex _mutex;

                bool _isOnText;
                int _key;
                int _letterCount;
                std::string pseudo;
                Model _background;
                Vector3 _backgroundPos;
                bomberman::entities::CameraCustom _camera;
                std::vector<bomberman::objects::Image> _images;

            protected:
                CreateProfile() {}
                ~CreateProfile() {}

            public:
                CreateProfile(CreateProfile &) = delete;
                void operator=(CreateProfile const &) = delete;

                static CreateProfile *getInstance()
                {
                    std::lock_guard<std::mutex> lock(_mutex);

                    if (_saveMenuInstance == nullptr)
                        _saveMenuInstance = new CreateProfile();
                    return _saveMenuInstance;
                }

                void init(bomberman::core::GameEngine *engine);
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
