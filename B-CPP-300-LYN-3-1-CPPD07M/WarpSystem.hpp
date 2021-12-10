/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD07M-
** File description:
** WarpSystem.hpp
*/

#ifndef WARPSYSTEM_H_
    #define WARPSYSTEM_H_

    #include <iostream>
    #include <string>

    namespace WarpSystem
    {
        class QuantumReactor
        {
            private:
                bool _stability;
            public:
                QuantumReactor();
                ~QuantumReactor();

                bool isStable();
                void setStability(bool);
        };

        class Core
        {
            private:
                QuantumReactor *_coreReactor;
            public:
                Core(QuantumReactor *);
                ~Core();

                bool isStable();
                void setStability(bool);
                QuantumReactor *getQuantumReactor();
                QuantumReactor *checkReactor();
        };
    };

#endif /* !WARPSYSTEM_H_ */