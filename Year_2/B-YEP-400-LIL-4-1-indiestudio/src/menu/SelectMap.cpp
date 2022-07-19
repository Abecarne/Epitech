/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** SelectMap.cpp
*/
#include "SelectMap.hpp"
#include "MainMenu.hpp"
#include "LoadingScreen.hpp"
#include <cctype>

bomberman::menu::SelectMap *bomberman::menu::SelectMap::_selectMapInstance {nullptr};
std::mutex bomberman::menu::SelectMap::_mutex;

void bomberman::menu::SelectMap::init(bomberman::core::GameEngine *engine)
{
    std::cout << "Initializing select map menu..." << std::endl;
    _background = LoadModel(BACKGROUNDMODEL);
    _backgroundPos = { 0.0f, 0.0f, 0.0f };
    _camera.setPosition(0.0f, 40.0f, 1.0f);
    _camera.setTarget(0.0f, 0.0f, 0.0f);
    _camera.setUp(0.0f, 1.0f, 0.0f);
    initAssets(engine);
    initButtons(engine);
    std::cout << "Select map initialized." << std::endl;
}

void bomberman::menu::SelectMap::initAssets(bomberman::core::GameEngine *engine)
{
    _images.push_back(bomberman::objects::Image("assets/img/plank.png",
    { engine->options.getWindowWidth() / 2.0f, 150.0f }, 0.4f));
    _images.back().setText(_images.back().getWidth() / 2.0f, _images.back().getHeight() / 2.0f - 25.0f,
    "Ballad", 50.0f, WHITE);
    _images.push_back(bomberman::objects::Image("assets/img/chinese.png",
    { engine->options.getWindowWidth() / 2.0f, engine->options.getWindowHeight() / 2.5f }, 0.3f));
    _images.back().setText(_images.back().getWidth() / 2.0f, _images.back().getHeight() / 1.8f - 25.0f,
    "", 50.0f, WHITE);
    _images.push_back(bomberman::objects::Image("assets/img/picnic.png",
    { engine->options.getWindowWidth() / 2.0f, engine->options.getWindowHeight() / 2.5f }, 0.3f));
    _images.back().setText(_images.back().getWidth() / 2.0f, _images.back().getHeight() / 1.8f - 25.0f,
    "", 50.0f, WHITE);
    _images.push_back(bomberman::objects::Image("assets/img/picnic_night.png",
    { engine->options.getWindowWidth() / 2.0f, engine->options.getWindowHeight() / 2.5f }, 0.3f));
    _images.back().setText(_images.back().getWidth() / 2.0f, _images.back().getHeight() / 1.8f - 25.0f,
    "", 50.0f, WHITE);
    _images.push_back(bomberman::objects::Image("assets/img/plank.png",
    { engine->options.getWindowWidth() / 2.0f, engine->options.getWindowHeight() / 1.5f }, 0.4f));
    _images.back().setText(_images.back().getWidth() / 2.0f, _images.back().getHeight() / 2.0f - 25.0f,
    "Day", 50.0f, WHITE);
}

void changeMap(std::string selectedMap, bomberman::core::GameEngine *engine)
{
}

void bomberman::menu::SelectMap::initButtons(bomberman::core::GameEngine *engine)
{
    _textButtons.push_back(bomberman::objects::TextButton("Launch Game",
    { (float)engine->options.getWindowWidth() / 2, (float)(engine->options.getWindowHeight() / 1.2) },
    50.0f, [](bomberman::core::GameEngine *engine){ engine->changeState(bomberman::menu::LoadingScreen::getInstance()); }));
    _buttons.push_back(bomberman::objects::Button("assets/buttons/back.png",
    { 100.0f, (float)(engine->options.getWindowHeight() - 100.0f) },
    0.2f, [](bomberman::core::GameEngine *engine){ engine->changeState(bomberman::menu::MainMenu::getInstance()); }));
    _buttons.push_back(bomberman::objects::Button("assets/buttons/leafButtonRight.png",
    { engine->options.getWindowWidth() / 2.0f + _images[0].getWidth() / 1.5f, 150.0f },
    0.2f, [](bomberman::core::GameEngine *engine){ engine->options.changeMap(); }));
    _buttons.push_back(bomberman::objects::Button("assets/buttons/leafButtonLeft.png",
    { engine->options.getWindowWidth() / 2.0f - _images[0].getWidth() / 1.5f, 150.0f },
    0.2f, [](bomberman::core::GameEngine *engine){ engine->options.changeMap(); }));
    _buttons.push_back(bomberman::objects::Button("assets/buttons/leafButtonRight.png",
    { engine->options.getWindowWidth() / 2.0f + _images[0].getWidth() / 1.5f, engine->options.getWindowHeight() / 1.5f },
    0.2f, [](bomberman::core::GameEngine *engine){ engine->options.changeDayCycle(); }));
    _buttons.push_back(bomberman::objects::Button("assets/buttons/leafButtonLeft.png",
    { engine->options.getWindowWidth() / 2.0f - _images[0].getWidth() / 1.5f, engine->options.getWindowHeight() / 1.5f },
    0.2f, [](bomberman::core::GameEngine *engine){ engine->options.changeDayCycle(); }));
}

void bomberman::menu::SelectMap::cleanup()
{
    std::cout << "Cleaning select map menu..." << std::endl;
    UnloadModel(_background);
    _selectMapInstance = nullptr;
    std::cout << "Select map menu cleanup." << std::endl;
}

void bomberman::menu::SelectMap::pause()
{
}

void bomberman::menu::SelectMap::resume()
{
}

void bomberman::menu::SelectMap::processInput(bomberman::core::GameEngine *engine)
{
}

void bomberman::menu::SelectMap::update(bomberman::core::GameEngine *engine,
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
    for (size_t i = 0; i < _textButtons.size(); i++) {
        if (CheckCollisionPointRec(engine->getMouseCoordinates(), _textButtons[i].getBounds())) {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                _textButtons[i].press();
            else
                _textButtons[i].hover(engine->options.music.isSoundActive(), engine);
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
                _textButtons[i].click(engine->options.music.isSoundActive(), engine);
        } else
            _textButtons[i].released();
    }
    _images[0].changeText(engine->options.getMap(), 0);
    _images[4].changeText(engine->options.isNight() ? "Night" : "Day", 0);
    (void)engine;
}

void bomberman::menu::SelectMap::render(bomberman::core::GameEngine *engine)
{
    BeginDrawing();
        ClearBackground({ 85, 97, 67, 1 });
        BeginMode3D(*_camera.getCamera());
            DrawModel(_background, _backgroundPos, 1.0f, WHITE);
        EndMode3D();
        for (size_t i = 0; i < _buttons.size(); i++)
            _buttons[i].draw();
        for (size_t i = 0; i < _textButtons.size(); i++)
            _textButtons[i].draw();
        _images[0].draw();
        _images[4].draw();
        if (engine->options.getMap().compare("Ballad") == 0) {
            if (engine->options.isNight())
                _images[3].draw();
            else
                _images[2].draw();
        } else
            _images[1].draw();
        engine->drawCursor();
    EndDrawing();
}
