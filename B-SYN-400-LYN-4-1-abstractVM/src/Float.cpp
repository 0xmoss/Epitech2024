/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM- [WSL: Ubuntu-20.04]
** File description:
** CFloat
*/

#include "Float.hpp"

CFloat::CFloat(const std::string &value)
{
    _value = static_cast<float>(atof(value.c_str()));
}

std::string CFloat::toString() const
{
    std::string str = std::to_string(_value);
    char c = ' ';
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == '.') {
            i += 3;
            c = str[i];
            for (size_t j = i; j < str.size(); i++)
                str.erase(j, 1);
            double tmp = atof(str.c_str());
            int d = c - '0';
            if (d >= 5) {
                tmp += 0.01;
            }
            str = std::to_string(tmp);
        }
    }

    str.erase(str.find_last_not_of('0') + 1, std::string::npos);
    if (str[str.size() - 1] == '.')
        str.pop_back();
    return str;
}

eOperandType CFloat::getType() const
{
    return Float;
}

IOperand *CFloat::operator+(const IOperand &rhs) const
{
    if (Float >= rhs.getType()) {
        CFloat *tmp = new CFloat(rhs.toString());
        tmp->_value += _value;
        return tmp;
    } else {
        return rhs + *this;
    }
}

IOperand *CFloat::operator-(const IOperand &rhs) const
{
    if (Float >= rhs.getType()) {
        CFloat *tmp = new CFloat(rhs.toString());
        tmp->_value -= _value;
        return tmp;
    } else {
        CFloat *tmp = new CFloat("-1");
        CFloat *tmp2 = new CFloat(rhs.toString());
        tmp->_value = tmp->_value * tmp2->_value + this->_value;
        return new CFloat(std::to_string(tmp->_value));
    }
}

IOperand *CFloat::operator*(const IOperand &rhs) const
{
    if (Float >= rhs.getType()) {
        CFloat *tmp = new CFloat(rhs.toString());
        tmp->_value *= _value;
        return tmp;
    } else {
        return rhs * *this;
    }
}

IOperand *CFloat::operator/(const IOperand &rhs) const
{
    if (atoi(rhs.toString().c_str()) == 0)
        throw Exception(rhs.toString(), DIVISION_ZERO);

    if (Float >= rhs.getType()) {
        CFloat *tmp = new CFloat(rhs.toString());
        CFloat *tmp2 = new CFloat(std::to_string(_value));
        tmp2->_value /= tmp->_value;
        return tmp2;
    } else {
        double a = atof(rhs.toString().c_str());
        double b = atof(std::to_string(_value).c_str());
        b /= a;
        return new CDouble(std::to_string(b));
    }
}

IOperand *CFloat::operator%(const IOperand &rhs) const
{
    throw Exception(rhs.toString(), MODULO_FLOAT);
}
