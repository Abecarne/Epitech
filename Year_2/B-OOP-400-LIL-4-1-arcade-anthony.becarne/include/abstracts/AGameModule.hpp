/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** AGameModule
*/

#ifndef AGAMEMODULE_HPP_
#define AGAMEMODULE_HPP_

#include "../interface/ICoreModule.hpp"

namespace arcade
{
    namespace game
    {
        class AGameModule : public IGameModule {
            public:
                virtual ~AGameModule();

                virtual std::string getGameName(void) = 0;
                virtual State getState(void) = 0;
                virtual int getScore(void) = 0;
                virtual void launch(std::string) = 0;
                virtual void update(arcade::Keys inputKey) = 0;
                virtual MapType getMap(void) = 0;

                virtual void keyInput(Keys inputKey) = 0;
                virtual MapType getMapFromFile(std::string filepath) = 0;

            protected:
                std::string gameName;
                State state;
                int score;
                MapType map;
        };
    } // namespace game
} // namespace arcade

#endif /* !AGAMEMODULE_HPP_ */
