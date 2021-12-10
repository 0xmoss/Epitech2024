/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** 4040.hpp
*/

#ifndef _4040_HPP_
    #define _4040_HPP_

    #include "Interface.hpp"
    #include "Factory.hpp"

    class _4040_ : public nts::IComponent
    {
        public:
            _4040_(Factory *);
            ~_4040_();

            virtual void simulate(std::size_t tick) override;
            virtual nts::Tristate compute(std::size_t pin) override;
            virtual void setLink(std::size_t pin, IComponent &other, std::size_t other_pin) override;
            virtual void dump() const override;
        private:
            Factory *factory;
    };

#endif /* _4040_HPP_ */