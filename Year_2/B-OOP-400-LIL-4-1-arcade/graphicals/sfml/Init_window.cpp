/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** Init_window
*/

#include "sfml.hpp"

void Sfml::_initWindow(void)
{
    _videoMode.height = 845;
    _videoMode.width = 725;
    _window = new sf::RenderWindow(_videoMode, "Pacman", sf::Style::Default);
    _window->setFramerateLimit(30);
}

// const bool Sfml::is_running(void) const
// {
//     return (_window->isOpen());
// }

void Sfml::_initClock(void)
{
    clockCpu.restart();
}