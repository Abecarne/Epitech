/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** Algorithm
*/

#ifndef ALGORITHM_HPP_
#define ALGORITHM_HPP_

#include <iostream>

template<typename T>
void swap(T& a, T& b)
{
    T c = a;
    a = b;
    b = c;
}

template<typename T>
T min(T a, T b)
{
    if (a < b) {
        return (a);
    }
    return (b);
}

template<typename T>
T max(T a, T b)
{
    if (a < b) {
        return (b);
    }
    return (a);
}

template<typename T>
T clamp(T value, T min, T max)
{
    if (value < min)
        return (min);
    else if (max < value)
        return (max);
    return (value);
}

#endif /* !ALGORITHM_HPP_ */
