/*
** EPITECH PROJECT, 2022
** B-PDG-300-LIL-3-1-PDGRUSH3-pierre-jean.descarpentries
** File description:
** Cpu
*/

#include "../include/header.hpp"

Cpu::Cpu()
{
    std::string line;
    std::ifstream cpuCore ("/proc/stat");

    this->_nbr_core = -1;
    while (getline(cpuCore, line)) {
        if (line.find("intr", 0) == 0)
            break;
        this->_nbr_core += 1;
    }
    this->setUsage();
    this->Do_calcul();
    this->searchNameCpu();
    this->setFrequency();
}

std::string Cpu::getName(void)
{
    return _name;
}

void Cpu::setFrequency(void)
{
    std::ifstream cpuInfo ("/proc/cpuinfo");
    std::string line;
    this->_frequency.clear();
    if (!cpuInfo.is_open())
        throw std::logic_error("Can not FIND CORE's frequency.");
    while (getline(cpuInfo, line)) {
        if (line.find("cpu MHz", 0) == 0)
            this->_frequency.push_back(std::stof(line.substr(10, line.length())));
    }
}

std::vector<float> Cpu::getFrequency(void)
{
    return _frequency;
}

void Cpu::searchNameCpu(void)
{
    std::ifstream cpuInfo ("/proc/cpuinfo");
    std::string line;

    if (!cpuInfo.is_open())
        throw std::logic_error("Can not FIND CPU's informations.");
    while (getline(cpuInfo, line)) {
        if (line.find("model name", 0) == 0)
            break;
    }
    this->_name = line.substr(13, line.length());
}

int Cpu::getNumberCore(void)
{
    return _nbr_core;
}

void Cpu::Do_calcul(void)
{
    double work = 0.0;
    double total = 0.0;

    this->_Usage.clear();
    for (int i = 0; i != this->_nbr_core; i++) {
        work = (this->_CurrentValueC[i] - this->_oldValueC[i]);
        total = (this->_CurrentValueA[i] - this->_oldValueA[i]);
        this->_Usage.push_back(std::to_string(work / total * 100));
    }
}

void Cpu::setUsage(void) {
    std::string line;
    std::string tmp_line;
    char *ptr;
    double all_process = 0.0;
    double current_process = 0.0;

    for (int i = 0; i != 2; i++) {
        std::vector<std::string> tab;
        std::ifstream cpuCore ("/proc/stat");
        if (!cpuCore.is_open())
            throw std::logic_error("Can not OPEN the file");
        while (getline(cpuCore, line)) {
            if (line.find("intr", 0) == 0)
                break;
            tab.push_back(line);
        }
        for (std::string tmp : tab) {
            tmp_line = tmp;
            char *char_arr;
            char *char_arr_current;
            char_arr = &tmp_line[0];
            char_arr_current = &tmp_line[0];
            ptr = strtok(char_arr, " ");
            for (int i = 0; i != 4; ++i) {
                ptr = strtok(NULL, " ");
                all_process += std::stoi(ptr);
                if (i < 2)
                    current_process += std::stoi(ptr);
            }
            if (i == 0) {
                this->_oldValueC.push_back(current_process);
                this->_oldValueA.push_back(all_process);
            } else {
                this->_CurrentValueC.push_back(current_process);
                this->_CurrentValueA.push_back(all_process);
            }
            all_process = 0;
            current_process = 0;
        }
        cpuCore.close();
        usleep(150000);
    }
}

void Cpu::setOldValue(void)
{
    this->_oldValueC = this->_CurrentValueC;
    this->_oldValueA = this->_CurrentValueA;
}

void Cpu::setCurrentValue(void)
{
    std::string line;
    std::string tmp_line;
    std::vector<std::string> tab;
    double all_process = 0.0;
    double current_process = 0.0;
    char *ptr;
    char *char_arr;
    std::ifstream cpuCore ("/proc/stat");

    _CurrentValueA.clear();
    _CurrentValueC.clear();
    while (getline(cpuCore, line)) {
        if (line.find("intr", 0) == 0)
            break;
        tab.push_back(line);
    }
    for (std::string tmp : tab) {
        tmp_line = tmp;


        char_arr = &tmp_line[0];
        ptr = strtok(char_arr, " ");
        for (int i = 0; i != 4; ++i) {
            ptr = strtok(NULL, " ");
            all_process += std::stoi(ptr);
        if (i < 2)
            current_process += std::stoi(ptr);
        }
        this->_CurrentValueC.push_back(current_process);
        this->_CurrentValueA.push_back(all_process);
    }
    cpuCore.close();
}

std::vector<std::string> Cpu::getUsage(void)
{
    return _Usage;
}

void Cpu::refresh(void)
{
    this->setOldValue();
    this->setCurrentValue();
    this->Do_calcul();
}