/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** Options.cpp
*/
#include "raylib.h"
#include "Options.hpp"
#include <iostream>
#include <vector>
#include <string>

bomberman::settings::Options::Options()
{
    _width = 1920;
    _height = 1080;
    _fps = 144;
    _nb_players = 1;
    _nb_ia = 3;
    _isNight = false;
    _mapAssets = {{"Ballad", "assets/models/maps/picnic/"}, {"Chinese", "assets/models/maps/chinease/"}};
    _selectedMap = "Ballad";
    _difficulty = bomberman::settings::EASY;
    _title = "Pikmins";
    _player1 = {
        {bomberman::settings::FORWARD, KEY_W},
        {bomberman::settings::BACKWARD, KEY_S},
        {bomberman::settings::RIGHT, KEY_D},
        {bomberman::settings::LEFT, KEY_A},
        {bomberman::settings::BOMB, KEY_X}
    };
    _player2 = {
        {bomberman::settings::FORWARD, KEY_T},
        {bomberman::settings::BACKWARD, KEY_F},
        {bomberman::settings::RIGHT, KEY_G},
        {bomberman::settings::LEFT, KEY_H},
        {bomberman::settings::BOMB, KEY_B}
    };
    _player3 = {
        {bomberman::settings::FORWARD, KEY_I},
        {bomberman::settings::BACKWARD, KEY_J},
        {bomberman::settings::RIGHT, KEY_K},
        {bomberman::settings::LEFT, KEY_L},
        {bomberman::settings::BOMB, KEY_P}
    };
    _player4 = {
        {bomberman::settings::FORWARD, KEY_KP_1},
        {bomberman::settings::BACKWARD, KEY_KP_2},
        {bomberman::settings::RIGHT, KEY_KP_3},
        {bomberman::settings::LEFT, KEY_KP_4},
        {bomberman::settings::BOMB, KEY_KP_5}
    };
    _stringToKey = {
        {"A", KEY_Q},
        {"B", KEY_B},
        {"C", KEY_C},
        {"D", KEY_D},
        {"E", KEY_E},
        {"F", KEY_F},
        {"G", KEY_G},
        {"H", KEY_H},
        {"I", KEY_I},
        {"J", KEY_J},
        {"K", KEY_K},
        {"L", KEY_L},
        {"M", KEY_PERIOD},
        {"N", KEY_N},
        {"O", KEY_O},
        {"P", KEY_P},
        {"Q", KEY_A},
        {"R", KEY_R},
        {"S", KEY_S},
        {"T", KEY_T},
        {"U", KEY_U},
        {"V", KEY_V},
        {"W", KEY_Z},
        {"X", KEY_X},
        {"Y", KEY_Y},
        {"Z", KEY_W},
        {"1", KEY_KP_1},
        {"2", KEY_KP_2},
        {"3", KEY_KP_3},
        {"4", KEY_KP_4},
        {"5", KEY_KP_5},
        {"6", KEY_KP_6},
        {"7", KEY_KP_7},
        {"8", KEY_KP_8},
        {"9", KEY_KP_9},
        {"0", KEY_KP_0},
    };
    _keyToString = {
        {KEY_Q, "A"},
        {KEY_B, "B"},
        {KEY_C, "C"},
        {KEY_D, "D"},
        {KEY_E, "E"},
        {KEY_F, "F"},
        {KEY_G, "G"},
        {KEY_H, "H"},
        {KEY_I, "I"},
        {KEY_J, "J"},
        {KEY_K, "K"},
        {KEY_L, "L"},
        {KEY_PERIOD, "M"},
        {KEY_N, "N"},
        {KEY_O, "O"},
        {KEY_P, "P"},
        {KEY_A, "Q"},
        {KEY_R, "R"},
        {KEY_S, "S"},
        {KEY_T, "T"},
        {KEY_U, "U"},
        {KEY_V, "V"},
        {KEY_Z, "W"},
        {KEY_X, "X"},
        {KEY_Y, "Y"},
        {KEY_W, "Z"},
        {KEY_KP_1, "1"},
        {KEY_KP_2, "2"},
        {KEY_KP_3, "3"},
        {KEY_KP_4, "4"},
        {KEY_KP_5, "5"},
        {KEY_KP_6, "6"},
        {KEY_KP_7, "7"},
        {KEY_KP_8, "8"},
        {KEY_KP_9, "9"},
        {KEY_KP_0, "0"},
    };
}

size_t bomberman::settings::Options::getWindowWidth()
{
    return _width;
}

size_t bomberman::settings::Options::getWindowHeight()
{
    return _height;
}

size_t bomberman::settings::Options::getFps()
{
    return _fps;
}

double bomberman::settings::Options::getFramePerUpdate()
{
    return (1.0f / _fps) * 1000.0f;
}

char const *bomberman::settings::Options::getTitle()
{
    return _title.c_str();
}

std::vector<std::map<bomberman::settings::Actions, KeyboardKey>> bomberman::settings::Options::getActions()
{
    return { _player1, _player2, _player3, _player4 };
}

void bomberman::settings::Options::setActions(bomberman::settings::Actions action, std::string key, int player)
{
    if (player == 1)
        _player1[action] =_stringToKey[key];
    if (player == 2)
        _player2[action] =_stringToKey[key];
    if (player == 3)
        _player3[action] =_stringToKey[key];
    if (player == 4)
        _player4[action] =_stringToKey[key];

}

void bomberman::settings::Options::increasePlayers()
{
    _nb_players = _nb_players + 1 > 4 ? 1 : _nb_players + 1;
    _nb_ia = _nb_ia - 1 < 1 ? 3 : _nb_ia - 1;
}

void bomberman::settings::Options::decreasePlayers()
{
    _nb_players = _nb_players - 1 < 1 ? 4 : _nb_players - 1;
    _nb_ia = _nb_ia + 1 > 3 ? 0 : _nb_ia - 1;
}

void bomberman::settings::Options::increaseDifficulty()
{
    _difficulty = _difficulty + 1 > 1 ? 0 : _difficulty + 1;
}

void bomberman::settings::Options::decreaseDifficulty()
{
    _difficulty = _difficulty - 1 < 0 ? 1 : _difficulty - 1;
}

std::string bomberman::settings::Options::getDifficulty()
{
    return _difficulty == bomberman::settings::EASY ? "Easy" : "Advanced";
}

int bomberman::settings::Options::getBotsDifficulty()
{
    return (int)_difficulty;
}

int bomberman::settings::Options::getNbPlayers()
{
    return _nb_players;
}

void bomberman::settings::Options::changeMap()
{
    if (_selectedMap.compare("Ballad") == 0)
        _selectedMap = "Chinese";
    else
        _selectedMap = "Ballad";
}

std::string bomberman::settings::Options::getMapPath()
{
    if (_mapAssets.contains(_selectedMap)) {
       return  _mapAssets.find(_selectedMap)->second;
    }
    return "";
}


std::string bomberman::settings::Options::getMap()
{
    return _selectedMap;
}

void bomberman::settings::Options::changeDayCycle()
{
    if (_isNight)
        _isNight = false;
    else
        _isNight = true;
}

bool bomberman::settings::Options::isNight()
{
    return _isNight;
}
