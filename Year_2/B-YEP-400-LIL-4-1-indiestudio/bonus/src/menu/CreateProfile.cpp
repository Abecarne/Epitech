/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** MainMenu.cpp
*/
// #include "raylib.h"
#include "CreateProfile.hpp"
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>

bomberman::menu::CreateProfile *bomberman::menu::CreateProfile::_saveMenuInstance {nullptr};
std::mutex bomberman::menu::CreateProfile::_mutex;

void bomberman::menu::CreateProfile::init(bomberman::core::GameEngine *engine)
{
    std::cout << "Initializing create profile menu..." << std::endl;
    _background = LoadModel(BACKGROUNDMODEL);
    _backgroundPos = { 0.0f, 0.0f, 0.0f };
    _camera.setPosition(0.0f, 40.0f, 1.0f);
    _camera.setTarget(0.0f, 0.0f, 0.0f);
    _camera.setUp(0.0f, 1.0f, 0.0f);
    initAssets(engine);
    std::cout << "Create profile menu initialized." << std::endl;
}

void bomberman::menu::CreateProfile::initAssets(bomberman::core::GameEngine *engine)
{
    _images.push_back(bomberman::objects::Image("assets/img/plank.png",
    (Vector2){ (float)(engine->options.getWindowWidth() / 2), (float)(engine->options.getWindowHeight() / 2) },
    0.6f));
    _images[0].setText(_images[0].getWidth() / 2.0f, _images[0].getHeight() / 2.5f, "Entrer votre pseudo", 50.0f, WHITE);
}

void bomberman::menu::CreateProfile::cleanup()
{
    std::cout << "Cleaning create profile menu..." << std::endl;
    UnloadModel(_background);
    std::cout << "Create profile menu cleanup." << std::endl;
}

void bomberman::menu::CreateProfile::pause()
{
}

void bomberman::menu::CreateProfile::resume()
{
}

void bomberman::menu::CreateProfile::processInput(bomberman::core::GameEngine *engine)
{
    (void)engine;
    if (CheckCollisionPointRec(engine->getMouseCoordinates(), _images[0].getBounds()))
        _isOnText = true;
    else
        _isOnText = false;
    if (_isOnText) {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        _key = GetCharPressed();
        while (_key > 0) {
            if (_key >= 32 && _key <= 125 && _letterCount < 8) {
                pseudo[_letterCount] = (char)_key;
                pseudo[_letterCount + 1] = '\0';
                _letterCount++;
            }
            _key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE)) {
            _letterCount--;
            if (_letterCount < 0)
                _letterCount = 0;
            pseudo[_letterCount] = '\0';
        }
    } else
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
}

void bomberman::menu::CreateProfile::update(bomberman::core::GameEngine *engine,
bomberman::core::Time deltaTime)
{
    UpdateMusicStream(engine->options.music.getMusicStream());
}

void bomberman::menu::CreateProfile::render(bomberman::core::GameEngine *engine)
{
    (void)engine;
    BeginDrawing();
        ClearBackground((Color){ 85, 97, 67, 1 });
        BeginMode3D(*_camera.getCamera());
            DrawModel(_background, _backgroundPos, 1.0f, WHITE);
        EndMode3D();
        for (size_t i = 0; i < _images.size(); i++) {
            _images[i].draw();
        }
        DrawText(pseudo.c_str(), _images[0].getBounds().x, _images[0].getBounds().y, 40, MAROON);
    EndDrawing();
}
