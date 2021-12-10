/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-
** File description:
** Wrap
*/
#include "../Object/Object.hpp"
#include "../Wrap/Wrap.hpp"

Wrap::Wrap(std::string const *name) : Object(name)
{
    std::cout << "whistles while working" << std::endl;
    isOpen = true;
}

Wrap::~Wrap()
{
    return;
}

GiftPaper *Wrap::wrapMeThat(Toy *toy, Box *box, GiftPaper *gift)
{
    box->_toy = toy;
    gift->_box = box;
    gift->_isReady = true;

    return (gift);
}

void Wrap::openMe(Box *box)
{
    isOpen = true;
}

void Wrap::closeMe(Box *box)
{
    isOpen = false;
}