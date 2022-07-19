/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** VolumeOptions.cpp
*/
#include "VolumeOptions.hpp"
#include "OptionsMenu.hpp"
#include "Options.hpp"
#include <cctype>

bomberman::menu::VolumeOptions *bomberman::menu::VolumeOptions::_volumeOptionsInstance {nullptr};
std::mutex bomberman::menu::VolumeOptions::_mutex;

void bomberman::menu::VolumeOptions::init(bomberman::core::GameEngine *engine)
{
    std::cout << "Initializing control options menu..." << std::endl;
    _background = LoadModel(BACKGROUNDMODEL);
    _backgroundPos = { 0.0f, 0.0f, 0.0f };
    _camera.setPosition(0.0f, 40.0f, 1.0f);
    _camera.setTarget(0.0f, 0.0f, 0.0f);
    _camera.setUp(0.0f, 1.0f, 0.0f);
    initAssets(engine);
    initButtons(engine);
    std::cout << "Control options initialized." << std::endl;
}

void bomberman::menu::VolumeOptions::initButtons(bomberman::core::GameEngine *engine)
{
    _buttons.push_back(bomberman::objects::Button("assets/buttons/back.png",
    { 100.0f, (float)(engine->options.getWindowHeight() - 100.0f) },
    0.2f, [](bomberman::core::GameEngine *engine){ engine->changeState(bomberman::menu::OptionsMenu::getInstance()); }));
    _buttons.push_back(bomberman::objects::Button("assets/buttons/leafButtonRight.png",
    { engine->options.getWindowWidth() / 2.0f + _images[1].getWidth() / 1.5f, engine->options.getWindowHeight() / 1.7f },
    0.2f, [](bomberman::core::GameEngine *engine){ engine->options.music.increaseSound(); }));
    _buttons.push_back(bomberman::objects::Button("assets/buttons/leafButtonLeft.png",
    { engine->options.getWindowWidth() / 2.0f - _images[1].getWidth() / 1.5f, engine->options.getWindowHeight() / 1.7f },
    0.2f, [](bomberman::core::GameEngine *engine){ engine->options.music.decreaseSound(); }));
    _buttons.push_back(bomberman::objects::Button("assets/buttons/leafButtonRight.png",
    { engine->options.getWindowWidth() / 2.0f + _images[2].getWidth() / 1.5f, engine->options.getWindowHeight() / 3.0f },
    0.2f, [](bomberman::core::GameEngine *engine){ engine->options.music.increaseMusic(); }));
    _buttons.push_back(bomberman::objects::Button("assets/buttons/leafButtonLeft.png",
    { engine->options.getWindowWidth() / 2.0f - _images[2].getWidth() / 1.5f, engine->options.getWindowHeight() / 3.0f },
    0.2f, [](bomberman::core::GameEngine *engine){ engine->options.music.decreaseMusic(); }));
}

void bomberman::menu::VolumeOptions::initAssets(bomberman::core::GameEngine *engine)
{
    _images.push_back(bomberman::objects::Image("assets/img/plank.png",
    { (float)(engine->options.getWindowWidth() / 2), 100.0f }, 0.4f));
    _images[0].setText(_images[0].getWidth() / 2.0f, _images[0].getHeight() / 3.0f, "Volume", 50.0f, WHITE);
    _images.push_back(bomberman::objects::Image("assets/img/plank.png",
    { engine->options.getWindowWidth() / 2.0f, engine->options.getWindowHeight() / 1.7f }, 0.5f));
    _images.back().setText(_images.back().getWidth() / 2.0f, _images.back().getHeight() / 2.0f - 25.0f,
    "Music volume: " + std::to_string(engine->options.music.getMusicVolume() * 10) + "%", 50.0f, WHITE);
    _images.push_back(bomberman::objects::Image("assets/img/plank.png",
    { engine->options.getWindowWidth() / 2.0f, engine->options.getWindowHeight() / 3.0f }, 0.5f));
    _images.back().setText(_images.back().getWidth() / 2.0f, _images.back().getHeight() / 2.0f - 25.0f,
    "Sound volume: " + std::to_string(engine->options.music.getSoundVolume() * 10) + "%", 50.0f, WHITE);
}

void bomberman::menu::VolumeOptions::cleanup()
{
    std::cout << "Cleaning control options menu..." << std::endl;
    UnloadModel(_background);
    _volumeOptionsInstance = nullptr;
    std::cout << "Control options menu cleanup." << std::endl;
}

void bomberman::menu::VolumeOptions::pause()
{
}

void bomberman::menu::VolumeOptions::resume()
{
}

void handleButtonsVolume(std::vector<bomberman::objects::Button> *buttons,
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

void bomberman::menu::VolumeOptions::processInput(bomberman::core::GameEngine *engine)
{
    handleButtonsVolume(&_buttons, engine);
}

void bomberman::menu::VolumeOptions::update(bomberman::core::GameEngine *engine,
bomberman::core::Time deltaTime)
{
    _images[2].changeText("Music volume: " + std::to_string(engine->options.music.getMusicVolume() * 10) + "%", 0);
    _images[1].changeText("Sound volume: " + std::to_string(engine->options.music.getSoundVolume() * 10) + "%", 0);
}

void bomberman::menu::VolumeOptions::render(bomberman::core::GameEngine *engine)
{
    (void)engine;
    BeginDrawing();
        ClearBackground({ 85, 97, 67, 1 });
        BeginMode3D(*_camera.getCamera());
            DrawModel(_background, _backgroundPos, 1.0f, WHITE);
        EndMode3D();
        for (size_t i = 0; i < _images.size(); i++)
            _images[i].draw();
        for (size_t i = 0; i < _buttons.size(); i++)
            _buttons[i].draw();
        for (size_t i = 0; i < _texts.size(); i++)
            _texts[i].drawText();
        engine->drawCursor();
    EndDrawing();
}
