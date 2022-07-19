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

#define BLAST_MODELS "./assets/models/entities/blasts/fire.iqm"
#define BLAST_ANIMATIONS "./assets/models/entities/blasts/fire.iqm"

namespace bomberman
{
    namespace entities
    {
        struct BlastInfo {
            Vector3 _pos;
            int _distanceFromBomb;
        };

        class Blast {
            public:
                Blast(Texture2D texture, Vector3 position, int distanceFromBomb);
                ~Blast(void);

                void render(void);
                void update(void);

                Vector3 getPosition(void);

                int _distanceFromBomb;

            private:
                Model _model;
                Texture2D _texture;
                ModelAnimation *_animations;
                unsigned int _animCount;
                int _animFrameCounter;
                float _animationTime;

                Vector3 _size;
                Vector3 _rotationAxis;
                Vector3 _pos;
                BoundingBox _boundingBox;

                void initAnimations(void);
                void initModel(Texture2D texture);

                void updateAnimation(void);
                void createBlast(void);
        };

    };

};