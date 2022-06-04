/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** C_output
*/

#include "Header.hpp"

#ifndef C_OUTPUT_HPP_
#define C_OUTPUT_HPP_

class C_output : public Component {
    public:
        C_output(std::string name);
        ~C_output();

    private:
        int _state = nts::UNDEFINED;
};

#endif /* !C_OUTPUT_HPP_ */
