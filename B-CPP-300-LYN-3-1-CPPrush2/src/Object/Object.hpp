/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-
** File description:
** Object
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <iostream>

class Object {
    public:
        Object(std::string const *name);
        ~Object();
        void openMe();
        bool isOpen() const;
        bool wrapMeThat(Object *);
        void closeMe();

    protected:
        std::string const *_Name;
    private:
};

#endif /* !OBJECT_HPP_ */