/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-arcade-
** File description:
** ncureses_outils.cpp
*/

#include "tools.hpp"

bool Tools::Create()
{
    initscr();
    return (true);
}

bool Tools::Display(int x, int y, char *text)
{
    move(x,y);
    printw(text);
    return (true);
}
