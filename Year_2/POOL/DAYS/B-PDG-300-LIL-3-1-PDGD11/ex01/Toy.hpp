/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include <iostream>
#include "Picture.hpp"

class Toy {
    public:
        enum ToyType {BASIC_TOY, ALIEN};
        Toy(ToyType type, const std::string &name, const std::string &filename);
        Toy(const Toy &ref_toy);
        Toy();
        ~Toy();
        Toy &operator=(const Toy &ref_toy);
        int getType(void) const;
        std::string getName(void) const;
        void setName(std::string name);
        bool setAscii(const std::string &filename);
        std::string getAscii(void) const;

    private:
        int _type;
        std::string _name;
        Picture _picture;
};

#endif /* !TOY_HPP_ */
