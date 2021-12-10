/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD06-
** File description:
** SickKoala.hpp
*/

#ifndef SICKKOALA_H
    #define SICKKOALA_H

    #include <string>

    class SickKoala {
        private:
            std::string name;
        public:
            SickKoala(std::string);
            ~SickKoala();

            void poke();
            bool takeDrug(std::string);
            void overDrive(std::string);
            std::string getName();
    };

#endif