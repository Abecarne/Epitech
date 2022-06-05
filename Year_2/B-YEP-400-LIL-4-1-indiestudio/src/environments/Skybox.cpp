/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** Skybox.cpp
*/

#include "Skybox.hpp"

bomberman::environment::Skybox::Skybox(void)
{
    // Nothing
}

bomberman::environment::Skybox::~Skybox(void)
{
    UnloadShader(this->_skybox.materials[0].shader);
    UnloadTexture(this->_skybox.materials[0].maps[MATERIAL_MAP_CUBEMAP].texture);
}

void bomberman::environment::Skybox::init(bomberman::environment::Skybox::day_cycle state)
{
    Mesh cube = GenMeshCube(1.0f, 1.0f, 1.0f);

    this->_state = state;
    this->_skybox = LoadModelFromMesh(cube);
    this->loadSkyboxShaders();
}

void bomberman::environment::Skybox::loadSkyboxShaders(void)
{
    Shader cubeMapShade = LoadShader(CUBEMAP_VS, CUBEMAP_FS);
    this->_skybox.materials[0].shader = LoadShader(SKYBOX_VS, SKYBOX_FS);
    int arraySave[1] = {0};

    SetShaderValue(cubeMapShade, GetShaderLocation(cubeMapShade, "equirectangularMap"), arraySave, SHADER_UNIFORM_INT);
    arraySave[0] = MATERIAL_MAP_CUBEMAP;
    SetShaderValue(this->_skybox.materials[0].shader, GetShaderLocation(this->_skybox.materials[0].shader, "environmentMap"), arraySave, SHADER_UNIFORM_INT);
    arraySave[0] = 0;
    SetShaderValue(this->_skybox.materials[0].shader, GetShaderLocation(this->_skybox.materials[0].shader, "doGamma"), arraySave, SHADER_UNIFORM_INT);
    SetShaderValue(this->_skybox.materials[0].shader, GetShaderLocation(this->_skybox.materials[0].shader, "vflipped"), arraySave, SHADER_UNIFORM_INT);
    this->applyShaderToTexture();
}

void bomberman::environment::Skybox::applyShaderToTexture(void)
{
    Image skyImg;

    if (this->_state == DAY)
        skyImg = LoadImage(DAY_SKY);
    else
        skyImg = LoadImage(NIGHT_SKY);
    this->_skybox.materials[0].maps[MATERIAL_MAP_CUBEMAP].texture = LoadTextureCubemap(skyImg, CUBEMAP_LAYOUT_AUTO_DETECT);
    UnloadImage(skyImg);
}

void bomberman::environment::Skybox::drawSkybox(void)
{
    rlDisableBackfaceCulling();
    rlDisableDepthMask();
    DrawModel(this->_skybox, (Vector3){0, 0, 0}, 1.0f, WHITE);
    rlEnableBackfaceCulling();
    rlEnableDepthMask();
}