/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** endGame
*/

#include "sfml.hpp"

void Sfml::printLoose(void)
{
    sf::Text loose;
    sf::Font font;

    font.loadFromFile("res/Roboto-light.fft");
    loose.setFont(font);
    loose.setCharacterSize(100);
    loose.setFillColor(sf::Color(255, 0, 0));
    loose.setString("YOU LOOSE !");
    loose.setPosition(sf::Vector2f(215, 300));
    _window->draw(loose);
}

void Sfml::printWin(void)
{
    sf::Text win;
    sf::Font font;

    font.loadFromFile("res/Roboto-light.fft");
    win.setFont(font);
    win.setCharacterSize(100);
    win.setFillColor(sf::Color(0, 0, 255));
    win.setString("YOU WIN !");
    win.setPosition(sf::Vector2f(215, 300));
    _window->draw(win);
}