/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** systemInfo.hpp
*/

#ifndef _OS_HPP_
    #define _OS_HPP_

    #include "main.hpp"
    #include <iostream>
    #include <sys/utsname.h>

class systemInfo {
    public:
        systemInfo();
        ~systemInfo();

        // GET OS
        std::string getOs() const {return _os_;}
        std::string getKernelname() const {return _kernel_name_;}
        std::string getKernelrelease() const {return _kernel_release_;}
        bool getActivate() const {return _activate_module;}

        // SET OS
        void setOs();
        void setKernel();
        void setActivate(bool choice);

        // DISPLAY OS
        void display();
    private:
        std::string _os_;
        std::string _kernel_name_;
        std::string _kernel_release_;
        bool _activate_module;
};

#endif /* !_OS_HPP_ */