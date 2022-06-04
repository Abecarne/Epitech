/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** Paladin
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int power) :
    Peasant(name, power),
    Knight(name, power),
    Priest(name, power)
{
    std::cout << _name << " fights for the light." << std::endl;
}

Paladin::~Paladin()
{
    std::cout << _name << " is blessed." << std::endl;
}

int Paladin::attack(void)
{
    return Knight::attack();
}

int Paladin::special(void)
{
    return Enchanter::special();
}

void Paladin::rest(void)
{
    Priest::rest();
}