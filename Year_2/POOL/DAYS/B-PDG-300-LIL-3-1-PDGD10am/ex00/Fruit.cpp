/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** Fruit
*/

#include "Fruit.hpp"

Fruit::Fruit(std::string name, int vitamins) :
    _name(name)
{
    _vitamins = vitamins;
}

Fruit::~Fruit()
{
}

int Fruit::getVitamins(void) const
{
    return (_vitamins);
}

const std::string Fruit::getName(void) const
{
    return (_name);
}