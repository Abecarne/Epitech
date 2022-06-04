/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** C_4008
*/

#include "Header.hpp"

#ifndef C_4008_HPP_
#define C_4008_HPP_

class C_4008 : public Component {
    public:
        C_4008(std::string name);
        ~C_4008();

        const std::vector<int> _validInputs = {15, 1, 2, 5, 6, 7, 9};
        const std::vector<int> _validOutputs = {10, 11, 12, 13, 14};
};

#endif /* !C_4008_HPP_ */
