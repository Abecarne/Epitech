/*
** EPITECH PROJECT, 2022
** Pikmins
** File description:
** BoardGame.hpp
*/
#pragma once

#include "StaticModels.hpp"

#include <memory>
#include <vector>
#include <map>

// Destructible Mesh

#define DESTRUCTIBLE_JAPANEASE "./assets/models/boardgame/desctructible/japaneasebox.glb"
#define DESTRUCTIBLE_WOODBOX "./assets/models/boardgame/desctructible/woodbox.glb"

namespace bomberman {

    namespace environment {

        class GameBoard {
            public:
                void init(size_t width, size_t heigth, Vector3 pos, std::string floorMesh, std::string destructibleMesh, std::string undestructibleMesh);
                void loadNextModels(void);
                void drawGameBoard(void);
                bool getAssetsState(void);
            private:
                enum gameboardState {
                    FLOOR,
                    UNDESTRUCTIBLE,
                    DESTRUCTIBLE
                };

                bomberman::environment::GameBoard::gameboardState _state;
                std::vector<std::shared_ptr<bomberman::models::StaticModels>> _gameBoardModels;
                size_t _width;
                size_t _height;
                float _scale;
                Vector3 _position;
                bool _isFinish;

                std::string _destructibleBox;
                std::string _undestructibleBox;
                std::string _floor;

                size_t _modelsCount;

                std::shared_ptr<bomberman::models::StaticModels> createStaticModel(std::string floorMesh, Vector3 position);

                void initFloorMesh(size_t width, size_t heigth, std::string floorMesh);
                void initDestructibleMesh(size_t width, size_t heigth, std::string destructibleMesh);
                void initUndestructibleMesh(size_t width, size_t heigth, std::string undestructibleMesh);

                void loadNextUndestructibleModels(void);
                void loadNextFloorModels(void);

                int getUndestructibleCount(void);
        };

    };

};
