/*
** EPITECH PROJECT, 2022
** Pikmins
** File description:
** Bots.hpp
*/

#pragma once

namespace bomberman {
    namespace game {
        class Game;
    };
};

#include "ACharacters.hpp"

namespace bomberman
{
    namespace entities
    {
        enum BotDifficulty {
            EASY    =   0,
            MEDIUM  =   1,
            HARD    =   2
        };

        enum CollisionType {
            NONE    =   0,
            WALL    =   1,
            LBOX    =   2
        };

        class Bots : public bomberman::entities::ACharacters
        {
            public:
                Bots(bomberman::entities::ACharacters::playerNum playerNum, std::string typeModel = MODEL_RED_LEAF_PIKMIN, std::string skinModel = SKIN_DEFAULT, bomberman::entities::ACharacters::characterColors skinColor = bomberman::entities::ACharacters::characterColors::DEFAULT, std::string animationModel = ANIMATION_PIKMIN_DEFAULT, Vector3 pos = {0.0f, 0.0f, 0.0f}, BotDifficulty difficulty = bomberman::entities::EASY);
                ~Bots();

                void move(bomberman::core::Time deltaTime, int action = 0);

            private:
                BotDifficulty _difficulty;
                std::shared_ptr<bomberman::entities::ACharacters> _targetedEntity;
                Vector3 _targetedPos;
                Vector3 _basePos;
                vectorOfStaticModels _baseSafePos;
                bool _hasPlacedBomb;
                float _hasPlacedBombTimer;

                int getRandomDir(void);
                void newDir(int nexMove, std::vector<Vector4> possibleDirs, bomberman::core::Time deltaTime);
                void move_up(std::vector<Vector4> possibleDirs);
                void move_down(std::vector<Vector4> possibleDirs);
                void move_left(std::vector<Vector4> possibleDirs);
                void move_right(std::vector<Vector4> possibleDirs);

                void easyAI(std::vector<Vector4> possibleDirs, bomberman::core::Time deltaTime);

                void mediumIA(std::vector<Vector4> possibleDirs);
                void moveTo(std::vector<Vector4> possibleDirs);
                vectorOfStaticModels getSafePos(void);
                CollisionType handleCollisionWithMap(Vector3 newPos);
        };
    };
};
