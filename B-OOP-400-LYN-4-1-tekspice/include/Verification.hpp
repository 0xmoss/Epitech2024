/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** Verification.hpp
*/

#ifndef _VERIFICATION_HPP_
    #define _VERIFICATION_HPP_

    #include "Nanotekspice.hpp"

    #include "Logs.hpp"

    class Verification
    {
        public:
            Verification();
            ~Verification();

            bool check_all(Nanotekspice *);
        private:
            bool check_chipset(Nanotekspice *, Logs);
    };

#endif /* _VERIFICATION_HPP_ */