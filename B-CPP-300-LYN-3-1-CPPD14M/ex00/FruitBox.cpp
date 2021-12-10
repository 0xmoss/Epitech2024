/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD14M-
** File description:
** FruitBox.cpp
*/

#include <iostream>

#include "FruitBox.hpp"

FruitBox::FruitBox(int size) : count(0), size(size), _head(NULL)
{
    return;
}

FruitBox::~FruitBox()
{
    return;
}

int FruitBox::nbFruits() const
{
    return (this->count);
}

bool FruitBox::putFruit(Fruit *fruit)
{
    FruitNode *tmp;
    FruitNode* new_node;

    if (this->nbFruits() == this->size)
        return (false);
    new_node = new FruitNode;
    new_node->next = NULL;
    new_node->content = fruit; 
    if (_head == NULL)
        _head = new_node;
    else {
        for (tmp = _head; tmp->next != NULL; tmp = tmp->next);
        tmp->next = new_node;
    }
    this->count++;
    return (true);
}

Fruit *FruitBox::pickFruit()    
{
    FruitNode *tmp;
    Fruit *fruit;

    if (this->_head != NULL) {
        fruit = this->_head->content;
        tmp = _head;
        _head = _head->next;
        this->count--;
        delete tmp;
        return (fruit);
    }

    return (NULL);
}

FruitNode *FruitBox::head() const
{
    return (this->_head);
}