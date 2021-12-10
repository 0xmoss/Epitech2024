/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** systemInfo.cpp
*/

#include <stdio.h>

#include "systemInfo.hpp"

systemInfo::systemInfo()
{
    setOs();
    setKernel();
    this->_activate_module = false;
}

systemInfo::~systemInfo()
{
}

void systemInfo::setOs()
{
    std::string detect = "Unknown";

    #if __APPLE__
	    detect = "Mac OS";
	#elif _WIN64
	    detect = "Windows 64";
    #elif _WIN32
	    detect = "Windows 32";
	#elif __unix__
	    detect = "Linux";
	#elif BSD
	    detect = "FreeBSD";
	#endif

    this->_os_ = detect;
}

void systemInfo::setKernel()
{
    struct utsname sysinfo;
    std::string kernel_name = "_ERROR_";
    std::string kernel_release = "_ERROR_";

    if (uname(&sysinfo) != -1) {
        kernel_name = sysinfo.sysname;
        kernel_release = sysinfo.release;
    }
    this->_kernel_name_ = kernel_name;
    this->_kernel_release_ = kernel_release;
}

void systemInfo::setActivate(bool choice)
{
    this->_activate_module = choice;
}

void systemInfo::display()
{
    std::cout << "OS : " << getOs() << "\t Kernelname : " << getKernelname() << "\t Kernelrelease : " << getKernelrelease() <<std::endl;

    return;
}