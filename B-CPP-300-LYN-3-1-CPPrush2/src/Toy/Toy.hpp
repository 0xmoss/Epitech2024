/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-
** File description:
** Toy
*/

#ifndef TOY_HPP_
    #define TOY_HPP_

    #include <iostream>
    #include "../Object/Object.hpp"

    class Toy : public Object{
        public:
            Toy(const std::string *name, bool is_taken);
            ~Toy();

        protected:
            std::string m_name;
            bool m_is_taken;
    };

#endif /* !TOY_HPP_ */