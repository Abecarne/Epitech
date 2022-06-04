/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** KoalaNurse
*/

#include <fstream>
#include <iostream>
#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(const int id)
{
    _id = id;
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << _id << ": Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *koala)
{
    koala->takeDrugs(drug);
}

std::string getDrugName(std::string file_name)
{
    std::ifstream file(file_name);
    std::string drug;

    if (file.good()) {
        file >> drug;
        return (drug);
    }
    return ("");
}

std::string getPatientName(std::string file_name)
{
    std::string ind_extension = "";

    for (int i = 0; i < file_name.find(".report"); i++) {
        ind_extension += file_name[i];
    }
    return (ind_extension);
}

bool isCorrectFileName(std::string file_name)
{
    if (file_name.find(".report") < file_name.length())
        return (true);
    return (false);
}

std::string KoalaNurse::readReport(std::string report)
{
    std::string patient_name;
    std::string drug_name;

    if (isCorrectFileName(report)) {
        patient_name = getPatientName(report);
        drug_name = getDrugName(report);
        std::cout << "Nurse " << _id << ": Kreog! Mr." << patient_name << " needs a " << drug_name << std::endl;
        return (patient_name);
    } else {
        return ("");
    }
}

void KoalaNurse::timeCheck(void)
{
    if (_nurseWorks == false) {
        _nurseWorks = true;
        std::cout << "Nurse " << _id << ": Time to get to work!" << std::endl;
    } else {
        _nurseWorks = false;
        std::cout << "Nurse " << _id << ": Time to go home to my eucalyptus forest!" << std::endl;
    }
}

int KoalaNurse::getID(void)
{
    return (_id);
}