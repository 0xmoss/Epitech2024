/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** Main.cpp
*/

#include "Nanotekspice.hpp"
#include "Verification.hpp"
#include "Interface.hpp"
#include "Commands.hpp"
#include "Tools.hpp"
#include "Logs.hpp"
#include "Load.hpp"
#include "Signals.hpp"
#include "Factory.hpp"

bool exists_test(const std::string &name)
{
    std::ifstream f(name.c_str());

    if (is_empty(f))
        return (false);
    return (f.good());
}

bool args(int ac, char **argv)
{
    Logs logs;

    if (ac == 2) {
        if (exists_test(argv[1]) == true) {
            return (true);
        }
        logs.error("file_not_found", argv[1]);
        return (false);
    }
    logs.error("argument_type", "");
    return (false);
}

bool setup(Nanotekspice *nanotekspice, Load *load, char **argv)
{
    Logs logs;
    Verification verification;

    nanotekspice->filename(argv[1]);
    if (load->load_file(nanotekspice) == false)
        return (false);
    verification.check_all(nanotekspice);

    return (true);
}

int main(int ac, char **argv)
{
    Nanotekspice nanotekspice;
    Factory factory;
    Commands commands;
    Load load;
    Tools tools;
    Logs logs;

    std::string command = "_EMPTY_";

    signal(SIGINT, signal_handler_SIGINT);

    if (args(ac, argv) == true) {
        if (setup(&nanotekspice, &load, argv) == true) {
            logs.prompt();
            while (std::getline(std::cin, command)) {
                if (command != nanotekspice.commands[0]) {
                    commands.Check(&nanotekspice, &factory, command);
                    logs.prompt();
                } else {
                    return (0);
                }
            }
            logs.display("\b\b(CTRL+D)");

            return (0);
        }

        return (84);
    }

    return (84);
}
