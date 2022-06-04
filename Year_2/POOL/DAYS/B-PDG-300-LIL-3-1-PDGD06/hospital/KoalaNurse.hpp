/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** KoalaNurse
*/

#ifndef KOALANURSE_HPP_
#define KOALANURSE_HPP_

#include "SickKoala.hpp"

class KoalaNurse {
    public:
        KoalaNurse(int id);
        ~KoalaNurse();
        void giveDrug(std::string drug, SickKoala *koala);
        std::string readReport(std::string report);
        void timeCheck(void);
        int getID(void);

    private:
        int _id;
        bool _nurseWorks = false;
};

#endif /* !KOALANURSE_HPP_ */
