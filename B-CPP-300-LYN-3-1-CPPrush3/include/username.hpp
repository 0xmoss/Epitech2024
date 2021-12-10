/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** username.hpp
*/

#ifndef _USERNAME_HPP_
    #define _USERNAME_HPP_

    #include "main.hpp"
    #include <stdio.h>
    #include <unistd.h>
    #include <limits.h>
    #include <fstream>
    #include <sstream>
    #include <string>

    class nameInfo {
        public:
            nameInfo();
            ~nameInfo();

            // GET USERNAME
            std::string getUsername() const {return _username_;}
            std::string getHostname() const {return _hostname_;}
            bool getActivate() const {return _activate_module;}

            // SET USERNAME
            void setUsername();
            void setHostname();
            void setActivate(bool choice);

            // DISPLAY USERNAME
            void display();
        private:
            std::string _username_;
            std::string _hostname_;
            bool _activate_module;
    };

#endif /* !_USERNAME_HPP_ */