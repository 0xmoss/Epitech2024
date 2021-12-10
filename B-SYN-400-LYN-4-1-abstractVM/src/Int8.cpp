/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM- [WSL: Ubuntu-20.04]
** File description:
** INT8
*/

#include "Int8.hpp"

INT8::INT8(const std::string &value)
{
    _value = static_cast<int8_t>(atoi(value.c_str()));
    int tmp = atoi(value.c_str());

    if (tmp > 127)
        throw Exception(value, OVERFLOW);
}

std::string INT8::toString() const
{
    return std::to_string(_value);
}

eOperandType INT8::getType() const
{
    return Int8;
}

IOperand *INT8::operator+(const IOperand &rhs) const
{
    if (Int8 >= rhs.getType()) {
        INT8 *tmp = new INT8(rhs.toString());
        tmp->_value += _value;
        return tmp;
    } else {
        return rhs + *this;
    }
}

IOperand *INT8::operator-(const IOperand &rhs) const
{
    if (Int8 >= rhs.getType()) {
        INT8 *tmp = new INT8(rhs.toString());
        tmp->_value -= _value;
        return tmp;
    } else {
        INT8 *tmp = new INT8("-1");
        INT8 *tmp2 = new INT8(rhs.toString());
        tmp->_value = tmp->_value * tmp2->_value + this->_value;
        return new INT8(std::to_string(tmp->_value));
    }
}

IOperand *INT8::operator*(const IOperand &rhs) const
{
    if (Int8 >= rhs.getType()) {
        INT8 *tmp = new INT8(rhs.toString());
        tmp->_value *= _value;
        return tmp;
    } else {
        return rhs * *this;
    }
}

IOperand *INT8::operator/(const IOperand &rhs) const
{
    if (rhs.toString() == "0")
        throw Exception(rhs.toString(), DIVISION_ZERO);

    if (Int8 >= rhs.getType()) {
        INT8 *tmp = new INT8(rhs.toString());
        INT8 *tmp2 = new INT8(std::to_string(_value));
        tmp2->_value /= tmp->_value;
        return tmp2;
    } else {
        double a = atof(rhs.toString().c_str());
        double b = atof(std::to_string(_value).c_str());
        b /= a;
        return new CDouble(std::to_string(b));
    }
}

IOperand *INT8::operator%(const IOperand &rhs) const
{
    if (rhs.getType() > Int32)
         Exception(rhs.toString(), MODULO_FLOAT);
    if (rhs.toString() == "0")
        throw Exception(rhs.toString(), MODULO_ZERO);

    if (Int8 >= rhs.getType()) {
        INT8 *tmp = new INT8(rhs.toString());
        return tmp;
    } else {
        INT8 *tmp = new INT8(rhs.toString());
        INT8 *tmp2 = new INT8(std::to_string(_value));
        tmp2->_value %= tmp->_value;
        return tmp2;
    }
}
