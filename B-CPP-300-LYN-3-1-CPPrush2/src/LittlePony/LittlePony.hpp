/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-
** File description:
** LittlePony
*/

#ifndef LITTLEPONY_HPP_
    #define LITTLEPONY_HPP_

    #include "../Toy/Toy.hpp"

    class LittlePony : public Toy {
        public:
            LittlePony(const std::string name = "Little Pony", bool is_taken = 0);
            ~LittlePony();

            void isTaken();
            void isDropped();
        private:
    };

#endif /* !LITTLEPONY_HPP_ */