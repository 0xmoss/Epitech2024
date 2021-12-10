/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD06-
** File description:
** KoalaDoctor.cpp
*/

#include <iostream>
#include <fstream>
#include <string>

#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string name)
{
    this->name = name;
    this->work = false;
    std::cout << "Dr." << this->name << ": I'm Dr." << this->name <<
    "! How do you kreog?" << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{
    this->name = "";
}

void KoalaDoctor::diagnose(SickKoala *koala)
{
    int get_drug = random() % 5;
    std::string report;
    std::ofstream stream;
    std::string drugs[5] {
        "Mars", "Kinder", "Crunch", "Maroilles", "Eucalyptus leaf"
    };

    std::cout << "Dr." << this->name << ": So what's goerking you Mr." <<
    koala->getName() << "?" << std::endl;
    koala->poke();
    report = koala->getName();
    report += ".report";
    stream.open(report.c_str());
    if (stream.is_open())
        stream << drugs[get_drug];
}

void KoalaDoctor::timeCheck()
{
    if (this->work == false) {
        std::cout << "Dr." << this->name << ": Time to get to work!" <<
        std::endl;
        this->work = true;
    } else if (this->work == true) {
        std::cout << "Dr." << this->name <<
        ": Time to go home to my eucalyptus forest!" << std::endl;
        this->work = false;
    }
}

std::string KoalaDoctor::getName()
{
    return (this->name);
}