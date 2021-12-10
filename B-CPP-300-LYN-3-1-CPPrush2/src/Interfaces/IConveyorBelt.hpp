/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-
** File description:
** ConveyorBelt
*/

#ifndef CONVEYOR_HPP_
    #define CONVEYOR_HPP_

    #include "../Object/Object.hpp"

    class IConveyorBelt {
        public:
            ~IConveyorBelt();

            virtual void addObject(Object *obj) = 0;
            
            virtual Object *getObject() const = 0;

            enum Direction {IN, OUT};
        protected:
            Object *m_obj;
        private:
    };

#endif /* !CONVEYOR_HPP_ */