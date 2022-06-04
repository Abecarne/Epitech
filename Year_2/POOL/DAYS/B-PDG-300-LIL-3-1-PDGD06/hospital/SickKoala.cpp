/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** SickKoala
*/

#include "SickKoala.hpp"

SickKoala::SickKoala(std::string name)
{
    _name = name;
}

SickKoala::~SickKoala()
{
    std::cout << "Mr." << _name << ": Kreooogg !! I'm cuuuured!" << std::endl;
}

void SickKoala::poke(void)
{
    std::cout << "Mr." << _name << ": Gooeeeeerrk !!" << std::endl;
}

void SickKoala::takeDrugs(std::string drug)
{
    if (drug == "Mars")
        std::cout << "Mr." << _name << ": Mars, and it kreogs!" << std::endl;
    else if (drug == "Kinder")
        std::cout << "Mr." << _name << ": There is a toy inside!" << std::endl;
    else
        std::cout << "Mr." << _name << ": Goerkreog!" << std::endl;
}

void SickKoala::overDrive(std::string over_drive)
{
    while (over_drive.find("Kreog!") < over_drive.length())
        over_drive.replace(over_drive.find("Kreog!"), 6, "1337!");

    std::cout << "Mr." << _name << ": " << over_drive << std::endl;
}

std::string SickKoala::getName(void)
{
    return (_name);
}