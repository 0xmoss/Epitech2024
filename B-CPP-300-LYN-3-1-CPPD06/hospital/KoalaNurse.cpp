/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD06-
** File description:
** KoalaNurse.cpp
*/

#include <iostream>
#include <fstream>
#include <string>

#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(int ID)
{
    this->ID = ID;
    this->work = false;
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << this->ID << ": Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *koala)
{
    koala->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string filename)
{
    std::ifstream report;
    std::string koala;
    std::string drug = "";
    char data = '\0';

    if (filename.substr(filename.find_last_of(".") + 1) == "report") {
        koala = filename.substr(0, filename.find("."));
        report.open(filename.c_str());
        if (report.is_open()) {
            data = report.get();
            while (report.good()) {
                drug += data;
                data = report.get();
            }
            report.close();
            if (drug != "") {
                std::cout << "Nurse " << this->ID << ": Kreog! Mr." << koala <<
                " needs a " << drug << "!" << std::endl;
            }
        }
    }
    return (drug);
}

void KoalaNurse::timeCheck()
{
    if (this->work == false) {
        std::cout << "Nurse " << this->ID <<
        ": Time to get to work!" << std::endl;
        this->work = true;
    } else {
        std::cout << "Nurse " << this->ID <<
        ": Time to go home to my eucalyptus forest!" << std::endl;
        this->work = false;
    }
}

int KoalaNurse::getID()
{
    return (this->ID);
}