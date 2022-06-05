/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** Draw_map
*/

#include "sfml.hpp"

bool Sfml::Score(int score)
{
    sf::Text textScore;
    sf::Text intScore;
    sf::Font font;

    font.loadFromFile("./res/Roboto-Light.ttf");
    textScore.setFont(font);
    textScore.setCharacterSize(40);
    textScore.setPosition(10, 10);
    textScore.setString("SCORE :");

    intScore.setString(std::to_string(score));
    intScore.setFont(font);
    intScore.setCharacterSize(40);
    intScore.setPosition(165, 10);

    _window->draw(textScore);
    _window->draw(intScore);
    return (true);
}

void Sfml::draw_map(std::vector<std::string> my_content)
{
    x = 5;
    y = 75;

    for(auto j : my_content){
        for (auto i : j) {
            switch (i) {
                case '\n':
                    x = 5;
                    y += 25;
                    break;
                case ' ':
                    _empty.set_pos(x, y);
                    _window->draw(_empty.get_empty());
                    x += 25;
                    break;
                case '#':
                    _wall.set_pos(x, y);
                    _window->draw(_wall.get_wall());
                    x += 25;
                    break;
                case '.':
                    _food.set_pos(x, y);
                    _window->draw(_food.get_food());
                    x += 25;
                    break;
                case 'O':
                    _bonus.set_pos(x, y);
                    _window->draw(_bonus.get_bonus());
                    x += 25;
                    break;
                case '\"':
                    _home.set_pos(x, y);
                    _window->draw(_home.get_home());
                    x += 25;
                    break;
                case '_':
                    _door.set_pos(x, y);
                    _window->draw(_door.get_door());
                    x += 25;
                    break;
                case 'P':
                    _perso.set_pos(x, y);
                    _window->draw(_perso.get_perso());
                    x += 25;
                    break;
                case '1':
                    _ghost_1.set_pos(x, y);
                    _window->draw(_ghost_1.get_ghost_1());
                    x += 25;
                    break;
                case '2':
                    _ghost_2.set_pos(x, y);
                    _window->draw(_ghost_2.get_ghost_2());
                    x += 25;
                    break;
                case '3':
                    _ghost_3.set_pos(x, y);
                    _window->draw(_ghost_3.get_ghost_3());
                    x += 25;
                    break;
                case '4':
                    _ghost_4.set_pos(x, y);
                    _window->draw(_ghost_4.get_ghost_4());
                    x += 25;
                    break;
                case 'S':
                    _snake.set_pos(x, y);
                    _window->draw(_snake.get_snake());
                    x += 25;
                    break;
                case 'F':
                    _fruit.set_pos(x, y);
                    _window->draw(_fruit.get_fruit());
                    x += 25;
                    break;
                default:
                    break;
            }
        }
    }
}


