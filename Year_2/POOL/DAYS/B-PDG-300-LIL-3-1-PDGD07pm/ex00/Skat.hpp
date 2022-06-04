/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** Skat
*/

#ifndef SKAT_HPP_
#define SKAT_HPP_

#include <iostream>

class Skat {
    public:
        Skat(const std::string &name = "bob", int stimPaks = 15);
        ~Skat();
        int &stimPaks(int stimpaks);
        int &stimPaks();
        const std::string &name(void);
        void shareStimPaks(int number, int &stock);
        void addStimPaks(unsigned int number);
        void useStimPaks(void);
        void status(void);
        void informations(void);

    private:
        int _stimpaks;
        std::string _name;
};

#endif /* !SKAT_HPP_ */
