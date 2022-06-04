/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** sfml
*/

#include "sfml.hpp"

arcade::display::ADisplayModule::~ADisplayModule() {};

// ~~~~~~ Beginning of member functions ~~~~~~

Sfml::Sfml(void)
{
    std::cout << "Constructeur SFML" << std::endl;
    _initWindow();
    this->libName = "sfml";
    theScore = 0;
}

Sfml::~Sfml()
{
    std::cout << "Destructeur SFML" << std::endl;
    _window->close();
}

std::string Sfml::getLibName(void)
{
    return (this->libName);
}

void Sfml::setGame(std::string gameName)
{
    _currentGame = gameName;
}

arcade::Keys Sfml::displayMenu(std::vector<std::string> gameLibs, std::vector<std::string> graphicLibs)
{
    (void)gameLibs;
    (void)graphicLibs;

    arcade::Keys input = arcade::Keys::NONE;
    this->_menu = new Menu(gameLibs, graphicLibs, getCurrentGame());
    _window->clear();
    draw_menu();
    input = keyPressed();
    _window->display();
    return (input);
}

arcade::State Sfml::endLib(arcade::State state)
{
     if (state = arcade::State::LOOSE){
        _window->clear();
        printLoose();
        _window->display();
    }
    else if (state = arcade::State::WIN){
        _window->clear();
        printWin();
        _window->display();
    }
    return (state);
}

void Sfml::loadScreen(MapType map)
{
    set_map(map);
    draw_map(my_content);
    _window->display();
}

void Sfml::refreshScreen(MapType map)
{
    if (!_window->isOpen())
        return;
    _window->clear();
    set_map(map);
    Score(theScore);
    draw_map(my_content);
    _window->display();
}

bool Sfml::updateScore(int score)
{
    theScore = score;
    return (true);
}

arcade::Keys Sfml::theKey(sf::Event event)
{
    switch (event.key.code) {
        case sf::Keyboard::Escape:
            return (arcade::Keys::ESC);
            break;
        case sf::Keyboard::Z:
            return (arcade::Keys::UP);
            break;
        case sf::Keyboard::Q:
            return (arcade::Keys::RIGHT);
            break;
        case sf::Keyboard::S:
            return (arcade::Keys::DOWN);
            break;
        case sf::Keyboard::D:
            return (arcade::Keys::LEFT);
            break;
        case sf::Keyboard::A:
            return (arcade::Keys::PREVLIB);
            break;
        case sf::Keyboard::E:
            return (arcade::Keys::NEXTLIB);
            break;
        case sf::Keyboard::O:
            return (arcade::Keys::PREVGAME);
            break;
        case sf::Keyboard::P:
            return (arcade::Keys::NEXTGAME);
            break;
        case sf::Keyboard::M:
            return (arcade::Keys::MENU);
            break;
        case sf::Keyboard::Space:
            return (arcade::Keys::ENTER);
            break;
        case sf::Keyboard::Enter:
            return (arcade::Keys::ENTER);
            break;
        default:
            break;
    }
    return (arcade::Keys::NONE);
}

arcade::Keys Sfml::keyPressed(void)
{
    while (this->_window->pollEvent(this->_event)) {
        switch (_event.type) {
            case sf::Event::Closed:
                return (arcade::Keys::ESC);
                break;
            case sf::Event::KeyPressed:
                return (theKey(_event));
            default:
                break;
        }
    }
    return (arcade::Keys::NONE);
}

// ~~~~~~ End of member functions ~~~~~~

extern "C" {
    arcade::display::IDisplayModule *EntryPoint(void)
    {
        arcade::display::IDisplayModule *instance = new Sfml();
        return instance;
    }

    void deleteInstance(arcade::display::IDisplayModule *instance)
    {
        delete instance;
    }
}