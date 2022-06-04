/*
** EPITECH PROJECT, 2022
** CPP pool rush3
** File description:
** info class to get all the structs and classes
*/

#include "../include/header.hpp"

//---------------------------Constructor---------------------------------------
Info::Info(void)
{
    gethostname(this->_hostName, HOST_NAME_MAX);
    getlogin_r(this->_userName, LOGIN_NAME_MAX);

    struct sysinfo in;
    utsname inf;

    if (uname(&inf) == 0)
        this->_coreInfo = inf;
    if (sysinfo(&in) == 0) {
        this->_runtime = std::to_string(in.uptime / 60 / 60);
        this->_runtime += ":" + std::to_string(in.uptime / 60 - (60 * (in.uptime / 60 / 60)));
        this->_runtime += ":" + std::to_string(in.uptime % 60);
    } else
        this->_runtime = "";
}
//---------------------------End of Constructor--------------------------------

//------------------------------UserName---------------------------------------
char const *Info::getUserName(void) const
{
    return (this->_userName);
}

char const *Info::getHostName(void) const
{
    return (this->_hostName);
}

//---------------------------End of UserName-----------------------------------

//---------------------------Time and date-------------------------------------

tm *Info::getDate(void) const
{
    time_t tmp = time(0);

    return (localtime(&tmp));
}

std::string Info::getRuntime(void)
{
    struct sysinfo in;

    if (sysinfo(&in) == 0) {
        this->_runtime = std::to_string(in.uptime / 60 / 60);
        this->_runtime += ":" + std::to_string(in.uptime / 60 - (60 * (in.uptime / 60 / 60)));
        this->_runtime += ":" + std::to_string(in.uptime % 60);
    }
    return (this->_runtime);
}
//------------------------End of Time and date---------------------------------

utsname Info::getCoreInfo(void) const
{
    return (this->_coreInfo);
}