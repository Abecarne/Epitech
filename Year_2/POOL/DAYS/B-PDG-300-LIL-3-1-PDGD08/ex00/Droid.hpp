/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** Droid
*/

#ifndef DROID_HPP_
#define DROID_HPP_

#include <iostream>

class Droid {
    public:
        Droid(std::string id = "");
        Droid(const Droid &droid);
        ~Droid();
        Droid &operator=(const Droid &droid);
        bool operator==(const Droid &droid) const;
        bool operator!=(const Droid &droid) const;
        Droid &operator<<(size_t &size);
        std::string getId(void) const;
        void setId(std::string id);
        size_t getEnergy(void) const;
        void setEnergy(size_t energy);
        size_t getAttack(void) const;
        size_t getToughness(void) const;
        std::string *getStatus(void) const;
        void setStatus(std::string *status);


    private:
        std::string _id;
        size_t _energy;
        const size_t _attack;
        const size_t _toughness;
        std::string *_status;
};

std::ostream &operator<<(std::ostream &target, const Droid &droid);

#endif /* !DROID_HPP_ */
