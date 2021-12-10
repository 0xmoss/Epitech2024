/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush2-
** File description:
** Elf.cpp
*/

#include <iostream>

#include "Elf.hpp"

#include "../Wrap/Wrap.hpp"
#include "../GiftPaper/GiftPaper.hpp"
#include "../Box/Box.hpp"

Elf::Elf()
{
    return;
}

Elf::~Elf()
{
    return;
}

GiftPaper *Elf::wrapObject(Toy *toy, Box *box, GiftPaper *gift)
{
    return (Wrap::wrapMeThat(toy, box, gift));
}

void Elf::sendGift(GiftPaper *gift)
{
    // TODO
}