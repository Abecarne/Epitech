/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** C_4069
*/

#include "Header.hpp"

#ifndef C_4069_HPP_
#define C_4069_HPP_

class C_4069 : public Component {
    public:
        C_4069(std::string name);
        ~C_4069();

        const std::vector<int> _validInputs = {1, 2, 5, 6, 8, 9, 12, 13};
        const std::vector<int> _validOutputs = {3, 4, 10, 11};
};

#endif /* !C_4069_HPP_ */
