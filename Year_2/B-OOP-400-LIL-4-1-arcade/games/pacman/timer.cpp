/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** timer
*/

#include "main.hpp"

Timer::Timer()
{
    running = false;
}

Timer::~Timer()
{

}

void Timer::start()
{
    startTime = std::chrono::system_clock::now();
    running = true;
}
      
void Timer::stop()
{
    stopTime = std::chrono::system_clock::now();
    running = false;
}
      
double Timer::NowMilliseconds()
{
    std::chrono::time_point<std::chrono::system_clock> endTime;
         
    if(running) {
        endTime = std::chrono::system_clock::now();
    }
    else {
        endTime = stopTime;
    }
         
    return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
}
      
double Timer::NowSeconds()
{
    return NowMilliseconds() / 1000.0;
}