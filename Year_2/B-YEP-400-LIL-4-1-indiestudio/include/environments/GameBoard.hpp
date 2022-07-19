/*
** EPITECH PROJECT, 2022
** Pikmins
** File description:
** BoardGame.hpp
*/
#pragma once

#include "StaticModels.hpp"
#include "ACharacters.hpp"
#include "LootBox.hpp"

#include <memory>
#include <vector>
#include <map>

// Destructible Mesh

#define LOOTING_BOX "./assets/models/boardgame/desctructible/lootingBox.glb"
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

                Vector3 getPosition(void);
                Vector3 getBlockSize(void);
                float getScale(void);
                int getWidth(void);
                int getHeight(void);

                std::vector<std::shared_ptr<bomberman::models::StaticModels>> getWallModels(void);
                std::vector<std::shared_ptr<bomberman::models::StaticModels>> getFloorModels(void);
                std::vector<std::shared_ptr<bomberman::models::StaticModels>> getInvisibleBlock(void);
                std::vector<std::shared_ptr<bomberman::entities::LootBox>> &getLootBoxes(void);
                Vector3 getInvisibleBlockPosAtEntity(std::shared_ptr<bomberman::entities::ACharacters> entity);
                Vector3 getInvisibleBlockPosAtEntity(bomberman::entities::ACharacters *entity);


            private:
                enum gameboardState {
                    FLOOR,
                    UNDESTRUCTIBLE,
                    DESTRUCTIBLE,
                    INVISIBLE_BOX
                };

                bomberman::environment::GameBoard::gameboardState _state;
                std::vector<std::shared_ptr<bomberman::entities::LootBox>> _lootingBox;
                std::vector<std::shared_ptr<bomberman::models::StaticModels>> _wallsModels;
                std::vector<std::shared_ptr<bomberman::models::StaticModels>> _invisibleBox;
                std::vector<std::shared_ptr<bomberman::models::StaticModels>> _floorModels;
                size_t _width;
                size_t _height;
                float _scale;
                Vector3 _size;
                Vector3 _position;
                bool _isFinish;

                std::string _destructibleBox;
                std::string _undestructibleBox;
                std::string _floor;

                size_t _modelsCount;

                std::shared_ptr<bomberman::models::StaticModels> createStaticModel(std::string Mesh, Vector3 position);
                std::shared_ptr<bomberman::models::StaticModels> createStaticModel(Vector3 position);

                void initFloorMesh(size_t width, size_t heigth, std::string floorMesh);
                void initDestructibleMesh(size_t width, size_t heigth, std::string destructibleMesh);
                void initUndestructibleMesh(size_t width, size_t heigth, std::string undestructibleMesh);

                void loadNextUndestructibleModels(void);
                void loadNextFloorModels(void);
                void loadDestructibleBox(void);

                int getUndestructibleCount(void);

                int getDestructibleCount(void);
                bool isPlayerPosition(int width, int height);

                bool isCorrectPos(Vector3 pos);
                void loadInvisibleBox(void);

                void createLootBox(std::string mesh, Vector3 position);
        };

    };

};
