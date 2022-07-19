/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Chronometer
*/

#ifndef CHRONOMETER_HPP_
#define CHRONOMETER_HPP_

#include <raylib.h>
#include <iostream>
#include <string>
#include <map>

namespace bomberman
{
    namespace settings
    {
        class Chronometer
        {
        public:
            Chronometer(size_t minute, size_t second);
            ~Chronometer();

            std::map<std::string, std::string> getTime(void);
            void reStart(size_t minutes, size_t );
            void start(void);
            void update(void);
            bool isOver(void);

            void continueTimer(void);
            void stopTimer(void);

            protected:
                int _minutes;
                int _seconds;
                size_t _InSeconds;
                size_t _timeAsk;
                std::map<std::string, size_t> _remainingTime;
                std::map<std::string, std::string> _chrono;
                double _startTime;
                double _lastTime;

                // PAUSE
                int _timeAtPause;
                int _elapseTimePause;
        };
    }
}

#endif /* !CHRONOMETER_HPP_ */