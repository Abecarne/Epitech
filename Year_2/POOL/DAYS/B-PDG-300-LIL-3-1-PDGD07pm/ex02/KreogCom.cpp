/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** KreogCom
*/

#include "KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial) :
    m_serial(serial)
{
    _x = x;
    _y = y;

    std::cout << "KreogCom " << m_serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << m_serial << " shutting down" << std::endl;
}

void KreogCom::addCom(int x, int y, int serial)
{
	KreogCom 	*new_elm = new KreogCom(x, y, serial);

	new_elm->_nextCom = this->_nextCom;
	this->_nextCom = new_elm;
}

void KreogCom::removeCom(void)
{
    KreogCom *tmp = this;
    KreogCom *del;

    if (this->_nextCom != nullptr) {
        while (tmp->_nextCom->_nextCom != nullptr) {
            tmp = tmp->_nextCom;
        }
        delete tmp->_nextCom;
        tmp->_nextCom = nullptr;
    }
}

KreogCom *KreogCom::getCom(void)
{
    if (_nextCom == nullptr)
        return (nullptr);
    else
        return (_nextCom);
}

void KreogCom::ping(void)
{
    std::cout << "KreogCom " << m_serial << " currently at " << _x << " " << _y << std::endl;
}

void KreogCom::locateSquad(void)
{
    if (this->_nextCom)
		this->_nextCom->locateSquad();	
	this->ping();
}
