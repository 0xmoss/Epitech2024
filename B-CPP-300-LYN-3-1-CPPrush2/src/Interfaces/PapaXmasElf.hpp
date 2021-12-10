/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush2-
** File description:
** PapaXmasElf.hpp
*/

#ifndef PAPAXMASELF_HPP_
    #define PAPAXMASELF_HPP_

    #include "../Interfaces/IElf.hpp"

    class Elf : public IElf {
        public:
            Elf();
            ~Elf();

            GiftPaper *wrapObject(Toy *, Box *, GiftPaper *);
            void Elf::sendGift(GiftPaper *);
        protected:
        private:
    };

#endif /* !PAPAXMASELF_HPP_ */
