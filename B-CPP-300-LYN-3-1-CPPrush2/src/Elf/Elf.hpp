/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush2-
** File description:
** Elf.hpp
*/

#ifndef ELF_HPP_
    #define ELF_HPP_

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

#endif /* !ELF_HPP_ */