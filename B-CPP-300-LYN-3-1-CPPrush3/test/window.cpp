/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** window
*/

#include "window.hpp"

window::window()
{
    _window.create(sf::VideoMode(800, 600, 32), "SFML Window");
}

window::~window()
{
}

sf::Text window::getText(const std::string str, int size)
{
    sf::Text text(str, _font, size);
    return (text);
}

void window::start()
{
    if (!_texture.loadFromFile("assets/back.jpg"))
        return;
    _back.setTexture(_texture);
    if (!_font.loadFromFile("assets/arial.ttf"))
        return;
    while (_window.isOpen()) {
        sf::Event event;
        while (_window.pollEvent(event))
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                _window.close();
        _window.clear();
        _window.draw(_back);
//        _window.draw(getText("CPU", 50));
        _window.display();
    }
}

