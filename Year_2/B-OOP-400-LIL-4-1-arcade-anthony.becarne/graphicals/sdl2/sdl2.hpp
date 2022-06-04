/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** sdl2
*/

#ifndef SDL2_HPP_
#define SDL2_HPP_

#include "../../include/abstracts/ADisplayModule.hpp"
#include "encapsulate/encapsulate.hpp"

class Sdl2 : public arcade::display::ADisplayModule {
    public:
        Sdl2(void);
        ~Sdl2();

        std::string getLibName(void) override;
        void setGame(std::string gameName) override;
        arcade::Keys displayMenu(std::vector<std::string> gameLibs, std::vector<std::string> graphicLibs) override;
        arcade::State endLib(arcade::State) override;

        void loadScreen(MapType map) override;
        void refreshScreen(MapType map) override;
        bool updateScore(int score) override;
        arcade::Keys keyPressed(void) override;

        void setTextsGameLibs(std::vector<std::string> gameLibs);
        void setTextsGraphicLibs(std::vector<std::string> graphicLibs);

        arcade::State keyPressedYesNo(void);

        void displaygraphicLibs(void);
        void displaygameLibs(void);
        void displayTitle(void);
        void displayScore(int score);
        void displayMap(MapType map);

    private:
        std::string libName;
        std::string _currentGame;
        int score;

        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Event events;
        TTF_Font *font;
        SDL_Color color;

        std::vector<SDL_Texture *> textsGameLibs;
        std::vector<SDL_Texture *> textsGraphicLibs;
        std::vector<SDL_Rect> rectGameLibs;
        std::vector<SDL_Rect> rectGraphicLibs;

};
#endif /* !SDL2_HPP_ */
