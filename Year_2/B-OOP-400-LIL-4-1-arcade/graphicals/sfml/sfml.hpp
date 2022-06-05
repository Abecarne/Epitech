/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "../../include/abstracts/ADisplayModule.hpp"

class Wall {
    public:
        Wall();
        ~Wall();
        sf::RectangleShape get_wall();
        void set_pos(float x, float y);

    protected:
        sf::RectangleShape rec_wall;
};

class Food {
    public:
        Food();
        ~Food();
        sf::Sprite get_food();
        void set_pos(float x, float y);

    protected:
        sf::Sprite s_food;
        sf::Texture t_food;
};

class Bonus {
    public:
        Bonus();
        ~Bonus();
        sf::Sprite get_bonus();
        void set_pos(float x, float y);

    protected:
        sf::Sprite s_bonus;
        sf::Texture t_bonus;
};

class Empty {
    public:
        Empty();
        ~Empty();
        sf::RectangleShape get_empty();
        void set_pos(float x, float y);

    protected:
        sf::RectangleShape rec_empty;
};

class Home {
    public:
        Home();
        ~Home();
        sf::RectangleShape get_home();
        void set_pos(float x, float y);

    protected:
        sf::RectangleShape rec_home;
};

class Door {
    public:
        Door();
        ~Door();
        sf::RectangleShape get_door();
        void set_pos(float x, float y);

    protected:
        sf::RectangleShape rec_door;
};

class Perso {
    public:
        Perso();
        ~Perso();
        sf::Sprite get_perso();
        void set_pos(float x, float y);

    protected:
        sf::Sprite s_perso;
        sf::Texture t_perso;
};

class Snake {
    public:
        Snake();
        ~Snake();
        sf::RectangleShape get_snake();
        void set_pos(float x, float y);

    protected:
        sf::RectangleShape rec_snake;
};

class Fruit {
    public:
        Fruit();
        ~Fruit();
        sf::Sprite get_fruit();
        void set_pos(float x, float y);

    protected:
        sf::Sprite s_fruit;
        sf::Texture t_fruit;
};

class Ghost_1 {
    public:
        Ghost_1();
        ~Ghost_1();
        sf::Sprite get_ghost_1();
        void set_pos(float x, float y);

    protected:
        sf::Sprite s_ghost_1;
        sf::Texture t_ghost_1;
};
class Ghost_2 {
    public:
        Ghost_2();
        ~Ghost_2();
        sf::Sprite get_ghost_2();
        void set_pos(float x, float y);

    protected:
        sf::Sprite s_ghost_2;
        sf::Texture t_ghost_2;
};
class Ghost_3 {
    public:
        Ghost_3();
        ~Ghost_3();
        sf::Sprite get_ghost_3();
        void set_pos(float x, float y);

    protected:
        sf::Sprite s_ghost_3;
        sf::Texture t_ghost_3;
};
class Ghost_4 {
    public:
        Ghost_4();
        ~Ghost_4();
        sf::Sprite get_ghost_4();
        void set_pos(float x, float y);

    protected:
        sf::Sprite s_ghost_4;
        sf::Texture t_ghost_4;
};

class Score {
    public:
        Score();
        ~Score();
        sf::Text getScore();
    
    protected:
        sf::Text score;
};

class Menu {
    public:
        Menu(std::vector<std::string> gameLibs, std::vector<std::string> graphicLibs, std::string _currentGame);
        Menu();
        ~Menu();

        sf::Text getArcade();
        std::vector<sf::Text> getGames();
        std::vector<sf::Text> getGraph();
        sf::Font getFont();
        sf::Text arcade;
        sf::Font font;

    protected:
        std::vector<sf::Text> games;
        std::vector<sf::Text> graph;
        std::string currentGame;
};

class Sfml : public arcade::display::ADisplayModule {
    public:
        Sfml(void);
        ~Sfml();

        std::string getLibName(void) override;
        void setGame(std::string gameName) override;
        arcade::Keys displayMenu(std::vector<std::string> gameLibs, std::vector<std::string> graphicLibs) override;
        arcade::State endLib(arcade::State) override;

        void loadScreen(MapType map) override;
        void refreshScreen(MapType map) override;
        bool updateScore(int score) override;
        arcade::Keys keyPressed(void) override;

        void draw_menu();
        void draw_map(std::vector<std::string> my_content);
        void set_map(MapType map);
        bool Score(int score);
        arcade::Keys theKey(sf::Event event);
        void printLoose(void);
        void printWin(void);

        std::string getCurrentGame(void) { return (_currentLib);}

    protected:
        void _initWindow(void);
        void _initClock(void);

        sf::Font _fontG;
        sf::Event _event;
        sf::Clock clockCpu;
        sf::VideoMode _videoMode;
        sf::RenderWindow *_window;

        float x;
        float y;
        
        std::string _currentLib;

    private:

        std::string libName;
        std::vector<std::string> my_content;
        int theScore;
        
        Menu *_menu;
 
        Wall _wall;
        Food _food;
        Bonus _bonus;
        Empty _empty;
        Home _home;
        Door _door;
        Perso _perso;
        Ghost_1 _ghost_1;
        Ghost_2 _ghost_2;
        Ghost_3 _ghost_3;
        Ghost_4 _ghost_4;
        Snake _snake;
        Fruit _fruit;
};

#endif /* !SFML_HPP_ */
