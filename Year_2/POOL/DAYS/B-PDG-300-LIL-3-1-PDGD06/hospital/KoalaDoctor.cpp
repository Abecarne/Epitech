/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** KoalaDoctor
*/

#include "SickKoala.hpp"
#include "KoalaNurse.hpp"
#include "KoalaDoctor.hpp"
#include <vector>
#include <fstream>

KoalaDoctor::KoalaDoctor(std::string doctor_name)
{
    _doctorName = doctor_name;
    std::cout << "Dr." << _doctorName << ": I'm Dr." << _doctorName << "! How do you kreog?" << std::endl;
}

KoalaDoctor::~KoalaDoctor(void)
{
}

std::string get_drug(void)
{
    std::vector<std::string> drug_list = {"Mars", "Kinder", "Crunch", "Maroilles", "Eucalyptus leaf"};

    return (drug_list[random() % 5]);
}

void write_report(std::string patient_name)
{
    std::string filename = "";
    filename += patient_name;
    filename += ".report";
    std::ofstream monFlux(filename.c_str());
    std::string drug = get_drug();
    if (monFlux) {
        monFlux << drug;
    }
}

void KoalaDoctor::diagnose(SickKoala *patient)
{
    std::string patient_name = patient->getName();
    std::cout << "Dr." << _doctorName << ": So what's goerking you Mr." << patient_name << "?" << std::endl;
    patient->poke();
    write_report(patient_name);
}

void KoalaDoctor::timeCheck(void)
{
    if (_docWorks == false) {
        _docWorks = true;
        std::cout << "Dr." << _doctorName << ": Time to get to work!" << std::endl;
    } else {
        _docWorks = false;
        std::cout << "Dr." << _doctorName << ": Time to go home to my eucalyptus forest!" << std::endl;
    }
}

std::string KoalaDoctor::getName(void)
{
    return (_doctorName);
}