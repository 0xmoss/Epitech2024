/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** Logs.cpp
*/

#include "Logs.hpp"

Logs::Logs()
{
    return;
}

Logs::~Logs()
{
    return;
}

void Logs::prompt()
{
    std::cout << "> ";
}

void Logs::error(std::string type, std::string message)
{
    std::string _error_;

    if (type == "chipset_type")
        std::cerr << "Unknown chipset type" << std::endl;
    if (type == "component_type")
        std::cerr << "Unknown component name " <<  "'" << message << "'." << std::endl;
    if (type == "argument_type")
        std::cerr << "Usage: ./nanotekspice <filepath> [<input=value> ...]" << std::endl;
    if (type == "file_not_found")
        std::cerr << message << ": Cannot open file." << std::endl;
    if (type == "command_type")
        std::cerr << message << ": Command not found." << std::endl;
    if (type == "input_name")
        std::cerr << message << ": input not found." << std::endl;
    if (type == "output_name")
        std::cerr << message << ": output not found." << std::endl;
    if (type == "edit_key")
        std::cerr << message << ": key is not found." << std::endl;
    if (type == "edit_value")
        std::cerr << message << ": incorrect value." << std::endl;
}

void Logs::display(std::string message)
{
    std::cout << message << std::endl;
}