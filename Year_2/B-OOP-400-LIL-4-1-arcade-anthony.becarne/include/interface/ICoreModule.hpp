/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** ICoreModule
*/

#ifndef ICOREMODULE_HPP_
#define ICOREMODULE_HPP_

#include "../Type.hpp"
#include "IGameModule.hpp"
#include "IDisplayModule.hpp"

namespace arcade
{
    namespace core
    {
        class ICoreModule {
            public:
                ~ICoreModule() = default;

                virtual arcade::State gameloop(void) = 0;
                virtual arcade::State menu(void) = 0;
                virtual int checkGameStatus(void) = 0;
        };
    } // namespace core
} // namespace arcade

#endif /* !ICOREMODULE_HPP_ */
