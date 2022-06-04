/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** MainMenu.cpp
*/
// #include "raylib.h"
#include "CreateProfile.hpp"
#include "SaveMenu.hpp"
#include "MainMenu.hpp"
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>

bomberman::menu::CreateProfile *bomberman::menu::CreateProfile::_createMenuInstance {nullptr};
std::mutex bomberman::menu::CreateProfile::_mutex;

void bomberman::menu::CreateProfile::init(bomberman::core::GameEngine *engine)
{
    std::cout << "Initializing create profile menu..." << std::endl;
    _background = LoadModel(BACKGROUNDMODEL);
    _backgroundPos = { 0.0f, 0.0f, 0.0f };
    _camera.setPosition(0.0f, 40.0f, 1.0f);
    _camera.setTarget(0.0f, 0.0f, 0.0f);
    _camera.setUp(0.0f, 1.0f, 0.0f);
    _letterCount = 0;
    _isOnText = false;
    initAssets(engine);
    initButtons(engine);
    std::cout << "Create profile menu initialized." << std::endl;
}

void bomberman::menu::CreateProfile::initButtons(bomberman::core::GameEngine *engine)
{
    _buttons.push_back(bomberman::objects::Button("assets/buttons/back.png",
    (Vector2){ 100.0f, (float)(engine->options.getWindowHeight() - 100.0f) },
    0.2f, [](bomberman::core::GameEngine *engine){ engine->changeState(bomberman::menu::SaveMenu::getInstance()); }));
}

void bomberman::menu::CreateProfile::initAssets(bomberman::core::GameEngine *engine)
{
    _image = bomberman::objects::Image("assets/img/plank.png",
    (Vector2){ (float)(engine->options.getWindowWidth() / 2), (float)(engine->options.getWindowHeight() / 2) },
    0.6f);
    _image.setText(_image.getWidth() / 2.0f, _image.getHeight() / 2.5f, "Entrer votre pseudo", 50.0f, WHITE);
}

void bomberman::menu::CreateProfile::cleanup()
{
    std::cout << "Cleaning create profile menu..." << std::endl;
    UnloadModel(_background);
    _createMenuInstance = nullptr;
    std::cout << "Create profile menu cleanup." << std::endl;
}

void bomberman::menu::CreateProfile::pause()
{
}

void bomberman::menu::CreateProfile::resume()
{
}

void handleButtons(std::vector<bomberman::objects::Button> *buttons,
bomberman::core::GameEngine *engine)
{
    for (size_t i = 0; i < buttons->size(); i++) {
        if (CheckCollisionPointRec(engine->getMouseCoordinates(), (*buttons)[i].getBounds())) {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                (*buttons)[i].press();
            else
                (*buttons)[i].hover(engine->options.music.isSoundActive());
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
                (*buttons)[i].click(engine->options.music.isSoundActive(), engine);
        } else
            (*buttons)[i].released();
    }
}

void bomberman::menu::CreateProfile::processInput(bomberman::core::GameEngine *engine)
{
    handleButtons(&_buttons, engine);
    if (GetKeyPressed() == KEY_ENTER)
        engine->changeState(MainMenu::getInstance());
    if (CheckCollisionPointRec(engine->getMouseCoordinates(), _image.getBounds()))
        _isOnText = true;
    else
        _isOnText = false;
    if (_isOnText) {
        SetMouseCursor(MOUSE_CURSOR_IBEAM);
        _key = GetCharPressed();
        std::cout << (char)_key << std::endl;
        while (_key > 0) {
            if (_key >= 32 && _key <= 125 && _letterCount < 8) {
                pseudo.insert(_letterCount, 1, (char(_key)));
                pseudo.insert(_letterCount + 1, 1, '\0');
                _letterCount++;
            }
            _image.changeText(pseudo, 0);
            _key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE)) {
            _letterCount--;
            if (_letterCount < 0)
                _letterCount = 0;
            pseudo.insert(_letterCount, 1, '\0');
            _image.changeText(pseudo, 0);
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
        _image.draw();
        for (size_t i = 0; i < _buttons.size(); i++)
            _buttons[i].draw();
    EndDrawing();
}
