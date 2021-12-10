/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD10-
** File description:
** ISquad.hpp
*/

#ifndef ISQUAD_HPP_
    #define ISQUAD_HPP_

    #include "ISpaceMarine.hpp"

    class ISquad {
        public:
            virtual ~ISquad() {}
            virtual int getCount() const = 0;
            virtual ISpaceMarine *getUnit(int) = 0;
            virtual int push(ISpaceMarine*) = 0;
    };

#endif /* !ISQUAD_HPP_ */