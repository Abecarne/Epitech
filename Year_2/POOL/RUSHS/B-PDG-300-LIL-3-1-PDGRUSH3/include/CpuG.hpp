/*
** EPITECH PROJECT, 2022
** Documents
** File description:
** CpuG
*/

#ifndef CpuG_HPP_
#define CpuG_HPP_

#include "header.hpp"

class CpuG : public Module {
    public:
        CpuG(std::string name = "CpuG", int x = 0);
        ~CpuG();
        void setCpuGUse(float CpuGUse);
        void setFrequencyG(float freq);
        float getCpuGUse();
        float getFrequency(void);

        void refresh(void);
        void render(sf::RenderTarget &target);

        void initAll(void);
        bool initTextCpuG(void);
        bool initTextCpuGUse(void);
        bool initTextCpuGFrequency(void);
        bool initTextLimit(void);
        void initRectCpuG(void);
        void refreshRectangles(float value);

    protected:
        float _CpuGUse;
        float _freq;
        bool _display;
        sf::Text _TextCpuG;
        sf::Text _TextCpuGUse;
        sf::Text _TextLimit;
        sf::Text _TextFrequency;
        sf::Vector2f _size;
        sf::RectangleShape _rectBase;
        sf::RectangleShape _rectTop;
        sf::RectangleShape _rectCpuG;
};

#endif /* !CpuG_HPP_ */
