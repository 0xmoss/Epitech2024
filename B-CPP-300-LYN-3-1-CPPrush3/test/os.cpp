/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** os.cpp
*/

#include <stdio.h>

#include "os.hpp"

os::os()
{
    this->_os_ = "_EMPTY_";

    return;
}

os::~os()
{
    return;
}

void os::set()
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

std::string os::get() 
{
    if (this->_os_ == "_EMPTY_") {
        set();
    }

	return (this->_os_);
}

void os::display()
{
    std::cout << get() << std::endl;

    return;
}