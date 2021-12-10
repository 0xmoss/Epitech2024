/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** Verification.cpp
*/

#include "Logs.hpp"

#include "Verification.hpp"

Verification::Verification()
{
    return;
}

Verification::~Verification()
{
    return;
}

bool Verification::check_chipset(Nanotekspice *nanotekspice, Logs logs)
{
    if (nanotekspice->chipset.empty() == true) {
        logs.error("chipset_type", "");
        return (false);
    }

    return (true);
}

bool Verification::check_all(Nanotekspice *nanotekspice)
{
    Logs logs;

    /*
    if (Verification::check_chipset(nanotekspice, logs) == false)
        exit(84);
    */

    return (true);
}