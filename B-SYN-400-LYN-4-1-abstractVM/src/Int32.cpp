/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM- [WSL: Ubuntu-20.04]
** File description:
** INT32
*/

#include "Int32.hpp"

INT32::INT32(const std::string &value)
{
    _value = atoi(value.c_str());
    int64_t tmp = atoi(value.c_str());

    if (tmp > 2147483647)
        throw Exception(value, OVERFLOW);
}

std::string INT32::toString() const
{
    return std::to_string(_value);
}

eOperandType INT32::getType() const
{
    return Int32;
}

IOperand *INT32::operator+(const IOperand &rhs) const
{
    if (Int32 >= rhs.getType()) {
        INT32 *tmp = new INT32(rhs.toString());
        tmp->_value += _value;
        return tmp;
    } else {
        return rhs + *this;
    }
}

IOperand *INT32::operator-(const IOperand &rhs) const
{
    if (Int32 >= rhs.getType()) {
        INT32 *tmp = new INT32(rhs.toString());
        tmp->_value -= _value;
        return tmp;
    } else {
        INT32 *tmp = new INT32("-1");
        INT32 *tmp2 = new INT32(rhs.toString());
        tmp->_value = tmp->_value * tmp2->_value + this->_value;
        return new INT32(std::to_string(tmp->_value));
    }
}

IOperand *INT32::operator*(const IOperand &rhs) const
{
    if (Int32 >= rhs.getType()) {
        INT32 *tmp = new INT32(rhs.toString());
        tmp->_value *= _value;
        return tmp;
    } else {
        return rhs * *this;
    }
}

IOperand *INT32::operator/(const IOperand &rhs) const
{
    if (rhs.toString() == "0")
        throw Exception(rhs.toString(), DIVISION_ZERO);

    if (Int32 >= rhs.getType()) {
        INT32 *tmp = new INT32(rhs.toString());
        INT32 *tmp2 = new INT32(std::to_string(_value));
        tmp2->_value /= tmp->_value;
        return tmp2;
    } else {
        double a = atof(rhs.toString().c_str());
        double b = atof(std::to_string(_value).c_str());
        b /= a;
        return new CDouble(std::to_string(b));
    }
}

IOperand *INT32::operator%(const IOperand &rhs) const
{
    if (rhs.getType() > Int32)
        throw Exception(rhs.toString(), MODULO_FLOAT);
    if (rhs.toString() == "0")
        throw Exception(rhs.toString(), MODULO_ZERO);

    INT32 *tmp = new INT32(rhs.toString());
    INT32 *tmp2 = new INT32(std::to_string(_value));
    tmp2->_value %= tmp->_value;
    return tmp2;
}
