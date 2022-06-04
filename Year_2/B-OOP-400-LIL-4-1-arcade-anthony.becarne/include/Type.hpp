/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** IType
*/

#ifndef ITYPE_HPP_
#define ITYPE_HPP_

#include <iostream>
#include <vector>

namespace arcade
{
    enum State  {RUNNING, WIN, LOOSE, MENU_WINDOW, EXIT, STORE, NO_STORE};
    enum Keys   {UP, LEFT, DOWN, RIGHT, NEXTLIB, PREVLIB, NEXTGAME, PREVGAME, MENU, ESC, ENTER, NONE, W, L, YES, NO};
} // namespace arcade

typedef std::vector<std::string> MapType;

#endif /* !ITYPE_HPP_ */
