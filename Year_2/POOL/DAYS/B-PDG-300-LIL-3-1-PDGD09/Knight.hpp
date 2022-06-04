/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** Knight
*/

#ifndef KNIGHT_HPP_
#define KNIGHT_HPP_

#include "Peasant.hpp"

class Knight : public virtual Peasant {
    public:
        Knight(const std::string &name, int power);
        ~Knight();
        int attack(void);
        int special(void);
        void rest(void);
};

#endif /* !KNIGHT_HPP_ */
