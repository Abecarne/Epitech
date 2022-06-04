/*
** EPITECH PROJECT, 2022
** Pikmins
** File description:
** Characters.hpp
*/
#pragma once

#include "ICharacters.hpp"
#include "Errors.hpp"

#include <raylib.h>
#include <raymath.h>

#include <string>
#include <vector>
#include <map>
#include <iostream>

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

namespace bomberman {

    namespace entities {

        class ACharacters : public ICharacters {
            public:
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
                    DEATH,
                    BOMB
                } actions;

                virtual void updateCharacter(void) = 0;
                void renderCharacter(void);
                void reloadCharacter(std::string typeModel, std::string skinModel, bomberman::entities::ACharacters::characterColors skinColor, std::string animation);

                void moveCharacter(Vector3 newPosition, float rotationAngle);

                bool isCollision(Vector3 objectPos, Vector3 objectSize, Vector3 objectScale);
                Vector3 getCharacterPos(void);

                void setCharacterAction(bomberman::entities::ACharacters::actions action);
                bomberman::entities::ACharacters::actions getCharacterAction(void);

                float getCharacterRotation(void);
            protected:
                Model _characterModel;
                Vector3 _characterPos;
                Vector3 _characterSize;
                Vector3 _rotationAxis;
                float _rotationAngle;

                ModelAnimation *_animations;
                int _animFrameCounter;
                unsigned int _animCount;

                bomberman::entities::ACharacters::actions _characterActions;

                std::string getChoosenModel(std::string typeModel, std::string skinModel);
                std::string getChoosenSkin(std::string typeModel, std::string skinModel, bomberman::entities::ACharacters::characterColors skinColor);
                void initCharacterMesh(std::string typeModel, std::string skinModel, bomberman::entities::ACharacters::characterColors skinColor);
                void initCharacterAnimations(std::string animation);
                void unloadCharacter(void);
        };

    };

};