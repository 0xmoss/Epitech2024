/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** Factory.hpp
*/

#ifndef _FACTORY_HPP_
    #define _FACTORY_HPP_

    #include <iostream>
    #include <memory>
    #include <unordered_map>
    #include <string>
    #include <functional>

    #include "Interface.hpp"

    class Factory
    {
        public:
            Factory();
            ~Factory();

            std::string simulate_or(std::string, std::string);
            std::string simulate_and(std::string, std::string);
            std::string simulate_nand(std::string, std::string);
            std::string simulate_nor(std::string, std::string);
            std::string simulate_xor(std::string, std::string);
            std::string simulate_sum(std::string, std::string);
            std::string simulate_not(std::string, std::string);

            std::unique_ptr<nts::IComponent> create(std::string const &, Factory *);

            std::vector<std::string> input_keys_l;
            std::vector<std::string> input_values_l;
            std::vector<std::string> input_pins_l;

            std::vector<std::string> output_keys_l;
            std::vector<std::string> output_values_l;
            std::vector<std::string> output_pins_l;
        
            std::vector<std::string> clock_keys_l;
            std::vector<std::string> clock_values_l;
            std::vector<std::string> clock_pins_l;
    };

#endif /* _FACTORY_HPP_ */