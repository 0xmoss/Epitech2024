/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD07A-
** File description:
** KroegCom.cpp
*/

#include "KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial)
{
    this->_x = x;
    this->_y = y;
    this->m_serial = serial;
    this->_next = 0;

    std::cout << "KreogCom " << this->m_serial << " initialised" << std::endl;
}

KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << this->m_serial << " shutting down" << std::endl;
}

void KreogCom::addCom(int x, int y, int serial)
{
    KreogCom *com = new KreogCom(x, y, serial);
    KreogCom *tmp = this;

    while (tmp->_next)
        tmp = tmp->_next;

    com->_next = tmp->_next;
    tmp->_next = com;
}

KreogCom *KreogCom::getCom()
{
    return (_next);
}

void KreogCom::removeCom()
{
    KreogCom *del;

    if (this->_next) {
        del = this->_next;
        this->_next = this->_next->_next;
        delete del;
    }
}

void KreogCom::ping()
{
    std::cout << "KreogCom " << this->m_serial << " currently at " <<
    this->_x << " " << this->_y << std::endl;
}

void KreogCom::locateSquad()
{
    if (this->_next)
        this->_next->locateSquad();
    this->ping();
}