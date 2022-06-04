/*
** EPITECH PROJECT, 2022
** Documents
** File description:
** Parser
*/

#include "../include/Header.hpp"

Parser::Parser()
{
}

Parser::Parser(char *filename)
{
    setFileContent(filename);
    setInfos();
}

Parser::~Parser()
{
}

void Parser::setFileContent(char *filename)
{
    std::ifstream ifs(filename);

    std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    _content = content;
}

void Parser::setInfos(void)
{
    std::vector<std::string> tab;
    std::vector<std::string> tab_inputs;
    std::vector<std::string> tab_outputs;
    std::vector<std::string> tab_names;
    std::vector<std::string> tab_links;

    tab = toWordArray(_content);
    tab_inputs = getTabInputChipsets(tab);
    tab_outputs = getTabOutputChipsets(tab);
    tab_names = getTabTypeName(tab);
    tab_links = getTabTypeLinks(tab);
    _inputs = parse_tab(tab_inputs);
    _outputs = parse_tab(tab_outputs);
    _names = parse_tab(tab_names);
    _links = parse_tab(tab_links);
    checkFirstElem(_names);
    checkLinks(_names, _links, _inputs, _outputs);
}

std::vector<std::pair<std::string, std::string>> Parser::getTabInputs(void)
{
    return (_inputs);
}
std::vector<std::pair<std::string, std::string>> Parser::getTabOutputs(void)
{
    return (_outputs);
}
std::vector<std::pair<std::string, std::string>> Parser::getTabLinks(void)
{
    return (_links);
}
std::vector<std::pair<std::string, std::string>> Parser::getTabNames(void)
{
    return (_names);
}