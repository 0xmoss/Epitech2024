/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** False.hpp
*/

#ifndef _FALSE_HPP_
    #define _FALSE_HPP_

    #include "Interface.hpp"
    #include "Factory.hpp"

    class False : public nts::IComponent
    {
        public:
            False(Factory *);
            ~False();

            virtual void simulate(std::size_t tick) override;
            virtual nts::Tristate compute(std::size_t pin) override;
            virtual void setLink(std::size_t pin, IComponent &other, std::size_t other_pin) override;
            virtual void dump() const override;
        private:
            Factory *factory;
    };

#endif /* _FALSE_HPP_ */