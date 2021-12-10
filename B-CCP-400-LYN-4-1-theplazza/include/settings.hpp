/*
** EPITECH PROJECT, 2020
** B-CCP-400-LYN-4-1-theplazza-
** File description:
** settings.hpp
*/

#ifndef SETTINGS_HPP
    #define SETTINGS_HPP

    #include <iostream>
    #include <vector>

    namespace settings
    {
        enum PizzaType
        {
            Regina = 1,
            Margarita = 2,
            Americana = 4,
            Fantasia = 8,
        };

        std::vector<std::string> pizza_type = 
        {
            "_EMPTY_",
            "regina",
            "margarita",
            "_EMPTY_",
            "americana",
            "_EMPTY_",
            "_EMPTY_",
            "_EMPTY_",
            "fantasia"
        };

        enum PizzaSize
        {
            S = 1,
            M = 2,
            L = 4,
            XL = 8,
            XXL = 16
        };

        std::vector<std::string> pizza_size = 
        {
            "_EMPTY_",
            "S",
            "M",
            "_EMPTY_",
            "L",
            "_EMPTY_",
            "_EMPTY_",
            "_EMPTY_",
            "XL",
            "_EMPTY_",
            "_EMPTY_",
            "_EMPTY_",
            "_EMPTY_",
            "_EMPTY_",
            "_EMPTY_",
            "_EMPTY_",
            "XXL"
        };
    }

#endif /* SETTINGS_HPP */
