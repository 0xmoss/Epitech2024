/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD10-
** File description:
** TacticalMarine.hpp
*/

#ifndef TACTICALMARINE_HPP_
    #define TACTICALMARINE_HPP_

    #include <string>

    #include "ISpaceMarine.hpp"

    class TacticalMarine :public ISpaceMarine {
        public:
            TacticalMarine();
            TacticalMarine(TacticalMarine const &);
            virtual ~TacticalMarine();

            virtual ISpaceMarine *clone() const;
            virtual void battleCry() const;
            virtual void rangedAttack() const;
            virtual void meleeAttack() const;
        protected:
            void speak(std::string message) const;
    };

#endif /* !TACTICALMARINE_HPP_ */