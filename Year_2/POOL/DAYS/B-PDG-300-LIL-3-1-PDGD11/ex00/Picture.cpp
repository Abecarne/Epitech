/*
** EPITECH PROJECT, 2022
** cpp_pool
** File description:
** Picture
*/

#include "Picture.hpp"


Picture::Picture(const std::string &file) :
    data(file)
{
    getPictureFromFile(data);
}

Picture::~Picture()
{
}

bool Picture::getPictureFromFile(const std::string &file)
{
    if (file == "")
        return (true);
    std::ifstream ifs(file);
    if (ifs.good()) {
        std::string content((std::istreambuf_iterator<char>(ifs)),
                            (std::istreambuf_iterator<char>()));
        data = content;
    } else {
        data = "ERROR";
        return (false);
    }
    return (true);
}
