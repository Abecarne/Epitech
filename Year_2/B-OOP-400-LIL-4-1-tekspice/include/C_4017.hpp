/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** C_4017
*/

#include "Header.hpp"

#ifndef C_4017_HPP_
#define C_4017_HPP_

class C_4017 : public Component {
    public:
        C_4017(std::string name);
        ~C_4017();

        const std::vector<int> _validInputs = {13, 14, 15};
        const std::vector<int> _validOutputs = {1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12};
};

#endif /* !C_4017_HPP_ */
