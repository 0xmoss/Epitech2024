/*
** EPITECH PROJECT, 2019
** PlasmaRifle.cpp
** File description:
** @epitech.eu
*/

#include "PlasmaRifle.hpp"

static const char *rifle = "Plasma Rifle";

PlasmaRifle::PlasmaRifle() : AWeapon(rifle, 5, 21)
{
    return;
}

PlasmaRifle::~PlasmaRifle()
{
    return;
}

void PlasmaRifle::attack() const
{
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}