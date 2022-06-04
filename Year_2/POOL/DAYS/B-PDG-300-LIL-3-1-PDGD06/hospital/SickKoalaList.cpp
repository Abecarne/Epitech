/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** SickKoalaList
*/

#include "SickKoalaList.hpp"
#include "SickKoala.hpp"

SickKoalaList::SickKoalaList(SickKoala *koala)
{
    _koala = koala;
}

SickKoalaList::~SickKoalaList()
{
}

bool SickKoalaList::isEnd(void)
{
    return (_next == nullptr);
}

void SickKoalaList::append(SickKoalaList *koalas)
{
    if (_next == nullptr)
        _next = koalas;
    else
        _next->append(koalas);
        
}

SickKoala *SickKoalaList::getFromName(std::string searched_name)
{
    // if (searched_name == _koala->getName())
    //     return (_koala);
    // else if (_next == nullptr)
    //     return (nullptr);
    // else    
    //     return (_next->getFromName(searched_name));
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *not_wanted_koala)
{
    // SickKoalaList *current = this;

    // if (not_wanted_koala)

}

SickKoalaList *SickKoalaList::removeFromName(std::string)
{

}

SickKoalaList *SickKoalaList::getContent(void)
{

}

SickKoalaList *SickKoalaList::getNext(void)
{

}

void SickKoalaList::dump(void)
{

}
