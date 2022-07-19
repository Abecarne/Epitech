/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** LandingMenu.cpp
*/
#include "LandingMenu.hpp"
#include "MainMenu.hpp"
#include "PauseMenu.hpp"
#include "Time.hpp"
#include <iostream>
#include <cmath>

bomberman::menu::LandingMenu *bomberman::menu::LandingMenu::_landingMenuInstance {nullptr};
std::mutex bomberman::menu::LandingMenu::_mutex;

void bomberman::menu::LandingMenu::init(bomberman::core::GameEngine *engine)
{
    std::cout << "Initializing landing menu..." << std::endl;
    _background = LoadModel("assets/models/menu/menu.obj");
    _backgroundPos = { 0.0f, 0.0f, 0.0f };
    _camera.setPosition(0.0f, 350.0f, 1.0f);
    _camera.setTarget(0.0f, 0.0f, 0.0f);
    _camera.setUp(0.0f, 1.0f, 0.0f);
    _startedTime = GetTime();
    _isZoomEnded = false;
    _text = bomberman::text::Text(
        "Press any keys to start the game",
        { engine->options.getWindowWidth() / 2.0f, engine->options.getWindowHeight() / 1.5f },
        50.0f,
        { 255, 255, 255, 200 }
    );
    std::cout << "Landing menu initialized." << std::endl;
}

void bomberman::menu::LandingMenu::cleanup()
{
    std::cout << "Cleaning landing menu..." << std::endl;
    UnloadModel(_background);
    _landingMenuInstance = nullptr;
    std::cout << "Landing menu cleanup." << std::endl;
}

void bomberman::menu::LandingMenu::pause()
{
}

void bomberman::menu::LandingMenu::resume()
{
}

void bomberman::menu::LandingMenu::processInput(bomberman::core::GameEngine *engine)
{
    if (IsKeyPressed(GetKeyPressed()) && _isZoomEnded)
        engine->changeState(bomberman::menu::MainMenu::getInstance());
}

bool cameraZoom(bomberman::entities::CameraCustom &camera,
float startedTime, float deltaTime)
{
    float x = GetTime() - startedTime;
    float y = -1 * pow(x, 2) + 3.7 * x + 0.1;

    if (y > 0) {
        camera.setPosition(0.0f, camera.getPosition().y - y / 4, 1.0f);
        return false;
    } else
        return true;
    (void)deltaTime;
}

void bomberman::menu::LandingMenu::update(bomberman::core::GameEngine *engine,
bomberman::core::Time deltaTime)
{
    _isZoomEnded = cameraZoom(_camera, _startedTime, deltaTime);
}

void bomberman::menu::LandingMenu::render(bomberman::core::GameEngine *)
{
    BeginDrawing();
        ClearBackground({ 85, 97, 67, 1 });
        BeginMode3D(*_camera.getCamera());
            DrawModel(_background, _backgroundPos, 1.0f, WHITE);
        EndMode3D();
        if (_isZoomEnded)
            _text.drawText();
    EndDrawing();
}
