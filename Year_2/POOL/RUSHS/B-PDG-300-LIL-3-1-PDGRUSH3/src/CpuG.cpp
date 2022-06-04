/*
** EPITECH PROJECT, 2022
** Documents
** File description:
** CpuG
*/

#include "../include/header.hpp"

CpuG::CpuG(std::string name, int x) :
    Module(name, x)
{
    _CpuGUse = 0;
    _color.a = 50;
    _y = -600;
    initAll();
}

CpuG::~CpuG()
{
}

void CpuG::setFrequencyG(float freq) { _freq = freq; }
void CpuG::setCpuGUse(float CpuGUse) { _CpuGUse = CpuGUse; }

float CpuG::getCpuGUse() { return (_CpuGUse); }
float CpuG::getFrequency() { return (_freq); }

void CpuG::initAll(void)
{
    _size = {30, -50};
    _freq = 0;
    initTextCpuG();
    initTextCpuGUse();
    initTextLimit();
    initRectCpuG();
    initTextCpuGFrequency();
    sf::RectangleShape rectangle(sf::Vector2f(30, 2));
    rectangle.setFillColor(sf::Color(156,156,156));
    rectangle.setPosition(-getX(), -getY() + 45);
    _rectBase = rectangle;
    sf::RectangleShape rect(sf::Vector2f(30, 2));
    rect.setFillColor(sf::Color(156,156,156));
    rect.setPosition(-getX(), 302);
    _rectTop = rect;
}

void CpuG::initRectCpuG(void)
{
    sf::RectangleShape rectangle(_size);
    rectangle.setFillColor(sf::Color(77,255,0));
    rectangle.setPosition(-getX(), -getY() + 45);
    _rectCpuG = rectangle;
}

bool CpuG::initTextLimit(void)
{
    sf::Text Text;
    Text.setString("100 %");
    Text.setFont(_font);
    Text.setCharacterSize(13);
    Text.setFillColor(sf::Color(156,156,156));
    Text.setOrigin(-50, -295);
    _TextLimit = Text;
    return (true);
}

bool CpuG::initTextCpuG(void)
{
    sf::Text Text;
    Text.setString(getName());
    Text.setFont(_font);
    Text.setCharacterSize(13);
    Text.setFillColor(sf::Color::White);
    Text.setOrigin(getX(), getY() - 60);
    _TextCpuG = Text;
    return (true);
}

bool CpuG::initTextCpuGUse(void)
{
    _TextCpuGUse.setString("Usage: " + std::to_string(getCpuGUse()));
    _TextCpuGUse.setFont(_font);
    _TextCpuGUse.setCharacterSize(13);
    _TextCpuGUse.setFillColor(sf::Color::White);
    _TextCpuGUse.setOrigin(getX(), getY() - 80);
    return (true);
}

bool CpuG::initTextCpuGFrequency(void)
{
    _TextFrequency.setString("Freq: " + std::to_string(_freq) + "MHz");
    _TextFrequency.setFont(_font);
    _TextFrequency.setCharacterSize(13);
    _TextFrequency.setFillColor(sf::Color::White);
    _TextFrequency.setOrigin(getX(), getY() - 100);
    return (true);
}

void CpuG::refreshRectangles(float value)
{
    _size.y = - 3 * value;
    _rectCpuG.setSize(_size);
}

void CpuG::refresh(void)
{
    std::string value = std::to_string(getCpuGUse());
    value = value.substr(0, value.find(".") + 3);
    _TextCpuGUse.setString("Usage: " + value + " %");
    
    std::string freq = std::to_string(_freq);
    freq = freq.substr(0, freq.find(".") + 3);
    _TextFrequency.setString(freq + "MHz");
    refreshRectangles(getCpuGUse());
}

void CpuG::render(sf::RenderTarget &target)
{
    target.draw(_TextCpuG);
    target.draw(_TextFrequency);
    target.draw(_TextCpuGUse);
    target.draw(_TextLimit);
    target.draw(_rectCpuG);
    target.draw(_rectBase);
    target.draw(_rectTop);
}
