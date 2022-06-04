/*
** EPITECH PROJECT, 2022
** B-PDG-300-LIL-3-1-PDGRUSH3-pierre-jean.descarpentries
** File description:
** Core
*/

#include "../include/header.hpp"

Network::Network()
{
    this->refresh();
}

void Network::refresh(void)
{
    std::string line;
    std::ifstream network ("/proc/net/dev");

    this->_names.clear();
    this->_networkRc.clear();
    this->_networkTr.clear();
    getline(network, line);
    getline(network, line);
    do {
        getline(network, line);
        this->parser(line);
    } while (network.eof() == false);
    this->_names.erase(this->_names.end());
    this->_networkRc.erase(this->_networkRc.end());
    this->_networkTr.erase(this->_networkTr.end());
}

void Network::parser(std::string line)
{
    std::istringstream sstream(line);
    std::string word;

    size_t tmpByte;
    size_t tmpPack;
    std::string name;
    sstream >> name;
    sstream >> tmpByte;
    sstream >> tmpPack;

    this->newNet(name, tmpByte, tmpPack, false);
    for (int i = 0; i < 5; i++)
        sstream >> name;

    sstream >> name;
    sstream >> tmpByte;
    sstream >> tmpPack;
    this->newNet(name, tmpByte, tmpPack, true);
}

void Network::newNet(std::string name, size_t tmpByte, size_t tmpPack, bool tr)
{
    std::pair<size_t, size_t> tmp(tmpByte, tmpPack);

    if (tr == false) {
        this->_names.push_back(name);
        this->_networkRc.push_back(tmp);
    } else {
        this->_networkTr.push_back(tmp);
    }
}

std::vector<std::pair<size_t, size_t>> Network::getRC(void) const
{
    return (this->_networkRc);
}

std::vector<std::pair<size_t, size_t>> Network::getTr(void) const
{
    return (this->_networkTr);
}

std::vector<std::string> Network::getNames(void) const
{
    return (this->_names);
}
