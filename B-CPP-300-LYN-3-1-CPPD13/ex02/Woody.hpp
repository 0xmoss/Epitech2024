/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD13-
** File description:
** Woody.hpp
*/

#ifndef WOODY_HPP_
	#define WOODY_HPP_

    #include "Toy.hpp"

    class Woody : public Toy {
        public:
            Woody(std::string const &, std::string const &);
            Woody(Woody const &);
            virtual ~Woody();

            virtual void display(std::string const);
    };

#endif /* !WOODY_HPP_ */