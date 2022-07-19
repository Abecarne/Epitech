/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Timer
*/

#include "Chronometer.hpp"

bomberman::settings::Chronometer::Chronometer(size_t minute, size_t second)
{
    this->_minutes = minute;
    this->_seconds = second;
    this->_startTime = 0;
    this->_elapseTimePause = 0;

    this->_remainingTime.insert(std::pair<std::string, size_t>("minutes", this->_minutes));
    this->_remainingTime.insert(std::pair<std::string, size_t>("seconds", this->_seconds));

    this->_chrono.insert(std::pair<std::string, std::string>("minutes", std::to_string(this->_minutes)));
    if (this->_seconds < 10)
        this->_chrono.insert(std::pair<std::string, std::string>("seconds", "0" + std::to_string(this->_seconds)));
    else
        this->_chrono.insert(std::pair<std::string, std::string>("seconds", std::to_string(this->_seconds)));

    this->_InSeconds = this->_minutes * 60 + this->_seconds;
    this->_timeAsk = _InSeconds;
    if (this->_seconds == 0)
        this->_minutes -= 1;
    if (this->_seconds == 60) {
        this->_minutes++;
        this->_seconds = 0;
    }
}

bomberman::settings::Chronometer::~Chronometer()
{
}

std::map<std::string, std::string> bomberman::settings::Chronometer::getTime(void)
{
    return this->_chrono;
}

void bomberman::settings::Chronometer::reStart(size_t minute, size_t second)
{
    this->_minutes = minute;
    this->_seconds = second;
    this->_startTime = 0;
    this->_elapseTimePause = 0;

    if (this->_remainingTime.contains("minutes"))
        this->_remainingTime["minutes"] = this->_minutes;
    else
        this->_remainingTime.insert(std::pair<std::string, size_t>("minutes", this->_minutes));
    if (this->_remainingTime.contains("second"))
        this->_remainingTime["second"] = this->_seconds;
    else
        this->_remainingTime.insert(std::pair<std::string, size_t>("seconds", this->_seconds));

    if (this->_chrono.contains("minutes"))
        this->_chrono["minutes"] = std::to_string(this->_minutes);
    else
        this->_chrono.insert(std::pair<std::string, std::string>("minutes", std::to_string(this->_minutes)));

    if (this->_seconds < 10) {
        if (this->_chrono.contains("seconds"))
            this->_chrono.find("seconds")->second = "0" + std::to_string(this->_seconds);
        else
            this->_chrono.insert(std::pair<std::string, std::string>("seconds", "0" + std::to_string(this->_seconds)));
    } else {
        if (this->_chrono.contains("seconds"))
            this->_chrono.find("seconds")->second = std::to_string(this->_seconds);
        else
            this->_chrono.insert(std::pair<std::string, std::string>("seconds", std::to_string(this->_seconds)));
    }

    this->_InSeconds = this->_minutes * 60 + this->_seconds;
    this->_timeAsk = _InSeconds;

    if (this->_seconds == 0)
        this->_minutes -= 1;
    if (this->_seconds == 60) {
        this->_minutes++;
        this->_seconds = 0;
    }

    this->_startTime = GetTime();
}

void bomberman::settings::Chronometer::start(void)
{
    this->_startTime = GetTime();
}

void bomberman::settings::Chronometer::continueTimer(void)
{
    this->_elapseTimePause += GetTime() - this->_timeAtPause;
}

void bomberman::settings::Chronometer::stopTimer(void)
{
    this->_timeAtPause = GetTime();
}

void bomberman::settings::Chronometer::update(void)
{
    size_t tmp_seconds = this->_seconds;
    double currentTime = GetTime() - this->_elapseTimePause;
    int elapsedTime = (int)currentTime - (int)this->_startTime;

    if (elapsedTime == _lastTime)
        return;

    this->_seconds = (this->_timeAsk - elapsedTime) - this->_minutes * 60;

    if (this->_seconds < 0) {
        this->_minutes = (this->_minutes - 1 < 0) ? 0 : this->_minutes - 1;
        this->_seconds = 59;
    }

    if (_seconds == 60)
        _seconds--;

    this->_remainingTime["minutes"] = this->_minutes;
    this->_remainingTime["seconds"] = this->_seconds;

    this->_chrono["minutes"] = std::to_string(this->_minutes);
    if (this->_seconds < 10)
        this->_chrono["seconds"] = "0" + std::to_string(this->_seconds);
    else
        this->_chrono["seconds"] = std::to_string(this->_seconds);

    this->_InSeconds = this->_minutes * 60 + this->_seconds;
    this->_lastTime = elapsedTime;
}

bool bomberman::settings::Chronometer::isOver(void)
{
    if (this->_seconds <= 0 && this->_minutes <= 0)
        return true;
    return false;
}