/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** Vectors.hpp
*/

#ifndef _VECTORS_HPP_
    #define _VECTORS_HPP_

    #include "Interface.hpp"

    class Vectors
    {
        public:
            Vectors();
            ~Vectors();

            int get_key(std::vector<std::string>, std::string);
            int count(std::vector<std::string>);
            std::string get_value_from_key(std::vector<std::string>, int);
            std::string click(std::vector<std::string>, std::vector<std::string>, std::string);
    };

#endif /* _VECTORS_HPP_ */