/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** AnimatedModels.hpp
*/
#pragma once

#include "Errors.hpp"

#include <raylib.h>

#include <string>

// Define Burrowing Models

#define MODEL_BURROWING "./assets/models/entities/decorations/burrowing/burrowing.iqm"
#define TEXTURE_BURROWING "./assets/models/entities/decorations/burrowing/textures/body_msk.png"
#define ANIMATION_BURROWING "./assets/models/entities/decorations/burrowing/burrowing.iqm"

namespace bomberman {

    namespace models {

        class AnimatedModels {
            public:
                typedef enum actions {
                    DEFAULT,
                    ACTION1,
                    ACTION2
                } actions;

                AnimatedModels(std::string modelFile, std::string animationFile, std::string textureFile, Vector3 position = (Vector3){0.0f, 0.0f, 0.0f}, Vector3 scale = (Vector3){1.0f, 1.0f, 1.0f}, Vector3 rotationAxis = (Vector3){1.0f, 1.0f, 1.0f}, float rotationAngle = -90);
                ~AnimatedModels(void);

                void updateModel(void);
                void renderModel(void);

                void setPosition(Vector3 postion);
                Vector3 getPosition(void);

                Vector3 getSize(void);
                Vector3 getScale(void);
            private:
                Model _model;

                Vector3 _modelSize;
                Vector3 _modelScale;
                Vector3 _modelPosition;
                Vector3 _rotationAxis;
                float _rotationAngle;
                float _startedTime;

                bomberman::models::AnimatedModels::actions _modelAction;
                ModelAnimation *_animations;
                int _animFrameCounter;
                unsigned int _animCount;

                void initModel(std::string modelFile, std::string textureFile);
                void initAnimation(std::string animationFile);
                void unloadModel(void);
        };

    };

};
