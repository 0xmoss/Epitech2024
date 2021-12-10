/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD07M-
** File description:
** Borg.hpp
*/

#ifndef BORG_H_
    #define BORG_H_

    #include <iostream>
    #include <string>

    #include "WarpSystem.hpp"

    namespace Borg
    {
        class Ship;
    };

    namespace Borg
    {
        class Ship {
            private:
                int _side;
                short _maxWarp;
                WarpSystem::Core *_core;
            public:
                Ship();
                ~Ship();

                WarpSystem::Core *getCore();
                void setCore(WarpSystem::Core *);
                void setupCore(WarpSystem::Core *);
                void checkCore();
                bool isStable();
        };
    };

#endif /* !BORG_H_ */