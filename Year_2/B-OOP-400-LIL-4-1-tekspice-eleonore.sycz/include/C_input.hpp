/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** C_input
*/

#include "Header.hpp"

#ifndef C_INPUT_HPP_
#define C_INPUT_HPP_

class C_input : public Component {
    public:
        C_input(std::string name);
        ~C_input();

    private:
        int _state = nts::UNDEFINED;
};

#endif /* !C_INPUT_HPP_ */
