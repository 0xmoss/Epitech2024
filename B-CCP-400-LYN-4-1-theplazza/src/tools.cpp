/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#include "tools.hpp"

#include "settings.hpp"

int tools::get_pizza_type_value(std::string value)
{

    return (tools::getter(settings::pizza_type, value));
}

int tools::get_pizza_size_value(std::string value)
{
    return (tools::getter(settings::pizza_size, value));
}

int tools::getter(std::vector<std::string> vec, std::string value)
{
    int index = 0;

    for (auto i = vec.begin(); i != vec.end(); ++i, index++) {
        if (*i == value)
            return (index);
    }

    return (-1);
}

std::string tools::get_pizza_type_name(int index)
{
    return (tools::getter_name(settings::pizza_type, index));
}

std::string tools::get_pizza_size_name(int index)
{
    return (tools::getter_name(settings::pizza_size, index));
}

std::string tools::getter_name(std::vector<std::string> vec, int pos)
{
    int index = 0;

    for (auto i = vec.begin(); i != vec.end(); ++i) {
        if (*i != "_EMPTY_")
            index++;
        if (pos == index)
            return (*i);
    }

    return ("_EMPTY_");
}
