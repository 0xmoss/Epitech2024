/*
** EPITECH PROJECT, 2020
** B-CCP-400-LYN-4-1-theplazza--master
** File description:
** plazza.hpp
*/

/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#ifndef PLAZZA_HPP
    #define PLAZZA_HPP

    #include <sys/wait.h>

    #include "commands.hpp"

    #include "self.hpp"


    bool arguments(int, char **, self_t *);
    self_t *builder();
    bool kitchen_builder(int, int, int, commands *commands, std::vector<std::string>, std::vector<std::string>);
    

#endif /* PLAZZA_HPP */
