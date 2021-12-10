/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** Commands.hpp
*/

#ifndef _COMMANDS_HPP_
    #define _COMMANDS_HPP_

    #include "Nanotekspice.hpp"
    #include "Factory.hpp"
    #include <bits/stdc++.h>

    #include "Logs.hpp"

    class Commands
    {
        public:
            Commands();
            ~Commands();

            bool Check(Nanotekspice *, Factory *, std::string);

            bool Dump(Nanotekspice *);
            bool Simulate(Nanotekspice *, Factory *);
            bool Display(Nanotekspice *);
            bool Debug(Nanotekspice *);
            bool Help(Nanotekspice *);
            std::vector<std::string> sorted;
    };

#endif /* _COMMANDS_HPP_ */