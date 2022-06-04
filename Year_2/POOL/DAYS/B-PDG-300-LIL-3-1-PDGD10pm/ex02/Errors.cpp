/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** Errors
*/

#include "Errors.hpp"

NasaError::NasaError(std::string const &message, std::string const &component)
{
    _message = message;
    _component = component;
}

const char *NasaError::what() const noexcept
{
    return (_message.c_str());
}


const std::string &NasaError::getComponent() const
{
    return (_component);
}

MissionCriticalError::MissionCriticalError(std::string const &message, std::string const &component) : 
    NasaError(message, component)
{
}

LifeCriticalError::LifeCriticalError(std::string const &message, std::string const &component) :
    NasaError(message, component)
{
}

UserError::UserError(std::string const &message, std::string const &component) :
    NasaError(message, component)
{
}

CommunicationError::CommunicationError(std::string const &message) :
    NasaError(message, "CommunicationDevice")
{
}
