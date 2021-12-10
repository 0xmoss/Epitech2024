/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** RAM.hpp
*/

#ifndef RAM_H
#define RAM_H

#include "main.hpp"

class RAM
{
    public:
        RAM();
        ~RAM();

        float getTotal();
        float getAvailable() const {return _available_ram_;}
        float getUsed() const {return _used_ram_;}
        bool getActivate() const {return _activate_module;}

        void setRam();
        void setActivate(bool choice);

        void display();
    private:
        float _total_ram_;
        float _available_ram_;
        float _used_ram_;
        bool _activate_module;
};
#endif