/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** StaticModels.hpp
*/
#pragma once

#include <raylib.h>
#include <string>

#include "Errors.hpp"

namespace bomberman {

    namespace models {

        class StaticModels {
            private:
                Model _model;
                Color _color;
                bool _isMesh;

                Vector3 _modelPosition;
                Vector3 _modelSize;
                Vector3 _modelScale;
                Vector3 _rotationAxis;
                float _rotationAngle;

                void initModel(std::string modelFile);
                void initModel(Mesh mesh);
                void unloadModel(void);

            public:
                StaticModels(Mesh mesh, Color color, Vector3 position, Vector3 scale, Vector3 rotationAxis, float rotationAngle);
                StaticModels(std::string modelFile, Vector3 position, Vector3 scale, Vector3 rotationAxis, float rotationAngle);
                ~StaticModels(void);

                void renderModel(void);

                bool isCollision(Vector3 objectPos, Vector3 objectSize, Vector3 objectScale);

                Vector3 getPosition(void);
                Vector3 getSize(void);
                Vector3 getScale(void);
        };

    };

};