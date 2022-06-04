/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** KoalaBot
*/

#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string serial)
{
    _serial = serial;
}

KoalaBot::~KoalaBot()
{
}

void KoalaBot::setParts(const Arms &arms)
{
    _arms = arms;
}

void KoalaBot::setParts(const Legs &legs)
{
    _legs = legs;
}

void KoalaBot::setParts(const Head &head)
{
    _head = head;
}

void KoalaBot::swapParts(Arms &arms)
{
    setParts(arms);
}

void KoalaBot::swapParts(Legs &legs)
{
    setParts(legs);
}

void KoalaBot::swapParts(Head &head)
{
    setParts(head);
}

void KoalaBot::informations(void) const
{
    std::cout << "[KoalaBot] " << _serial << std::endl;
    _arms.informations();
    _legs.informations();
    _head.informations();
}

bool KoalaBot::status(void) const
{
    return (_arms.isFunctional() && _legs.isFunctional() && _head.isFunctional());
}
