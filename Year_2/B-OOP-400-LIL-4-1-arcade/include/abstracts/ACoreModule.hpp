/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** ACoreModule
*/

#ifndef ACOREMODULE_HPP_
#define ACOREMODULE_HPP_

#include "../interface/ICoreModule.hpp"
#include "ADisplayModule.hpp"
#include "AGameModule.hpp"

namespace arcade
{
    namespace core
    {
        class ACoreModule : public ICoreModule {
            public:
                virtual ~ACoreModule();

                virtual arcade::State gameloop(void) = 0;
                virtual arcade::State menu(void) = 0;
                virtual int checkGameStatus(void) = 0;

            protected:
                int score;
                std::string playerName;
                State state;
                std::vector<std::string> gamesLib;
                std::vector<std::string> displayLib;
        };
    } // namespace core
} // namespace arcade

#endif /* !ACOREMODULE_HPP_ */
