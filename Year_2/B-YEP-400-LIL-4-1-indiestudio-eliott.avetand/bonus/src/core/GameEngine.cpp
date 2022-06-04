/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** Core.cpp
*/
#include "raylib.h"
#include "GameEngine.hpp"
#include "AGameState.hpp"
#include <string>
#include <iostream>

void bomberman::core::GameEngine::init()
{
    std::cout << "Initializing game engine..." << std::endl;
    InitWindow(options.getWindowWidth(), options.getWindowHeight(), options.getTitle());
    SetTargetFPS(options.getFps());
    _gameAssets = nullptr;

    // A enlever plus tard

    // _gameAssets = new bomberman::game::GameAssets();

    // if (!_gameAssets)
    //     bomberman::core::Errors("[GameEngine]", "Not enough memories!");


    // this->getGameAssets()->initSkyBox(bomberman::environment::Skybox::DAY);
    // this->getGameAssets()->initMap(CHINEASE_MAP);
    // this->getGameAssets()->initGameBoard(15, 17, {1, 1, 1}, DESTRUCTIBLE_WOODBOX, DESTRUCTIBLE_WOODBOX, DESTRUCTIBLE_JAPANEASE);

    std::cout << "Game engine initialized." << std::endl;
}

void bomberman::core::GameEngine::cleanup()
{
    std::cout << "Cleaning game engine..." << std::endl;
    while (!_states.empty()) {
        _states.back()->cleanup();
        _states.pop_back();
    }
    CloseWindow();
    std::cout << "Game engine cleanup." << std::endl;
}

void bomberman::core::GameEngine::changeState(bomberman::core::AGameState *state)
{
    if (!_states.empty()) {
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
    _states.back()->update(this, deltaTime);
}

void bomberman::core::GameEngine::render()
{
    _states.back()->render(this);
}

void bomberman::core::GameEngine::gameLoop()
{
    double timeCore;

    while (!WindowShouldClose()) {
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
    _gameAssets = new bomberman::game::GameAssets();

    if (!_gameAssets)
        bomberman::core::Errors("[GameEngine]", "Not enough memories!");
}

void bomberman::core::GameEngine::cleanGameEngine(void)
{
    delete _gameAssets;
}

bomberman::game::GameAssets *bomberman::core::GameEngine::getGameAssets(void)
{
    return _gameAssets;
}