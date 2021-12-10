/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** Nanotekspice.cpp
*/

#include "Nanotekspice.hpp"

Nanotekspice::Nanotekspice()
{
    Nanotekspice::chipsets(false);
    Nanotekspice::links(false);
    Nanotekspice::ticks(0);

    return;
}

Nanotekspice::~Nanotekspice()
{
    return;
}

bool Nanotekspice::chipsets(bool value)
{
    this->chipsets_t = value;

    if (Nanotekspice::chipsets() == value)
        return (true);
    return (false);
}

bool Nanotekspice::chipsets()
{
    return (this->chipsets_t);
}

bool Nanotekspice::links(bool value)
{
    this->links_t = value;

    if (Nanotekspice::links() == value)
        return (true);
    return (false);
}

bool Nanotekspice::links()
{
    return (this->links_t);
}

bool Nanotekspice::filename(std::string file)
{
    this->file = file;

    if (Nanotekspice::filename() == file)
        return (true);
    return (false);
}

std::string Nanotekspice::filename()
{
    return (this->file);
}

bool Nanotekspice::ticks(size_t value)
{
    this->tick = value;

    if (Nanotekspice::ticks() == value)
        return (true);
    return (false);
}

size_t Nanotekspice::ticks()
{
    return (this->tick);
}