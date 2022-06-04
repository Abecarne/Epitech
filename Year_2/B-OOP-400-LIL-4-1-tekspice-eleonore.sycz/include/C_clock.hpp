/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** C_clock
*/

#include "Header.hpp"

#ifndef C_CLOCK_HPP_
#define C_CLOCK_HPP_

class C_clock : public Component {
    public:
        C_clock(std::string name);
        ~C_clock();
        size_t state;
};

#endif /* !C_CLOCK_HPP_ */
