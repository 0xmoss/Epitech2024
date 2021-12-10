/*
** EPITECH PROJECT, 2021
** SYN_Pool
** File description:
** print
*/


#include "abstractvm.hpp"

std::string abstractvm::vm_print(void)
{
    if (stack.size() == 0)
        throw Exception("The stack is empty", EMPTY_STACK);
    if (stack[stack.size() - 1]->getType() == Int8)
        std::cout << static_cast<char>(std::stoi(this->stack.back()->toString())) << std::endl;
    else 
        throw Exception(this->stack.back()->toString(), INVALID_TYPE_VALUE);
    return (EMPTY);
}
