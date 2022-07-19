/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** Core.cpp
*/
#include "raylib.h"
#include "GameEngine.hpp"
#include "AGameState.hpp"
#include <iostream>

bomberman::core::GameEngine *bomberman::core::GameEngine::_gameEngineInstance {nullptr};
std::mutex bomberman::core::GameEngine::_mutex;

void bomberman::core::GameEngine::init()
{
    std::cout << "Initializing game engine..." << std::endl;
    InitWindow(options.getWindowWidth(), options.getWindowHeight(), options.getTitle());
    ToggleFullscreen();
    SetTargetFPS(options.getFps());
    HideCursor();
    SetExitKey(0);
    _gameAssets = nullptr;
    _shouldClose = false;
    _image = LoadTexture("assets/img/cursor.png");
    std::cout << "Game engine initialized." << std::endl;
}

void bomberman::core::GameEngine::cleanup()
{
    std::cout << "Cleaning game engine..." << std::endl;
    while (!_states.empty()) {
        _states.back()->cleanup();
        _states.pop_back();
    }
    UnloadTexture(_image);
    if (this->_gameAssets)
        delete this->_gameAssets;
    CloseAudioDevice();
    CloseWindow();
    std::cout << "Game engine cleanup." << std::endl;
}

void bomberman::core::GameEngine::changeState(bomberman::core::AGameState *state)
{
    while (!_states.empty()) {
        _states.back()->cleanup();
        _states.pop_back();
    }
    _states.push_back(state);
    _states.back()->init(this);
}

void bomberman::core::GameEngine::pushState(bomberman::core::AGameState *state)
{
    if (!_states.empty())
        _states.back()->pause();
    _states.push_back(state);
    _states.back()->init(this);
}

void bomberman::core::GameEngine::popState()
{
    if (!_states.empty()) {
        _states.back()->cleanup();
        _states.pop_back();
    }
    if (!_states.empty())
        _states.back()->resume();
}

void bomberman::core::GameEngine::processInput()
{
    _states.back()->processInput(this);
}

void bomberman::core::GameEngine::update(Time deltaTime)
{
    _mousePoint = GetMousePosition();
    options.music.update();
    _states.back()->update(this, deltaTime);
}

void bomberman::core::GameEngine::render()
{
    _states.back()->render(this);
}

void bomberman::core::GameEngine::gameLoop()
{
    double timeCore;

    while (!WindowShouldClose() && !_shouldClose) {
        timeCore = GetTime();
        Time deltaTime = timeCore - _keepTime;
        _keepTime = timeCore;
        processInput();
        update(deltaTime);
        render();
	}
}

Vector2 bomberman::core::GameEngine::getMouseCoordinates()
{
    return _mousePoint;
}

void bomberman::core::GameEngine::initGameAssets(void)
{
    _gameAssets = bomberman::game::GameAssets::getInstance();

    if (!_gameAssets)
        bomberman::core::Errors("[GameEngine]", "Not enough memories!");
}

void bomberman::core::GameEngine::cleanGameEngine(void)
{
    //void
}

bomberman::game::GameAssets *bomberman::core::GameEngine::getGameAssets(void)
{
    return _gameAssets;
}

void bomberman::core::GameEngine::cleanGameAssets(void)
{
    if (_gameAssets) {
        _gameAssets->cleanUp();
        delete _gameAssets;
        _gameAssets = nullptr;
    }
}

void bomberman::core::GameEngine::shouldClose()
{
    _shouldClose = true;
}

void bomberman::core::GameEngine::drawCursor()
{
    DrawTextureEx(_image, _mousePoint, 0.0f, 0.2f, WHITE);
}