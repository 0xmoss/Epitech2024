/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-arcade-
** File description:
** parse.cpp
*/

#include "arguments.hpp"
#include "tools.hpp"

bool arguments::exists(char *path)
{
    std::ifstream ifile;
    ifile.open(path);

    if (ifile)
        return (true);
    return (false);
}


bool arguments::correct(int ac, char **argv)
{
    if (ac == 2 || ac == 3) {
        if (ac == 2)
            return (true);
        return (arguments::exists(argv[1]) && arguments::exists(argv[2]));
    }
    return (false);
}
