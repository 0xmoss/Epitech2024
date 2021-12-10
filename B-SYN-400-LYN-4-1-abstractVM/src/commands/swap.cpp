/*
** EPITECH PROJECT, 2021
** SYN_Pool
** File description:
** swap
*/


#include "abstractvm.hpp"

std::string abstractvm::vm_swap()
{
    if (this->stack.size() >= 2) {
        IOperand *stock = this->stack.back();
        this->stack.back() = this->stack[this->stack.size() - 2];
        this->stack[this->stack.size() - 2] = stock;
    } 
    return (EMPTY);
}
