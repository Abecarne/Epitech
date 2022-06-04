/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** Entities.hpp
*/
#pragma once

#include "raylib.h"

namespace bomberman {
    namespace entities {
        class CameraCustom {
            private:
                Camera3D _camera;
                float _moveSpeed;

            public:
                CameraCustom();

                Camera3D *getCamera();
                Vector3 getPosition();
                Vector3 getTarget();
                Vector3 getUp();
                float getFovy();
                float getMoveSpeed();

                void setPosition(float x, float y, float z);
                void setTarget(float x, float y, float z);
                void setUp(float x, float y, float z);
                void setFovy(float fovy);
                void setMoveSpeed(float moveSpeed);
        };
    }
}