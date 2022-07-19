/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** ControlOptions.cpp
*/
// #include "raylib.h"
#include "ControlOptions.hpp"
#include "OptionsMenu.hpp"
#include "Options.hpp"
#include <cctype>
#include <cmath>

bomberman::menu::ControlOptions *bomberman::menu::ControlOptions::_controlOptionsInstance {nullptr};
std::mutex bomberman::menu::ControlOptions::_mutex;

void bomberman::menu::ControlOptions::init(bomberman::core::GameEngine *engine)
{
    std::cout << "Initializing control options menu..." << std::endl;
    _background = LoadModel(BACKGROUNDMODEL);
    _backgroundPos = { 0.0f, 0.0f, 0.0f };
    _camera.setPosition(0.0f, 40.0f, 1.0f);
    _camera.setTarget(0.0f, 0.0f, 0.0f);
    _camera.setUp(0.0f, 1.0f, 0.0f);
    initAssets(engine);
    initTexts(engine);
    initButtons(engine);
    std::cout << "Control options initialized." << std::endl;
}

void bomberman::menu::ControlOptions::initButtons(bomberman::core::GameEngine *engine)
{
    std::vector<std::map<bomberman::settings::Actions, KeyboardKey>> allKeys = engine->options.getActions();

    std::vector<buttons_t> keys = {
        {engine->options._keyToString[allKeys[0][bomberman::settings::FORWARD]], {500.0f, 400.0f}, bomberman::settings::FORWARD},
        {engine->options._keyToString[allKeys[0][bomberman::settings::BACKWARD]], {500.0f, 500.0f}, bomberman::settings::BACKWARD},
        {engine->options._keyToString[allKeys[0][bomberman::settings::RIGHT]], {500.0f, 600.0f}, bomberman::settings::RIGHT},
        {engine->options._keyToString[allKeys[0][bomberman::settings::LEFT]], {500.0f, 700.0f}, bomberman::settings::LEFT},
        {engine->options._keyToString[allKeys[0][bomberman::settings::BOMB]], {500.0f, 800.0f}, bomberman::settings::BOMB},

        {engine->options._keyToString[allKeys[1][bomberman::settings::FORWARD]], {800.0f, 400.0f}, bomberman::settings::FORWARD},
        {engine->options._keyToString[allKeys[1][bomberman::settings::BACKWARD]], {800.0f, 500.0f}, bomberman::settings::BACKWARD},
        {engine->options._keyToString[allKeys[1][bomberman::settings::RIGHT]], {800.0f, 600.0f}, bomberman::settings::RIGHT},
        {engine->options._keyToString[allKeys[1][bomberman::settings::LEFT]], {800.0f, 700.0f}, bomberman::settings::LEFT},
        {engine->options._keyToString[allKeys[1][bomberman::settings::BOMB]], {800.0f, 800.0f}, bomberman::settings::BOMB},

        {engine->options._keyToString[allKeys[2][bomberman::settings::FORWARD]], {1100.0f, 400.0f}, bomberman::settings::FORWARD},
        {engine->options._keyToString[allKeys[2][bomberman::settings::BACKWARD]], {1100.0f, 500.0f}, bomberman::settings::BACKWARD},
        {engine->options._keyToString[allKeys[2][bomberman::settings::RIGHT]], {1100.0f, 600.0f}, bomberman::settings::RIGHT},
        {engine->options._keyToString[allKeys[2][bomberman::settings::LEFT]], {1100.0f, 700.0f}, bomberman::settings::LEFT},
        {engine->options._keyToString[allKeys[2][bomberman::settings::BOMB]], {1100.0f, 800.0f}, bomberman::settings::BOMB},

        {engine->options._keyToString[allKeys[3][bomberman::settings::FORWARD]], {1400.0f, 400.0f}, bomberman::settings::FORWARD},
        {engine->options._keyToString[allKeys[3][bomberman::settings::BACKWARD]], {1400.0f, 500.0f}, bomberman::settings::BACKWARD},
        {engine->options._keyToString[allKeys[3][bomberman::settings::RIGHT]], {1400.0f, 600.0f}, bomberman::settings::RIGHT},
        {engine->options._keyToString[allKeys[3][bomberman::settings::LEFT]], {1400.0f, 700.0f}, bomberman::settings::LEFT},
        {engine->options._keyToString[allKeys[3][bomberman::settings::BOMB]], {1400.0f, 800.0f}, bomberman::settings::BOMB}
    };

    _buttons.push_back(bomberman::objects::Button("assets/buttons/back.png",
    { 100.0f, (float)(engine->options.getWindowHeight() - 100.0f) },
    0.2f, [](bomberman::core::GameEngine *engine){ engine->changeState(bomberman::menu::OptionsMenu::getInstance()); }));
    for (auto &key : keys) {
        _buttons.push_back(bomberman::objects::Button("assets/buttons/touch.png", key.pos,
        0.2f, [](bomberman::core::GameEngine *){}));
        _buttons.back().setText(_buttons.back().getWidth() / 2, _buttons.back().getHeight() / 2 - 25.0f, key.input , 50.0f, DARKGRAY);
        _buttons.back().defineActions(key.action);
    }
}

void bomberman::menu::ControlOptions::initAssets(bomberman::core::GameEngine *engine)
{
    _image = bomberman::objects::Image("assets/img/plank.png",
    { (float)(engine->options.getWindowWidth() / 2), 100.0f }, 0.4f);
    _image.setText(_image.getWidth() / 2.0f, _image.getHeight() / 3.0f, "Controls", 50.0f, WHITE);
}

void bomberman::menu::ControlOptions::initTexts(bomberman::core::GameEngine *engine)
{
    _texts.push_back(bomberman::text::Text("Forward", { 200.0f, 400.0f }, 50.0f));
    _texts.push_back(bomberman::text::Text("Backward", { 200.0f, 500.0f }, 50.0f));
    _texts.push_back(bomberman::text::Text("Right", { 200.0f, 600.0f }, 50.0f));
    _texts.push_back(bomberman::text::Text("Left", { 200.0f, 700.0f }, 50.0f));
    _texts.push_back(bomberman::text::Text("Bomb", { 200.0f, 800.0f }, 50.0f));
    _texts.push_back(bomberman::text::Text("Player 1", { 500.0f, 250.0f }, 50.0f));
    _texts.push_back(bomberman::text::Text("Player 2", { 800.0f, 250.0f }, 50.0f));
    _texts.push_back(bomberman::text::Text("Player 3", { 1100.0f, 250.0f }, 50.0f));
    _texts.push_back(bomberman::text::Text("Player 4", { 1400.0f, 250.0f }, 50.0f));
}

void bomberman::menu::ControlOptions::cleanup()
{
    std::cout << "Cleaning control options menu..." << std::endl;
    UnloadModel(_background);
    _controlOptionsInstance = nullptr;
    std::cout << "Control options menu cleanup." << std::endl;
}

void bomberman::menu::ControlOptions::pause()
{
}

void bomberman::menu::ControlOptions::resume()
{
}

void handleButtonsOptions(std::vector<bomberman::objects::Button> *buttons,
bomberman::core::GameEngine *engine)
{
    for (size_t i = 0; i < buttons->size(); i++) {
        if (CheckCollisionPointRec(engine->getMouseCoordinates(), (*buttons)[i].getBounds())) {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                (*buttons)[i].press();
            else
                (*buttons)[i].hover(engine->options.music.isSoundActive(), engine);
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
                (*buttons)[i].click(engine->options.music.isSoundActive(), engine);
        } else
            (*buttons)[i].released();
    }
}

void bomberman::menu::ControlOptions::handleKeyMapping(bomberman::core::GameEngine *engine)
{
    int counter = 0;
    std::map<int, bomberman::settings::Actions> _indexToActions = {
        {0, bomberman::settings::FORWARD},
        {1, bomberman::settings::BACKWARD},
        {2, bomberman::settings::RIGHT},
        {3, bomberman::settings::LEFT},
        {4, bomberman::settings::BOMB},
    };

    for (auto &button : _buttons) {
        if (CheckCollisionPointRec(engine->getMouseCoordinates(), button.getBounds())) {
            _isOnText = true;
            break;
        } else {
            counter++;
            _isOnText = false;
        }
    }
    if (_isOnText) {
        SetMouseCursor(MOUSE_CURSOR_IBEAM);
        _key = GetCharPressed();
        if (_key >= 32 && _key <= 125) {
            _currentKey = std::toupper(char(_key));
            _buttons[counter].changeText(_currentKey);
            engine->options.setActions(_buttons[counter].getActions(), _currentKey, (int)((counter - 1) / 5) + 1);
            _currentKey.clear();
        }
    } else
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
}

void bomberman::menu::ControlOptions::processInput(bomberman::core::GameEngine *engine)
{
    handleButtonsOptions(&_buttons, engine);
    handleKeyMapping(engine);
}

void bomberman::menu::ControlOptions::update(bomberman::core::GameEngine *engine,
bomberman::core::Time deltaTime)
{
}

void bomberman::menu::ControlOptions::render(bomberman::core::GameEngine *engine)
{
    BeginDrawing();
        ClearBackground({ 85, 97, 67, 1 });
        BeginMode3D(*_camera.getCamera());
            DrawModel(_background, _backgroundPos, 1.0f, WHITE);
        EndMode3D();
        _image.draw();
        for (size_t i = 0; i < _buttons.size(); i++)
            _buttons[i].draw();
        for (size_t i = 0; i < _texts.size(); i++)
            _texts[i].drawText();
        engine->drawCursor();
    EndDrawing();
}
