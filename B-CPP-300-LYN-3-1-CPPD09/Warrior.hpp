/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD09-
** File description:
** Warrior.hpp
*/

#ifndef WARRIOR_HPP_
    #define WARRIOR_HPP_

    #include "Character.hpp"

    class Warrior : public Character {
        private:
            std::string _weaponName;
        protected:
            const int defaultForce = 12;
            const int defaultEndurance = 12;
            const int defaultIntelligence = 6;
            const int defaultEsprit = 5;
            const int defaultAgilite = 7;

            const int lifeMax = 100;
            const int movMax = 100;
            const int baseAtkClose = 20;
            const int costAtkClose = 30;
            const int baseAtkRange = 0;
            const int costAtkRange = 10;
            const int baseRestorePv = 50;
            const int baseCostPv = 0;
            const int baseRestorePm = 100;
            const int baseCostPm = 0;
        public:
            Warrior(std::string const & name, int lvl);
            Warrior(std::string const & name, int lvl, std::string weaponName);
            Warrior();
            ~Warrior();

            int CloseAttack();
            int RangeAttack();
    };

#endif /* !WARRIOR_HPP_ */