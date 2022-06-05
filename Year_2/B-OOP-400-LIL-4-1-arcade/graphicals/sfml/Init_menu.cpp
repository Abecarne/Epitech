/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** Init_menu
*/

#include "sfml.hpp"

Menu::Menu()
{
}

Menu::Menu(std::vector<std::string> gameLibs, std::vector<std::string> graphicLibs, std::string _currentGame)
{
    std::string currentLib = "sfml";
    currentGame = _currentGame;
    sf::Text tmp;
    int x = 450;
    int y = 300;
    int x2 = 100;
    int y2 = 300;

    this->font.loadFromFile("./res/Roboto-Light.ttf");
    this->arcade.setFont(font);
    this->arcade.setPosition(215, 100); 
    this->arcade.setCharacterSize(80);
    this->arcade.setString("ARCADE");
    this->arcade.setFillColor(sf::Color(255, 0, 0));
    this->arcade.setStyle(sf::Text::Bold | sf::Text::Underlined);
    for (size_t ind = 0; ind < gameLibs.size(); ind++) {
        this->games.push_back(tmp);
        this->games[ind].setString(gameLibs[ind]);
        tmp.setString(gameLibs[ind]);
        if (gameLibs[ind] == currentGame)
            games[ind].setFillColor(sf::Color(127, 0, 255));
        this->games[ind].setPosition(x, y);
        this->games[ind].setFont(font);
        this->games[ind].setCharacterSize(40);
        y += 100;
    }
    for (size_t ind = 0; ind < graphicLibs.size(); ind++) {
        tmp.setString(graphicLibs[ind]);
        this->graph.push_back(tmp);
        if (graphicLibs[ind] == currentLib)
            graph[ind].setFillColor(sf::Color(0, 255, 255));
        this->graph[ind].setPosition(x2, y2);
        this->graph[ind].setFont(font);
        this->graph[ind].setCharacterSize(40);
        y2 += 100;
    }
}

Menu::~Menu()
{
}

sf::Text Menu::getArcade()
{
    return (arcade);
}

std::vector<sf::Text> Menu::getGames()
{
    return (games);
}

std::vector<sf::Text> Menu::getGraph()
{
    return (graph);
}

sf::Font Menu::getFont()
{
    return (font);
}

void Sfml::draw_menu()
{
    std::vector<sf::Text> games = _menu->getGames();
    std::vector<sf::Text> graph = _menu->getGraph();

    _window->draw(this->_menu->arcade);
    for (size_t ind = 0; ind < games.size(); ind++){
        _window->draw(games[ind]);
    }
    for (size_t ind = 0; ind < graph.size(); ind++) {
        _window->draw(graph[ind]);
    }
}
