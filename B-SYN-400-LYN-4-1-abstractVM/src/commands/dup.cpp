/*
** EPITECH PROJECT, 2021
** SYN_Pool
** File description:
** dup
*/

#include "abstractvm.hpp"

std::string abstractvm::vm_dup()
{
    this->stack.push_back(this->stack.back());
    return (EMPTY);
}
