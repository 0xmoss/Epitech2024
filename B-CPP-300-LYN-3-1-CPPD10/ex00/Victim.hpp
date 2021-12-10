/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD10-
** File description:
** Victim.hpp
*/

#ifndef VICTIM_H_
    #define VICTIM_H_

    #include <iostream>
    #include <string>

    class Victim {
        public:
            Victim(std::string);
            ~Victim();

            std::string getName() const;
            void getPolymorphed() const;
        protected:
            std::string name;
    };
    std::ostream &operator << (std::ostream &, Victim const &);

#endif /*! VICTIM_H_ */