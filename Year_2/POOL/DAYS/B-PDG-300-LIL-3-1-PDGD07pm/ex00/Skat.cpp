/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** Skat
*/

#include "Skat.hpp"

// ~~~~~~~~~~~~~~~~~~ Skat Class ~~~~~~~~~~~~~~~~~~~~~~~~~
Skat::Skat(const std::string &name , int stimPaks)
{
    _name = name;
    _stimpaks = stimPaks;
}

Skat::~Skat()
{
}

int &Skat::stimPaks(int stimpaks)
{
    _stimpaks = stimpaks;
    return (_stimpaks);
}

int &Skat::stimPaks(void)
{
    return (_stimpaks);
}

const std::string &Skat::name(void)
{
    return (_name);
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (number > _stimpaks)
        std::cout << "Don't be greedy" << std::endl;
    else {
        _stimpaks -= number;
        stock += number;
        std::cout << "Keep the change." << std::endl;
    }
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0) {
        std::cout << "Hey boya, did you forget something?" << std::endl;
    } else {
        _stimpaks += number;
    }
}

void Skat::useStimPaks(void)
{
    if (_stimpaks > 0) {
        _stimpaks--;
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
    } else {
        std::cout << "Mediiiiiic" << std::endl;
    }
}

void Skat::status(void)
{
    std::cout << "Soldier " <<  _name << " reporting " << _stimpaks << " stimpaks remaining sir!" << std::endl;
}
// ~~~~~~~~~~~~~~~~ End of Skat Class ~~~~~~~~~~~~~~~~~~~~~
