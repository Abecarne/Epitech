/*
** EPITECH PROJECT, 2022
** Pikmins
** File description:
** Bombs.hpp
*/
#pragma once

#include <raylib.h>
#include <memory>

#include "Time.hpp"

namespace bomberman {

    namespace entities {
    
        namespace powerup {
            
            typedef enum PUType {
                NOTHING,
                BOMBUP,
                SPEEDUP,
                WALLPASSUP,
                FIREUP,
            } PowerUpType;

            class APowerup {
                public:
                    virtual void render(void) = 0;
                    virtual PowerUpType getPowerUpType(void) = 0;
                    // virtual void applyBonus(PowerUpType type) = 0;
                    virtual void updatePU(bomberman::core::Time deltaTime) = 0;
                    virtual Vector3 getPosition(void) = 0;

                protected:
                    Model _model;
                    ModelAnimation* _animations;
                    unsigned int _animCount;
                    int _animFrameCounter;
                    float _animationTime;
                    Vector3 _position;
                    Vector3 _rotationAxis;
                    float _rotationAngle;
                    PowerUpType _type;
            };

        }; // namespace powerup
    };  // namespace entities
}; // namespace bomberman
