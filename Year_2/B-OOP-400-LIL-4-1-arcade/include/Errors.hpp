/*
** EPITECH PROJECT, 2022
** PROJECTS
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <iostream>
#include <stdexcept>
#include <exception>
#include <dlfcn.h>
#include <cstring>
#include <cstdio>

class Error {
    public:
        Error();
        Error(int ac, char **av);

        ~Error();

        void help(void);
        void error(int ac, char **av);
        void isValidLib(std::string filepath);


    private:
        std::string _filename;
};

#endif /* !ERROR_HPP_ */
