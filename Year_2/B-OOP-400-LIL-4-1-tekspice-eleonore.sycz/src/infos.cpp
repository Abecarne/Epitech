/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** infos
*/

#include "../include/Header.hpp"

std::vector<std::string> mysplitStr(std::string str, char sep)  
{
    int i = 0;
    std::string tok;
    std::vector<std::string> res;

    for (i = 0; str[i] != ' '; i++)
        tok += str[i];
    res.push_back(tok);
    tok = "";
    for (i; str[i]; i++) {
        if (str[i] == ' ')
            continue;
        tok += str[i];
    }
    res.push_back(tok);
    return (res);
}

std::vector<std::pair<std::string, std::string>> parse_tab(std::vector<std::string> tab)
{
    std::vector<std::pair<std::string, std::string>> tab_pair;
    std::vector<std::string> tmp;

    for (int i = 0; i < tab.size(); i++) {
        check_nb_space(tab[i]);
        tmp = mysplitStr(tab[i], ' ');
        std::pair<std::string, std::string> pair(tmp[0], tmp[1]);
        tab_pair.push_back(pair);
    }
    return(tab_pair);
}

std::vector<std::string> getTabInputChipsets(std::vector<std::string> tab)
{
    std::vector<std::string> tab_InChipsets;
    int i = 0;

    for (int i = 0; i < tab.size(); i++) {
        if (tab[i].find(".chipsets:") == 0) {
            while ((tab[i].find(".links:")) >= tab[i].size()) {
                if (tab[i].find("input") == 0) {
                    tab_InChipsets.push_back(tab[i]);
                }
                i++;
            }
        }
    }
    return (tab_InChipsets);
}

std::vector<std::string> getTabOutputChipsets(std::vector<std::string> tab)
{
    std::vector<std::string> tab_OutChipsets;
    int i = 0;

    for (int i = 0; i < tab.size(); i++) {
        if (tab[i].find(".chipsets:") == 0) {
            while ((tab[i].find(".links:")) >= tab[i].size()) {
                if (tab[i].find("output") == 0) {
                    tab_OutChipsets.push_back(tab[i]);
                }
                i++;
            }
        }
    }
    return (tab_OutChipsets);
}

std::vector<std::string> getTabTypeName(std::vector<std::string> tab)
{
    std::vector<std::string> tab_TypeNameChipsets;
    int i = 0;

    for (int i = 0; i < tab.size(); i++) {
        if (tab[i].find(".chipsets:") == 0) {
            while ((tab[i].find(".links:")) >= tab[i].size()) {
                if (tab[i].find("output") >= tab[i].size() && tab[i].find("input") >= tab[i].size() && tab[i].find(".chipsets:") >= tab[i].size()) {
                    tab_TypeNameChipsets.push_back(tab[i]);
                }
                i++;
            }
        }
    }
    return (tab_TypeNameChipsets);
}

std::vector<std::string> getTabTypeLinks(std::vector<std::string> tab)
{
    std::vector<std::string> tab_Links;
    int i = 0;

    for (int i = 0; i < tab.size(); i++) {
        if (tab[i].find(".links:") == 0) {
            i++;
            while (i < tab.size()) {
                 tab_Links.push_back(tab[i]);
                i++;
            }
        }
    }
    return (tab_Links);
}

std::vector<std::string> toWordArray(std::string content)
{
    std::vector<std::string> tab;
    std::string tmp = "";
    int i = 0;

    for (int i = 0; content[i] != '\0'; i++) {
        if (content[i] == '#') {
            while (content[i] != '\n' || content[i+1] == '#')
                i++;
            i++;
        }
        if (content[i] == '\n' ) {
            if (tmp != "") {
                tab.push_back(tmp);
                tmp = "";
            }
        } else {
            tmp += content[i];
        }
    }
    error_tab(tab);
    return (tab);
}

std::string getFirstPart(std::string input, char sep)
{
    std::string part("");
    int i = 0;

    while (input[i] != sep) {
        part += input[i];
        i++;
    }
    return (part);
}

std::string getSecondPart(std::string input, char sep)
{
    std::string part("");
    int i = input.find(sep) + 1;

    while (input[i]) {
        part += input[i];
        i++;
    }
    return (part);
}