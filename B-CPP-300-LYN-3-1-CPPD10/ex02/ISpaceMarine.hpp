/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD10-
** File description:
** ISpaceMarine.hpp
*/

#ifndef ISPACEMARINE_HPP_
    #define ISPACEMARINE_HPP_

    class ISpaceMarine {
        public:
            virtual ISpaceMarine *clone() const = 0;
            virtual ~ISpaceMarine() {}
            virtual void battleCry() const = 0;
            virtual void rangedAttack() const = 0;
            virtual void meleeAttack() const = 0;
    };

#endif /* !ISPACEMARINE_HPP_ */