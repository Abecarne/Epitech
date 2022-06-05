/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** Time.hpp
*/
#pragma once

namespace bomberman {
    namespace core {
        class Time {
            private:
                double _time;
                double _lastTime;
                double _deltaTime;

            public:
                Time(double time);

                operator float() const;

                double getSeconds() const;
                double getMilliseconds() const;
        };
    }
}