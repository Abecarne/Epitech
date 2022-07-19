/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** ControlOptions.hpp
*/
#pragma once

#include "AGameState.hpp"
#include "Camera.hpp"
#include "Image.hpp"
#include "Button.hpp"
#include "Options.hpp"
#include <mutex>
#include <iostream>

#define BACKGROUNDMODEL "assets/models/menu/menu.obj"

namespace bomberman {
    namespace menu {
        typedef struct button_s {
            std::string input;
            Vector2 pos;
            bomberman::settings::Actions action;
        } buttons_t;

        class ControlOptions : public bomberman::core::AGameState {
            private:
                static ControlOptions *_controlOptionsInstance;
                static std::mutex _mutex;

                bool _isOnText;
                int _key;
                int _letterCount;
                std::string _currentKey;
                Model _background;
                Vector3 _backgroundPos;
                bomberman::entities::CameraCustom _camera;
                bomberman::objects::Image _image;
                std::vector<bomberman::text::Text> _texts;
                std::vector<bomberman::objects::Button> _buttons;

            protected:
                ControlOptions() {}
                ~ControlOptions() {}

            public:
                ControlOptions(ControlOptions &) = delete;
                void operator=(ControlOptions const &) = delete;

                static ControlOptions *getInstance()
                {
                    std::lock_guard<std::mutex> lock(_mutex);

                    if (_controlOptionsInstance == nullptr)
                        _controlOptionsInstance = new ControlOptions();
                    return _controlOptionsInstance;
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
