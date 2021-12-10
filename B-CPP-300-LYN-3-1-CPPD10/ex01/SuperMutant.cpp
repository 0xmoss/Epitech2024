/*
** EPITECH PROJECT, 2019
** SuperMutant.cpp
** File description:
** @epitech.eu
*/

#include <iostream>

#include "SuperMutant.hpp"

static const char *mutant = "Super Mutant";

SuperMutant::SuperMutant() : AEnemy(170, mutant)
{
    std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh..." << std::endl;
}

void SuperMutant::takeDamage(int dmg)
{
    AEnemy::takeDamage(dmg - 3);
}
