/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** window
*/

#include "window.hpp"

window::window(MonitorCore *core)
{
    _window.create(sf::VideoMode(1366, 768, 32), "MyGKrellm");
    m_core = core;
    inf = {getTextTitle("User Name", 18, 0, 0), getText(m_core->name.getUsername(), 18, 25, 25), getTextTitle("Host Name", 18, 0, 50), getText(m_core->name.getHostname(), 18, 25, 75), getTextTitle("Operating System", 18, 0, 100),
getText(m_core->sys.getOs(), 18, 25, 125), getTextTitle("Kernel Release", 18, 0, 150), getText(m_core->sys.getKernelrelease(), 18, 25, 175)};
    button = {getTextButton("User and Host Names module", 18, 900, 0),
            getTextButton("Operating System and Kernel Release module", 18, 900, 30),
            getTextButton("Date and Time module", 18, 900, 60),
            getTextButton("CPU module", 18, 900, 90),
            getTextButton("RAM module", 18, 900, 120),
            getTextButton("Network load module", 18, 900, 150)};
}

window::~window()
{
}

sf::Text window::getText(const std::string str, int size, int a, int b)
{
    sf::Text text(str, _font, size);
    text.setPosition(a, b);
    return (text);
}

sf::Text window::getTextButton(const std::string str, int size, int a, int b)
{
    sf::Text text(str, _font, size);
    text.setPosition(a, b);
    text.setFillColor(sf::Color::Red);
    return (text);
}

sf::Text window::getTextTitle(const std::string str, int size, int a, int b)
{
    sf::Text text(str, _font, size);
    text.setPosition(a, b);
    text.setFillColor(sf::Color::Blue);
    return (text);
}

void window::draw_button()
{
    if (m_core->name.getActivate())
        button[0].setFillColor(sf::Color::Green);
    if (m_core->sys.getActivate())
        button[1].setFillColor(sf::Color::Green);
    if (m_core->current_date.getActivate())
        button[2].setFillColor(sf::Color::Green);
    if (m_core->_cpu.getActivate())
        button[3].setFillColor(sf::Color::Green);
    if (m_core->ram.getActivate())
        button[4].setFillColor(sf::Color::Green);
    if (m_core->net.getActivate())
        button[5].setFillColor(sf::Color::Green);
    for (int i = 0; i < 6; i++) {
        _window.draw(button[i]);
    }
}

void window::draw1()
{
    inf = {getTextTitle("User Name", 18, 0, _b), getText(m_core->name.getUsername(), 18, 25, _b + 25),
           getTextTitle("Host Name", 18, 0, _b + 50), getText(m_core->name.getHostname(), 18, 25, _b + 75),
           getTextTitle("Operating System", 18, 0, _b + 100), getText(m_core->sys.getOs(), 18, 25, _b + 125),
           getTextTitle("Kernel Release", 18, 0, _b + 150), getText(m_core->sys.getKernelrelease(), 18, 25, _b + 175)};
    _window.draw(inf[0]);
    _window.draw(inf[1]);
    _window.draw(inf[2]);
    _window.draw(inf[3]);
    _b += 100;
}

void window::draw2()
{
    inf = {getTextTitle("User Name", 18, 0, _b), getText(m_core->name.getUsername(), 18, 25, _b + 25),
           getTextTitle("Host Name", 18, 0, _b + 50), getText(m_core->name.getHostname(), 18, 25, _b + 75),
           getTextTitle("Operating System", 18, 0, _b), getText(m_core->sys.getOs(), 18, 25, _b + 25),
           getTextTitle("Kernel Release", 18, 0, _b + 50), getText(m_core->sys.getKernelrelease(), 18, 25, _b + 75)};
    _window.draw(inf[4]);
    _window.draw(inf[5]);
    _window.draw(inf[6]);
    _window.draw(inf[7]);
    _b += 100;
}

void window::draw3() {
    int r = 0, w = 0;
    _window.draw(getTextTitle("CPU", 18, 0, _b));
    std::vector<float> cpu = m_core->_cpu.calculs();
    int j = 0;
    _b += 25;
    for (auto i = cpu.begin(); i != cpu.end(); i++, j++, _b += 25) {
        int y = 5 * (*i);
        sf::RectangleShape rectangle(sf::Vector2f(100, 20));
        rectangle.setSize(sf::Vector2f(y, 20));
        rectangle.move(sf::Vector2f(240, _b));
        if ((*i) < 33)
            rectangle.setFillColor(sf::Color::Green);
        else if ((*i) >= 33 && (*i) <= 66)
            rectangle.setFillColor(sf::Color::Yellow);
        else
            rectangle.setFillColor(sf::Color::Red);
        _window.draw(rectangle);
        _window.draw(getText("CPU" + ((j != 0) ? std::to_string(j - 1) : "") + " : ", 18, 25, _b));
        _window.draw(getText(std::to_string(*i) + " %", 18, 90, _b));
        _window.draw(getText(" [", 18, 220, _b));
        _window.draw(getText(" ]", 18, 750, _b));
    }
    r = 800;
    w = 600;
    _window.draw(getTextTitle("Vendor info : ", 18, r, w));
    _window.draw(getText(m_core->_cpu.get_vendor_id(), 18, r + 120, w));
    _window.draw(getTextTitle("Model info : ", 18, r, w + 25));
    _window.draw(getText(m_core->_cpu.get_model(), 18, r + 120, w+25));
    _window.draw(getTextTitle("Frequency info : ", 18, r, w + 50));
    _window.draw(getText(m_core->_cpu.get_frequency(), 18, r + 140, w + 50));
    _window.draw(getTextTitle("Family info : ", 18, r, w + 75));
    _window.draw(getText(m_core->_cpu.get_family(), 18, r + 120, w + 75));
    _window.draw(getTextTitle("Sizez info : ", 18, r, w + 100));
    _window.draw(getText(m_core->_cpu.get_sizes(), 18, r + 120, w + 100));
}

void window::draw4() {
    float total = 0, used = 0, available = 0;
    total = m_core->ram.getTotal();
    used = m_core->ram.getUsed();
    available = m_core->ram.getAvailable();
    _window.draw(getTextTitle("RAM", 18, 0, _b));
    _window.draw(getText("Used ---> ", 18, 25, _b + 25));
    _window.draw(getText(std::to_string(used) + " GB", 18, 150, _b + 25));
    _window.draw(getText("Available ---> ", 18, 25, _b + 50));
    _window.draw(getText(std::to_string(available) + " GB", 18, 150, _b + 50));
    _window.draw(getText("Total ---> ", 18, 25, _b + 75));
    _window.draw(getText(std::to_string(total) + " GB", 18, 150, _b + 75));
    _b += 100;
}

void window::draw5() {
    _window.draw(getTextTitle("Network", 18, 0, _b));
    _window.draw(getText("WLP --- ", 18, 25, _b + 25));
    _window.draw(getText(m_core->net.get_WLP() + " bytes", 18, 150, _b + 25));
    _window.draw(getText("LO --- ", 18, 25, _b + 50));
    _window.draw(getText(m_core->net.get_LO() + " bytes", 18, 150, _b + 50));
}

void window::display_infos() {
    draw_button();
    if (m_core->name.getActivate())
        draw1();
    if (m_core->sys.getActivate())
        draw2();
    if (m_core->current_date.getActivate()) {
        _window.draw(getTextTitle("DATE & TIME", 18, 0, _b));
        _window.draw(getText(m_core->current_date.get(), 18, 25, _b + 25));
        _b += 50;
    }
    if (m_core->_cpu.getActivate())
        draw3();
    if (m_core->ram.getActivate())
        draw4();
    if (m_core->net.getActivate())
        draw5();
}


int window::check_position(sf::Text text)
{
    sf::FloatRect bound = text.getGlobalBounds();
    sf::Vector2i click_position;

    click_position = sf::Mouse::getPosition(_window);
    if ((text.getPosition().x <= click_position.x && click_position.x <= text.getPosition().x + bound.width)
&& (text.getPosition().y <= click_position.y && click_position.y <= text.getPosition().y + bound.height))
        return (1);
    return (0);
}

void window::setmethat(int i, bool f)
{
    if (i == 0)
        m_core->name.setActivate(f);
    if (i == 1)
        m_core->sys.setActivate(f);
    if (i == 2)
        m_core->current_date.setActivate(f);
    if (i == 3)
        m_core->_cpu.setActivate(f);
    if (i == 4)
        m_core->ram.setActivate(f);
    if (i == 5)
        m_core->net.setActivate(f);
}

void window::check_text()
{
    for (int i = 0; i < 6; i++)
        if (check_position(button[i])) {
            if (button[i].getFillColor() == sf::Color::Red) {
                button[i].setFillColor(sf::Color::Green);
                setmethat(i, true);
            } else if (button[i].getFillColor() == sf::Color::Green) {
                button[i].setFillColor(sf::Color::Red);
                setmethat(i, false);
            }
        }
}

void window::start()
{
    if (!_texture.loadFromFile("assets/back.jpg"))
        return;
    _back.setTexture(_texture);
    if (!_font.loadFromFile("assets/arial.ttf"))
        return;
    _window.setFramerateLimit(100);
    while (_window.isOpen()) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                _window.close();
            if (event.type == sf::Event::MouseButtonPressed)
                check_text();
        }
        _window.clear();
        _window.draw(_back);
        display_infos();
        _window.display();
        _b = 0;
    }
}