/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD10-
** File description:
** AssaultTerminator.hpp
*/

#ifndef ASSAULTTERMINATOR_HPP_
    #define ASSAULTTERMINATOR_HPP_

    #include <string>

    #include "ISpaceMarine.hpp"

    class AssaultTerminator : public ISpaceMarine {
        public:
            AssaultTerminator();
            AssaultTerminator(AssaultTerminator const & marine);
            virtual ~AssaultTerminator();

            virtual ISpaceMarine *clone() const;
            virtual void battleCry() const;
            virtual void rangedAttack() const;
            virtual void meleeAttack() const; 
    };

#endif /* !ASSAULTTERMINATOR_HPP_ */