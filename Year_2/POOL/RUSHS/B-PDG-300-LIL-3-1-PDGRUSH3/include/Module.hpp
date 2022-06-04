/*
** EPITECH PROJECT, 2022
** Documents
** File description:
** Module
*/

#ifndef MODULE_HPP_
#define MODULE_HPP_

#include "header.hpp"

class Module : public IMonitorModule {
    public:
        // CTOR & DTOR
        Module(std::string name = "", int x = 0);
        ~Module();
        void setX(int x);
        void setY(int y);
        void setSize(float a, float b);
        void setColor(sf::Color color);
        void setName(std::string name);
        void setFont(sf::Font font);
        void setFontSize(int fontSize);

        int getX(void);
        int getY(void);
        sf::Vector2f getSize(void);
        sf::Color getColor(void);
        std::string getName(void);
        sf::Font getFont(void);
        int getFontSize(void);
        sf::RectangleShape getRectangle(void);

        virtual void refresh(void) = 0;
        virtual void initAll(void) = 0;
        virtual void render(sf::RenderTarget &target) = 0;

    protected:
        int _x;
        int _y;
        sf::Vector2f _size;
        sf::Color _color;
        std::string _name;
        sf::Font _font;
        int _fontSize;
        sf::RectangleShape _rect;
};

#endif /* !MODULE_HPP_ */
