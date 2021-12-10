/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD06-
** File description:
** KoalaNurse.hpp
*/

#ifndef KOALANURSE_H
    #define KOALANURSE_H

    #include "SickKoala.hpp"

    class KoalaNurse {
        private:
            int ID;
            bool work;
        public:
            KoalaNurse(int);
            ~KoalaNurse();

            void giveDrug(std::string, SickKoala *);
            std::string readReport(std::string);
            void timeCheck();
            int getID();
    };

#endif
