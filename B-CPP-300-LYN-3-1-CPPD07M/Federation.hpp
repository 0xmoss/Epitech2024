/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD07M-
** File description:
** Federation.hpp
*/

#ifndef FEDERATION_H_
    #define FEDERATION_H_

    #include <iostream>
    #include <string>

    #include "WarpSystem.hpp"

    namespace Federation
    {
        namespace Starfleet
        {
            class Captain;
            class Ensign;
            class Ship;
        };
        class Ship;
    };

    namespace Federation
    {
        namespace Starfleet
        {
            class Captain {
                private:
                    std::string _name;
                    int _age;
                public:
                    Captain(std::string);
                    ~Captain();

                    std::string getName();
                    int getAge();
                    void setAge(int age);
            };

            class Ensign {
                private:
                    std::string _name;
                public:
                    Ensign(std::string);
                    ~Ensign();

                    void speak(std::string);
            };

            class Ship {
                private:
                    int _length;
                    int _width;
                    std::string _name;
                    short _maxWarp;
                    Captain *capt;

                    WarpSystem::Core *_core;
                public:
                    Ship(int, int, std::string, short);
                    Ship(int, int, std::string);
                    ~Ship();

                    void setupCore(WarpSystem::Core *);
                    void checkCore();

                    void promote(Captain *captain);
            };
        };

        class Ship {
            private:
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;

                WarpSystem::Core *_core;
            public:
                Ship(int, int, std::string, short);
                Ship(int, int, std::string);
                ~Ship();

                void setupCore(WarpSystem::Core *);
                void checkCore();
        };
    };

#endif /* !FEDERATION_H_ */