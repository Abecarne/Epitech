/*
** EPITECH PROJECT, 2022
** Pikmins
** File description:
** CharacterStats.hpp
*/
#pragma once

#include <raylib.h>
#include <string>
#include <vector>
#include <memory>

#include "LootBox.hpp"

namespace bomberman {

    namespace entities {

        class CharacterStats {
            private:
                size_t _life;

                bool _isWallPass;

                float _speed;
                float _speedBonus;

                size_t _playerBombRange;
                float _bombTimer;
                size_t _maxBombs;
                size_t _nbrBombs;

                float _wallPassTimer;

            public:
                CharacterStats();
                ~CharacterStats();

                void maxPlayerSpeedBonus(void);
                void maxPlayerBombRange(void);

                void addWallPassUp(void);
                void removeWallPassUp(void);
                bool getWallPassUp(void);
                void updateWallPass(bool inWall, std::vector<std::shared_ptr<bomberman::entities::LootBox>> Lootbox);

                void addPlayerLife(void);
                void removePlayerLife(void);
                size_t getPlayerLife(void);

                void addPlayerSpeedBonus(void);
                float getPlayerSpeedBonus(void);

                float getPlayerSpeed(void);

                size_t getPlayerBombRange(void);
                void addPlayerBombRange(void);
                void removePlayerBombRange(void);

                void removeBombNumber(void);
                void updateBombTimer(void);
                size_t getBombNumber(void);
                void upgradeBombNumber(void);
        };

    };

};