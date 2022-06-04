/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** GameAssets.hpp
*/
#pragma once

#include "Map.hpp"
#include "Skybox.hpp"
#include "GameBoard.hpp"

#include <memory>

namespace bomberman {

    namespace game {

        class GameAssets {
            private:
                std::shared_ptr<bomberman::environment::Skybox> _skybox;
                std::shared_ptr<bomberman::environment::Map> _map;
                std::shared_ptr<bomberman::environment::GameBoard> _gameBoard;

            public:
                GameAssets(void);
                ~GameAssets(void);

                void initMap(std::string mapFolder);
                void initSkyBox(bomberman::environment::Skybox::day_cycle state);
                void initGameBoard(size_t width, size_t heigth, Vector3 pos, std::string floorMesh,
                std::string destructibleMesh, std::string undestructibleMesh);

                std::shared_ptr<bomberman::environment::Skybox> getSkyBox(void);
                std::shared_ptr<bomberman::environment::GameBoard> getGameBoard(void);
                std::shared_ptr<bomberman::environment::Map> getMap(void);
        };

    };

};