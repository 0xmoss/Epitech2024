/*
** EPITECH PROJECT, 2021
** SYN_Pool
** File description:
** push
*/

#include "abstractvm.hpp"
#include "Factory.hpp"

std::string abstractvm::vm_push(std::string type, std::string value)
{
    for (size_t i = 0; i < 6; i++) {
        if (type == this->types[i])
            this->stack.push_back(Factory::createOperand(static_cast<eOperandType>(i), value));
    }
    return (EMPTY);
}
