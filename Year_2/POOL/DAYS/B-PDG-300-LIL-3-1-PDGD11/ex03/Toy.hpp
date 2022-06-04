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
        enum ToyType {
            BASIC_TOY,
            ALIEN,
            BUZZ,
            WOODY
        };

        // CTOR & DTOR
        Toy();
        Toy(const Toy &ref_toy);
        Toy(ToyType type, const std::string &name, const std::string &filename);
        virtual ~Toy();

        // OPERTATORS
        Toy &operator=(const Toy &ref_toy);

        // GETTER
        int getType(void) const;
        std::string getName(void) const;
        std::string getAscii(void) const;

        // SETTER
        void setName(std::string name);
        bool setAscii(const std::string &filename);

        // MEMBER FUNCTIONS
        virtual void speak(const std::string &statement) const;

    protected:
        int _type;
        std::string _name;
        Picture _picture;
};

#endif /* !TOY_HPP_ */
