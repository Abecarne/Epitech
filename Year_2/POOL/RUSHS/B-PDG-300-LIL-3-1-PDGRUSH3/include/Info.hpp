
/*
** EPITECH PROJECT, 2022
** CPP pool rush3
** File description:
** info class to get all the structs and classes
*/

#ifndef INFO
#define INFO

#include "header.hpp"

class Info
{
    private:
        char _userName[LOGIN_NAME_MAX];
        char _hostName[HOST_NAME_MAX];
        utsname _coreInfo;
        std::string _runtime;
    public:
        Info(void);

        char const *getUserName(void) const;
        char const *getHostName(void) const;
        struct utsname getCoreInfo(void) const;
        std::string getRuntime(void);

        tm *getDate(void) const;
};

#endif