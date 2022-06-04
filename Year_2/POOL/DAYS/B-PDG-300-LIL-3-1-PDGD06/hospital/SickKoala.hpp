/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** SickKoala
*/

#ifndef SICKKOALA_HPP_
#define SICKKOALA_HPP_

#include <iostream>

class SickKoala {
    public:
        SickKoala(std::string name);
        ~SickKoala(void);
        void poke(void);
        void takeDrugs(std::string drug);
        void overDrive(std::string);
        std::string getName(void);

    protected:
        std::string _name;
    private:
};

#endif /* !SICKKOALA_HPP_ */
