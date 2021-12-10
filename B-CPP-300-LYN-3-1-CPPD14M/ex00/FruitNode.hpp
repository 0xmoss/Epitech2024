/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD14M-
** File description:
** FruitNode.hpp
*/

#ifndef _FRUITNODE_HPP_
	#define _FRUITNODE_HPP_

    #include "Fruit.hpp"

    class FruitNode {
        public:
            Fruit *content;
            FruitNode *next;
    };

#endif /* !_FRUITNODE_HPP_ */