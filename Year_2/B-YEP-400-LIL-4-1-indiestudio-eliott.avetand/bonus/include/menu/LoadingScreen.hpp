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
#include <vlc/vlc.h>
#include <raylib.h>
#include <rlgl.h>
#include <thread>
#include <vector>
#include <ctime>
#include <iostream>
#include <any>
#include <glib.h>

#define LOADING1 "./assets/loading/loading1.mov"
#define LOADING2 "./assets/loading/loading2.mov"

namespace bomberman {

    namespace menu {

        typedef struct video_s {
            GMutex mutex;
            Texture2D texture;
            uint8_t *videoBuffer;
            bool getUpdate;
        } video_t;

        class LoadingScreen : public bomberman::core::AGameState {
            private:

                static LoadingScreen *_saveMenuInstance;
                static std::mutex _mutex;

                std::map<std::string, void (bomberman::menu::LoadingScreen::*)(bomberman::core::GameEngine *)> _loadingFct;
                std::string _loadingState;
                bool _isLoaded;

                std::vector<std::string> _videoList;
                std::string _readedVideo;

                Font _font;
                bomberman::entities::CameraCustom _camera;
                bomberman::menu::video_t *_video;
                libvlc_instance_t *_lib_vlc;
                libvlc_media_player_t *_mediaPlayer;
                libvlc_media_t *_media;

                void loadAllAssets(bomberman::core::GameEngine *engine);
                void loadMapAssets(bomberman::core::GameEngine *engine);
                void loadSkyAssets(bomberman::core::GameEngine *engine);
                void loadGameBoardAssets(bomberman::core::GameEngine *engine);
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

                bool videoIsFinished(void);

                void instanceVideo(size_t screenWidth, size_t screenHeight);
                void restartLoadingScreen(void);
        };
    };
};