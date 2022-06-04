/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include "Fruit.hpp"
#include "FruitNode.hpp"

class FruitBox {
    public:
        FruitBox(int size);
        ~FruitBox();
        int nbFruits(void) const;
        bool putFruit(Fruit *f);
        Fruit *pickFruit(void);
        FruitNode *head(void) const;

    private:
        int _size;
        int _nbFruits;
        FruitNode *_nodes;
};

#endif /* !FRUITBOX_HPP_ */
