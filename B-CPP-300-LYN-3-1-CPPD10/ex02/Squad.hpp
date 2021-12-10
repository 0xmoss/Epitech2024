/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD10-
** File description:
** Squad.hpp
*/

#ifndef SQUAD_HPP_
    #define SQUAD_HPP_

    #include "ISquad.hpp"
    #include "ISpaceMarine.hpp"

    class Squad : public ISquad {
        public:
            Squad(Squad const &);
            Squad();
            virtual ~Squad();

            int getCount() const;
            ISpaceMarine *getUnit(int);
            int push(ISpaceMarine*);
            Squad & operator=(Squad const &);
        protected:
            int count;
            int size;
            ISpaceMarine **array;
            void resize();
    };

#endif /* !SQUAD_HPP_ */