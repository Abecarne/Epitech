/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** Enchanter
*/

#include "Enchanter.hpp"

Enchanter::Enchanter(const std::string &name, int power) :
    Peasant(name, power)
{
    std::cout << _name << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter()
{
    std::cout << _name << " closes his spellbook." << std::endl;
}

int Enchanter::attack(void)
{
    if (_hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return (0);
    } else {
        std::cout << _name << " doesn't know how to fight." << std::endl;
        return (0);
    }
    
}

int Enchanter::special(void)
{
    if (_hp <= 0) {
        std::cout << _name << " is out of combat." << std::endl;
        return (0);
    }
    else if (_power < 50) {
        std::cout << _name << " is out of power." << std::endl;
        return (0);
    } else {
        _power = std::max(_power - 50, 0);
        std::cout << _name << " casts a fireball." << std::endl;
        return (99);
    }
}

void Enchanter::rest(void)
{
    if (_hp <= 0)
        std::cout << _name << " is out of combat." << std::endl;
    else {
        std::cout << _name << " meditates." << std::endl;
        _power = std::min(_power + 100, 100);
    }
}
