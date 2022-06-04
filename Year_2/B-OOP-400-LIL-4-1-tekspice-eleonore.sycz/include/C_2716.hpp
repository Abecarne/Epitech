/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** C_2716
*/

#include "Header.hpp"

#ifndef C_2716_HPP_
#define C_2716_HPP_

class C_2716 : public Component {
    public:
        C_2716(std::string name);
        ~C_2716();
        const std::vector<int> _validInputs = {19, 22, 23, 1 ,2, 3, 4, 5, 6, 7, 8};
        const std::vector<int> _validOutputs = {9, 10, 11, 13, 14, 15, 16, 17};
};

#endif /* !C_2716_HPP_ */
