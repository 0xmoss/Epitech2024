/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** MonitorCore
*/

#ifndef _MONITORCORE_HPP_
#define _MONITORCORE_HPP_

#include "main.hpp"
#include "errors.hpp"
#include "engine.hpp"
#include "username.hpp"
#include "date.hpp"
#include "systemInfo.hpp"
#include "CPU.hpp"
#include "RAM.hpp"
#include "network.hpp"

class MonitorCore
{
    public:
        MonitorCore() {};
        virtual ~MonitorCore() {};

    date current_date;
    nameInfo name;
    systemInfo sys;
    CPU _cpu;
    RAM ram;
    network net;
};

#endif /* !_MONITORCORE_HPP_ */