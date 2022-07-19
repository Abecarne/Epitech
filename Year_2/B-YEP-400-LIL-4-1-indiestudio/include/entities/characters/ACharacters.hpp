/*
** EPITECH PROJECT, 2022
** Pikmins
** File description:
** Characters.hpp
*/

#pragma once

namespace bomberman {
    namespace game {
        class GameAssets;
        class Game;
    };

    namespace core {
        class GameEngine;
    };

    namespace entities {
        class Bombs;
        class Blast;
    };
};

#include "ICharacters.hpp"
#include "CharacterStats.hpp"
#include "APowerUp.hpp"
#include "StaticModels.hpp"
#include "Errors.hpp"
#include "Time.hpp"

#include <raylib.h>
#include <raymath.h>

#include <string>
#include <memory>
#include <vector>
#include <map>
#include <iostream>

#define PLAYER_VELOCITY 0.5f

#define PLAYER_DEATH_SOUND "./assets/music/pikminDeathSounds.mp3"
#define PLAYER_BONUS_SOUND "./assets/music/PickUp.mp3"

// Define folders path to find models and others assets

#define CHARACTERS_FOLDERS "./assets/models/entities/players/"

// Define all types of models

#define MODEL_RED_LEAF_PIKMIN "red"
#define MODEL_YELLOW_LEAF_PIKMIN "yellow"
#define MODEL_BLUE_LEAF_PIKMIN "blue"
#define MODEL_WHITE_LEAF_PIKMIN "white"
#define MODEL_PURPLE_LEAF_PIKMIN "purple"

#define MODEL_GRAY_LEAF_PIKMIN "gray"
#define MODEL_PINK_LEAF_PIKMIN "flying"

// Define all differents skins for models

#define SKIN_DEFAULT "default"
#define SKIN_KATANA "katana"
#define SKIN_BEACH "beach"

// Define all animations for differents models

#define ANIMATION_PIKMIN_DEFAULT "animation_pikmin_default"
#define ANIMATION_PIKMIN_FLYING_DEFAULT "animation_pikmin_flying"
#define ANIMATION_PIKMIN_GRAY_DEFAULT "animation_pikmin_gray"

#define ANIMATION_PIKMIN_KATANA "animation_pikmin_katana"

// Typedefs
typedef std::vector<std::shared_ptr<bomberman::models::StaticModels>> vectorOfStaticModels;

namespace bomberman {

    namespace entities {

        class ACharacters : public ICharacters {
            public:
                typedef enum playerNum {
                    PLAYER1,
                    PLAYER2,
                    PLAYER3,
                    PLAYER4
                } playerNum;

                typedef enum characterColors {
                    DEFAULT,
                    COLOR1,
                    COLOR2,
                    COLOR3,
                    COLOR4,
                    COLOR5,
                    COLOR6,
                    SPECIAL1,
                    SPECIAL2,
                    SPECIAL3
                } characterColors;

                typedef enum actions {
                    IDLE,
                    RUN,
                    BEFORE_DEATH,
                    BOMB,
                    AFTER_DEATH
                } actions;

                void updateCharacter(void);
                void renderCharacter(void);
                void reloadCharacter(std::string typeModel, std::string skinModel, bomberman::entities::ACharacters::characterColors skinColor, std::string animation);

                void moveCharacter(Vector3 newPosition, float rotationAngle);
                void moveCharacter(Vector3 newPosition);

                Vector3 getCharacterPos(void);
                bool isCollision(Vector3 objectPos, Vector3 objectSize, Vector3 objectScale);
                void applyGravity(vectorOfStaticModels undestructibleBlocks);

                void setCharacterAction(bomberman::entities::ACharacters::actions action);
                bomberman::entities::ACharacters::actions getCharacterAction(void);

                Vector3 getCharacterRotation(void);
                void setCharacterRotation(float rotation);

                std::shared_ptr<bomberman::entities::CharacterStats> getCharacterStats(void);
                playerNum getPlayerNum(void);

                bool canPlaceBomb(void);
                void placeBomb(void);
                void checkBombsDamage(std::vector<std::shared_ptr<bomberman::entities::Bombs>> allBombs);
                bool checkCollisionWithMap(Vector4 newDir);

                bool checkPowerUpEffect(std::shared_ptr<bomberman::entities::powerup::APowerup> powerUp);

                void applyPowerUp(powerup::PowerUpType powerUp);
                virtual void move(bomberman::core::Time deltaTime, int action) = 0;

            protected:
                Model _characterModel;
                Vector3 _characterPos;
                Vector3 _characterSize;
                Vector3 _rotationAxis;
                float _rotationAngle;
                bomberman::entities::ACharacters::playerNum _playerNum;

                bomberman::core::GameEngine *_engine;

                ModelAnimation *_animations;
                int _animFrameCounter;
                unsigned int _animCount;

                Sound _deathSound;
                Sound _bonusSound;

                bomberman::entities::ACharacters::actions _characterActions;
                std::shared_ptr<bomberman::entities::CharacterStats> _stats;

                bomberman::game::GameAssets *gameAssetsInstance;
                bomberman::game::Game *gameSceneInstance;

                ACharacters();

                std::string getChoosenModel(std::string typeModel, std::string skinModel);
                std::string getChoosenSkin(std::string typeModel, std::string skinModel, bomberman::entities::ACharacters::characterColors skinColor);
                void initCharacterMesh(std::string typeModel, std::string skinModel, bomberman::entities::ACharacters::characterColors skinColor);
                void initCharacterAnimations(std::string animation);
                void unloadCharacter(void);

        };

    };

};