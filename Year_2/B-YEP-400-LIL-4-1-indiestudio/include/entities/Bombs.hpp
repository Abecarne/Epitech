/*
** EPITECH PROJECT, 2022
** Pikmins
** File description:
** Bombs.hpp
*/

#pragma once

#include "GameAssets.hpp"
#include "Blast.hpp"
#include "Vector3Utils.hpp"
#include "Errors.hpp"

#include <raylib.h>
#include <raymath.h>
#include <memory>
#include <vector>
#include <iostream>

#define BOMBS_MODELS "./assets/models/entities/bombs/bomb.iqm"
#define BOMBS_ANIMATIONS "./assets/models/entities/bombs/bomb.iqm"
#define BOMBS_TEXTURES "./assets/models/entities/bombs/textures/walnut.png"

namespace bomberman
{
    namespace entities
    {
        class Bombs {
            public:
                enum bombState {
                    WAITING,
                    EXPLODING,
                    END
                };

                Bombs(Vector3 initialposition, size_t explosionRadius);
                ~Bombs();

                bomberman::entities::Bombs::bombState getState(void);

                std::vector<std::shared_ptr<bomberman::entities::Blast>> getBlasts(void);

                void update(void);
                void render(void);

                size_t _renderBlastRadius;

            private:
                Model _model;
                ModelAnimation *_animations;
                unsigned int _animCount;
                int _animFrameCounter;
                float _animationTime;

                std::vector<std::shared_ptr<bomberman::entities::Blast>> _allBlasts;
                std::vector<bomberman::entities::BlastInfo> _allBlastsInfos;
                Texture2D _blastTexture;

                Vector3 _position;
                Vector3 _rotationAxis;
                float _rotationAngle;
                size_t _explosionRadius;
                std::vector<bool> _dirAvailable;

                bomberman::entities::Bombs::bombState _state;
                float _explodingTimer;
                float _renderBlastTimer;

                bomberman::game::GameAssets *gameAssetsInstance;

                void initAnimations(void);
                void initModel(std::shared_ptr<Texture2D> texture);

                void updateAnimation(void);

                std::vector<Vector3> getBlastPositionsForRadius(Vector3 blockSize, float blockScale);
                void createBlastsForRadius(void);

                Sound _explosionSound;


        };

    };

};