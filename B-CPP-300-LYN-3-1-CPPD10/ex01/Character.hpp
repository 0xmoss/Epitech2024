/*
** EPITECH PROJECT, 2019
** Character.hpp
** File description:
** @epitech.eu
*/

#ifndef CHARACTER_HPP_
    #define CHARACTER_HPP_

    #include <iostream>

    #include "AEnemy.hpp"
    #include "AWeapon.hpp"

    class Character {
        private:
            std::string name;
            int ap;
            AWeapon *weapon;
        public:
            Character(std::string);
            ~Character();

            void recoverAP();
            void equip(AWeapon *);
            void attack(AEnemy *);
            bool action(int);
            std::string const & getName() const;
            int getAp() const;
            AWeapon *getWeapon() const;
    };
    
    std::ostream &operator << (std::ostream &, Character const &);

#endif /* !CHARACTER_HPP_ */