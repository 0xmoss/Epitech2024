/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD15-paul.gardien
** File description:
** ex00.hpp
*/

#ifndef _EX00_HPP_
    #define _EX00_HPP_

    template<typename T>
    void swap(T &_argv_1, T &_argv_2) {
        T tmp = _argv_2;

        _argv_2 = _argv_1;
        _argv_1 = tmp;
    }

    template<typename T>
    const T &min(const T &_argv_1, const T &_argv_2) {
        if (_argv_1 < _argv_2)
            return (_argv_1);
        return (_argv_2);
    }

    template<typename T>
    const T &max(const T &_argv_1, const T &_argv_2) {
        if (_argv_1 > _argv_2)
            return (_argv_1);
        return (_argv_2);
    }

    template<typename T>
    T add(const T &_argv_1, const T &_argv_2) {
        return (_argv_1 + _argv_2);
    }

#endif /* !_EX00_HPP_ */

/* www.programiz.com/cpp-programming/function-template */