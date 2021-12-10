/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** 2716.hpp
*/

#ifndef _2716_HPP_
    #define _2716_HPP_

    #include "Interface.hpp"
    #include "Factory.hpp"

    class _2716_ : public nts::IComponent
    {
        public:
            _2716_(Factory *);
            ~_2716_();

            virtual void simulate(std::size_t tick) override;
            virtual nts::Tristate compute(std::size_t pin) override;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t other_pin) override;
            virtual void dump() const override;
        private:
            Factory *factory;
    };

#endif /* _2716_HPP_ */