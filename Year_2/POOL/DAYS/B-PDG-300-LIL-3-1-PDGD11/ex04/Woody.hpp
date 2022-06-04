/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** Woody
*/

#ifndef WOODY_HPP_
#define WOODY_HPP_

#include "Toy.hpp"

class Woody : public Toy {
    public:
        Woody(std::string name, std::string ascii = "woody.txt");
        ~Woody();
        void speak(const std::string &statement) const override;
};

#endif /* !WOODY_HPP_ */
