/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "main.hpp"
#include "IMonitorDisplay.hpp"

class window : public IMonitorDisplay {
    public:
        window(MonitorCore *core);
        ~window();
        void start();
        void draw1();
        void draw2();
        void draw3();
        void draw4();
        void draw5();
        void draw_button();
        void display_infos();
        void check_text();
        void setmethat(int i, bool f);
        int check_position(sf::Text text);
        sf::Text getTextButton(const std::string str, int size, int a, int b);
        sf::Text getTextTitle(const std::string str, int size, int a, int b);
        sf::Text getText(const std::string str, int size, int a, int b);

    private:
        sf::RenderWindow _window;
        sf::Sprite _back;
        sf::Font _font;
        sf::Texture _texture;
        std::array<sf::Text, 8> inf;
        std::array<sf::Text, 6> button;
        int _a = 0;
        int _b = 0;
};


#endif /* !WINDOW_HPP_ */
