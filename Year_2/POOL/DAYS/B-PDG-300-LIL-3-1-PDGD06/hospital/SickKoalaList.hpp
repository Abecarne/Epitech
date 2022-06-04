/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** SickKoalaList
*/

#ifndef SICKKOALALIST_HPP_
#define SICKKOALALIST_HPP_

#include "SickKoala.hpp"

class SickKoalaList {
    public:
        SickKoalaList(SickKoala *koala);
        ~SickKoalaList();
        bool isEnd(void);
        void append(SickKoalaList *koalas);
        SickKoala *getFromName(std::string);
        SickKoalaList *remove(SickKoalaList *);
        SickKoalaList *removeFromName(std::string);
        SickKoalaList *getContent(void);
        SickKoalaList *getNext(void);
        void dump(void);

    private:
        SickKoala *_koala;
        SickKoalaList *_next = nullptr;
};

#endif /* !SICKKOALALIST_HPP_ */
