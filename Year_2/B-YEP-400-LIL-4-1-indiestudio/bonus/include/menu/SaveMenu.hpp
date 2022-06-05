/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** SaveMenu.hpp
*/
#pragma once

#include "AGameState.hpp"
#include "Camera.hpp"
#include "MenuButton.hpp"
#include <mutex>

#define BACKGROUNDMODEL "assets/models/menu/menu.obj"
#define LOADSAVEBTN "assets/img/plank.png"

namespace bomberman {
    namespace menu {
        typedef struct textInfos_s {
            Vector2 pos;
            std::string prefix;
            std::string suffix;
            float fontSize;
            Color color;
        } textInfos_t;

        class SaveMenu : public bomberman::core::AGameState {
            private:
                static SaveMenu *_saveMenuInstance;
                static std::mutex _mutex;

                Model _background;
                Vector3 _backgroundPos;
                bomberman::entities::CameraCustom _camera;
                std::vector<bomberman::objects::MenuButton> _buttons;

            protected:
                SaveMenu() {}
                ~SaveMenu() {}

            public:
                SaveMenu(SaveMenu &) = delete;
                void operator=(SaveMenu const &) = delete;

                static SaveMenu *getInstance()
                {
                    std::lock_guard<std::mutex> lock(_mutex);

                    if (_saveMenuInstance == nullptr)
                        _saveMenuInstance = new SaveMenu();
                    return _saveMenuInstance;
                }

                void init(bomberman::core::GameEngine *engine);
                void initButton(bomberman::core::GameEngine *engine);
                void initSave(bomberman::core::GameEngine *engine);
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
