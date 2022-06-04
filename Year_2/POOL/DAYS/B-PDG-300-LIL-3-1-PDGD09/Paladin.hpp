/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** Paladin
*/

#ifndef PALADIN_HPP_
#define PALADIN_HPP_

#include "Priest.hpp"
#include "Knight.hpp"

class Paladin : public Knight, public Priest {
    public:
        Paladin(const std::string &name, int power);
        ~Paladin();
        int attack(void);
        int special(void);
        void rest(void);
        // using Knight::attack;
        // using Enchanter::special;
        // using Priest::rest;
};

#endif /* !PALADIN_HPP_ */
