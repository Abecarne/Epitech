/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** Init_map
*/

#include "sfml.hpp"


void Sfml::set_map(MapType map)
{
    my_content = map;
}

Wall::Wall()
{
    rec_wall.setFillColor(sf::Color(0, 128, 255));
    rec_wall.setSize(sf::Vector2f(15,15));
}

Wall::~Wall()
{
}

sf::RectangleShape Wall::get_wall()
{
    return(rec_wall);
}

void Wall::set_pos(float x, float y)
{
    rec_wall.setPosition(x, y);
}

Empty::Empty()
{
    rec_empty.setFillColor(sf::Color(0, 0, 0));
}

Empty::~Empty()
{
}

sf::RectangleShape Empty::get_empty()
{
    return(rec_empty);
}

void Empty::set_pos(float x, float y)
{
    rec_empty.setPosition(x, y);
}

Food::Food()
{
    this->t_food.loadFromFile("res/Map.png");
    this->s_food.setTexture(t_food);
    s_food.setTextureRect(sf::IntRect(5, 20, 10, 10));
    s_food.setScale(sf::Vector2f(2.f, 2.f));
}

Food::~Food()
{
}

sf::Sprite Food::get_food()
{
    return(s_food);
}

void Food::set_pos(float x, float y)
{
    s_food.setPosition(x, y);
}

Bonus::Bonus()
{
    this->t_bonus.loadFromFile("res/Map.png");
    this->s_bonus.setTexture(t_bonus);
    s_bonus.setTextureRect(sf::IntRect(20, 20, 10, 10));
    s_bonus.setScale(sf::Vector2f(2.f, 2.f));
}

Bonus::~Bonus()
{
}

sf::Sprite Bonus::get_bonus()
{
    return(s_bonus);
}

void Bonus::set_pos(float x, float y)
{
    s_bonus.setPosition(x, y);
}

Home::Home()
{
    rec_home.setFillColor(sf::Color(0,128, 255));
    rec_home.setSize(sf::Vector2f(25,25));
}

Home::~Home()
{;
}

sf::RectangleShape Home::get_home()
{
    return(rec_home);
}

void Home::set_pos(float x, float y)
{
    rec_home.setPosition(x, y);
}

Door::Door()
{
    rec_door.setFillColor(sf::Color(128,128, 128));
    rec_door.setSize(sf::Vector2f(25,25));
}

Door::~Door()
{
}

sf::RectangleShape Door::get_door()
{
    return(rec_door);
}

void Door::set_pos(float x, float y)
{
    rec_door.setPosition(x, y);
}

Perso::Perso()
{
    this->t_perso.loadFromFile("res/Pac-Man.png");
    this->s_perso.setTexture(t_perso);
    s_perso.setTextureRect(sf::IntRect(19, 0, 14, 14));
    s_perso.setScale(sf::Vector2f(1.5f, 1.5f));
}


sf::Sprite Perso::get_perso()
{
    return(s_perso);
}

void Perso::set_pos(float x, float y)
{
    s_perso.setPosition(x, y);
}

Perso::~Perso()
{
}

Snake::Snake()
{
    rec_snake.setFillColor(sf::Color(240, 0, 32));
    rec_snake.setSize(sf::Vector2f(25,25));
}

sf::RectangleShape Snake::get_snake()
{
    return(rec_snake);
}

void Snake::set_pos(float x, float y)
{
    rec_snake.setPosition(x, y);
}

Snake::~Snake()
{
}

Fruit::Fruit()
{
    this->t_fruit.loadFromFile("res/fruit.png");
    this->s_fruit.setTexture(t_fruit);
    s_fruit.setTextureRect(sf::IntRect(0, 0, 13, 13));
    s_fruit.setScale(sf::Vector2f(1.5f, 1.5f));
}

sf::Sprite Fruit::get_fruit()
{
    return(s_fruit);
}

void Fruit::set_pos(float x, float y)
{
    s_fruit.setPosition(x, y);
}

Fruit::~Fruit()
{
}

Ghost_1::Ghost_1()
{
    this->t_ghost_1.loadFromFile("res/Pac-Man.png");
    this->s_ghost_1.setTexture(t_ghost_1);
    s_ghost_1.setTextureRect(sf::IntRect(17, 63, 17, 18));
    s_ghost_1.setScale(sf::Vector2f(1.5f, 1.5f));
}

Ghost_1::~Ghost_1()
{
}

sf::Sprite Ghost_1::get_ghost_1()
{
    return(s_ghost_1);
}

void Ghost_1::set_pos(float x, float y)
{
    s_ghost_1.setPosition(x, y);
}

Ghost_2::Ghost_2()
{
    this->t_ghost_2.loadFromFile("res/Pac-Man.png");
    this->s_ghost_2.setTexture(t_ghost_2);
    s_ghost_2.setTextureRect(sf::IntRect(17, 79, 17, 18));
    s_ghost_2.setScale(sf::Vector2f(1.5f, 1.5f));
}

Ghost_2::~Ghost_2()
{
}

sf::Sprite Ghost_2::get_ghost_2()
{
    return(s_ghost_2);
}

void Ghost_2::set_pos(float x, float y)
{
    s_ghost_2.setPosition(x, y);
}

Ghost_3::Ghost_3()
{
    this->t_ghost_3.loadFromFile("res/Pac-Man.png");
    this->s_ghost_3.setTexture(t_ghost_3);
    s_ghost_3.setTextureRect(sf::IntRect(17, 95, 17, 18));
    s_ghost_3.setScale(sf::Vector2f(1.5f, 1.5f));
}

Ghost_3::~Ghost_3()
{
}

sf::Sprite Ghost_3::get_ghost_3()
{
    return(s_ghost_3);
}

void Ghost_3::set_pos(float x, float y)
{
    s_ghost_3.setPosition(x, y);
}

Ghost_4::Ghost_4()
{
    this->t_ghost_4.loadFromFile("res/Pac-Man.png");
    this->s_ghost_4.setTexture(t_ghost_4);
    s_ghost_4.setTextureRect(sf::IntRect(17, 112, 17, 18));
    s_ghost_4.setScale(sf::Vector2f(1.5f, 1.5f));
}

Ghost_4::~Ghost_4()
{
}

sf::Sprite Ghost_4::get_ghost_4()
{
    return(s_ghost_4);
}

void Ghost_4::set_pos(float x, float y)
{
    s_ghost_4.setPosition(x, y);
}

Score::Score()
{
    sf::Font font;

    font.loadFromFile("res/Roboto-Light.ttf");
    score.setFont(font);
    score.setPosition(10, 10);
    score.setCharacterSize(50);
    score.setString("SCORE :");
}

sf::Text Score::getScore()
{
    return (score);
}

Score::~Score()
{
}