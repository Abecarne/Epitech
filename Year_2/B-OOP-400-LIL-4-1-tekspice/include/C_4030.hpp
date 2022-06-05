/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** C_4030
*/

#include "Header.hpp"

#ifndef C_4030_HPP_
#define C_4030_HPP_

class C_4030 : public Component {
    public:
        C_4030(std::string name);
        ~C_4030();
        
        const std::vector<int> _validInputs = {1, 2, 5, 6, 8, 9, 12, 13};
        const std::vector<int> _validOutputs = {3, 4, 10, 11};
};

#endif /* !C_4030_HPP_ */
