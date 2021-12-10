/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD09-
** File description:
** Character.hpp
*/

#ifndef CHARACTER_H_
    #define CHARACTER_H_

    #include <iostream>
    #include <string>

    typedef enum AttackRange_e {
        AR_CLOSE,
        AR_RANGE
    } AttackRange;

    class Character {
        private:
            std::string name;
            std::string race;
            std::string weaponClose;
            std::string weaponRange;
            int level;
            int pv;
            int pm;
            int force;
            int endurance;
            int intelligence;
            int esprit;
            int agilite;
            int atkClose;
            int costClose;
            int atkRange;
            int costRange;
            int restorePv;
            int costPv;
            int restorePm;
            int costPm;
            int const Character::*bonusCloseAttack;
            int const Character::*bonusRangeAttack;
            int const Character::*bonusRestorePm;

            const int defaultForce = 5;
            const int defaultEndurance = 5;
            const int defaultIntelligence = 5;
            const int defaultEsprit = 5;
            const int defaultAgilite = 5;

            const int lifeMax = 100;
            const int movMax = 100;
            const int baseAtkClose = 10;
            const int costAtkClose = 10;
            const int baseAtkRange = 5;
            const int costAtkRange = 10;
            const int baseRestorePv = 50;
            const int baseCostPv = 0;
            const int baseRestorePm = 100;
            const int baseCostPm = 0;
        public:
            Character (const std::string &, int);
            ~Character();

            // Vars
            const AttackRange CLOSE = AR_CLOSE;
            const AttackRange RANGE = AR_RANGE;
            AttackRange Range;

            // Get
            std::string const & getName() const;
            int getLvl() const;
            int getPv() const;
            int getPower() const;
            int getForce() const;
            int getEndurance() const;
            int getIntelligence() const;
            int getEsprit() const;
            int getAgilite() const;

            void changePv(int value);
            void changePm(int value);

            int CloseAttack();
            int RangeAttack();
            void Heal();
            void RestorePower();
            void TakeDamage(int damage);

            bool actionCost(int cost);
            void display(std::string message) const;
    };

#endif /* !CHARACTER_H_ */