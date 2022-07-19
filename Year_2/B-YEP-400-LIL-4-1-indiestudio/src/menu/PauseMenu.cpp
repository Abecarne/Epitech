/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** PauseMenu.cpp
*/
#include "PauseMenu.hpp"
#include <cctype>

bomberman::menu::PauseMenu *bomberman::menu::PauseMenu::_pauseMenuInstance {nullptr};
std::mutex bomberman::menu::PauseMenu::_mutex;

void bomberman::menu::PauseMenu::init(bomberman::core::GameEngine *engine)
{
    std::cout << "Initializing pause menu..." << std::endl;
    engine->options.music.changeMusic("assets/music/Pause.mp3");
    initAssets(engine);
    initButtons(engine);
    std::cout << "Pause menu initialized." << std::endl;
}

void bomberman::menu::PauseMenu::initButtons(bomberman::core::GameEngine *engine)
{
    _buttons.push_back(bomberman::objects::MenuButton(LOADSAVEBTN,
    { (float)(engine->options.getWindowWidth() / 1.4f), (float)(engine->options.getWindowHeight() - 150.0f) },
    0.3f, [](bomberman::core::GameEngine *engine) {
        engine->options.music.rechangeMusic("assets/music/gameMusic.mp3");
        engine->popState();
    }));
    _buttons[0].setText(_buttons[0].getWidth() / 2, _buttons[0].getHeight() / 3.0f, "Resume", 40.0f, WHITE);
    _buttons.push_back(bomberman::objects::MenuButton(LOADSAVEBTN,
    { (float)(engine->options.getWindowWidth() / 3.3f), (float)(engine->options.getWindowHeight()  - 150.0f) },
    0.3f, [](bomberman::core::GameEngine *engine) {
        engine->options.music.changeMusic("assets/music/menu.mp3");
        engine->cleanGameAssets();
        engine->changeState(bomberman::menu::MainMenu::getInstance());
    }));
    _buttons[1].setText(_buttons[1].getWidth() / 2, _buttons[1].getHeight() / 3.0f, "Quit", 40.0f, WHITE);
}

void bomberman::menu::PauseMenu::initAssets(bomberman::core::GameEngine *engine)
{
    _bg = bomberman::objects::Image("assets/img/pauseBG.png", { engine->options.getWindowWidth() / 2.0f, engine->options.getWindowHeight() / 2.0f }, 1.0f);
    _image = bomberman::objects::Image("assets/img/plank.png",
    { (float)(engine->options.getWindowWidth() / 2), 100.0f }, 0.4f);
    _image.setText(_image.getWidth() / 2.0f, _image.getHeight() / 3.0f, "Pause", 50.0f, WHITE);
}

void bomberman::menu::PauseMenu::cleanup()
{
    std::cout << "Cleaning pause menu..." << std::endl;
    _pauseMenuInstance = nullptr;
    std::cout << "Pause menu cleanup." << std::endl;
}

void bomberman::menu::PauseMenu::pause()
{
}

void bomberman::menu::PauseMenu::resume()
{
}

void handleButtonsPause(std::vector<bomberman::objects::MenuButton> *buttons,
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

void bomberman::menu::PauseMenu::processInput(bomberman::core::GameEngine *engine)
{
    if (IsKeyPressed(KEY_ESCAPE)) {
        engine->options.music.rechangeMusic("assets/music/gameMusic.mp3");
        engine->popState();
    }
}

void bomberman::menu::PauseMenu::update(bomberman::core::GameEngine *engine,
bomberman::core::Time deltaTime)
{
    handleButtonsPause(&_buttons, engine);
}

void bomberman::menu::PauseMenu::render(bomberman::core::GameEngine *engine)
{
    BeginDrawing();
        ClearBackground({ 85, 97, 67, 1 });
        _bg.draw();
        _image.draw();
        for (size_t i = 0; i < _buttons.size(); i++)
            _buttons[i].draw();
        engine->drawCursor();
    EndDrawing();
}
