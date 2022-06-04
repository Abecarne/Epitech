/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** main
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

void convert_celsius(float temp)
{
    float res = 5.0 / 9.0 * (temp - 32);

    std::cout << "          " << std::fixed << std::setprecision(3) << res << "      " << "Celsius\n";
}

void convert_fahrenheit(float temp)
{
    float res = 9.0 / 5.0 * temp + 32;

    std::cout << "          " << std::fixed << std::setprecision(3) << res << "      " << "Fahrenheit\n";
}

int main(int ac, char **av)
{
    int res;
    float temp;
    std::string scale;

    if (ac != 1)
        std::cerr << "Too much arguments\n";
    std::cin >> temp;
    std::cin >> scale;

    if (scale == "Fahrenheit")
        convert_celsius(temp);
    else if (scale == "Celsius")
        convert_fahrenheit(temp);
    return (0);
}
