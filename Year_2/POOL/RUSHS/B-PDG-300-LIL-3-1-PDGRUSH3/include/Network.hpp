/*
** EPITECH PROJECT, 2022
** B-PDG-300-LIL-3-1-PDGRUSH3-pierre-jean.descarpentries
** File description:
** Core
*/

#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <iostream>
#include <fstream>
#include <vector>

class Network {
    public:
        Network(void);

        void refresh(void);
        void newNet(std::string, size_t, size_t, bool);
        void parser(std::string);
        std::vector<std::pair<size_t, size_t>> getRC(void) const;
        std::vector<std::pair<size_t, size_t>> getTr(void) const;
        std::vector<std::string> getNames(void) const;

    private:
        std::vector<std::string> _names;
        std::vector<std::pair<size_t, size_t>> _networkRc;
        std::vector<std::pair<size_t, size_t>>_networkTr;
};

#endif