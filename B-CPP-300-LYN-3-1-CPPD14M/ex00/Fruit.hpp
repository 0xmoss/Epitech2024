/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD14M-
** File description:
** Fruit.hpp
*/

#ifndef _FRUIT_HPP_
	#define _FRUIT_HPP_

    #include <iostream>
    #include <string>

    class Fruit {
        protected:
            std::string name;
            int _vitamins;
            
            Fruit();
            Fruit(std::string const &, int);
        public:
            virtual ~Fruit();

            std::string const & getName();
            int getVitamins();

    };

#endif /* !_FRUIT_HPP_ */