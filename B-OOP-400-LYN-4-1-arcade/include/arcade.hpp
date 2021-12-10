/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-arcade-
** File description:
** arcade.hpp
*/

#ifndef ARCADE_HPP
    #define ARCADE_HPP

    #include <iostream>

    class Arcade
    {
        public:
            Arcade();
            ~Arcade();

            bool graphical(char *);
            char *graphical();

            bool game(char *);
            char *game();
        private:
            char *_graphical_;
            char *_game_;
    };

#endif /* ARCADE_HPP */
