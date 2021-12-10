/*
** EPITECH PROJECT, 2019
** AEnemy.hpp
** File description:
** @epitech.eu
*/

#ifndef AENEMY_HPP_
    #define AENEMY_HPP_

    #include <string>

    class AEnemy {
        private:
            int hp;
            std::string type;
        public:
            AEnemy(int, std::string const & type);
            virtual ~AEnemy();

            std::string const & getType() const;
            int getHP() const;
            virtual void takeDamage(int);
    };

#endif /* !AENEMY_HPP_ */