/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush2-
** File description:
** ConveyorBelt.cpp
*/

#include <iostream>

#include "PapaXmasConveyorBelt.hpp"

void ConveyorBelt::addObject(Object *obj)
{
    m_obj = obj;
}
        
Object *ConveyorBelt::getObject() const
{
    return(m_obj);
}

ConveyorBelt::ConveyorBelt()
{
    m_obj = nullptr;
}

ConveyorBelt::~ConveyorBelt()
{
    return;
}
