/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-arcade-
** File description:
** core.hpp
*/

#ifndef CORE_HPP
    #define CORE_HPP

    #include <iostream>
    #include <dlfcn.h>
    #include <stdio.h>

    #include "arcade.hpp"

    class Core
    {
        public:
            Core(char *, char *);
            ~Core();

            bool Engine();

        private:
            char *graphical_data;
            char *game_data;

            bool Open(char *);
    };

#endif /* CORE_HPP */
