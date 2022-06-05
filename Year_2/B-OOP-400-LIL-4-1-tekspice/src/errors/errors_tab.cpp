/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** errors_tab
*/

#include "../../include/Header.hpp"

int error_tab(std::vector<std::string> tab)
{
    int link = 0;
    int chip = 0;

    for (int i = 0; i < tab.size(); i++) {
        if (tab[i].find(".") == 0 && tab[i].find(".chipsets:") >= tab[i].size() && tab[i].find(".links:") >= tab[i].size()) {
            std::cerr << "bad ." << std::endl;
            exit(84);
        }
        if (tab[i].find(".chipsets:") == 0)
            chip++;
        if (tab[i].find(".links:") == 0)
            link++;
    }
    if (chip != 1 || link != 1) {
        std::cerr << "The file need .chipsets and .links" << std::endl;
        exit(84);
    }
    return(0);
}

int check_nb_space(std::string str)
{
    int space = 0;

    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == ' ' && str[i + 1] != ' ')
            space++;
        if (space > 1) {
            std::cerr << "Too much spaces" << std::endl;
            exit(84);
        }
    }
    if (space < 1) {
        std::cerr << "Not enough space" << std::endl;
        exit(84);
    }
    return (0);
}

int checkFirstElem(std::vector<std::pair<std::string, std::string>> _names)
{
    std::vector<std::string> chipsetsType = {   "2716",         "4001",         "4008",         "4011",
                                                "4013",         "4017",         "4030",         "4040",
                                                "4069",         "4071",         "4081",         "4094",
                                                "4512",         "4514",         "4801",         "clock",
                                                "false",        "input",        "output",       "true"};
    for (auto chip : _names) {
        for (int i = 0; i < chipsetsType.size(); i++) {
            if (chip.first == chipsetsType[i]) {
                return (0);
            }
        }
    }
    std::cout << "invalid chipset" << std::endl;
    exit(84);
}

int errorRien(std::vector<std::pair<std::string, std::string>> _links, std::vector<std::pair<std::string, std::string>> _inputs, std::vector<std::pair<std::string, std::string>> _outputs, std::string chip)
{
    return (0);
}

int checkLinks(std::vector<std::pair<std::string, std::string>> _names, std::vector<std::pair<std::string, std::string>> _links, std::vector<std::pair<std::string, std::string>> _inputs, std::vector<std::pair<std::string, std::string>> _outputs)
{
    int (* arr[])(std::vector<std::pair<std::string, std::string>> _links, std::vector<std::pair<std::string, std::string>> _inputs, std::vector<std::pair<std::string, std::string>> _outputs, std::string chip) = {
                                                &errorLinks2716,    &errorLinks4001_4071_4011_4081_4030,    &errorLinks4008,    &errorLinks4001_4071_4011_4081_4030,
                                                &errorLinks4013,    &errorLinks4017,    &errorLinks4001_4071_4011_4081_4030,    &errorLinks4040,
                                                &errorLinks4069,    &errorLinks4001_4071_4011_4081_4030,    &errorLinks4001_4071_4011_4081_4030,    &errorLinks4094,
                                                &errorLinks4512,    &errorLinks4514,    &errorLinks4801,    &errorRien,
                                                &errorRien, &errorRien, &errorRien, &errorRien};

    std::vector<std::string> chipsetsType = {   "2716",         "4001",         "4008",         "4011",
                                                "4013",         "4017",         "4030",         "4040",
                                                "4069",         "4071",         "4081",         "4094",
                                                "4512",         "4514",         "4801",         "clock",
                                                "false",        "input",        "output",       "true"};
    for (auto chip : _names) {
        for (int i = 0; i < chipsetsType.size(); i++) {
            if (chip.first == chipsetsType[i])
                arr[i](_links, _inputs, _outputs, chip.second);
        }
    }
    return (0);
}