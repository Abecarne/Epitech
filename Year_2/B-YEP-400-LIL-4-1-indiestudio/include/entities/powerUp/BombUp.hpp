/*
** EPITECH PROJECT, 2022
** Pikmins
** File description:
** Bombs.hpp
*/
#pragma once

#include <raylib.h>
#include <vector>
#include <memory>
#include <raymath.h>

#include "Errors.hpp"
#include "APowerUp.hpp"
#include "GameEngine.hpp"

#define BOMBUP_MODELS "./assets/models/entities/powerups/BombUp.glb"

namespace bomberman {

    namespace entities {

        namespace powerup {

            class BombUp : public APowerup {
                public:
                    BombUp(Vector3 position);
                    ~BombUp();
                    void render(void) override;
                    Vector3 getPosition(void) override;
                    PowerUpType getPowerUpType(void) override;
                    // void applyBonus(PowerUpType type) override;
                    void updatePU(bomberman::core::Time deltaTime) override;

                private:
                    Model _model;
                    ModelAnimation* _animations;
                    unsigned int _animCount;
                    int _animFrameCounter;
                    float _animationTime;
                    Vector3 _position;
                    Vector3 _rotationAxis;
                    float _rotationAngle;
                    PowerUpType _type;

                    void initModel(void);
                    void updateAnimation(bomberman::core::Time deltaTime);
            };
        };
    };  // namespace entities
};