/*
** EPITECH PROJECT, 2021
** SYN_Pool
** File description:
** dump
*/

#include "abstractvm.hpp"

std::string abstractvm::vm_dump()
{
    if (stack.size() == 0)
        return (EMPTY);
    for (size_t i = this->stack.size(); i != 0 ; i--) {
        std::cout << this->stack[i - 1]->toString() << std::endl;
    }
    return (EMPTY);
}
