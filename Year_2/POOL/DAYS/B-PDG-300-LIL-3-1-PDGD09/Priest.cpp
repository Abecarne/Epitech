/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** Priest
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name, int power) :
    Peasant(name, power),
    Enchanter(name, power)
{
    std::cout << _name << " enters in the order." << std::endl;
}

Priest::~Priest()
{
    std::cout << _name << " finds peace." << std::endl;
}

void Priest::rest(void)
{
    if (_hp <= 0)
        std::cout << _name << " is out of combat." << std::endl;
    else {
        std::cout << _name << " prays." << std::endl;
        _power = std::min(_power + 100, 100);
        _hp = std::min(_hp + 100, 100);
    }
}