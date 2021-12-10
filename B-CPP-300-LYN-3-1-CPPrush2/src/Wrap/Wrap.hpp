/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2-
** File description:
** Wrap
*/

#ifndef WRAP_HPP_
    #define WRAP_HPP_

    #include <iostream>

    #include "../Object/Object.hpp"

    #include "../Box/Box.hpp"
    #include "../GiftPaper/GiftPaper.hpp"
    #include "../Toy/Toy.hpp"

    class Wrap : public Object {
        public:
            Wrap(std::string const *name);
            ~Wrap();

            GiftPaper *wrapMeThat(Toy *, Box *, GiftPaper *);
            void openMe(Box *);
            void closeMe(Box *);
        protected:
        private:
            Box *_box;
            bool isOpen;
    };

#endif /* !WRAP_HPP_ */