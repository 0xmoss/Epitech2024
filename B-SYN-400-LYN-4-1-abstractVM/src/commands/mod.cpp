/*
** EPITECH PROJECT, 2021
** SYN_Pool
** File description:
** mod
*/

#include "abstractvm.hpp"

std::string abstractvm::vm_mod(void)
{
    if (this->stack.size() >= 2) {
        IOperand *a = this->stack.back();
        this->stack.pop_back();
        IOperand *b = this->stack.back();
        this->stack.pop_back();
        this->stack.push_back((*a)%(*b));
    } else 
        throw Exception(std::to_string(this->stack.size()), SHORT_STACK);
    return (EMPTY);
}
