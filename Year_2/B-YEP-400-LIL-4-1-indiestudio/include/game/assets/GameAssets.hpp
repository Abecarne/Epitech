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
#include "Players.hpp"
#include "Bots.hpp"

#include <memory>
#include <vector>

namespace bomberman {

    namespace game {

        class GameAssets {
            private:
                static GameAssets *_instance;

                size_t _nbrPlayers;
                size_t _nbrBots;

                std::map<std::string, std::shared_ptr<Texture2D>> _loadedTexture;

                std::shared_ptr<bomberman::environment::Skybox> _skybox;
                std::shared_ptr<bomberman::environment::Map> _map;
                std::shared_ptr<bomberman::environment::GameBoard> _gameBoard;
                std::vector<std::shared_ptr<bomberman::entities::Players>> _players;
                std::vector<std::shared_ptr<bomberman::entities::Bots>> _bots;

            protected:
                GameAssets();

            public:
                GameAssets(GameAssets &) = delete;
                void operator=(GameAssets const &) = delete;
                static GameAssets *getInstance()
                {
                    if (_instance == nullptr) {
                        _instance = new GameAssets();
                    }
                    return _instance;
                }
                ~GameAssets();

                void initMap(std::string mapFolder);
                void initSkyBox(void);
                void initGameBoard(size_t width, size_t heigth, Vector3 pos, std::string floorMesh,
                std::string destructibleMesh, std::string undestructibleMesh);
                void initPlayer(bomberman::entities::ACharacters::playerNum playerNum, std::string typeModel, std::string skinModel, bomberman::entities::ACharacters::characterColors skinColor, std::string animationModel);
                void initBots(bomberman::entities::ACharacters::playerNum playerNum, std::string typeModel, std::string skinModel, bomberman::entities::ACharacters::characterColors skinColor, std::string animationModel, bomberman::entities::BotDifficulty difficulty);

                void initNewTexture(std::string textureName, std::string texturePath);
                std::map<std::string, std::shared_ptr<Texture2D>> getAllLoadedTextures(void);

                size_t getNbrPlayers(void);
                size_t getNbrBots(void);

                std::shared_ptr<bomberman::environment::Skybox> getSkyBox(void);
                std::shared_ptr<bomberman::environment::GameBoard> getGameBoard(void);
                std::shared_ptr<bomberman::environment::Map> getMap(void);
                std::vector<std::shared_ptr<bomberman::entities::Players>> getPlayers(void);
                std::vector<std::shared_ptr<bomberman::entities::Bots>> getBots(void);

                void cleanUp(void);
        };

    };

};