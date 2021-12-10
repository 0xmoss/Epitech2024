/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD07A-
** File description:
** KroegComp.hpp
*/

#ifndef KREOGCOM_HH_
    #define KREOGCOM_HH_

    #include <string>
    #include <iostream>

    class KreogCom {
        public:
            KreogCom(int, int, int);
            ~KreogCom();
            void addCom(int, int, int);
            KreogCom *getCom();
            void removeCom();
            void ping();
            void locateSquad();
        private:
            int m_serial;
            int _x;
            int _y;
            KreogCom *_next;
    };

#endif /* !KREOGCOM_HH_ */