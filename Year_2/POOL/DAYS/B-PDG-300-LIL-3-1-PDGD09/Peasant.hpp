/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** Peasant
*/

#ifndef PEASANT_HPP_
#define PEASANT_HPP_

#include <iostream>
#include "ICharacter.hpp"

class Peasant : public ICharacter {
    public:
        Peasant(const std::string &name, int power);
        ~Peasant();
        const std::string &getName(void) const;
        int getPower(void) const;
        int getHp(void) const;
        int attack(void);
        int special(void);
        void rest(void);
        void damage(int damage);

    protected:
        std::string _name;
        int _power;
        int _hp;
};

#endif /* !PEASANT_HPP_ */
