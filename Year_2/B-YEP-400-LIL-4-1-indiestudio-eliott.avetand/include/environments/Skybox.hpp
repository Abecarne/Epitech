/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** Skybox.hpp
*/

#pragma once

#include <raylib.h>
#include <rlgl.h>

#define CUBEMAP_VS "./assets/models/skybox/cubemap.vs"
#define CUBEMAP_FS "./assets/models/skybox/cubemap.fs"

#define SKYBOX_VS "./assets/models/skybox/skybox.vs"
#define SKYBOX_FS "./assets/models/skybox/skybox.fs"

#define DAY_SKY "./assets/models/skybox/textures/day_sky.png"
#define NIGHT_SKY "./assets/models/skybox/textures/night_sky.png"

namespace bomberman {

    namespace environment {

        class Skybox {
            public:
                typedef enum day_cycle {
                    DAY,
                    NIGHT
                } day_cycle;

                Skybox(void);
                ~Skybox(void);

                void init(bomberman::environment::Skybox::day_cycle state);
                void drawSkybox(void);
            private:
                Model _skybox;
                day_cycle _state;

                void loadSkyboxShaders(void);
                void applyShaderToTexture(void);
        };
    };
};