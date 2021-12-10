/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-
** File description:
** Table.cpp
*/

#include "Table.hpp"

Table::Table()
{
    return;
}

Table::~Table()
{
    return;
}

bool Table::and_gate(bool a, bool b)
{
    return (a && b);
}


bool Table::nand_gate(bool a, bool b)
{
    return (!a && !b);
}

bool Table::or_gate(bool a, bool b)
{
    return (a || b);
}

bool Table::nor_gate(bool a, bool b)
{
    return (!a || !b);
}

bool Table::xor_gate(bool a, bool b)
{
    return (!a != !b);
}

bool Table::not_gate(bool a, bool b)
{
    return (a != b);
}

int Table::sum_gate(bool a, bool b)
{
    return (a + b);
}