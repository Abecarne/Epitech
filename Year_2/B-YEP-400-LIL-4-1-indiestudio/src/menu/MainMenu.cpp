/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** MainMenu.cpp
*/
// #include "raylib.h"
#include "MainMenu.hpp"
#include "LoadingScreen.hpp"
#include "SelectGame.hpp"
#include "OptionsMenu.hpp"
#include <iostream>

bomberman::menu::MainMenu *bomberman::menu::MainMenu::_mainMenuInstance {nullptr};
std::mutex bomberman::menu::MainMenu::_mutex;

void bomberman::menu::MainMenu::init(bomberman::core::GameEngine *engine)
{
    std::cout << "Initializing main menu..." << std::endl;
    _background = LoadModel("assets/models/menu/menu.obj");
    _backgroundPos = { 0.0f, 0.0f, 0.0f };
    _camera.setPosition(0.0f, 40.0f, 1.0f);
    _camera.setTarget(0.0f, 0.0f, 0.0f);
    _camera.setUp(0.0f, 1.0f, 0.0f);
    initButton(engine);
    std::cout << "Main menu initialized." << std::endl;
}

void bomberman::menu::MainMenu::initButton(bomberman::core::GameEngine *engine)
{
    _buttons.push_back(bomberman::objects::Button("assets/buttons/play.png",
    { (float)(engine->options.getWindowWidth() / 2.3), (float)(engine->options.getWindowHeight() / 1.5) },
    0.5f, [](bomberman::core::GameEngine *engine){ engine->changeState(bomberman::menu::SelectGame::getInstance()); }));
    _buttons.push_back(bomberman::objects::Button("assets/buttons/options.png",
    { (float)(engine->options.getWindowWidth() / 1.7), (float)(engine->options.getWindowHeight() / 1.5) },
    0.3f, [](bomberman::core::GameEngine *engine){ engine->changeState(bomberman::menu::OptionsMenu::getInstance()); }));
    _buttons.push_back(bomberman::objects::Button("assets/buttons/close.png",
    { (float)(engine->options.getWindowWidth() - 50.0f), 50.0f },
    0.15f, [](bomberman::core::GameEngine *engine){ engine->shouldClose(); }));
}

void bomberman::menu::MainMenu::cleanup()
{
    std::cout << "Cleaning main menu..." << std::endl;
    UnloadModel(_background);
    _mainMenuInstance = nullptr;
    std::cout << "Main menu cleanup." << std::endl;
}

void bomberman::menu::MainMenu::pause()
{
}

void bomberman::menu::MainMenu::resume()
{
}

void bomberman::menu::MainMenu::processInput(bomberman::core::GameEngine *engine)
{
    (void)engine;
}

void bomberman::menu::MainMenu::update(bomberman::core::GameEngine *engine,
bomberman::core::Time deltaTime)
{
    for (size_t i = 0; i < _buttons.size(); i++) {
        if (CheckCollisionPointRec(engine->getMouseCoordinates(), _buttons[i].getBounds())) {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                _buttons[i].press();
            else
                _buttons[i].hover(engine->options.music.isSoundActive(), engine);
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
                _buttons[i].click(engine->options.music.isSoundActive(), engine);
        } else
            _buttons[i].released();
    }
    (void)deltaTime;
}

void bomberman::menu::MainMenu::render(bomberman::core::GameEngine *engine)
{
    BeginDrawing();
        ClearBackground({ 85, 97, 67, 1 });
        BeginMode3D(*_camera.getCamera());
            DrawModel(_background, _backgroundPos, 1.0f, WHITE);
        EndMode3D();
        for (size_t i = 0; i < _buttons.size(); i++) {
            _buttons[i].draw();
        }
        engine->drawCursor();
    EndDrawing();
}
