/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** IMonitorDisplay
*/

#ifndef _IMONITORMODULE_HPP_
	#define _IMONITORMODULE_HPP_

    #include "main.hpp"

    class IMonitorModule
    {
        public:
            virtual ~IMonitorModule() {};
            virtual std::string get() = 0;
            virtual void set() = 0;
            virtual void display() = 0;
    };

#endif /* !_IMONITORMODULE_HPP_ */