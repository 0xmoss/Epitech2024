/*
** EPITECH PROJECT, 2021
** SYN_Pool
** File description:
** load
*/

#include "abstractvm.hpp"

std::string abstractvm::vm_load(std::string type, std::string value)
{
    if ((strcmp(type.c_str(), "int8") ||strcmp(type.c_str(), "int16") 
    || strcmp(type.c_str(), "int32")) && (std::stoi(value) >= 0 && std::stoi(value) <= 15)
    && this->regist[std::stoi(value)]) {
        this->stack.push_back(this->regist[std::stoi(value)]);
    } else 
        throw Exception("0", EMPTY_REGISTER);
    return (EMPTY);
}
