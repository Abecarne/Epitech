/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** PreGame.hpp
*/
#pragma once

#include "AGameState.hpp"
#include "Game.hpp"
#include "Camera.hpp"
#include "Skybox.hpp"
#include "Map.hpp"
#include "Text.hpp"

#include <memory>
#include <raylib.h>
#include <cmath>
#include <mutex>
#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/json_parser.hpp"

#define PREGAME_MUSIC "./assets/music/travelingMusic.mp3"

namespace bomberman {
    namespace game {
        class PreGame : public bomberman::core::AGameState {
            private:
                class TravelingParser {
                    private:
                        boost::property_tree::ptree _root;
                        std::vector<std::pair<Vector3, Vector3>> _beginPositions;
                        std::vector<std::pair<Vector3, Vector3>> _endingPositions;
                        std::vector<float> _travelingDurations;
                        float _startedTime;

                        void openFile(std::string filepath);
                        void getTravelingInformations(std::string mapFolder);
                        void checkLineInfos(boost::property_tree::ptree::value_type travelingNode);
                        void pushTravelingInformations(boost::property_tree::ptree::value_type travelingNode);
                    public:
                        TravelingParser(void) {};
                        ~TravelingParser(void);

                        void init(std::string mapFolder);
                        std::vector<std::pair<Vector3, Vector3>> getBeginPosition(void);
                        std::vector<std::pair<Vector3, Vector3>> getEndingPosition(void);
                        std::vector<float> getTravelingDurations(void);
                };

            private:
                // Threadsafe's singletons
                static PreGame *_preGameInstance;
                static std::mutex _mutex;

                float _startedTime;
                bomberman::entities::CameraCustom _camera;
                bomberman::environment::Skybox *_skybox;
                bomberman::environment::Map *_map;
                bomberman::game::PreGame::TravelingParser _travelingParser;

                bomberman::text::Text _text;

                std::vector<std::pair<Vector3, Vector3>> _beginPositions;
                std::vector<std::pair<Vector3, Vector3>> _endingPositions;
                std::vector<float> _travelingDurations;
                size_t _nbrTraveling;

            protected:
                PreGame(void) {};
                ~PreGame(void) {};

            public:
                // Threadsafe's singletons
                PreGame(PreGame &) = delete;
                void operator=(PreGame const &) = delete;
                static PreGame *getInstance()
                {
                    std::lock_guard<std::mutex> lock(_mutex);

                    if (_preGameInstance == nullptr)
                        _preGameInstance = new PreGame();
                    return _preGameInstance;
                }

                void init(bomberman::core::GameEngine *engine);
                void cleanup(void);

                void pause(void);
                void resume(void);

                void processInput(bomberman::core::GameEngine *engine);
                void update(bomberman::core::GameEngine *engine,
                bomberman::core::Time deltaTime);
                void render(bomberman::core::GameEngine *engine);
        };
    };
};