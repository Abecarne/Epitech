/*
** EPITECH PROJECT, 2022
** Pikmins
** File description:
** CharacterStats.cpp
*/

#include "CharacterStats.hpp"
#include <iostream>

bomberman::entities::CharacterStats::CharacterStats(void)
{
    this->_life = 1;
    this->_speed = 30;
    this->_speedBonus = 1;
    this->_playerBombRange = 2;
    this->_bombTimer = 0;
    this->_maxBombs = 1;
    this->_nbrBombs = this->_maxBombs;
    _life = 1;

    _isWallPass = false;
    _wallPassTimer = 0;

    _playerBombRange = 2;

    _speedBonus = 1;

    _bombTimer = 0;
    _maxBombs = 1;
    _nbrBombs = _maxBombs;
}

bomberman::entities::CharacterStats::~CharacterStats(void)
{
}

void bomberman::entities::CharacterStats::addWallPassUp(void)
{
    this->_isWallPass = true;
    _wallPassTimer = GetTime();
}

void bomberman::entities::CharacterStats::removeWallPassUp(void)
{
    this->_isWallPass = false;
}

bool bomberman::entities::CharacterStats::getWallPassUp(void)
{
    return (this->_isWallPass);
}

void bomberman::entities::CharacterStats::addPlayerLife(void)
{
    _life++;
}

void bomberman::entities::CharacterStats::removePlayerLife(void)
{
    _life--;
}

size_t bomberman::entities::CharacterStats::getPlayerLife(void)
{
    return _life;
}

size_t bomberman::entities::CharacterStats::getPlayerBombRange(void)
{
    return _playerBombRange;
}

void bomberman::entities::CharacterStats::maxPlayerSpeedBonus(void)
{
    this->_speedBonus = 2;
}

void bomberman::entities::CharacterStats::maxPlayerBombRange(void)
{
    this->_playerBombRange = 100;
}

void bomberman::entities::CharacterStats::addPlayerBombRange(void)
{
    this->_playerBombRange++;
}

void bomberman::entities::CharacterStats::removePlayerBombRange(void)
{
    this->_playerBombRange--;
}

float bomberman::entities::CharacterStats::getPlayerSpeed(void)
{
    return _speed;
}

void bomberman::entities::CharacterStats::addPlayerSpeedBonus(void)
{
    if (_speedBonus >= 2)
        return;
    _speedBonus += 0.2;
}

float bomberman::entities::CharacterStats::getPlayerSpeedBonus(void)
{
    return _speedBonus;
}

void bomberman::entities::CharacterStats::updateWallPass(bool inWall, std::vector<std::shared_ptr<bomberman::entities::LootBox>> lootBox)
{
    float deltaTime = GetTime() - _wallPassTimer;

    if (deltaTime > 10 && !inWall)
        _isWallPass = false;
}

void bomberman::entities::CharacterStats::updateBombTimer(void)
{
    float deltaTime = GetTime() - _bombTimer;

    if (_nbrBombs == _maxBombs) {
        _bombTimer = GetTime();
        return;
    }

    if (deltaTime > 3) {
        _bombTimer = GetTime();
        if (_nbrBombs < _maxBombs)
            _nbrBombs++;
    }

}

void bomberman::entities::CharacterStats::removeBombNumber(void)
{
    _nbrBombs--;
}

size_t bomberman::entities::CharacterStats::getBombNumber(void)
{
    return _nbrBombs;
}

void bomberman::entities::CharacterStats::upgradeBombNumber(void)
{
    _maxBombs++;
}
