/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush2-
** File description:
** GiftPaper.cpp
*/

#include <iostream>

#include "../GiftPaper/GiftPaper.hpp"

GiftPaper::GiftPaper()
{
    _isReady = false;
}

GiftPaper::~GiftPaper()
{
    return;
}

bool GiftPaper::isReady(GiftPaper *gift)
{
    return (_isReady);
}