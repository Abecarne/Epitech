/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** ADisplayModule
*/

#ifndef ADISPLAYMODULE_HPP_
#define ADISPLAYMODULE_HPP_

#include "../interface/ICoreModule.hpp"

namespace arcade
{
    namespace display
    {
        class ADisplayModule : public IDisplayModule {
            public:
                virtual ~ADisplayModule();

                virtual std::string getLibName(void) = 0;
                virtual void setGame(std::string gameName) = 0;
                virtual Keys displayMenu(std::vector<std::string> gameLibs, std::vector<std::string> graphicLibs) = 0;
                virtual arcade::State endLib(arcade::State) = 0;
                virtual void loadScreen(MapType map) = 0;
                virtual void refreshScreen(MapType map) = 0;
                virtual bool updateScore(int score) = 0;
                virtual Keys keyPressed(void) = 0;

            protected:
                std::string _name;
                std::string _currentGame;
        };
    } // namespace display
} // namespace arcade

#endif /* !ADISPLAYMODULE_HPP_ */
