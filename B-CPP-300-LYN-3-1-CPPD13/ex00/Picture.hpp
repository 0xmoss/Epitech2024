/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD13-
** File description:
** Picture.hpp
*/

#ifndef PICTURE_HPP_
    #define PICTURE_HPP_

    #include <iostream>
    #include <string>

    class Picture {
        public:
            std::string data;

            Picture();
            Picture(const std::string &);
            virtual ~Picture();

            bool getPictureFromFile(const std::string &);
            Picture &operator = (Picture const &);
    };

#endif /* !PICTURE_HPP_ */