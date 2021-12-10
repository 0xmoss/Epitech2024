/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2- [WSL: Ubuntu-20.04]
** File description:
** ITable
*/

#ifndef ITABLE_HPP_
    #define ITABLE_HPP_

    #include "../Object/Object.hpp"

    class ITable {
        public:
            ~ITable();

            virtual void addObject(Object *obj);

            virtual Object *getObject() const;
        protected:
        private:
            Object *m_obj[11];
    };

#endif /* !ITABLE_HPP_ */
