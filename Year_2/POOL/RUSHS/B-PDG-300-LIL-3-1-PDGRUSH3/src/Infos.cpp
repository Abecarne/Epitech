/*
** EPITECH PROJECT, 2022
** Documents
** File description:
** Infos
*/

#include "../include/header.hpp"

Infos::Infos() :
    Module()
{
}

Infos::~Infos()
{
}

// GETTER
std::string Infos::getDate(void) const { return (_date); }
std::string Infos::getVersion(void) const { return (_version); }
std::string Infos::getUserName(void) const { return (_username); }
std::string Infos::getHostName(void) const { return (_hostname); }
std::string Infos::getSystemName(void) const { return (_systemName); }

// SETTER
void Infos::setDate(std::string name) { _date = name; }
void Infos::setVersion(std::string name) { _version = name; }
void Infos::setHostName(std::string name) { _hostname = name; }
void Infos::setUserName(std::string name) { _username = name; }
void Infos::setSystemName(std::string name) { _systemName = name; }

void Infos::setAllInfos(void)
{
    std::ostringstream oss;
    std::string buff = "Date and time: ";
    oss << std::put_time(_infos.getDate(), "%A %d-%m-%Y %H:%M:%S");
    buff += oss.str();
    buff += " - Uptime: " + _infos.getRuntime();
    setDate(buff);
    setVersion(_infos.getCoreInfo().version);
    setUserName(_infos.getUserName());
    setHostName(_infos.getHostName());
    setSystemName(_infos.getCoreInfo().sysname);
}

void Infos::initAll(void)
{
    setAllInfos();
    initTextDate();
    initTextHostName();
    initTextsystemeName();
    initTextUserName();
    initTextVersion();
}

bool Infos::initTextHostName()
{
    sf::Text Text;
    Text.setString("Hostname: " + getHostName());
    Text.setFont(_font);
    Text.setCharacterSize(18);
    Text.setFillColor(sf::Color::White);
    Text.setOrigin(0, 0);
    _TextHostname = Text;
    return (true);
}

bool Infos::initTextUserName()
{
    sf::Text Text;
    Text.setString("Username: " + getUserName());
    Text.setFont(_font);
    Text.setCharacterSize(18);
    Text.setFillColor(sf::Color::White);
    Text.setOrigin(0, -21.);
    _TextUsername = Text;
    return (true);
}

bool Infos::initTextsystemeName()
{
    sf::Text Text;
    Text.setString("System name: " + getSystemName());
    Text.setFont(_font);
    Text.setCharacterSize(18);
    Text.setFillColor(sf::Color::White);
    Text.setOrigin(0., -1660.);
    _TextSystemName = Text;
    return (true);
}

bool Infos::initTextVersion()
{
    sf::Text Text;
    Text.setString("Version: " + getVersion());
    Text.setFont(_font);
    Text.setCharacterSize(18);
    Text.setFillColor(sf::Color::White);
    Text.setOrigin(0., -770.);
    _TextVersion = Text;
    return (true);
}

bool Infos::initTextDate()
{
    sf::Text Text;
    Text.setString(getDate());
    Text.setFont(_font);
    Text.setCharacterSize(18);
    Text.setFillColor(sf::Color::White);
    Text.setPosition(1450, 770);
    _TextDate = Text;
    return (true);
}

void Infos::refresh(void)
{
    std::ostringstream oss;
    std::string buff;
    oss << std::put_time(_infos.getDate(), "%A %d-%m-%Y %H:%M:%S");
    buff += oss.str();
    buff += " - Uptime: " + _infos.getRuntime();
    _TextDate.setString(buff);
}

void Infos::render(sf::RenderTarget &target)
{
    target.draw(_TextUsername);
    target.draw(_TextHostname);
    target.draw(_TextSystemName);
    target.draw(_TextVersion);
    target.draw(_TextDate);
}