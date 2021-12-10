/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** True.hpp
*/

#ifndef _TRUE_HPP_
    #define _TRUE_HPP_

    #include "Interface.hpp"
    #include "Factory.hpp"

    class True : public nts::IComponent
    {
        public:
            True(Factory *);
            ~True();

            virtual void simulate(std::size_t tick) override;
            virtual nts::Tristate compute(std::size_t pin) override;
            virtual void setLink(std::size_t pin, IComponent &other, std::size_t other_pin) override;
            virtual void dump() const override;
        private:
            Factory *factory;
    };

#endif /* _TRUE_HPP_ */