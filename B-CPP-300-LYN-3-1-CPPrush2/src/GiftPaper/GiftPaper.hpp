/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush2-
** File description:
** GiftPaper.hpp
*/

#ifndef GIFTPAPER_HPP_
    #define GIFTPAPER_HPP_

    #include <iostream>

    #include "../Box/Box.hpp"
    #include "../Wrap/Wrap.hpp"

    class GiftPaper : public Wrap {
        public:
            GiftPaper();
            ~GiftPaper();

            bool isReady(GiftPaper *);
        private:
            bool _isReady;
    };

#endif /* !GIFTPAPER_HPP_ */