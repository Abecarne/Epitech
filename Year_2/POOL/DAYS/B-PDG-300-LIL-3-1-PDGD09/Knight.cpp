/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** Knight
*/

#include "Knight.hpp"

Knight::Knight(const std::string &name, int power) :
    Peasant(name, power)
{
    std::cout << _name << " vows to protect the kingdom." << std::endl;
}

Knight::~Knight()
{
    std::cout << _name << " takes off his armor." << std::endl;
}

int Knight::attack(void)
{
    if (_hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return (0);
    } else if (_power < 10) {
        std::cout << _name << " is out of power." << std::endl;
        return (0);
    } else {
        std::cout << _name << " strikes with his sword." << std::endl;
        _power = std::max(_power- 10, 0);
        return (20);
    }
    
}

int Knight::special(void)
{
    if (_hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return (0);
    }
    else if (_power < 30) {
        std::cout << _name << " is out of power." << std::endl;
        return (0);
    } else {
        _power = std::max(_power- 30, 0);
        std::cout << _name << " impales his enemy." << std::endl;
        return (50);
    }
}

void Knight::rest(void)
{
    if (_hp <= 0)
        std::cout << _name << " is out of combat." << std::endl;
    else {
        std::cout << _name << " eats." << std::endl;
        _power = std::min(_power + 50, 100);
    }
}