/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** C_4001
*/

#include "Header.hpp"

#ifndef C_4001_HPP_
#define C_4001_HPP_

class C_4001 : public Component {
    public:
        C_4001(std::string name);
        ~C_4001();
        
        const std::vector<int> _validInputs = {1, 2, 5, 6, 8, 9, 12, 13};
        const std::vector<int> _validOutputs = {3, 4, 10, 11};
};

#endif /* !C_4001_HPP_ */
