/*
** EPITECH PROJECT, 2021
** SYN_Pool
** File description:
** store
*/

#include "abstractvm.hpp"

std::string abstractvm::vm_store(std::string type, std::string value)
{
    if ((strcmp(type.c_str(), "int8") ||strcmp(type.c_str(), "int16") 
    || strcmp(type.c_str(), "int32")) && (std::stoi(value) >= 0 
    && std::stoi(value) <= 15) && this->stack.size() > 0) {
        this->regist[std::stoi(value)] = this->stack.back();
        this->stack.pop_back();
    }
    return (EMPTY);
}
