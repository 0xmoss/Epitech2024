/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD06-
** File description:
** main.cpp
*/

#include <iostream>
#include <iomanip>
#include <string>

void display(float value, std::string type)
{
    const char *celsius = "Celsius";
    const char *fahrenheit = "Fahrenheit";

    if (type == celsius) {
        type = celsius;
    } else if (type == fahrenheit) {
        type = fahrenheit;
    }
    std::cout << std::setw(16) << std::fixed << std::setprecision(3) << value
    << std::setw(16) << type << std::endl;
}

void convert(std::string type, float value)
{
    std::string celsius("Celsius");
    std::string fahrenheit("Fahrenheit");

    float celsius_value = ((5.0 / 9.0) * (value - 32));
    float fahrenheit_value = ((value / (5.0 / 9.0)) + 32);

    if (type == "Celsius")
        display(fahrenheit_value, fahrenheit);
    else if (type == "Fahrenheit")
        display(celsius_value, celsius);
}

int main(void)
{
    float value;
    std::string temp;

    std::cin >> value;
    std::cin >> temp;

    convert(temp, value);
}