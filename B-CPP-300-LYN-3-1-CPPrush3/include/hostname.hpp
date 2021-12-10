/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** hostname.hpp
*/

#ifndef _HOSTNAME_HPP_
    #define _HOSTNAME_HPP_

    #include "main.hpp"
    #include "IMonitorModule.hpp"


    class hostname : IMonitorModule {
        public:
            hostname();
            ~hostname();

            // GET HOSTNAME
            std::string get() override;

            // SET HOSTNAME
            void set() override;

            // DISPLAY HOSTNAME
            void display() override;

            std::string host;
    };

#endif /* !_HOSTNAME_HPP_ */