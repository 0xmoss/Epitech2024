/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** network.cpp
*/

#include "network.hpp"

#include "main.hpp"

network::network()
{
    _activate_module = false;
}

network::~network()
{
    return;
}

void network::set_WLP(std::string up)
{
    this->wlp = up;

    return;
}

void network::set_LO(std::string down)
{
    this->lo = down;

    return;
}

std::string network::get_WLP()
{
    network::set();

    return (this->wlp);
}

std::string network::get_LO()
{
    network::set();

    return (this->lo);
}

void network::display()
{
    std::cout << "WLP: " << network::get_WLP() << std::endl;
    std::cout << "LO:  " << network::get_LO() << std::endl;

    return;
}

void network::set()
{
    int	max = 0;
    int	a = 0;
    int	i = 0;
    bool first = true;

    std::string src = "/proc/net/dev";
    std::string	line;
    std::ifstream file(src.c_str(), std::ios::in);
    std::string	temp;

    while (std::getline(file, line)) {
        if ((a = line.find(":")) != -1) {
            a++;
            while (line[a] == ' ')
                a++;
            while (line[a] != ' ') {
                temp += line[a];
                a++;
            }
            if (std::stoi(temp) > max) {
                if (first == true)
                    network::set_WLP(temp);
                temp.erase();
                while (i != 7) {
                    while (line[a] == ' ')
                        a++;
                    while (line[a] != ' ')
                        a++;
                    i++;
                }
                i = 0;
                while (line[a] == ' ')
                    a++;
                while (line[a] != ' ') {
                    temp += line[a];
                    a++;
                }
                    network::set_LO(temp);
                first = false;
            }
        }
        temp.erase();
    }
    file.close();
}  