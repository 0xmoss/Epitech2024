/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** Commands.cpp
*/

#include "Commands.hpp"

#include "Nanotekspice.hpp"
#include "Logs.hpp"
#include "Tools.hpp"
#include "Factory.hpp"
#include "Edit.hpp"
#include "Contains.hpp"

Commands::Commands()
{
    return;
}

Commands::~Commands()
{
    return;
}

bool Commands::Help(Nanotekspice *nanotekspice)
{
    Logs logs;

    for (auto i = nanotekspice->commands.begin(); i != nanotekspice->commands.end(); ++i) {
        logs.display(*i);
    }

    return (true);
}

bool Commands::Dump(Nanotekspice *nanotekspice)
{
    return (true);
}

bool Commands::Simulate(Nanotekspice *nanotekspice, Factory *factory)
{
    Logs logs;

    nanotekspice->tick += 1;
    factory->create(nanotekspice->chipset, factory);

    nanotekspice->output_keys_l = factory->output_keys_l;
    nanotekspice->output_values_l = factory->output_values_l;
    nanotekspice->output_pins_l = factory->output_pins_l;

    return (true);
}

bool Commands::Display(Nanotekspice *nanotekspice)
{
    Vectors vectors;

    std::cout << "tick: " << nanotekspice->ticks() << std::endl;
    std::cout << "input(s):" << std::endl;
    this->sorted = nanotekspice->input_keys_l;

    std::sort(this->sorted.begin(), this->sorted.end());
    for (int i = 0; i < vectors.count(nanotekspice->input_keys_l); i++) {
        std::cout << "  " << this->sorted[i] << ": " << vectors.get_value_from_key(nanotekspice->input_values_l, vectors.get_key(nanotekspice->input_keys_l, this->sorted[i])) << std::endl;
    }

    this->sorted = nanotekspice->output_keys_l;
    std::sort(this->sorted.begin(), this->sorted.end());
    std::cout << "output(s):" << std::endl;
    for (int i = 0; i < vectors.count(nanotekspice->output_keys_l); i++) {
        std::cout << "  " << this->sorted[i] << ": " << vectors.get_value_from_key(nanotekspice->output_values_l, vectors.get_key(nanotekspice->output_keys_l, this->sorted[i])) << std::endl;
    }

    return (true);
}

bool Commands::Debug(Nanotekspice *nanotekspice)
{
    Logs logs;

    logs.display("\n------- INPUT -------\n");
    // INPUT
    for (auto i = nanotekspice->input_keys_l.begin(); i < nanotekspice->input_keys_l.end(); i++) {
        std::cout << "input_keys_l:    " << *i << std::endl;
    }

    for (auto i = nanotekspice->input_values_l.begin(); i < nanotekspice->input_values_l.end(); i++) {
        std::cout << "input_values_l:  " << *i << std::endl;
    }

    for (auto i = nanotekspice->input_pins_l.begin(); i < nanotekspice->input_pins_l.end(); i++) {
        std::cout << "input_pins_l:    " << *i << std::endl;
    }

    logs.display("\n------- OUTPUT -------\n");
    // OUTPUT
    for (auto i = nanotekspice->output_keys_l.begin(); i < nanotekspice->output_keys_l.end(); i++) {
        std::cout << "output_keys_l:   " << *i << std::endl;
    }

    for (auto i = nanotekspice->output_values_l.begin(); i < nanotekspice->output_values_l.end(); i++) {
        std::cout << "output_values_l: " << *i << std::endl;
    }

    for (auto i = nanotekspice->output_pins_l.begin(); i < nanotekspice->output_pins_l.end(); i++) {
        std::cout << "output_pins_l:   " << *i << std::endl;
    }

    logs.display("\n------- CHIPSET -------\n");

    std::cout << "chipset's type:  " << nanotekspice->chipset << std::endl;
    std::cout << "chipset's name:  " << nanotekspice->name << std::endl;

    return (true);
}

bool Commands::Check(Nanotekspice *nanotekspice, Factory *factory, std::string command)
{
    Logs logs;
    Tools tools;
    Edit edit;


    if (tools.check_command(command)) {
        if (command == "debug")
            return (Commands::Debug(nanotekspice));
        
        if (command == "simulate") {
            factory->input_keys_l = nanotekspice->input_keys_l;
            factory->input_values_l = nanotekspice->input_values_l;
            factory->input_pins_l = nanotekspice->input_pins_l;
            factory->output_keys_l = nanotekspice->output_keys_l;
            factory->output_values_l = nanotekspice->output_values_l;
            factory->output_pins_l = nanotekspice->output_pins_l;

            return (Commands::Simulate(nanotekspice, factory));
        }

        if (command == "display")
            return (Commands::Display(nanotekspice));

        if (command == "help")
            return (Commands::Help(nanotekspice));

        if (command == "exit") {
            return (true);
        }
    }
    if (Contains_char(command, '=') == true) {
        edit.change_input_value(nanotekspice, command);
        return (true);
    }

    logs.error("command_type", command);

    return (false);
}