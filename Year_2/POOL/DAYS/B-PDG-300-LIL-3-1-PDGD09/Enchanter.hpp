/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** Enchanter
*/

#ifndef ENCHANTER_HPP_
#define ENCHANTER_HPP_

#include "Peasant.hpp"

class Enchanter : public virtual Peasant {
    public:
        Enchanter(const std::string &name, int power);
        ~Enchanter();
        int attack(void);
        int special(void);
        void rest(void);
};

#endif /* !ENCHANTER_HPP_ */
