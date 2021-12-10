/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#ifndef KITCHEN_HPP
    #define KITCHEN_HPP

    #include <iostream>
    #include <vector>

    #include "commands.hpp"

    #include "self.hpp"

    class kitchen
    {
        public:
            kitchen(
                int,
                int,
                int,
                commands *,
                std::vector<std::string>,
                std::vector<std::string>
            );
            ~kitchen();

            int multiplier();
            int cooks();
            int time();
            bool cook();
            std::vector<std::string> pizza_queue();
            std::vector<std::string> size_queue();
            commands *commands_d;

            int multiplier_d;
            int cooks_d;
            int time_d;
            std::vector<std::string> pizza_queue_d;
            std::vector<std::string> size_queue_d;
    };

#endif /* KITCHEN_HPP */

