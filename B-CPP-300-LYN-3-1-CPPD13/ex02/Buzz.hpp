/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD13-
** File description:
** Buzz.hpp
*/

#ifndef BUZZ_HPP_
	#define BUZZ_HPP_

    #include "Toy.hpp"

    class Buzz : public Toy {
        public:
            Buzz(std::string const &, std::string const &);
            Buzz(Buzz const &);
            ~Buzz();

            virtual void display(std::string const);
    };

#endif /* !BUZZ_HPP_ */