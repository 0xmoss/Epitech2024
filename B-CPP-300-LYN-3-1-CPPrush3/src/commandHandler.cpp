/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** parsing.cpp
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include "commandHandler.hpp"

Command::Command()
{
}

Command::~Command()
{
}

int Command::helpCommand(int argc, char **argv)
{
    std::string inString;

    if (argc > 1)
        inString = argv[1];
    if ((inString == "-h" && argc == 2) || ((inString != "gui") & (inString != "cli"))) {
        std::cout << "./MyGKrellm <mode>(\"cli\" or \"gui\") you can specified module activation(-sys, -user, -time, -cpu, -ram, -net)" << std::endl;
        return 1;
    }
    return 0;
}

int Command::parsingCommand(int argc, char **argv, MonitorCore &monitor)
{
    bool check_command_exist = false;
    std::string inString;

    if (this->helpCommand(argc, argv))
        return 1;
    else if (argc > 2) {
        for (int i = 2; argv[i] != NULL; i++) {
            inString = argv[i];
            if (inString == "-sys") {
                monitor.sys.setActivate(true);
                check_command_exist = true;
            } else if (inString == "-user") {
                monitor.name.setActivate(true);
                check_command_exist = true;
            } else if (inString == "-time") {
                monitor.current_date.setActivate(true);
                check_command_exist = true;
            }   else if (inString == "-cpu") {
                monitor._cpu.setActivate(true);
                check_command_exist = true;
            } else if (inString == "-ram") {
                monitor.ram.setActivate(true);
                check_command_exist = true;
            } else if (inString == "-net") {
                monitor.net.setActivate(true);
                check_command_exist = true;
            }
            if (check_command_exist == false){
                std::cerr << "Bad options input" << std::endl;
                return 1;
            }
        }
    } else if (argc < 2)
        std::cerr << "Bad input check \"./MyGKrellM -h\"" << std::endl;
    return 0;
}