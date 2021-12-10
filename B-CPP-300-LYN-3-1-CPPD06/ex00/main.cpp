/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD06-
** File description:
** main.cpp
*/

#include <iostream>
#include <fstream>
#include <string>

int argparse(int ac)
{
    std::string usage("my_cat: Usage: ./my_cat file [...]");

    if (ac < 2) {
        std::cerr << usage << std::endl;
        return (-1);
    }
    return (0);
}

int cat(char *arg)
{
    std::ifstream file(arg);
    std::string error_binary("my_cat: ");
    std::string error_type(": No such file or directory");
    char data = '\0';

    if (file.is_open()) {
        data = file.get();
        while (file.good()) {
            std::cout << data;
            data = file.get();
        }
        file.close();
        return (1);
    }
    std::cerr << error_binary << arg << error_type << std::endl;
    return (-1);

}

int main(int ac, char **argv)
{
    if (argparse(ac) == 0) {
        for (int i = 1; i < ac ; i++) {
            if (cat(argv[i]) == -1) {
                return (-1);
            }
        }
    }
}