/*
** EPITECH PROJECT, 2019
** Character.cpp
** File description:
** @epitech.eu
*/

#include "Character.hpp"

Character::Character(std::string _name)
{
    this->name = _name;
    this->ap = 40;

}

Character::~Character()
{
    return;
}

void Character::recoverAP()
{
    this->ap += 10;
    if (this->ap > 40)
        ap = 40;
}

void Character::equip(AWeapon *weapon)
{
    this->weapon = weapon;
}

void Character::attack(AEnemy *enemy)
{
    if (this->weapon && enemy) {
        if (this->action(this->weapon->getAPCost())) {
            std::cout << name << " attacks " << enemy->getType() <<
            " with a " << weapon->getName() << std::endl;
            this->weapon->attack();
            enemy->takeDamage(this->weapon->getDamage());
            if (enemy->getHP() <= 0)
                delete enemy;
        }
    }
    
}

bool Character::action(int val)
{
    if (this->ap >= val) {
        this->ap -= val;
        return(true);
    }
    return(false);
}

std::string const & Character::getName() const
{
    return(this->name);
}

int Character::getAp() const
{
    return(this->ap);
}

AWeapon *Character::getWeapon() const
{
    return(this->weapon);
}

std::ostream &operator<<(std::ostream &os, Character const &perso)
{
    os << perso.getName() <<  " has " << perso.getAp() << " AP and ";
    if (perso.getWeapon())
        os << "wields a " << perso.getWeapon()->getName();
    else
        os << "is unarmed";
    os << std::endl;
    return(os);
}
