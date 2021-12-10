/*
** EPITECH PROJECT, 2021
** SYN_Pool
** File description:
** clear
*/

#include "abstractvm.hpp"

std::string abstractvm::vm_clear(void)
{
    this->stack.clear();
    return (EMPTY);
}
