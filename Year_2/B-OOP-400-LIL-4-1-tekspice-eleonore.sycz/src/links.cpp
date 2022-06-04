/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** links
*/

#include "../include/Header.hpp"

void setAllLinks(const std::vector<std::unique_ptr<nts::IComponent>> & allChipsets, Parser parser)
{
    std::vector<std::pair<std::string, std::string>> links = parser.getTabLinks();
    std::string s1;
    std::string s2;
    std::string s3;
    std::string s4;

    for (auto item : links) {
        s1 = getFirstPart(item.first, ':');
        s2 = getSecondPart(item.first, ':');
        s3 = getFirstPart(item.second, ':');
        s4 = getSecondPart(item.second, ':');
        // std::cout << "< " << s1 << ", " << s2 << " >";
        // std::cout << "< " << s3 << ", " << s4 << " >" << std::endl;
    }
}