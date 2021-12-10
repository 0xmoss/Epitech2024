/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM- [WSL: Ubuntu-20.04]
** File description:
** Double
*/

#pragma once
#include "IOperand.hpp"
#include <string>
#include <iostream>

class CDouble : public IOperand {
    private:
        double _value;
    public:
        CDouble(const std::string &value);

        std::string toString() const override;
        eOperandType getType() const override;
        IOperand *operator+(const IOperand &rhs) const override;
        IOperand *operator-(const IOperand &rhs) const override;
        IOperand *operator*(const IOperand &rhs) const override;
        IOperand *operator/(const IOperand &rhs) const override;
        IOperand *operator%(const IOperand &rhs) const override;
};
