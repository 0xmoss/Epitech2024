/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-arcade-
** File description:
** arcade.cpp
*/

#include "arcade.hpp"

#include "tools.hpp"

Arcade::Arcade()
{
    logs::display("Building arcade");
    return;
}

Arcade::~Arcade()
{
    logs::display("Destroying arcade");
    return;
}

bool Arcade::graphical(char *value)
{
    this->_graphical_ = value;

    if (Arcade::graphical() == value) {
        return (true);
    }
    logs::display("graphical set failed");
    return (false);
}

char *Arcade::graphical()
{
    return (this->_graphical_);
}

bool Arcade::game(char *value)
{
    this->_game_ = value;

    if (Arcade::game() == value) {
        return (true);
    }
    logs::display("game set failed");
    return (false);
}

char *Arcade::game()
{
    return (this->_game_);
}
