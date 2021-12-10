/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-arcade-
** File description:
** correct.hpp
*/

#ifndef TOOLS_HPP
    #define TOOLS_HPP

    #include <iostream>
    #include <string.h>

    namespace logs
    {
        void display(std::string);
        void error(std::string);
        void help(std::string);
    }

    namespace manage
    {
        char *Set(std::string);
    }

#endif /* TOOLS_HPP */

