/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2- [WSL: Ubuntu-20.04]
** File description:
** ConveyorBelt
*/

#ifndef CONVEYORBELT_HPP_
    #define CONVEYORBELT_HPP_

    #include "../Interfaces/IConveyorBelt.hpp"

    class ConveyorBelt : public IConveyorBelt {
        public:
            ConveyorBelt();
            ~ConveyorBelt();

            IConveyorBelt *createConveyorBelt();

            virtual void addObject(Object *obj) = 0;
            
            virtual Object *getObject() const = 0;
        protected:
        private:
    };

#endif /* !CONVEYORBELT_HPP_ */