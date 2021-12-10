/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD06-
** File description:
** main.cpp
*/

#include <iostream>
#include <string>
#include <cstring>

#include "SickKoala.hpp"

SickKoala::SickKoala(std::string name)
{
    this->name = name;
}

SickKoala::~SickKoala()
{
    std::string message(": Kreooogg!! I'm cuuuured!");

    std::cout << "Mr." << this->name << message << std::endl;
}

void SickKoala::poke()
{
    std::string message(": Gooeeeeerrk!!");

    std::cout << "Mr." << this->name << message << std::endl;
}

bool SickKoala::takeDrug(std::string drug)
{
    std::string mars("Mars");
    std::string kinder("Kinder");

    if (drug == mars) {
        std::cout << "Mr." << this->name <<
        ": Mars, and it kreogs!" << std::endl;
        return (true);
    }
    if (drug == kinder) {
        std::cout << "Mr." << this->name <<
        ": There is a toy inside!" << std::endl;
        return (true);
    }
    std::cout << "Mr." << this->name << ": Goerkreog!" << std::endl;
    return (false);
}

void SickKoala::overDrive(std::string message)
{
    const char *to_find = "Kreog!";
    const char *to_replace = "1337!";

    while (message.find(to_find) != std::string::npos)
        message.replace(message.find(to_find), strlen(to_find), to_replace);
    std::cout << "Mr." << this->name << ": " << message << std::endl;
}

std::string SickKoala::getName()
{
    return (this->name);
}