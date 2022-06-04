/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail) [WSL: Ubuntu-20.04]
** File description:
** errors_links
*/

#include "../../include/Header.hpp"

std::string checkErrorLink(std::string str, std::string name_chip, int nb)
{
    std::string part1 = "";
    std::string part2 = "";
    int i = 0;

    for (; str[i] != ':'; i++) {
        part1 += str[i];
    }
    i++;
    for (; str[i] != '\0'; i++)
        part2 += str[i];
    if (part2.size() > 1) {
        std::cout << "input and output have to be 1 0 or U" << std::endl;
        exit(84);
    }
    if (part1.find(name_chip) != 0 && (part2.find("1") != 0 && part2.find("0") != 0 && part2.find("U") != 0)) {
            std::cout << "input and output have to be 1 0 or U" << std::endl;
            exit(84);
    }
    if (nb == 1)
        return (part1);
    else if (nb == 2);
        return (part2);
    return (NULL);
}

int errorLinks2716(std::vector<std::pair<std::string, std::string>> _links,
                   std::vector<std::pair<std::string, std::string>> _inputs,
                   std::vector<std::pair<std::string, std::string>> _outputs,
                   std::string name_chip)
{
    // std::string part1 = "";
    // std::string part2 = "";

    // std::vector<std::string> input = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "12", "13", "19", "22", "23"};
    // std::vector<std::string> output = {"9", "10", "11", "13", "14", "15", "16", "17"};

    // for (auto i : _links) {
    //     part1 += checkErrorLink(i.first, name_chip, 1);
    //     part2 += checkErrorLink(i.first, name_chip, 2);
    //     if (part1.find(name_chip) == 0) {
    //         for (int ind = 0; ind < output.size(); ind++) {
    //             if (part2.find(output[ind]) == 0)
    //                 break;
    //             if (ind + 1 >= output.size()) {
    //                 std::cout << "invalid output" << std::endl;
    //                 exit(84);
    //             }
    //         }
    //     }
    //     part1 = "";
    //     part2 = "";
    //     part1 += checkErrorLink(i.second, name_chip, 1);
    //     part2 += checkErrorLink(i.second, name_chip, 2);
    //     if (part1.find(name_chip) == 0) {
    //         for (int ind = 0; ind < input.size(); ind++) {
    //             if (part2.find(input[ind]) == 0)
    //                 break;
    //             if (ind + 1 >= input.size()) {
    //                 std::cout << "invalid input" << std::endl;
    //                 exit(84);
    //             }
    //         }
    //     }
    //     part1 = "";
    //     part2 = "";
    // }
    return (0);
}

int errorLinks4001_4071_4011_4081_4030(std::vector<std::pair<std::string, std::string>> _links,
                   std::vector<std::pair<std::string, std::string>> _inputs,
                   std::vector<std::pair<std::string, std::string>> _outputs,
                   std::string name_chip)
{
    // std::string part1 = "";
    // std::string part2 = "";

    // std::vector<std::string> input = {"1", "2", "5", "6", "8", "9", "12", "13"};
    // std::vector<std::string> output = {"3", "4", "10", "11"};

    // for (auto i : _links) {
    //     part1 += checkErrorLink(i.first, name_chip, 1);
    //     part2 += checkErrorLink(i.first, name_chip, 2);
    //     if (part1.find(name_chip) == 0) {
    //         for (int ind = 0; ind < output.size(); ind++) {
    //             if (part2.find(output[ind]) == 0)
    //                 break;
    //             if (ind + 1 >= output.size()) {
    //                 std::cout << "invalid output" << std::endl;
    //                 exit(84);
    //             }
    //         }
    //     }
    //     part1 = "";
    //     part2 = "";
    //     part1 += checkErrorLink(i.second, name_chip, 1);
    //     part2 += checkErrorLink(i.second, name_chip, 2);
    //     if (part1.find(name_chip) == 0) {
    //         for (int ind = 0; ind < input.size(); ind++) {
    //             if (part2.find(input[ind]) == 0)
    //                 break;
    //             if (ind + 1 >= input.size()) {
    //                 std::cout << "invalid input" << std::endl;
    //                 exit(84);
    //             }
    //         }
    //     }
    //     part1 = "";
    //     part2 = "";
    // }
    return (0);
}

int errorLinks4008(std::vector<std::pair<std::string, std::string>> _links,
                    std::vector<std::pair<std::string, std::string>> _inputs,
                    std::vector<std::pair<std::string, std::string>> _outputs,
                    std::string name_chip)
{
    // std::string part1 = "";
    // std::string part2 = "";

    // std::vector<std::string> input = {"1", "2", "3", "4", "5", "6", "7", "9"};
    // std::vector<std::string> output = {"10", "11", "12", "13"};

    // for (auto i : _links) {
    //     part1 += checkErrorLink(i.first, name_chip, 1);
    //     part2 += checkErrorLink(i.first, name_chip, 2);
    //     if (part1.find(name_chip) == 0) {
    //         for (int ind = 0; ind < output.size(); ind++) {
    //             if (part2.find(output[ind]) == 0)
    //                 break;
    //             if (ind + 1 >= output.size()) {
    //                 std::cout << "invalid output" << std::endl;
    //                 exit(84);
    //             }
    //         }
    //     }
    //     part1 = "";
    //     part2 = "";
    //     part1 += checkErrorLink(i.second, name_chip, 1);
    //     part2 += checkErrorLink(i.second, name_chip, 2);
    //     if (part1.find(name_chip) == 0) {
    //         for (int ind = 0; ind < input.size(); ind++) {
    //             if (part2.find(input[ind]) == 0)
    //                 break;
    //             if (ind + 1 >= input.size()) {
    //                 std::cout << "invalid input" << std::endl;
    //                 exit(84);
    //             }
    //         }
    //     }
    //     part1 = "";
    //     part2 = "";
    // }
    return (0);
}

int errorLinks4013(std::vector<std::pair<std::string, std::string>> _links,
                    std::vector<std::pair<std::string, std::string>> _inputs,
                    std::vector<std::pair<std::string, std::string>> _outputs,
                    std::string name_chip)
{
    // std::string part1 = "";
    // std::string part2 = "";

    // std::vector<std::string> input = {"4", "5", "6", "8", "9", "10"};
    // std::vector<std::string> output = {"1", "2", "12", "13"};

    // for (auto i : _links) {
    //     part1 += checkErrorLink(i.first, name_chip, 1);
    //     part2 += checkErrorLink(i.first, name_chip, 2);
    //     if (part1.find(name_chip) == 0) {
    //         for (int ind = 0; ind < output.size(); ind++) {
    //             if (part2.find(output[ind]) == 0)
    //                 break;
    //             if (ind + 1 >= output.size()) {
    //                 std::cout << "invalid output" << std::endl;
    //                 exit(84);
    //             }
    //         }
    //     }
    //     part1 = "";
    //     part2 = "";
    //     part1 += checkErrorLink(i.second, name_chip, 1);
    //     part2 += checkErrorLink(i.second, name_chip, 2);
    //     if (part1.find(name_chip) == 0) {
    //         for (int ind = 0; ind < input.size(); ind++) {
    //             if (part2.find(input[ind]) == 0)
    //                 break;
    //             if (ind + 1 >= input.size()) {
    //                 std::cout << "invalid input" << std::endl;
    //                 exit(84);
    //             }
    //         }
    //     }
    //     part1 = "";
    //     part2 = "";
    // }
    return (0);
}

int errorLinks4017(std::vector<std::pair<std::string, std::string>> _links,
                    std::vector<std::pair<std::string, std::string>> _inputs,
                    std::vector<std::pair<std::string, std::string>> _outputs,
                    std::string name_chip)
{
    // std::string part1 = "";
    // std::string part2 = "";

    // std::vector<std::string> input = {"14", "13", "15"};
    // std::vector<std::string> output = {"1", "2", "3", "4", "5", "6", "7", "9", "10", "11", "12"};

    // for (auto i : _links) {
    //     part1 += checkErrorLink(i.first, name_chip, 1);
    //     part2 += checkErrorLink(i.first, name_chip, 2);
    //     if (part1.find(name_chip) == 0) {
    //         for (int ind = 0; ind < output.size(); ind++) {
    //             if (part2.find(output[ind]) == 0)
    //                 break;
    //             if (ind + 1 >= output.size()) {
    //                 std::cout << "invalid output" << std::endl;
    //                 exit(84);
    //             }
    //         }
    //     }
    //     part1 = "";
    //     part2 = "";
    //     part1 += checkErrorLink(i.second, name_chip, 1);
    //     part2 += checkErrorLink(i.second, name_chip, 2);
    //     if (part1.find(name_chip) == 0) {
    //         for (int ind = 0; ind < input.size(); ind++) {
    //             if (part2.find(input[ind]) == 0)
    //                 break;
    //             if (ind + 1 >= input.size()) {
    //                 std::cout << "invalid input" << std::endl;
    //                 exit(84);
    //             }
    //         }
    //     }
    //     part1 = "";
    //     part2 = "";
    // }
    return (0);
}

int errorLinks4040(std::vector<std::pair<std::string, std::string>> _links,
                    std::vector<std::pair<std::string, std::string>> _inputs,
                    std::vector<std::pair<std::string, std::string>> _outputs,
                    std::string name_chip)
{
    // std::string part1 = "";
    // std::string part2 = "";

    // std::vector<std::string> input = {"11"};
    // std::vector<std::string> output = {"1", "2", "3", "4", "5", "6", "7", "9", "12", "13", "14", "15"};

    // for (auto i : _links) {
    //     part1 += checkErrorLink(i.first, name_chip, 1);
    //     part2 += checkErrorLink(i.first, name_chip, 2);
    //     if (part1.find(name_chip) == 0) {
    //         for (int ind = 0; ind < output.size(); ind++) {
    //             if (part2.find(output[ind]) == 0)
    //                 break;
    //             if (ind + 1 >= output.size()) {
    //                 std::cout << "invalid output" << std::endl;
    //                 exit(84);
    //             }
    //         }
    //     }
    //     part1 = "";
    //     part2 = "";
    //     part1 += checkErrorLink(i.second, name_chip, 1);
    //     part2 += checkErrorLink(i.second, name_chip, 2);
    //     if (part1.find(name_chip) == 0) {
    //         for (int ind = 0; ind < input.size(); ind++) {
    //             if (part2.find(input[ind]) == 0)
    //                 break;
    //             if (ind + 1 >= input.size()) {
    //                 std::cout << "invalid input" << std::endl;
    //                 exit(84);
    //             }
    //         }
    //     }
    //     part1 = "";
    //     part2 = "";
    // }
    return (0);
}

int errorLinks4069(std::vector<std::pair<std::string, std::string>> _links,
                    std::vector<std::pair<std::string, std::string>> _inputs,
                    std::vector<std::pair<std::string, std::string>> _outputs,
                    std::string name_chip)
{
    // std::string part1 = "";
    // std::string part2 = "";

    // std::vector<std::string> input = {"1", "3", "5", "9", "11", "13"};
    // std::vector<std::string> output = {"2", "4", "6", "8", "10", "12"};

    // for (auto i : _links) {
    //     part1 += checkErrorLink(i.first, name_chip, 1);
    //     part2 += checkErrorLink(i.first, name_chip, 2);
    //     if (part1.find(name_chip) == 0) {
    //         for (int ind = 0; ind < output.size(); ind++) {
    //             if (part2.find(output[ind]) == 0)
    //                 break;
    //             if (ind + 1 >= output.size()) {
    //                 std::cout << "invalid output" << std::endl;
    //                 exit(84);
    //             }
    //         }
    //     }
    //     part1 = "";
    //     part2 = "";
    //     part1 += checkErrorLink(i.second, name_chip, 1);
    //     part2 += checkErrorLink(i.second, name_chip, 2);
    //     if (part1.find(name_chip) == 0) {
    //         for (int ind = 0; ind < input.size(); ind++) {
    //             if (part2.find(input[ind]) == 0)
    //                 break;
    //             if (ind + 1 >= input.size()) {
    //                 std::cout << "invalid input" << std::endl;
    //                 exit(84);
    //             }
    //         }
    //     }
    //     part1 = "";
    //     part2 = "";
    // }
    return (0);
}

int errorLinks4094(std::vector<std::pair<std::string, std::string>> _links,
                    std::vector<std::pair<std::string, std::string>> _inputs,
                    std::vector<std::pair<std::string, std::string>> _outputs,
                    std::string name_chip)
{
    // std::string part1 = "";
    // std::string part2 = "";

    // std::vector<std::string> input = {"2"};
    // std::vector<std::string> output = {"4", "5", "6", "7", "9", "10", "11", "12", "13", "14"};

    // for (auto i : _links) {
    //     part1 += checkErrorLink(i.first, name_chip, 1);
    //     part2 += checkErrorLink(i.first, name_chip, 2);
    //     if (part1.find(name_chip) == 0) {
    //         for (int ind = 0; ind < output.size(); ind++) {
    //             if (part2.find(output[ind]) == 0)
    //                 break;
    //             if (ind + 1 >= output.size()) {
    //                 std::cout << "invalid output" << std::endl;
    //                 exit(84);
    //             }
    //         }
    //     }
    //     part1 = "";
    //     part2 = "";
    //     part1 += checkErrorLink(i.second, name_chip, 1);
    //     part2 += checkErrorLink(i.second, name_chip, 2);
    //     if (part1.find(name_chip) == 0) {
    //         for (int ind = 0; ind < input.size(); ind++) {
    //             if (part2.find(input[ind]) == 0)
    //                 break;
    //             if (ind + 1 >= input.size()) {
    //                 std::cout << "invalid input" << std::endl;
    //                 exit(84);
    //             }
    //         }
    //     }
    //     part1 = "";
    //     part2 = "";
    // }
    return (0);
}

int errorLinks4512(std::vector<std::pair<std::string, std::string>> _links,
                    std::vector<std::pair<std::string, std::string>> _inputs,
                    std::vector<std::pair<std::string, std::string>> _outputs,
                    std::string name_chip)
{
    // std::string part1 = "";
    // std::string part2 = "";

    // std::vector<std::string> input = {"1", "2", "3", "4", "5", "6", "7", "9", "11", "12", "13"};
    // std::vector<std::string> output = {"14"};

    // for (auto i : _links) {
    //     part1 += checkErrorLink(i.first, name_chip, 1);
    //     part2 += checkErrorLink(i.first, name_chip, 2);
    //     if (part1.find(name_chip) == 0) {
    //         for (int ind = 0; ind < output.size(); ind++) {
    //             if (part2.find(output[ind]) == 0)
    //                 break;
    //             if (ind + 1 >= output.size()) {
    //                 std::cout << "invalid output" << std::endl;
    //                 exit(84);
    //             }
    //         }
    //     }
    //     part1 = "";
    //     part2 = "";
    //     part1 += checkErrorLink(i.second, name_chip, 1);
    //     part2 += checkErrorLink(i.second, name_chip, 2);
    //     if (part1.find(name_chip) == 0) {
    //         for (int ind = 0; ind < input.size(); ind++) {
    //             if (part2.find(input[ind]) == 0)
    //                 break;
    //             if (ind + 1 >= input.size()) {
    //                 std::cout << "invalid input" << std::endl;
    //                 exit(84);
    //             }
    //         }
    //     }
    //     part1 = "";
    //     part2 = "";
    // }
    return (0);
}

int errorLinks4514(std::vector<std::pair<std::string, std::string>> _links,
                    std::vector<std::pair<std::string, std::string>> _inputs,
                    std::vector<std::pair<std::string, std::string>> _outputs,
                    std::string name_chip)
{
    // std::string part1 = "";
    // std::string part2 = "";

    // std::vector<std::string> input = {"2", "3", "21", "22"};
    // std::vector<std::string> output = {"4", "5", "6", "7", "8", "9" "10", "11", "13",
    //                                     "14", "15", "16", "17", "18", "19", "20"};

    // for (auto i : _links) {
    //     part1 += checkErrorLink(i.first, name_chip, 1);
    //     part2 += checkErrorLink(i.first, name_chip, 2);
    //     if (part1.find(name_chip) == 0) {
    //         for (int ind = 0; ind < output.size(); ind++) {
    //             if (part2.find(output[ind]) == 0)
    //                 break;
    //             if (ind + 1 >= output.size()) {
    //                 std::cout << "invalid output" << std::endl;
    //                 exit(84);
    //             }
    //         }
    //     }
    //     part1 = "";
    //     part2 = "";
    //     part1 += checkErrorLink(i.second, name_chip, 1);
    //     part2 += checkErrorLink(i.second, name_chip, 2);
    //     if (part1.find(name_chip) == 0) {
    //         for (int ind = 0; ind < input.size(); ind++) {
    //             if (part2.find(input[ind]) == 0)
    //                 break;
    //             if (ind + 1 >= input.size()) {
    //                 std::cout << "invalid input" << std::endl;
    //                 exit(84);
    //             }
    //         }
    //     }
    //     part1 = "";
    //     part2 = "";
    // }
    return (0);
}

int errorLinks4801(std::vector<std::pair<std::string, std::string>> _links,
                    std::vector<std::pair<std::string, std::string>> _inputs,
                    std::vector<std::pair<std::string, std::string>> _outputs,
                    std::string name_chip)
{
    // std::string part1 = "";
    // std::string part2 = "";

    // std::vector<std::string> input = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11",
    //                                     "13", "14", "15", "16", "17", "18"};
    // std::vector<std::string> output = {"9", "10", "11", "13", "14", "15", "16", "17"};

    // for (auto i : _links) {
    //     part1 += checkErrorLink(i.first, name_chip, 1);
    //     part2 += checkErrorLink(i.first, name_chip, 2);
    //     if (part1.find(name_chip) == 0) {
    //         for (int ind = 0; ind < output.size(); ind++) {
    //             if (part2.find(output[ind]) == 0)
    //                 break;
    //             if (ind + 1 >= output.size()) {
    //                 std::cout << "invalid output" << std::endl;
    //                 exit(84);
    //             }
    //         }
    //     }
    //     part1 = "";
    //     part2 = "";
    //     part1 += checkErrorLink(i.second, name_chip, 1);
    //     part2 += checkErrorLink(i.second, name_chip, 2);
    //     if (part1.find(name_chip) == 0) {
    //         for (int ind = 0; ind < input.size(); ind++) {
    //             if (part2.find(input[ind]) == 0)
    //                 break;
    //             if (ind + 1 >= input.size()) {
    //                 std::cout << "invalid input" << std::endl;
    //                 exit(84);
    //             }
    //         }
    //     }
    //     part1 = "";
    //     part2 = "";
    // }
    return (0);
}