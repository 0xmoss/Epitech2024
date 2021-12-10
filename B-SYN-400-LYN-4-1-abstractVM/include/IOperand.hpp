/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM- [WSL: Ubuntu-20.04]
** File description:
** IOperand
*/

#pragma once

#include <string>
#include "errors.hpp"

enum eOperandType {
    Int8,
    Int16,
    Int32,
    Float,
    Double,
    BigDecimal
};

class  IOperand {
    public:
        virtual std::string toString() const = 0; 
        virtual eOperandType getType() const = 0; 
        
        virtual IOperand *operator +(const IOperand &rhs) const = 0;
        virtual IOperand *operator -(const IOperand &rhs) const = 0;
        virtual IOperand *operator *(const IOperand &rhs) const = 0;
        virtual IOperand *operator /(const IOperand &rhs) const = 0;
        virtual IOperand *operator %(const IOperand &rhs) const = 0;
        virtual  ~IOperand() {}
};
