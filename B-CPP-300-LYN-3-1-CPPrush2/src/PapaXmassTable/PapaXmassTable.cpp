/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush2-
** File description:
** PapaXmassTable.cpp
*/

#include <iostream>

#include "PapaXmassTable.hpp"

ITable *createTable()
{
    
}

void PapaXmassTable::addObject(Object *obj)
{
    int i = 0;

    while (m_obj[i] != NULL && i < 11) {
        i++;
    }
    if (i < 11) {
        m_obj[i] = obj;
    } else {
        std::cout << "The table collabse" << std::endl;
    }
}

Object *PapaXmassTable::getObject(Object *obj)
{
    int i = 0;

    while (m_obj[i] != NULL && i < 11) {
        i++;
    }
    if (i < 11) {
        m_obj[i] = NULL;
    } else {
        std::cout << "Nothing on the table" << std::endl;
    }
}

PapaXmassTable::PapaXmassTable()
{
    return;
}

PapaXmassTable::~PapaXmassTable()
{
    return;
}