/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** C_4011
*/

#include "Header.hpp"

#ifndef C_4011_HPP_
#define C_4011_HPP_

class C_4011 : public Component {
    public:
        C_4011(std::string name);
        ~C_4011();

        const std::vector<int> _validInputs = {1, 2, 5, 6, 8, 9, 12, 13};
        const std::vector<int> _validOutputs = {3, 4, 10, 11};
};

#endif /* !C_4011_HPP_ */
