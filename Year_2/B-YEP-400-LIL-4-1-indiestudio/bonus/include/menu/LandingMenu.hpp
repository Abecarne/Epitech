/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** LandingMenu.hpp
*/
#pragma once

#include "raylib.h"
#include "AGameState.hpp"
#include "Text.hpp"
#include "Camera.hpp"
#include <mutex>

namespace bomberman {
    namespace menu {
        class LandingMenu : public bomberman::core::AGameState {
            private:
                // Threadsafe's singletons
                static LandingMenu *_landingMenuInstance;
                static std::mutex _mutex;

                float _startedTime;
                bool _isZoomEnded;
                Model _background;
                Vector3 _backgroundPos;
                bomberman::entities::CameraCustom _camera;
                bomberman::text::Text _text;

            protected:
                LandingMenu() {}
                ~LandingMenu() {}

            public:
                // Threadsafe's singletons
                LandingMenu(LandingMenu &) = delete;
                void operator=(LandingMenu const &) = delete;
                static LandingMenu *getInstance()
                {
                    std::lock_guard<std::mutex> lock(_mutex);

                    if (_landingMenuInstance == nullptr)
                        _landingMenuInstance = new LandingMenu();
                    return _landingMenuInstance;
                }

                void init(bomberman::core::GameEngine *engine);
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
