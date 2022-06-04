/*
** EPITECH PROJECT, 2022
** Documents
** File description:
** Ram
*/

#ifndef RAM_HPP_
#define RAM_HPP_

#include "header.hpp"

class Ram : public Module {
    public:
        Ram(std::string name = "RAM");
        ~Ram();
        void setRam_Max(double ram);
        void setRam_Use(double ram);
        double getRamMax(void);
        double getRamUse(void);

        void refresh(void);
        void initAll(void);
        bool initTextRam(void);
        bool initTextRamUse(void);
        void initRectRam(void);
        void render(sf::RenderTarget &target);

    protected:
        double _ram_max;
        double _ram_used;
        sf::Text _TextRam;
        sf::Text _TextRamUse;
        sf::Vector2f _size;
        sf::RectangleShape _rectBase;
        sf::RectangleShape _rectTop;
        sf::RectangleShape _rectRam;
};

#endif /* !RAM_HPP_ */
