/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#ifndef COMMANDS_HPP
    #define COMMANDS_HPP

    #include <iostream>
    #include <vector>
    #include <string>
    #include <thread>
    #include <unistd.h>

    #include "tools.hpp"
    #include "self.hpp"

    class commands
    {
        public:
            commands(self_t *);
            ~commands();

            int count;
            std::string pizza;

            bool check_pizza(std::string);
            bool check_size(std::string);
            bool check_count(std::string);
            bool launch(std::string);

            // REGINA
            void regina();

            // MARGARITA
            void margarita();

            // AMERICANA
            void americana();

            // FANTASIA
            void fantasia();

            std::string type;
            std::string size;

            int doe = 1;
            int tomato = 1;
            int gruyere = 1;
            int ham = 1;
            int mushrooms = 1;
            int steak = 1;
            int eggplant = 1;
            int goat_cheese = 1;
            int bake = 0;
            int recipe = 0;

            void estimate(int);
            void received(std::string);
            int multiplier;
            int cooks;
            int time;
            self_t *self;
    };

#endif /* COMMANDS_HPP */
