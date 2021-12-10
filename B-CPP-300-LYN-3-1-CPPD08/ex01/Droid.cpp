/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD08-
** File description:
** Droid.cpp
*/

#include <iostream>
#include <string>

#include "Droid.hpp"

Droid::Droid(std::string id) : serial(id), energy(50), attack(25), toughness(15) 
{
    this->status = new std::string("Standing by");
    std::cout << "Droid '" << this->serial << "' " << "Activated" << std::endl;
}

Droid::Droid(Droid const & droid) : serial(droid.serial), energy(droid.energy), attack(droid.attack), toughness(droid.toughness)
{
    if (droid.status)
        this->status = new std::string(*(droid.status));
    else
        this->status = new std::string("Standing by");
    std::cout << "Droid '" << this->serial << "' " << "Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    if (this->status)
        delete this->status;
    std::cout << "Droid '" << this->serial << "' " << "Destroyed" << std::endl;
}

std::string Droid::getId() const
{
    return(this->serial);
}

size_t Droid::getEnergy() const
{
    return(this->energy);
}

size_t Droid::getAttack() const
{
    return(this->attack);
}

size_t Droid::getToughness() const
{
    return(this->toughness);
}

std::string *Droid::getStatus() const
{
    return(this->status);
}

void Droid::setId(std::string id)
{
    this->serial = id;
}

void Droid::setEnergy(size_t energy)
{
    this->energy = energy;
}

void Droid::setStatus(std::string *status)
{
    this->status = status;
}

Droid& Droid::operator=(Droid const & droid)
{
    this->serial = droid.serial;
    this->energy = droid.energy;
    delete this->status;
    this->status = new std::string(*(droid.status));
    return (*this);
}

bool Droid::operator==(Droid const & droid) const
{
    return (this->serial == droid.serial &&
    this->energy == droid.energy &&
    this->attack == droid.attack &&
    this->toughness == droid.toughness &&
    *this->status == *(droid.status));
}

bool Droid::operator!=(Droid const & droid) const
{
    return!(*this == droid);
}

Droid& Droid::operator<<(size_t & energy)
{
    if (this->energy < 100) {
        int take = std::min(100 - this->energy, energy);
        this->energy += take;
        energy -= take;
    }
    return (*this);
}

std::ostream & operator<<(std::ostream & os, const Droid & droid)
{
    if (droid.getEnergy() > 100)
        return(os << "Droid '" << droid.getId() << "', " << *(droid.getStatus()) << ", 100");
    return(os << "Droid '" << droid.getId() << "', " << *(droid.getStatus()) << ", " << droid.getEnergy());
}