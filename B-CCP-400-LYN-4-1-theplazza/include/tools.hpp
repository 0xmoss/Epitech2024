/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#ifndef TOOLS_HPP
    #define TOOLS_HPP

    #include <iostream>
    #include <vector>

    namespace tools
    {
        int get_pizza_type_value(std::string);
        int get_pizza_size_value(std::string);
        int getter(std::vector<std::string>, std::string);

        std::string get_pizza_type_name(int);
        std::string get_pizza_size_name(int);
        std::string getter_name(std::vector<std::string>, int);
    };

#endif /* TOOLS_HPP */
