/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM- [WSL: Ubuntu-20.04]
** File description:
** Int16
*/

#pragma once
#include "IOperand.hpp"
#include "Double.hpp"
#include <string>
#include <iostream>

class INT16 : public IOperand {
    private:
        int16_t _value;
    public:
        INT16(const std::string &value);

        std::string toString() const override;
        eOperandType getType() const override;
        IOperand *operator+(const IOperand &rhs) const override;
        IOperand *operator-(const IOperand &rhs) const override;
        IOperand *operator*(const IOperand &rhs) const override;
        IOperand *operator/(const IOperand &rhs) const override;
        IOperand *operator%(const IOperand &rhs) const override;
};
