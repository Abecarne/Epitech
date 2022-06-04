/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** Parts
*/

#include "Parts.hpp"

// ~~~~~~~~~~~~~~~~~ Arms class ~~~~~~~~~~~~~~~~~~~
Arms::Arms(std::string serial, bool functional)
{
    _serial = serial;
    _functional = _functional;
}

Arms::~Arms()
{
}

bool Arms::isFunctional(void) const
{
    return (_functional);
}

std::string Arms::serial(void) const
{
    return (_serial);
}

void Arms::informations(void) const
{
    std::string is_functional = isFunctional() ? "OK" : "KO";
    std::cout << "\t[Parts] " << "Arms" << " " << _serial << " status : " << is_functional << std::endl;
}
// ~~~~~~~~~~~~~~ End of Arms class ~~~~~~~~~~~~~~~


// ~~~~~~~~~~~~~~~~~ Legs class ~~~~~~~~~~~~~~~~~~~
Legs::Legs(std::string serial, bool functional)
{
    _serial = serial;
    _functional = _functional;
}

Legs::~Legs()
{
}

bool Legs::isFunctional(void) const
{
    return (_functional);
}

std::string Legs::serial(void) const
{
    return (_serial);
}

void Legs::informations(void) const
{
    std::string is_functional = isFunctional() ? "OK" : "KO";
    std::cout << "\t[Parts] " << "Arms" << " " << _serial << " status : " << is_functional << std::endl;
}
// ~~~~~~~~~~~~~~ End of Legs class ~~~~~~~~~~~~~~~


// ~~~~~~~~~~~~~~~~~ Head class ~~~~~~~~~~~~~~~~~~~
Head::Head(std::string serial, bool functional)
{
    _serial = serial;
    _functional = _functional;
}

Head::~Head()
{
}

bool Head::isFunctional(void) const
{
    return (_functional);
}

std::string Head::serial(void) const
{
    return (_serial);
}

void Head::informations(void) const
{
    std::string is_functional = isFunctional() ? "OK" : "KO";
    std::cout << "\t[Parts] " << "Arms" << " " << _serial << " status : " << is_functional << std::endl;
}
// ~~~~~~~~~~~~~~ End of Head class ~~~~~~~~~~~~~~~