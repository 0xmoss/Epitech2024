/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush2-
** File description:
** Elf.hpp
*/

#ifndef IELF_HPP_
    #define IELF_HPP_

    #include "../Object/Object.hpp"

    #include "../GiftPaper/GiftPaper.hpp"
    #include "../Toy/Toy.hpp"
    #include "../Box/Box.hpp"

    class IElf {
        public:
            ~IElf();

            virtual GiftPaper *wrapObject(Toy *, Box *, GiftPaper *);
            virtual void sendGift(GiftPaper *);
        protected:
        private:
    };

#endif /* !IELF_HPP_ */