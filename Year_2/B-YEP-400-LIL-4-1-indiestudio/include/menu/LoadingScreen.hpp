/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** LoadingScreen.hpp
*/
#pragma once

#include "AGameState.hpp"
#include "Camera.hpp"
#include "Errors.hpp"

#include <map>
#include <raylib.h>
#include <rlgl.h>
#include <thread>
#include <vector>
#include <ctime>
#include <iostream>
#include <any>
#include <mutex>

#define LOADING1 "./assets/loading/loading1.mov"
#define LOADING2 "./assets/loading/loading2.mov"

namespace bomberman {

    namespace menu {

        class LoadingScreen : public bomberman::core::AGameState {
            private:
                static LoadingScreen *_saveMenuInstance;
                static std::mutex _mutex;

                std::map<std::string, void (bomberman::menu::LoadingScreen::*)(bomberman::core::GameEngine *)> _loadingFct;
                std::string _loadingState;
                bool _isLoaded;

                Font _font;
                bomberman::entities::CameraCustom _camera;

                void loadAllAssets(bomberman::core::GameEngine *engine);
                void loadMapAssets(bomberman::core::GameEngine *engine);
                void loadSkyAssets(bomberman::core::GameEngine *engine);
                void loadGameBoardAssets(bomberman::core::GameEngine *engine);
                void loadAllPlayersAssets(bomberman::core::GameEngine *engine);
                void loadBombsAssets(bomberman::core::GameEngine* engine);
                void loadPowerUpsAssets(bomberman::core::GameEngine *engine);

            protected:
                LoadingScreen() {};
                ~LoadingScreen() {};

            public:
                LoadingScreen(LoadingScreen &) = delete;
                void operator=(LoadingScreen const &) = delete;

                static LoadingScreen *getInstance()
                {
                    std::lock_guard<std::mutex> lock(_mutex);

                    if (_saveMenuInstance == nullptr)
                        _saveMenuInstance = new LoadingScreen();
                    return _saveMenuInstance;
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
    };
};