/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size) :
    _size(size),
    _nbFruits(0),
    _nodes(nullptr)
{

}

FruitBox::~FruitBox()
{
    FruitNode *tmp = _nodes;

    if (_nodes == nullptr)
        return;
    while (tmp->next != nullptr) {
        delete _nodes;
        tmp = tmp->next;
    }
    delete tmp;
}

int FruitBox::nbFruits(void) const
{
    return (_nbFruits);
}

bool FruitBox::putFruit(Fruit *f)
{
    if (this->nbFruits() >= _size)
        return (false);

    FruitNode *new_node = new FruitNode;
    new_node->next = nullptr;
    if (!_nodes) {
        _nodes = new_node;
        new_node->current_fruit = f;
        _nbFruits++;
        return (true);
    }
    FruitNode *tmp = _nodes;

    while (tmp->next != nullptr) {
        if (tmp->current_fruit == f) {
            delete new_node;
            return (false);
        }
        tmp = tmp->next;
    }
    if (!tmp->next && tmp->current_fruit == f)
        return (false);
    tmp->next = new FruitNode;
    tmp->next->next = nullptr;
    tmp->next->current_fruit = f;
    _nbFruits++;
    return (true);
}

Fruit *FruitBox::pickFruit(void)
{
    if (!_nodes)
        return (nullptr);
    Fruit *tmp = _nodes->current_fruit;
    FruitNode *del = _nodes;
    if (!_nodes->next) {
        delete _nodes;
        _nodes = nullptr;
    } else {
        _nodes = _nodes->next;
        delete del;
    }
    _nbFruits--;
    return (tmp);
}

FruitNode *FruitBox::head(void) const
{
    return (_nodes);
}
