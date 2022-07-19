/*
** EPITECH PROJECT, 2022
** delivery [WSL : Ubuntu-20.04]
** File description:
** EasyAI
*/

#include "Bots.hpp"
#include "GameAssets.hpp"
#include "Game.hpp"
#include "Time.hpp"

void bomberman::entities::Bots::easyAI(std::vector<Vector4> possibleDirs, bomberman::core::Time deltaTime)
{
    if (this->canPlaceBomb())
        this->placeBomb();
}
