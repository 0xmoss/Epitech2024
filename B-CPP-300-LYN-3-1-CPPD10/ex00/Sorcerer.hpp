/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD10-
** File description:
** Sorcerer.hpp
*/

#ifndef SORCERER_H_
    #define SORCERER_H_

    #include <iostream>
    #include <string>

    #include "Victim.hpp"
    #include "Peon.hpp"

    class Sorcerer {
        protected:
            std::string name;
            std::string title;
        public:
            Sorcerer(std::string, std::string);
            ~Sorcerer();

            std::string getName() const;
            std::string getTitle() const;

            void polymorph(const Victim &) const;
            void polymorph(const Peon &) const;
    };
    std::ostream &operator<<(std::ostream &, Sorcerer const &);


#endif /*! SORCERER_H */