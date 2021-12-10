/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD15-paul.gardien
** File description:
** ex02.hpp
*/

#ifndef _EX02_HPP_
    #define _EX02_HPP_

    #include <iostream>
    #include <string>

    const int min(const int _argv_1, const int _argv_2)
    {
        std::cout << "non-template min" << std::endl;

        if (_argv_1 <= _argv_2)
            return (_argv_1);
        return (_argv_2);
    }

    template<typename T>
    const T &min(const T &_argv_1, const T &_argv_2)
    {
        std::cout << "template min" << std::endl;

        if (_argv_1 <= _argv_2)
            return (_argv_1);
        return (_argv_2);
    }

    int nonTemplateMin(int * _argv_1, int _argv_2)
    {
        int smaller = _argv_1[0];

        for (int i = 1; i < _argv_2; i++)
            smaller = min(smaller, _argv_1[i]);
        return (smaller);
    }

    template<typename T>
    T &templateMin(const T *_argv_1, int _argv_2)
    {
        T &smaller = const_cast<T&>(_argv_1[0]);

        for (int i = 1; i < size; i++)
            smaller = min<T>(smaller, _argv_1[i]);
        return (smaller);
    }

#endif /* !_EX02_HPP_ */