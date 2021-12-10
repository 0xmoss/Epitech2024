/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD07A-
** File description:
** KoalaBot.hpp
*/

#ifndef KOALABOT_HH_
    #define KOALABOT_HH_

    #include <string>

    #include "Parts.hpp"

    class KoalaBot {
        private:
            std::string _serial;
            Arms _arms;
            Legs _legs;
            Head _head;
        public:
            KoalaBot(std::string serial = "Bob-01");
            ~KoalaBot();

            void setParts(Arms&);
            void setParts(Legs&);
            void setParts(Head&);

            void swapParts(Arms&);
            void swapParts(Legs&);
            void swapParts(Head&);

            void informations();
            bool status();
    };

#endif /* !KOALABOT_HH_ */