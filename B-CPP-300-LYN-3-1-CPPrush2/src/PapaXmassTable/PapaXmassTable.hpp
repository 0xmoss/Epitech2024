/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush2-
** File description:
** PapaXmassTable.hpp
*/

#ifndef PAPAXMASSTABLE_HPP_
    #define PAPAXMASSTABLE_HPP_

    #include "../Interfaces/ITable.hpp"
    #include "../Toy/Toy.hpp"
    #include "../Box/Box.hpp"
    #include "../GiftPaper/GiftPaper.hpp"
    #include "../Object/Object.hpp"

    class PapaXmassTable {
        public:
            PapaXmassTable();
            ~PapaXmassTable();

            ITable *createTable();

            virtual void addObject(Object *obj);
            virtual Object *getObject(Object *obj);
        protected:
        private:
            Object *m_obj[11];
    };

#endif /* !PAPAXMASSTABLE_HPP_ */