/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** MainMenu.cpp
*/
#include "SaveMenu.hpp"
#include "CreateProfile.hpp"
#include "MainMenu.hpp"
#include "LoadingScreen.hpp"
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/classification.hpp>

bomberman::menu::SaveMenu *bomberman::menu::SaveMenu::_saveMenuInstance {nullptr};
std::mutex bomberman::menu::SaveMenu::_mutex;

void bomberman::menu::SaveMenu::init(bomberman::core::GameEngine *engine)
{
    std::cout << "Initializing save menu..." << std::endl;
    _background = LoadModel(BACKGROUNDMODEL);
    _backgroundPos = { 0.0f, 0.0f, 0.0f };
    _camera.setPosition(0.0f, 40.0f, 1.0f);
    _camera.setTarget(0.0f, 0.0f, 0.0f);
    _camera.setUp(0.0f, 1.0f, 0.0f);
    initButton(engine);
    std::cout << "Save menu initialized." << std::endl;
}

void displayProfile(bomberman::objects::MenuButton *button, size_t index)
{
    std::ifstream fileStream(".data/profile/" + std::to_string(index + 1) + "/data.txt");
    std::string fileData;
    std::vector<std::string> values;
    std::map<std::string, bomberman::menu::textInfos_t> infos = {
        {"PSEUDO", {(Vector2){ 110.0f, 25.0f }, "", "", 40.0f, (Color){ 245, 200, 90, 255 }}},
        {"TIME_PLAYED", {(Vector2){ button->getWidth() / 1.15f, button->getHeight() / 1.5f }, "", " m", 30.0f, (Color){ 245, 200, 90, 255 }}},
        {"PIKCOINS", {(Vector2){ 160.0f, button->getHeight() / 1.5f }, "Pikcoins ", " $", 30.0f, (Color){ 245, 200, 90, 255 }}},
    };

    for (size_t i = 0; fileStream >> fileData; i++) {
        boost::split(values, fileData, boost::is_any_of("="));
        if (infos.contains(values[0])) {
            button->setText(
                infos[values[0]].pos.x,
                infos[values[0]].pos.y,
                infos[values[0]].prefix + values[1] + infos[values[0]].suffix,
                infos[values[0]].fontSize,
                infos[values[0]].color
            );
            button->setCallback([](bomberman::core::GameEngine *engine)
            {engine->changeState(bomberman::menu::MainMenu::getInstance());});
        }
    }
    fileStream.close();
}

void loadSave(std::vector<bomberman::objects::MenuButton> *buttons,
bomberman::core::GameEngine *engine)
{
    std::string path = ".data/profile/";
    std::string profileFolder;
    std::string profileData;

    for (size_t i = 1; i < 4; i++) {
        profileFolder = path + std::to_string(i);
        profileData = profileFolder + "/data.txt";
        if (std::filesystem::exists(profileFolder) &&
        std::filesystem::exists(profileData))
            displayProfile(&(*buttons)[i - 1], i - 1);
        else {
            (*buttons)[i - 1].setText(
                (*buttons)[i - 1].getWidth() / 2.0f,
                (*buttons)[i - 1].getHeight() / 2.66f,
                "Empty Save",
                50.0f,
                (Color){ 245, 200, 90, 255 }
            );
            (*buttons)[i - 1].setCallback([](bomberman::core::GameEngine *engine)
            {engine->changeState(bomberman::menu::CreateProfile::getInstance());});
        }
    }
}

void bomberman::menu::SaveMenu::initButton(bomberman::core::GameEngine *engine)
{
    _buttons.push_back(bomberman::objects::MenuButton(LOADSAVEBTN,
    (Vector2){ (float)(engine->options.getWindowWidth() / 2), (float)(engine->options.getWindowHeight() / 4) },
    0.5f, [](bomberman::core::GameEngine *){}));
    _buttons.push_back(bomberman::objects::MenuButton(LOADSAVEBTN,
    (Vector2){ (float)(engine->options.getWindowWidth() / 2), (float)(engine->options.getWindowHeight() / 2) },
    0.5f, [](bomberman::core::GameEngine *){}));
    _buttons.push_back(bomberman::objects::MenuButton(LOADSAVEBTN,
    (Vector2){ (float)(engine->options.getWindowWidth() / 2), (float)(engine->options.getWindowHeight() / 1.33) },
    0.5f, [](bomberman::core::GameEngine *){}));
    loadSave(&_buttons, engine);
}

void bomberman::menu::SaveMenu::cleanup()
{
    std::cout << "Cleaning save menu..." << std::endl;
    UnloadModel(_background);
    _saveMenuInstance = nullptr;
    std::cout << "Save menu cleanup." << std::endl;
}

void bomberman::menu::SaveMenu::pause()
{
}

void bomberman::menu::SaveMenu::resume()
{
}

void bomberman::menu::SaveMenu::processInput(bomberman::core::GameEngine *engine)
{
    (void)engine;
}

void bomberman::menu::SaveMenu::update(bomberman::core::GameEngine *engine,
bomberman::core::Time deltaTime)
{
    UpdateMusicStream(engine->options.music.getMusicStream());
    for (size_t i = 0; i < _buttons.size(); i++) {
        if (CheckCollisionPointRec(engine->getMouseCoordinates(), _buttons[i].getBounds())) {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                _buttons[i].press();
                _buttons[i].setColor(WHITE);
            } else {
                _buttons[i].hover(engine->options.music.isSoundActive());
                _buttons[i].setColor((Color){ 255, 255, 255, 230 });
            }
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
                _buttons[i].click(engine->options.music.isSoundActive(), engine);
        } else {
            _buttons[i].released();
            _buttons[i].setColor(WHITE);
        }
    }
    (void)deltaTime;
}

void bomberman::menu::SaveMenu::render(bomberman::core::GameEngine *engine)
{
    (void)engine;
    BeginDrawing();
        ClearBackground((Color){ 85, 97, 67, 1 });
        BeginMode3D(*_camera.getCamera());
            DrawModel(_background, _backgroundPos, 1.0f, WHITE);
        EndMode3D();
        for (size_t i = 0; i < _buttons.size(); i++)
            _buttons[i].draw();
    EndDrawing();
}
