/*
** EPITECH PROJECT, 2019
** Federation.cpp
** File description:
** @epitech.eu
*/

#include "Federation.hpp"
#include "WarpSystem.hpp"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = maxWarp;

    std::cout << "The ship USS " << this->_name << " has been finished." << std::endl;
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << this->_maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::Ship(int length, int width, std::string name)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;

    std::cout << "The ship USS " << this->_name << " has been finished." << std::endl;
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
}

Federation::Ship::Ship(int len,int width, std::string name, short maxWarp)
{
    this->_length = len;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = maxWarp;

    std::cout << "The independent ship " << this->_name << " has been finished." << std::endl;
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << this->_maxWarp << "!" << std::endl;
}

Federation::Ship::Ship(int len,int width, std::string name)
{
    this->_length = len;
    this->_width = width;
    this->_name = name;

    std::cout << "The independent ship " << this->_name << " just finished its construction." << std::endl;
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{
    return;
}

Federation::Ship::~Ship()
{
    return;
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;

    std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    if (this->_core) {
        if (this->_core->checkReactor()->isStable() == true)
            std::cout << "USS " << this->_name <<
            ": The core is stable at the time." << std::endl;
        else
            std::cout << "USS " << this->_name <<
            ": The core is unstable at the time." << std::endl;
    }
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;

    std::cout << this->_name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore()
{
    if (this->_core) {
        if (this->_core->checkReactor()->isStable() == true)
            std::cout << this->_name <<
            ": The core is stable at the time." << std::endl;
        else
            std::cout << this->_name <<
            ": The core is unstable at the time." << std::endl;
    }   
}

Federation::Starfleet::Captain::Captain(std::string name)
{
    this->_name = name;
}

Federation::Starfleet::Captain::~Captain()
{
    return;
}

std::string Federation::Starfleet::Captain::getName()
{
    return(this->_name);
}

int Federation::Starfleet::Captain::getAge()
{
    return(this->_age);
}

void Federation::Starfleet::Captain::setAge(int nb)
{
    this->_age = nb;
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    this->_name = name;
    std::cout << "Ensign " << name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{
    return;
}

void Federation::Starfleet::Ensign::speak(std::string message)
{

    std::cout << "Ensign " << this->_name << ", " << message << std::endl;
}

void Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *capt)
{
    this->capt = capt;
    std::cout << capt->getName() << ": I'm glad to be the captain of the USS "
        << this->_name << "." << std::endl;
}