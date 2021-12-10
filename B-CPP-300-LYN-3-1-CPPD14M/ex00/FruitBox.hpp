/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD14M-
** File description:
** FruitBox.hpp
*/

#ifndef _FRUITBOX_HPP_
	#define _FRUITBOX_HPP_

    #include <iostream>
    #include <string>

    #include "Fruit.hpp"
    #include "FruitNode.hpp"

    class FruitBox {
        protected:
            int count;
            int size;
            FruitNode *_head;
        public:
            FruitBox(int);
            virtual ~FruitBox();

            bool create(Fruit *, int, FruitNode *, FruitNode *);

            int nbFruits() const;
            bool putFruit(Fruit*);
            Fruit *pickFruit();
            FruitNode *head() const;
    };

#endif /* !_FRUITBOX_HPP_ */