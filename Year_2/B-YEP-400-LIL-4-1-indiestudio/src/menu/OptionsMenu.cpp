/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** OptionsMenu.cpp
*/
// #include "raylib.h"
#include "OptionsMenu.hpp"
#include "ControlOptions.hpp"
#include "MainMenu.hpp"
#include "VolumeOptions.hpp"

bomberman::menu::OptionsMenu *bomberman::menu::OptionsMenu::_optionsMenuInstance {nullptr};
std::mutex bomberman::menu::OptionsMenu::_mutex;

void bomberman::menu::OptionsMenu::init(bomberman::core::GameEngine *engine)
{
    std::cout << "Initializing options menu..." << std::endl;
    _background = LoadModel("assets/models/menu/menu.obj");
    _backgroundPos = { 0.0f, 0.0f, 0.0f };
    _camera.setPosition(0.0f, 40.0f, 1.0f);
    _camera.setTarget(0.0f, 0.0f, 0.0f);
    _camera.setUp(0.0f, 1.0f, 0.0f);
    initButtons(engine);
    initAssets(engine);
    std::cout << "Options menu initialized." << std::endl;
}

void bomberman::menu::OptionsMenu::initAssets(bomberman::core::GameEngine *engine)
{
    _image = bomberman::objects::Image("assets/img/plank.png",
    { (float)(engine->options.getWindowWidth() / 2), 100.0f }, 0.4f);
    _image.setText(_image.getWidth() / 2.0f, _image.getHeight() / 3.0f, "Options", 50.0f, WHITE);
}

void bomberman::menu::OptionsMenu::initButtons(bomberman::core::GameEngine *engine)
{
    _buttons.push_back(bomberman::objects::TextButton("Control",
    { (float)engine->options.getWindowWidth() / 2, (float)(engine->options.getWindowHeight() / 3) },
    50.0f, [](bomberman::core::GameEngine *engine){ engine->changeState(bomberman::menu::ControlOptions::getInstance()); }));
    _buttons.push_back(bomberman::objects::TextButton("Volume",
    { (float)engine->options.getWindowWidth() / 2, (float)(engine->options.getWindowHeight() / 2) },
    50.0f, [](bomberman::core::GameEngine *engine){ engine->changeState(bomberman::menu::VolumeOptions::getInstance()); }));
    _backBtn.push_back(bomberman::objects::Button("assets/buttons/back.png",
    { 100.0f, (float)(engine->options.getWindowHeight() - 100.0f) },
    0.2f, [](bomberman::core::GameEngine *engine){ engine->changeState(bomberman::menu::MainMenu::getInstance()); }));
}

void bomberman::menu::OptionsMenu::cleanup()
{
    std::cout << "Cleaning options menu..." << std::endl;
    UnloadModel(_background);
    _optionsMenuInstance = nullptr;
    std::cout << "Options menu cleanup." << std::endl;
}

void bomberman::menu::OptionsMenu::pause()
{
}

void bomberman::menu::OptionsMenu::resume()
{
}

void bomberman::menu::OptionsMenu::processInput(bomberman::core::GameEngine *engine)
{
    (void)engine;
}

void bomberman::menu::OptionsMenu::update(bomberman::core::GameEngine *engine,
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
    for (size_t i = 0; i < _backBtn.size(); i++) {
        if (CheckCollisionPointRec(engine->getMouseCoordinates(), _backBtn[i].getBounds())) {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                _backBtn[i].press();
            else
                _backBtn[i].hover(engine->options.music.isSoundActive(), engine);
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
                _backBtn[i].click(engine->options.music.isSoundActive(), engine);
        } else
            _backBtn[i].released();
    }
    (void)deltaTime;
}

void bomberman::menu::OptionsMenu::render(bomberman::core::GameEngine *engine)
{
    BeginDrawing();
        ClearBackground({ 85, 97, 67, 1 });
        BeginMode3D(*_camera.getCamera());
            DrawModel(_background, _backgroundPos, 1.0f, WHITE);
        EndMode3D();
        _image.draw();
        for (size_t i = 0; i < _buttons.size(); i++)
            _buttons[i].draw();
        for (size_t i = 0; i < _backBtn.size(); i++)
            _backBtn[i].draw();
        engine->drawCursor();
    EndDrawing();
}
