/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** Tools.cpp
*/

#include "Tools.hpp"

#include "Nanotekspice.hpp"

Tools::Tools()
{
    return;
}

Tools::~Tools()
{
    return;
}

std::string Tools::f_line(std::string file, int to_get)
{
    int lines = 0;

    std::ifstream infile(file);
    std::string line;

    for (; std::getline(infile, line); lines++) {
        std::istringstream iss(line);

        if (lines == to_get) {
            return (line);
        }
    }
    infile.close();

    return (NULL);
}

int Tools::f_count(std::string file)
{
    int lines = 0;

    std::ifstream infile(file);
    std::string line;

    for (; std::getline(infile, line); lines++) {
        std::istringstream iss(line);
    }
    infile.close();

    return (lines);
}

bool Tools::check_command(std::string command)
{
    Nanotekspice nano;

    for (auto i = nano.commands.begin(); i < nano.commands.end(); i++) {
        if (*i == command) {
            return (true);
        }
    }

    return (false);
}