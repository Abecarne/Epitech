/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** SelectGame.cpp
*/
#include "SelectGame.hpp"
#include "SelectMap.hpp"
#include "MainMenu.hpp"
#include "LoadingScreen.hpp"
#include <cctype>

bomberman::menu::SelectGame *bomberman::menu::SelectGame::_selectGameInstance {nullptr};
std::mutex bomberman::menu::SelectGame::_mutex;

void bomberman::menu::SelectGame::init(bomberman::core::GameEngine *engine)
{
    std::cout << "Initializing select game menu..." << std::endl;
    _background = LoadModel(BACKGROUNDMODEL);
    _backgroundPos = { 0.0f, 0.0f, 0.0f };
    _camera.setPosition(0.0f, 40.0f, 1.0f);
    _camera.setTarget(0.0f, 0.0f, 0.0f);
    _camera.setUp(0.0f, 1.0f, 0.0f);
    initAssets(engine);
    initButtons(engine);
    std::cout << "Select game initialized." << std::endl;
}

void bomberman::menu::SelectGame::initAssets(bomberman::core::GameEngine *engine)
{
    _images.push_back(bomberman::objects::Image("assets/img/plank.png",
    { engine->options.getWindowWidth() / 2.0f, engine->options.getWindowHeight() / 1.7f }, 0.5f));
    _images.back().setText(_images.back().getWidth() / 2.0f, _images.back().getHeight() / 2.0f - 25.0f,
    "Players number: " + _nb_players, 50.0f, WHITE);
    _images.push_back(bomberman::objects::Image("assets/img/plank.png",
    { engine->options.getWindowWidth() / 2.0f, engine->options.getWindowHeight() / 3.0f }, 0.5f));
    _images.back().setText(_images.back().getWidth() / 2.0f, _images.back().getHeight() / 2.0f - 25.0f,
    "Difficulty mode: " + _difficulty, 50.0f, WHITE);
}

void bomberman::menu::SelectGame::initButtons(bomberman::core::GameEngine *engine)
{
    _textButtons.push_back(bomberman::objects::TextButton("Select map",
    { (float)engine->options.getWindowWidth() / 2, (float)(engine->options.getWindowHeight() / 1.2) },
    50.0f, [](bomberman::core::GameEngine *engine){ engine->changeState(bomberman::menu::SelectMap::getInstance()); }));
    _buttons.push_back(bomberman::objects::Button("assets/buttons/back.png",
    { 100.0f, (float)(engine->options.getWindowHeight() - 100.0f) },
    0.2f, [](bomberman::core::GameEngine *engine){ engine->changeState(bomberman::menu::MainMenu::getInstance()); }));
    _buttons.push_back(bomberman::objects::Button("assets/buttons/leafButtonRight.png",
    { engine->options.getWindowWidth() / 2.0f + _images[0].getWidth() / 1.5f, engine->options.getWindowHeight() / 1.7f },
    0.2f, [](bomberman::core::GameEngine *engine){ engine->options.increasePlayers(); }));
    _buttons.push_back(bomberman::objects::Button("assets/buttons/leafButtonLeft.png",
    { engine->options.getWindowWidth() / 2.0f - _images[0].getWidth() / 1.5f, engine->options.getWindowHeight() / 1.7f },
    0.2f, [](bomberman::core::GameEngine *engine){ engine->options.decreasePlayers(); }));
    _buttons.push_back(bomberman::objects::Button("assets/buttons/leafButtonRight.png",
    { engine->options.getWindowWidth() / 2.0f + _images[0].getWidth() / 1.5f, engine->options.getWindowHeight() / 3.0f },
    0.2f, [](bomberman::core::GameEngine *engine){ engine->options.increaseDifficulty(); }));
    _buttons.push_back(bomberman::objects::Button("assets/buttons/leafButtonLeft.png",
    { engine->options.getWindowWidth() / 2.0f - _images[0].getWidth() / 1.5f, engine->options.getWindowHeight() / 3.0f },
    0.2f, [](bomberman::core::GameEngine *engine){ engine->options.decreaseDifficulty(); }));
}

void bomberman::menu::SelectGame::cleanup()
{
    std::cout << "Cleaning select game menu..." << std::endl;
    UnloadModel(_background);
    _selectGameInstance = nullptr;
    std::cout << "Select game menu cleanup." << std::endl;
}

void bomberman::menu::SelectGame::pause()
{
}

void bomberman::menu::SelectGame::resume()
{
}

void bomberman::menu::SelectGame::processInput(bomberman::core::GameEngine *engine)
{
}

void bomberman::menu::SelectGame::update(bomberman::core::GameEngine *engine,
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
    _nb_players = std::to_string(engine->options.getNbPlayers());
    _difficulty = engine->options.getDifficulty();
    _images[0].changeText("Players number: " + _nb_players, 0);
    _images[1].changeText("Difficulty mode: " + _difficulty, 0);
    (void)engine;
}

void bomberman::menu::SelectGame::render(bomberman::core::GameEngine *engine)
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
        for (size_t i = 0; i < _images.size(); i++)
            _images[i].draw();
        engine->drawCursor();
    EndDrawing();
}
