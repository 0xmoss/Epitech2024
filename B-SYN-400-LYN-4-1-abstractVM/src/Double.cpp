/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM- [WSL: Ubuntu-20.04]
** File description:
** CDouble
*/

#include "Double.hpp"

CDouble::CDouble(const std::string &value)
{
    _value = static_cast<double>(atof(value.c_str()));
}

std::string CDouble::toString() const
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

eOperandType CDouble::getType() const
{
    return Double;
}

IOperand *CDouble::operator+(const IOperand &rhs) const
{
    if (Double >= rhs.getType()) {
        CDouble *tmp = new CDouble(rhs.toString());
        tmp->_value += _value;
        return tmp;
    } else {
        return rhs + *this;
    }
}

IOperand *CDouble::operator-(const IOperand &rhs) const
{
    if (Double >= rhs.getType()) {
        CDouble *tmp = new CDouble(rhs.toString());
        tmp->_value -= _value;
        return tmp;
    } else {
        CDouble *tmp = new CDouble("-1");
        CDouble *tmp2 = new CDouble(rhs.toString());
        tmp->_value = tmp->_value * tmp2->_value + this->_value;
        return new CDouble(std::to_string(tmp->_value));
    }
}

IOperand *CDouble::operator*(const IOperand &rhs) const
{
    if (Double >= rhs.getType()) {
        CDouble *tmp = new CDouble(rhs.toString());
        tmp->_value *= _value;
        return tmp;
    } else {
        return rhs * *this;
    }
}

IOperand *CDouble::operator/(const IOperand &rhs) const
{
    if (atoi(rhs.toString().c_str()) == 0)
        throw Exception(rhs.toString(), DIVISION_ZERO);

    if (Double >= rhs.getType()) {
        CDouble *tmp = new CDouble(rhs.toString());
        CDouble *tmp2 = new CDouble(std::to_string(_value));
        tmp2->_value /= tmp->_value;
        return tmp2;
    } else {
        double a = atof(rhs.toString().c_str());
        double b = atof(std::to_string(_value).c_str());
        b /= a;
        return new CDouble(std::to_string(b));   
    }
}

IOperand *CDouble::operator%(const IOperand &rhs) const
{
    throw Exception(rhs.toString(), MODULO_FLOAT);
}
