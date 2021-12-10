/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** Transform.hpp
*/

#ifndef _TRANSFORM_HPP_
    #define _TRANSFORM_HPP_

    #include "Interface.hpp"

    #include <iostream>

    namespace transform
    {
        nts::Tristate btotri(bool);
        bool stob(std::string);
        std::string btos(bool);
    };

#endif /* _TRANSFORM_HPP_ */