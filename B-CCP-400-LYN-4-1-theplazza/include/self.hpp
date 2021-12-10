/*
** EPITECH PROJECT, 2020
** B-CCP-400-LYN-4-1-theplazza-
** File description:
** self.hpp
*/

#ifndef SELF_HPP
    #define SELF_HPP

    #include <iostream>

    typedef struct self_s
    {
        int multiplier_d;
        int cooks_d;
        int time_d;
    } self_t;

    bool arguments(int, char **, self_t *);

#endif /* SELF_HPP */
