/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD16-
** File description:
** DomesticKoala.hpp
*/

#ifndef _DOMESTICKOALA_HPP_
	#define _DOMESTICKOALA_HPP_

    #include <iostream>
    #include <string>
    #include <vector>

    #include "KoalaAction.hpp"

    class DomesticKoala {
        public:
            DomesticKoala(KoalaAction &);
            DomesticKoala(const DomesticKoala &);
            ~DomesticKoala();

            typedef void (KoalaAction::*methodPointer_t)(const std::string &);
            DomesticKoala &operator = (const DomesticKoala &);
            std::vector<methodPointer_t> const * getAction(void) const;

            void learnAction(char, methodPointer_t);
            void unlearnAction(char);
            void doAction(char, const std::string &);
            void setKoalaAction(KoalaAction &);
        private:
            KoalaAction action;
            std::vector<methodPointer_t> knowAction;
    };

#endif /* !_DOMESTICKOALA_HPP_ */