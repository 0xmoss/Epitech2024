/*
** EPITECH PROJECT, 2021
** SYN_Pool
** File description:
** pop
*/


#include "abstractvm.hpp"

std::string abstractvm::vm_pop(void)
{
    if (!this->stack.empty())
        this->stack.pop_back();
    else
        throw Exception("0", EMPTY_STACK);
    return (EMPTY);
}
