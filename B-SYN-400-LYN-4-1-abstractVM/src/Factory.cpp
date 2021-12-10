/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM- [WSL: Ubuntu-20.04]
** File description:
** Factory
*/

#include "Factory.hpp"

IOperand *Factory::createOperand(eOperandType type ,const std::string& value)
{
    Factory fact = Factory();

    switch (type) {
    case Int8:
        return fact.createInt8(value);
    case Int16:
        return fact.createInt16(value);
    case Int32:
        return fact.createInt32(value);
    case Float:
        return fact.createFloat(value);
    case Double:
        return fact.createDouble(value);
    case BigDecimal:
        return fact.createDouble(value);
    }
}

IOperand *Factory::createInt8(const std::string& value)
{
    return new INT8(value);
}

IOperand *Factory::createInt16(const std::string& value)
{
    return new INT16(value);
}

IOperand *Factory::createInt32(const std::string& value)
{
    return new INT32(value);
}

IOperand *Factory::createFloat(const std::string& value)
{
    return new CFloat(value);
}

IOperand *Factory::createDouble(const std::string& value)
{
    return new CDouble(value);
}

IOperand *Factory::createBigDecimal(const std::string& value)
{
    return new CDouble(value);
    //return new BigDecimal(BigDecimal, value);
    //return nullptr;
}
