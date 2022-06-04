/*
** EPITECH PROJECT, 2022
** Documents
** File description:
** Ram
*/

#include "../include/header.hpp"

Ram::Ram(std::string name) :
    Module(name)
{
}

Ram::~Ram()
{
}

void Ram::setRam_Max(double ram)
{
    _ram_max = ram;
}

void Ram::setRam_Use(double ram)
{
    _ram_used = ram;
}

double Ram::getRamMax()
{
    return (_ram_max);
}

double Ram::getRamUse()
{
    return (_ram_used);
}

void Ram::initAll(void)
{
    _ram_max = getRamMax();
    _ram_used = 0.;
    _size = {30, -50};
    initTextRam();
    initTextRamUse();
    initRectRam();
    sf::RectangleShape rectangle(sf::Vector2f(30, 2));
    rectangle.setFillColor(sf::Color(156,156,156));
    rectangle.setPosition(200., 225.);
    _rectBase = rectangle;
    sf::RectangleShape rect(sf::Vector2f(30, -2));
    rect.setFillColor(sf::Color(156,156,156));
    rect.setPosition(-getX() + 200, -getY() + 230 - (_ram_max * 4));
    _rectTop = rect;
}

void Ram::initRectRam(void)
{
    sf::RectangleShape rectangle(sf::Vector2f(30, -5));
    rectangle.setFillColor(sf::Color(0,234,255));
    rectangle.setPosition(200., 225.);
    _rectRam = rectangle;
}

bool Ram::initTextRam(void)
{
    sf::Text Text;
    Text.setString("RAM");
    Text.setFont(_font);
    Text.setCharacterSize(13);
    Text.setFillColor(sf::Color::White);
    Text.setOrigin(-200., -240.);
    _TextRam = Text;
    return (true);
}

bool Ram::initTextRamUse(void)
{
    sf::Text Text;
    Text.setString("0 / 0 GB");
    Text.setFont(_font);
    Text.setCharacterSize(13);
    Text.setFillColor(sf::Color::White);
    Text.setOrigin(-250., -215.);
    _TextRamUse = Text;
    return (true);
}

void Ram::refresh(void)
{
    setRam_Max(getRamMax());
    setRam_Use(getRamUse());

    std::string max = std::to_string(getRamMax());
    max = max.substr(0, max.find(".") + 4);
    std::string used = std::to_string(getRamUse());
    used = used.substr(0, used.find(".") + 4);
    _rectTop.setPosition(-getX() + 200, -getY() + 230 - (_ram_max * 6));

    _TextRamUse.setString(used + " / " + max + " GB");
    _size.y = -getRamUse() * 5;
    _rectRam.setSize(_size);
}

void Ram::render(sf::RenderTarget &target)
{
    target.draw(_rectRam);
    target.draw(_rectBase);
    target.draw(_rectTop);
    target.draw(_TextRam);
    target.draw(_TextRamUse);
}