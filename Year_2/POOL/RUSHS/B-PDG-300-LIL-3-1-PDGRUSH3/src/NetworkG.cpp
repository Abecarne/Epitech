/*
** EPITECH PROJECT, 2022
** Documents
** File description:
** NetworkG
*/

#include "../include/header.hpp"

NetworkG::NetworkG(std::string name, int x) :
    Module(name)
{
    setY(x);
    initAll();
}

NetworkG::~NetworkG()
{
}

void NetworkG::setBytesSent(std::string name) { _byteSent = name; }
void NetworkG::setPaquetSent(std::string name) { _paquetSent = name; }
void NetworkG::setNetworkName(std::string name) { _networkName = name; }
void NetworkG::setBytesReceived(std::string name) { _byteReceived = name; }
void NetworkG::setPaquetReceived(std::string name) { _paquetReceived = name; }

std::string NetworkG::getBytesSent(void) { return (_byteSent); }
std::string NetworkG::getPaquetSent(void) { return (_paquetSent); }
std::string NetworkG::getNetworkName(void) { return (_networkName); }
std::string NetworkG::getBytesReceived(void) { return (_byteReceived); }
std::string NetworkG::getPaquetReceived(void) { return (_paquetReceived); }

void NetworkG::initNetworkName(void)
{
    _TextNetworkName.setString("0");
    _TextNetworkName.setPosition(600, -getY());
    _TextNetworkName.setFont(_font);
    _TextNetworkName.setCharacterSize(13);
    _TextNetworkName.setFillColor(sf::Color::White);
    _TitleNetworkName.setString("Network Name:");
    _TitleNetworkName.setPosition(600, 50);
    _TitleNetworkName.setFont(_font);
    _TitleNetworkName.setCharacterSize(13);
    _TitleNetworkName.setFillColor(sf::Color::White);
}

void NetworkG::initNetworkPaquetReceived(void)
{
    _TextPaquetReceived.setString("0");
    _TextPaquetReceived.setPosition(700, -getY());
    _TextPaquetReceived.setFont(_font);
    _TextPaquetReceived.setCharacterSize(13);
    _TextPaquetReceived.setFillColor(sf::Color::White);
    _TitlePaquetReceived.setString("Paquets received:");
    _TitlePaquetReceived.setPosition(700, 50);
    _TitlePaquetReceived.setFont(_font);
    _TitlePaquetReceived.setCharacterSize(13);
    _TitlePaquetReceived.setFillColor(sf::Color::White);
}

void NetworkG::initNetworkPaquetSent(void)
{
    _TextPaquetSent.setString("0");
    _TextPaquetSent.setPosition(850, -getY());
    _TextPaquetSent.setFont(_font);
    _TextPaquetSent.setCharacterSize(13);
    _TextPaquetSent.setFillColor(sf::Color::White);
    _TitlePaquetSent.setString("Bytes received:");
    _TitlePaquetSent.setPosition(850, 50);
    _TitlePaquetSent.setFont(_font);
    _TitlePaquetSent.setCharacterSize(13);
    _TitlePaquetSent.setFillColor(sf::Color::White);
}

void NetworkG::initNetworkBytesReceived(void)
{
    _TextByteReceived.setString("0");
    _TextByteReceived.setPosition(1000, -getY());
    _TextByteReceived.setFont(_font);
    _TextByteReceived.setCharacterSize(13);
    _TextByteReceived.setFillColor(sf::Color::White);
    _TitleBytesReceived.setString("Paquets sent:");
    _TitleBytesReceived.setPosition(1000, 50);
    _TitleBytesReceived.setFont(_font);
    _TitleBytesReceived.setCharacterSize(13);
    _TitleBytesReceived.setFillColor(sf::Color::White);
}

void NetworkG::initNetworkBytesSent(void)
{
    _TextByteSent.setString("0");
    _TextByteSent.setPosition(1150, -getY());
    _TextByteSent.setFont(_font);
    _TextByteSent.setCharacterSize(13);
    _TextByteSent.setFillColor(sf::Color::White);
    _TitleBytesSent.setString("Bytes sent:");
    _TitleBytesSent.setPosition(1150, 50);
    _TitleBytesSent.setFont(_font);
    _TitleBytesSent.setCharacterSize(13);
    _TitleBytesSent.setFillColor(sf::Color::White);
}


void NetworkG::initAll(void)
{
    initNetworkName();
    initNetworkPaquetReceived();
    initNetworkPaquetSent();
    initNetworkBytesReceived();
    initNetworkBytesSent();
}

void NetworkG::refresh()
{
    _TextNetworkName.setString(getNetworkName());
    _TextPaquetReceived.setString(getPaquetReceived());
    _TextByteReceived.setString(getBytesReceived());
    _TextPaquetSent.setString(getPaquetSent());
    _TextByteSent.setString(getBytesSent());
}

void NetworkG::render(sf::RenderTarget &target)
{
    target.draw(_TextNetworkName);
    target.draw(_TextPaquetReceived);
    target.draw(_TextPaquetSent);
    target.draw(_TextByteReceived);
    target.draw(_TextByteSent);
    target.draw(_TitleNetworkName);
    target.draw(_TitlePaquetReceived);
    target.draw(_TitlePaquetSent);
    target.draw(_TitleBytesReceived);
    target.draw(_TitleBytesSent);
}
