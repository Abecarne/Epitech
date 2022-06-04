/*
** EPITECH PROJECT, 2022
** Documents
** File description:
** Module
*/

#include "../include/header.hpp"

Module::Module(std::string name, int x) :
    _name(name),
    _x(x),
    _y(0),
    _color(sf::Color::Red),
    _fontSize(18)
{
    _font.loadFromFile("./res/Roboto-Light.ttf");
}

Module::~Module()
{
}

// GETTER
int Module::getX() { return (_x); }
int Module::getY() { return (_y); }
sf::Font Module::getFont() { return (_font); }
sf::Color Module::getColor() { return (_color); }
std::string Module::getName() { return (_name); }
int Module::getFontSize() { return (_fontSize); }
sf::Vector2f Module::getSize() { return (_size); }
sf::RectangleShape Module::getRectangle(void) { return (_rect); }

// SETTER
void Module::setX(int x) { _x = x; }
void Module::setY(int y) { _y = y; }
void Module::setFont(sf::Font font) { _font = font; }
void Module::setName(std::string name) { _name = name; }
void Module::setSize(float a, float b) { _size = {a, b}; }
void Module::setColor(sf::Color color) { _color = color; }
void Module::setFontSize(int fontSize) { _fontSize = fontSize; }

void Module::refresh(void)
{
    
}