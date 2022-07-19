/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** Options.hpp
*/
#pragma once

#include <cstddef>
#include <string>
#include <map>
#include <vector>
#include "Music.hpp"

namespace bomberman {
    namespace settings {
        enum Actions {
            FORWARD,
            BACKWARD,
            RIGHT,
            LEFT,
            BOMB
        };
        enum difficultyMode {
            EASY,
            ADVANCED
        };

        class Options {
            private:
                int _nb_players;
                int _nb_ia;
                int _difficulty;
                std::map<std::string, std::string> _mapAssets;
                std::string _selectedMap;
                bool _isNight;
                size_t _width;
                size_t _height;
                size_t _fps;
                std::string _title;
                std::map <bomberman::settings::Actions, KeyboardKey> _player1;
                std::map <bomberman::settings::Actions, KeyboardKey> _player2;
                std::map <bomberman::settings::Actions, KeyboardKey> _player3;
                std::map <bomberman::settings::Actions, KeyboardKey> _player4;

            public:
                Options();

                std::map <std::string, KeyboardKey> _stringToKey;
                std::map <KeyboardKey, std::string> _keyToString;
                size_t getWindowWidth();
                size_t getWindowHeight();
                size_t getFps();
                double getFramePerUpdate();
                int getNbPlayers();
                std::string getDifficulty();
                char const *getTitle();
                std::string getMapPath();
                void increasePlayers();
                void increaseDifficulty();
                void decreasePlayers();
                void decreaseDifficulty();
                int getBotsDifficulty();
                void changeMap();
                std::string getMap();
                void changeDayCycle();
                bool isNight();
                std::vector<std::map<bomberman::settings::Actions, KeyboardKey>> getActions();
                void setActions(bomberman::settings::Actions action, std::string key, int player);

                bomberman::settings::RaylibMusic music;
        };
    }
}