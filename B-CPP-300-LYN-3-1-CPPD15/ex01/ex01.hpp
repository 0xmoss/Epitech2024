/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD15-paul.gardien
** File description:
** ex01.hpp
*/

#ifndef _EX01_HPP_
    #define _EX01_HPP_

    #include <string>
    #include <cstring>

    template<typename T>
    int compare(const T &_argv_1, const T &_argv_2) {
        if (_argv_1 < _argv_2)
            return (-1);
        if (_argv_1 > _argv_2)
            return (1);
        return (0);
    }

    template<>
    int compare<const char *>(
        const char *const &_argv_1, const char * const &_argv_2) {
        int res = strcmp(_argv_1, _argv_2);

        if (res > 0)
            return(1);
        if (res < 0)
            return(-1);
        return(0);
    }

#endif /* !_EX01_HPP_ */

/* www.programiz.com/cpp-programming/function-template */