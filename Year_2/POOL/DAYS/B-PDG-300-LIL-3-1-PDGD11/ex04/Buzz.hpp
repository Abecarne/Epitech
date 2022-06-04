/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : public Toy {
    public:
        Buzz(std::string name, std::string ascii = "buzz.txt");
        ~Buzz();

        // MEMBER FUNCTIONS
        void speak(const std::string &statement) const override;
};

#endif /* !BUZZ_HPP_ */
    