/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** Nanotekspice.hpp
*/

#ifndef _NANOTEKSPICE_HPP_
    #define _NANOTEKSPICE_HPP_

    #include <iostream>
    #include <vector>
    #include <sstream>
    #include <string>
    #include <fstream>

    class Nanotekspice
    {
        public:
            Nanotekspice();
            ~Nanotekspice();

            std::string file;

            std::vector<std::string> commands
            {
                "exit",
                "display",
                "dump",
                "simulate",
                "loop",
                "help",
                "debug"
            };

            std::vector<std::string> types
            {
                ".chipsets:",
                ".links:"
            };

            std::vector<std::string> white_list
            {
                "clock",
                "tick",
                "false",
                "input",
                "output"
            };

            std::vector<std::string> input_keys_l;
            std::vector<std::string> input_values_l;
            std::vector<std::string> input_pins_l;

            std::vector<std::string> output_keys_l;
            std::vector<std::string> output_values_l;
            std::vector<std::string> output_pins_l;
        
            std::vector<std::string> clock_keys_l;
            std::vector<std::string> clock_values_l;
            std::vector<std::string> clock_pins_l;

            bool chipsets_t;
            bool links_t;

            std::size_t tick;
            std::string chipset;
            std::string chipset_type;

            std::string name;

            bool ticks(size_t);
            size_t ticks();

            bool chipsets(bool);
            bool chipsets();

            bool links(bool);
            bool links();

            bool filename(std::string);
            std::string filename();
    };

#endif /* _NANOTEKSPICE_HPP_ */