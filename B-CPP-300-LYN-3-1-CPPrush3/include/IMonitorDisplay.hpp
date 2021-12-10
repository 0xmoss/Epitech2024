/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** IMonitorDisplay
*/

#ifndef _IMONITORDISPLAY_HPP_
	#define _IMONITORDISPLAY_HPP_

    #include "main.hpp"
    #include "errors.hpp"
    #include "engine.hpp"
    #include "username.hpp"
    #include "date.hpp"
    #include "monitorcore.hpp"
    #include "systemInfo.hpp"

    class IMonitorDisplay
    {
        public:
            virtual ~IMonitorDisplay() {};

            MonitorCore *m_core = nullptr;
    };

#endif /* !_IMONITORDISPLAY_HPP_ */