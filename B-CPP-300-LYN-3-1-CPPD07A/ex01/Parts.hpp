/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD07A-
** File description:
** Parts.hpp
*/

#ifndef PARTS_HH_
    #define PARTS_HH_

    #include <string>
    #include <iostream>

    class Arms {
        private:
            std::string _serial;
            bool _functionnal;
        public:
            Arms(std::string serial = "A-01", bool functionnal = true);

            std::string serial();
            bool getFunctionnal();
            void informations();
    };

    class Legs {
        private:
            std::string _serial;
            bool _functionnal;
        public:
            Legs(std::string serial = "L-01", bool functionnal = true);

            std::string serial();
            bool getFunctionnal();
            void informations();
    };

    class Head {
        private:
            std::string _serial;
            bool _functionnal;
        public:
            Head(std::string serial = "H-01", bool functionnal = true);

            std::string serial();
            bool getFunctionnal();
            void informations();
    };

#endif /* !PARTS_HH_ */