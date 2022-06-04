/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** Peasant
*/

#include "Peasant.hpp"

Peasant::Peasant(const std::string &name, int power) :
    _name(name),
    _power(std::min(power, 100)),
    _hp(100)
{
    std::cout << _name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant()
{
    std::cout << _name << " is back to his crops." << std::endl;
}

const std::string &Peasant::getName(void) const
{
    return (_name);
}

int Peasant::getPower(void) const
{
    return (_power);
}

int Peasant::getHp(void) const
{
    return (_hp);
}

int Peasant::attack(void)
{
    if (_hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return (0);
    } else if (_power < 10) {
        std::cout << _name << " is out of power." << std::endl;
        return (0);
    } else {
        std::cout << _name << " tosses a stone." << std::endl;
        _power -= 10;
        return (5);
    }
    
}

int Peasant::special(void)
{
    if (_hp <= 0)
        std::cout << _name << " is out of combat." << std::endl;
    else
        std::cout << _name << " doesn't know any special move." << std::endl;
    return (0);
}

void Peasant::rest(void)
{
    if (_hp <= 0)
        std::cout << _name << " is out of combat." << std::endl;
    else {
        std::cout << _name << " takes a nap." << std::endl;
        _power = std::min(_power + 30, 100);
    }
}

void Peasant::damage(int damage)
{
    _hp = std::max(_hp - damage, 0);
    if (_hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
    } else {
        std::cout << _name << " takes " << damage << " damage." << std::endl;
    }
}
