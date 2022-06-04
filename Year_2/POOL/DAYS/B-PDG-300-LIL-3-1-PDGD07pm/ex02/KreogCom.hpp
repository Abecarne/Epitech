/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** KreogCom
*/

#ifndef KREOGCOM_HPP_
#define KREOGCOM_HPP_

#include <iostream>

class KreogCom {
    public:
        KreogCom(int x, int y, int serial);
        ~KreogCom();
        void addCom(int x, int y, int serial);
        void removeCom(void);
        KreogCom *getCom(void);
        void ping(void);
        void locateSquad(void);
        KreogCom *tmp (void) {return _nextCom;}
    private:
        const int m_serial;
        int _x;
        int _y;
        KreogCom *_nextCom = nullptr;
};

#endif /* !KREOGCOM_HPP_ */
