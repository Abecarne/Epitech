/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** ICharacter
*/

#ifndef ICHARACTER_HPP_
#define ICHARACTER_HPP_

class ICharacter {
    public:
        virtual ~ICharacter() {};
        virtual const std::string &getName(void) const = 0;
        virtual int getPower(void) const = 0;
        virtual int getHp(void) const = 0;
        virtual int attack() = 0;
        virtual int special() = 0;
        virtual void rest() = 0;
        virtual void damage(int damage) = 0;
};

#endif /* !ICHARACTER_HPP_ */
