/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-
** File description:
** MyUnitTest
*/
#include "LittlePony/LittlePony.hpp"
#include "Teddy/Teddy.hpp"
#include "Object/Object.hpp"

Object *MyUnitTests(Object  **test)
{
    if (!test && !test[0] && !test[1] && !test[2]) {
        if (!test[1]->isOpen())
            test[1]->openMe();
        test[1]->wrapMeThat(test[0]);
        test[2]->wrapMeThat(test[1]);
        return test[2];
    } else
        std::cerr << "Error, one object is missing";
}

Object **MyUnitTests(void)
{
    Object **res = new Object*[2];

    res[0] = new LittlePony("happy pony");
    res[1] = new Teddy("cuddles");
    return res;
}