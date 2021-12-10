/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD10-
** File description:
** Peon.hpp
*/

#ifndef PEON_HPP_
    #define PEON_HPP_

    #include <string>

    #include "Victim.hpp"

    class Peon : public Victim {
        public:
            Peon(std::string);
            virtual ~Peon();
            void getPolymorphed() const;
    };

#endif /* !PEON_HPP_ */