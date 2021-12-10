
/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** Vectors.hpp
*/

#ifndef VECTORS_HPP
    #define VECTORS_HPP

    #include <iostream>
    #include <vector>

    class Vectors
    {
        public:
            Vectors();
            ~Vectors();

            int get_key(std::vector<std::string>, std::string);
            int count(std::vector<std::string>);
            std::string get_value_from_key(std::vector<std::string>, int);
    };

#endif /* VECTORS_HPP */
