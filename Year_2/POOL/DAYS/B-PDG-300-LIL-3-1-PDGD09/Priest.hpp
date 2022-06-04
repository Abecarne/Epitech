/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** Priest
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include "Enchanter.hpp"

class Priest : public Enchanter {
    public:
        Priest(const std::string &name, int power);
        ~Priest();
        void rest(void);

};

#endif /* !PRIEST_HPP_ */
