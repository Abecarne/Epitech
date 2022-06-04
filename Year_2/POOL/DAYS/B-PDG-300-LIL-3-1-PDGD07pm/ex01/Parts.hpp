/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** Parts
*/

#ifndef PARTS_HPP_
#define PARTS_HPP_

#include <iostream>

class Arms {
    public:
        Arms(std::string serial = "A-01", bool functional = true);
        ~Arms();
        bool isFunctional(void) const;
        std::string serial(void) const;
        void informations(void) const;

    private:
        std::string _serial;
        bool _functional;
};

class Legs {
    public:
        Legs(std::string serial = "L-01", bool functional = true);
        ~Legs();
        bool isFunctional(void) const;
        std::string serial(void) const;
        void informations(void) const;

    private:
        std::string _serial;
        bool _functional;
};

class Head {
    public:
        Head(std::string serial = "H-01", bool functional = true);
        ~Head();
        bool isFunctional(void) const;
        std::string serial(void) const;
        void informations(void) const;

    private:
        std::string _serial;
        bool _functional;
};

#endif /* !PARTS_HPP_ */
