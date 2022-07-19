/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** VolumeOptions.hpp
*/
#pragma once

#include "AGameState.hpp"
#include "Camera.hpp"
#include "Image.hpp"
#include "Button.hpp"
#include <mutex>
#include <iostream>

#define BACKGROUNDMODEL "assets/models/menu/menu.obj"

namespace bomberman {
    namespace menu {
        class VolumeOptions : public bomberman::core::AGameState {
            private:
                static VolumeOptions *_volumeOptionsInstance;
                static std::mutex _mutex;

                bool _isOnText;
                int _key;
                int _letterCount;
                std::string _currentKey;
                Model _background;
                Vector3 _backgroundPos;
                bomberman::entities::CameraCustom _camera;
                std::vector<bomberman::objects::Image> _images;
                std::vector<bomberman::text::Text> _texts;
                std::vector<bomberman::objects::Button> _buttons;

            protected:
                VolumeOptions() {}
                ~VolumeOptions() {}

            public:
                VolumeOptions(VolumeOptions &) = delete;
                void operator=(VolumeOptions const &) = delete;

                static VolumeOptions *getInstance()
                {
                    std::lock_guard<std::mutex> lock(_mutex);

                    if (_volumeOptionsInstance == nullptr)
                        _volumeOptionsInstance = new VolumeOptions();
                    return _volumeOptionsInstance;
                }

                void init(bomberman::core::GameEngine *engine);
                void initAssets(bomberman::core::GameEngine *engine);
                void initButtons(bomberman::core::GameEngine *engine);
                void initTexts(bomberman::core::GameEngine *engine);
                void cleanup();

                void pause();
                void resume();

                void processInput(bomberman::core::GameEngine *engine);
                void handleKeyMapping(bomberman::core::GameEngine *engine);
                void update(bomberman::core::GameEngine *engine,
                bomberman::core::Time deltaTime);
                void render(bomberman::core::GameEngine *engine);
        };
    }
}
