/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD06-
** File description:
** KoalaDoctor.hpp
*/

#ifndef KOALADOCTOR_H
    #define KOALADOCTOR_H

    #include "SickKoala.hpp"
    #include "KoalaNurse.hpp"

    class KoalaDoctor {
        private:
            std::string name;
            bool work;
        public:
            KoalaDoctor(std::string);
            ~KoalaDoctor();

            void diagnose(SickKoala *);
            void timeCheck();
            std::string getName();
    }; 

#endif