/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class Picture {
    public:
        Picture(const std::string &file = "");
        Picture(const Picture &ref_pic);
        ~Picture();
        std::string data;
        bool getPictureFromFile(const std::string &file);
};

#endif /* !PICTURE_HPP_ */
