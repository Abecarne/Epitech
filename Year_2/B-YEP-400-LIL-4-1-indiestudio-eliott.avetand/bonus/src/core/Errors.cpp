/*
** EPITECH PROJECT, 2022
** Pikmins
** File description:
** Errors.cpp
*/

#include "Errors.hpp"

bomberman::core::Errors::Errors(std::string const &message, std::string const &errorType)
{
    this->_name = errorType;
    this->_message = message;
}

const char *bomberman::core::Errors::what() const noexcept
{
    return this->_message.c_str();
}

std::string const &bomberman::core::Errors::getErrorType() const
{
    return this->_name;
}