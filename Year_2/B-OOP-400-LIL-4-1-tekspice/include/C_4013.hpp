/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** C_4013
*/

#include "Header.hpp"

#ifndef C_4013_HPP_
#define C_4013_HPP_

class C_4013 : public Component {
    public:
        C_4013(std::string name);
        ~C_4013();

        const std::vector<int> _validInputs = {3, 4, 5, 6, 8, 9, 10, 11};
        const std::vector<int> _validOutputs = {1, 2, 12, 13};
};

#endif /* !C_4013_HPP_ */
