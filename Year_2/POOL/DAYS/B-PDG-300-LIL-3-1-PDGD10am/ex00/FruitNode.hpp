/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** FruitNode
*/

#ifndef FRUITNODE_HPP_
#define FRUITNODE_HPP_

#include "Fruit.hpp"

typedef struct FruitNode_s FruitNode;

struct FruitNode_s
{
    Fruit *current_fruit;
    FruitNode *next;
};

#endif /* !FRUITNODE_HPP_ */
