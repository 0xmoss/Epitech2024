/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM- [WSL: Ubuntu-20.04]
** File description:
** INT16
*/

#include "Int16.hpp"

INT16::INT16(const std::string &value)
{
    _value = static_cast<int16_t>(atoi(value.c_str()));
    int tmp = atoi(value.c_str());

    if (tmp > 32767)
        throw Exception(value, OVERFLOW);
}

std::string INT16::toString() const
{
    return std::to_string(_value);
}

eOperandType INT16::getType() const
{
    return Int16;
}

IOperand *INT16::operator+(const IOperand &rhs) const
{
    if (Int16 >= rhs.getType()) {
        INT16 *tmp = new INT16(rhs.toString());
        tmp->_value += _value;
        return tmp;
    } else {
        return rhs + *this;
    }
}

IOperand *INT16::operator-(const IOperand &rhs) const
{
    if (Int16 >= rhs.getType()) {
        INT16 *tmp = new INT16(rhs.toString());
        tmp->_value -= _value;
        return tmp;
    } else {
        INT16 *tmp = new INT16("-1");
        INT16 *tmp2 = new INT16(rhs.toString());
        tmp->_value = tmp->_value * tmp2->_value + this->_value;
        return new INT16(std::to_string(tmp->_value));
    }
}

IOperand *INT16::operator*(const IOperand &rhs) const
{
    if (Int16 >= rhs.getType()) {
        INT16 *tmp = new INT16(rhs.toString());
        tmp->_value *= _value;
        return tmp;
    } else {
        return rhs * *this;
    }
}

IOperand *INT16::operator/(const IOperand &rhs) const
{
    if (rhs.toString() == "0")
        throw Exception(rhs.toString(), DIVISION_ZERO);

    if (Int16 >= rhs.getType()) {
        INT16 *tmp = new INT16(rhs.toString());
        INT16 *tmp2 = new INT16(std::to_string(_value));
        tmp2->_value /= tmp->_value;
        return tmp2;
    } else {
        double a = atof(rhs.toString().c_str());
        double b = atof(std::to_string(_value).c_str());
        b /= a;
        return new CDouble(std::to_string(b)); 
    }
}

IOperand *INT16::operator%(const IOperand &rhs) const
{
    if (rhs.getType() > Int32)
        throw Exception(rhs.toString(), MODULO_FLOAT);
    if (rhs.toString() == "0")
        throw Exception(rhs.toString(), MODULO_ZERO);

    if (Int16 >= rhs.getType()) {
        INT16 *tmp = new INT16(rhs.toString());
        return tmp;
    } else {
        INT16 *tmp = new INT16(rhs.toString());
        INT16 *tmp2 = new INT16(std::to_string(_value));
        tmp2->_value %= tmp->_value;
        return tmp2;
    }
}
