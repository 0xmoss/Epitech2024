/*
** EPITECH PROJECT, 2021
** SYN_Pool
** File description:
** assert
*/

#include "abstractvm.hpp"

std::string abstractvm::vm_assert(std::string type, std::string value)
{
    for (size_t i = 0; i < 5; i++) {
        if (this->types[i] == type && static_cast<eOperandType>(i) == this->stack.back()->getType()
        && value == this->stack.back()->toString())
            return (EMPTY);
    }
    throw Exception(value, ASSERT);    
    return (EMPTY);
}
