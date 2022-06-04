/*
** EPITECH PROJECT, 2022
** CPP pool rush3
** File description:
** info class to get all the structs and classes
*/

#include "../include/header.hpp"

long double findValue(std::ifstream &ram, char const *toFind)
{
    std::string line;
    std::string word;
    long double val = 0;

    do {
        getline(ram, line);
    } while (line.find(toFind) != 0 && ram.eof() == false);

    std::istringstream sstream(line);
    while (sstream >> word) {
        val = std::strtold(word.c_str(), nullptr);
        if (val != 0.0L)
            break;
    }

    return (val);
}

RamCore::RamCore(void)
{
    this->refresh();
}

long double RamCore::convertKibi(long double kibi) const
{
    return (KIBITOGIBI * kibi);
}


//-------------------------------Getters---------------------------------------

    //-------------------------------RAM---------------------------------------

    long double RamCore::getTotMem(void) const
    {
        return (this->_totMem);
    }

    long double RamCore::getFreeMem(void) const
    {
        return (this->_freeMem);
    }

    long double RamCore::getUsedMem(void) const
    {
        return (this->_usedMem);
    }

    //-------------------------------SWAP--------------------------------------
        long double RamCore::getTotSwap(void) const
        {
            return (this->_totSwap);
        }

        long double RamCore::getFreeSwap(void) const
        {
            return (this->_freeSwap);
        }

        long double RamCore::getUsedSwap(void) const
        {
            return (this->_usedSwap);
        }

//------------------------------End of Getters---------------------------------

void RamCore::refresh(void)
{
    std::ifstream ram("/proc/meminfo");
    long double val;

    if (ram.is_open() == false)
        return;
    val = findValue(ram, "MemTotal:");
    this->_totMem = convertKibi(val);
    val = findValue(ram, "MemAvailable:");
    this->_freeMem = convertKibi(val);
    val = this->_totMem - this->_freeMem;
    this->_usedMem = val;

    val = findValue(ram, "SwapTotal:");
    this->_totSwap = convertKibi(val);
    val = findValue(ram, "SwapFree:");
    this->_freeSwap = convertKibi(val);
    this->_usedSwap = this->_totSwap - this->_freeSwap;
    ram.close();
}