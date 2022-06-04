/*
** EPITECH PROJECT, 2022
** Documents
** File description:
** header
*/

#ifndef HEADER_HPP
#define HEADER_HPP

// ~~~~ ERRORS ~~~~
#include <stdexcept>
#include <exception>

// ~~~~ STD ~~~~
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include <csignal>
#include <unistd.h>

// ~~~~ INCLUDE ~~~~
#include "Parser.hpp"
#include "IComponent.hpp"
#include "ComponentFactory.hpp"
#include "Component.hpp"
#include "Circuit.hpp"

// ~~~~ COMPONENTS ~~~~
#include "C_2716.hpp"
#include "C_4001.hpp"
#include "C_4008.hpp"
#include "C_4011.hpp"
#include "C_4013.hpp"
#include "C_4017.hpp"
#include "C_4030.hpp"
#include "C_4040.hpp"
#include "C_4069.hpp"
#include "C_4071.hpp"
#include "C_4081.hpp"
#include "C_4094.hpp"
#include "C_4512.hpp"
#include "C_4514.hpp"
#include "C_4801.hpp"
#include "C_clock.hpp"
#include "C_false.hpp"
#include "C_input.hpp"
#include "C_output.hpp"
#include "C_true.hpp"

// ~~~~ FUNCTIONS ~~~~
std::vector<std::unique_ptr<nts::IComponent>> createComponent(Parser parser);
void shell(Parser parser, const std::vector<std::unique_ptr<nts::IComponent>> & allChipsets, size_t *tick);
std::string getFirstPart(std::string input, char sep);
std::string getSecondPart(std::string input, char sep);
std::string getTypeToString(nts::Type type);
std::string getStatusToString(nts::Tristate status);

void loopAll(const std::vector<std::unique_ptr<nts::IComponent>> & allChipsets, size_t *tick);
void dumpAll(const std::vector<std::unique_ptr<nts::IComponent>> & allChipsets);
void displayAll(const std::vector<std::unique_ptr<nts::IComponent>> & allChipsets, size_t *tick);
void simulateAll(const std::vector<std::unique_ptr<nts::IComponent>> & allChipsets, size_t *tick);

void setAllLinks(const std::vector<std::unique_ptr<nts::IComponent>> & allChipsets, Parser parser);

// ~~ error ~~
void errorFile(char *filename);
int error_tab(std::vector<std::string> tab);
int check_nb_space(std::string str);
int checkFirstElem(std::vector<std::pair<std::string, std::string>> _names);
int checkLinks(std::vector<std::pair<std::string, std::string>> _names, std::vector<std::pair<std::string, std::string>> _links, std::vector<std::pair<std::string, std::string>> _input, std::vector<std::pair<std::string, std::string>> _output);
void Error(int ac, char **av);

int errorLinks2716(std::vector<std::pair<std::string, std::string>> _links, std::vector<std::pair<std::string, std::string>> _inputs, std::vector<std::pair<std::string, std::string>> _outputs, std::string name_chip);
int errorLinks4001_4071_4011_4081_4030(std::vector<std::pair<std::string, std::string>> _links, std::vector<std::pair<std::string, std::string>> _inputs, std::vector<std::pair<std::string, std::string>> _outputs, std::string name_chip);
int errorLinks4008(std::vector<std::pair<std::string, std::string>> _links, std::vector<std::pair<std::string, std::string>> _inputs, std::vector<std::pair<std::string, std::string>> _outputs, std::string name_chip);
int errorLinks4013(std::vector<std::pair<std::string, std::string>> _links, std::vector<std::pair<std::string, std::string>> _inputs, std::vector<std::pair<std::string, std::string>> _outputs, std::string name_chip);
int errorLinks4017(std::vector<std::pair<std::string, std::string>> _links, std::vector<std::pair<std::string, std::string>> _inputs, std::vector<std::pair<std::string, std::string>> _outputs, std::string name_chip);
int errorLinks4040(std::vector<std::pair<std::string, std::string>> _links, std::vector<std::pair<std::string, std::string>> _inputs, std::vector<std::pair<std::string, std::string>> _outputs, std::string name_chip);
int errorLinks4069(std::vector<std::pair<std::string, std::string>> _links, std::vector<std::pair<std::string, std::string>> _inputs, std::vector<std::pair<std::string, std::string>> _outputs, std::string name_chip);
int errorLinks4094(std::vector<std::pair<std::string, std::string>> _links, std::vector<std::pair<std::string, std::string>> _inputs, std::vector<std::pair<std::string, std::string>> _outputs, std::string name_chip);
int errorLinks4512(std::vector<std::pair<std::string, std::string>> _links, std::vector<std::pair<std::string, std::string>> _inputs, std::vector<std::pair<std::string, std::string>> _outputs, std::string name_chip);
int errorLinks4514(std::vector<std::pair<std::string, std::string>> _links, std::vector<std::pair<std::string, std::string>> _inputs, std::vector<std::pair<std::string, std::string>> _outputs, std::string name_chip);
int errorLinks4801(std::vector<std::pair<std::string, std::string>> _links, std::vector<std::pair<std::string, std::string>> _inputs, std::vector<std::pair<std::string, std::string>> _outputs, std::string name_chip);
// ~~ get ~~
void getInfos(std::string content);
std::vector<std::string> getTabInputChipsets(std::vector<std::string> tab);
std::vector<std::string> getTabOutputChipsets(std::vector<std::string> tab);
std::vector<std::string> getTabTypeName(std::vector<std::string> tab);
std::vector<std::string> getTabTypeLinks(std::vector<std::string> tab);

std::vector<std::string> mysplitStr(std::string str, char sep);
std::vector<std::pair<std::string, std::string>> parse_tab(std::vector<std::string> tab_InChipsets);
std::vector<std::string> toWordArray(std::string content);


#endif // HEADER_HPP
