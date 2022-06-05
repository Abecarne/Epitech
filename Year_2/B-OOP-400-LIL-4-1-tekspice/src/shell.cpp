/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** shell
*/

#include "../include/Header.hpp"

bool isAssignmentValid(std::string name, std::string assignment, const std::unique_ptr<nts::IComponent> & chipset)
{
    if (chipset->getComponentType() != nts::INPUT) {
        std::cerr << "Error: You can't assign state to a chipset of type " + getTypeToString(chipset->getComponentType()) + "." << std::endl;
        return (false);
    } else if (assignment != "0" && assignment != "1" && assignment != "U") {
        std::cerr << "Error: You must assign a state which is either '0', '1' or 'U'"<< std::endl;
        return (false);
    }
    return (true);
}

nts::Tristate getTristateFromString(std::string state)
{
    if (state == "0")
        return (nts::FALSE);
    else if (state == "1")
        return (nts::TRUE);
    else
        return (nts::UNDEFINED);
}

void assignTristate(std::string input, const std::vector<std::unique_ptr<nts::IComponent>> & allChipsets)
{
    std::string s1 = getFirstPart(input, '=');
    std::string s2 = getSecondPart(input, '=');
    std::string type;
    int i = 0;

    for (i = 0; i < allChipsets.size(); i++) {
        if (allChipsets[i]->getName() == s1) {
            if (isAssignmentValid(s1, s2, allChipsets[i]))
                allChipsets[i]->setStatus(getTristateFromString(s2));
            return;
        }
    }
    if (i == allChipsets.size()) {
        std::cerr << "Error: " + s1 + " isn't a chipset name." << std::endl;
    }
}

int executeCommand(std::string input, const std::vector<std::unique_ptr<nts::IComponent>> & allChipsets, size_t *tick)
{
    try {
        if (input == "exit") {
            return 42;
        } else if (input == "display") {
            displayAll(allChipsets, tick);
        } else if (input == "simulate") {
            simulateAll(allChipsets, tick);
        } else if (input == "loop") {
            loopAll(allChipsets, tick);
        } else if (input == "dump") {
            dumpAll(allChipsets);
        } else if (input.find('=') != std::string::npos) {
            assignTristate(input, allChipsets);
        }
    } catch(const std::exception& e) {
        throw std::runtime_error(e.what());
    }
    return (0);
}

void isEqualValid(std::string input)
{
    size_t occurences = std::count(input.begin(), input.end(), '=');

    if (occurences != 1) {
        throw std::runtime_error("Error: Too many '=' symbols.\n");
    }
    if (input.find(' ') != std::string::npos) {
        throw std::runtime_error("Error: Spaces (' ') symbols are forbidden.\n");
    }
}

void isValid(std::string input)
{
    std::vector<std::string> commands = {"simulate", "loop", "dump", "display", "exit", ""};

    if (std::find(commands.begin(), commands.end(), input) == commands.end()) {
        if (input.find('=') == std::string::npos) {
            throw std::runtime_error("Error: Command '" + input + "' not found.\n");
        } else {
            try {
                isEqualValid(input);
            } catch(const std::exception& e) {
                throw std::runtime_error(e.what());
            }
        }
    }
}

void shell(Parser parser, const std::vector<std::unique_ptr<nts::IComponent>> & allChipsets, size_t *tick)
{
    std::string input;
    int status;

    std::cout << "> ";
    while (std::getline(std::cin, input) && !std::cin.eof()) {
        try {
            isValid(input);
            status = executeCommand(input, allChipsets, tick);
        } catch(const std::exception& e) {
            std::cerr << e.what();
        }
        if (status == 42)
            return;
        std::cout << "> ";
    }
}