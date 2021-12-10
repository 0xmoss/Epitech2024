/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-
** File description:
** Teddy
*/

#ifndef TEDDY_HPP_
    #define TEDDY_HPP_

    #include "../Toy/Toy.hpp"

    class Teddy : public Toy {
        public:
            Teddy(const std::string name = "Teddy", bool is_taken = false);
            ~Teddy();

            void isTaken();
            void isDropped();
        private:
    };

#endif /* !TEDDY_HPP_ */