/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** Fruit
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include <iostream>

class Fruit {
    public:
        Fruit(std::string name, int vitamins);
        ~Fruit();
        int getVitamins(void) const;
        const std::string getName(void) const;

    protected:
        const std::string _name;
        int _vitamins;
};

#endif /* !FRUIT_HPP_ */