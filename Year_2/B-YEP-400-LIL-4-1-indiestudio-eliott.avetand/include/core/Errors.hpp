/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Errors.hpp
*/
#pragma once

#include <exception>
#include <string>

namespace bomberman {

    namespace core {

        class Errors : public std::exception {
            protected:
                std::string _message;
                std::string _name;

            public:
                Errors(std::string const &message, std::string const &errorType = "Unknown");

                virtual const char *what() const noexcept;
                std::string const &getErrorType() const;
        };

    };

};
