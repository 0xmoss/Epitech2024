/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** nCurses
*/

#include "nCurses.hpp"
#include "main.hpp"

nCurses::nCurses(MonitorCore *core)
{
    initscr();
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);

    scrollok(stdscr, TRUE);
    m_core = core;

    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);

    return;
}

nCurses::~nCurses()
{
    return;
}

void nCurses::start()
{
    while (1)
    {
        clear();

        if ((m_core->current_date.getActivate()))
            printTime();

        if ((m_core->sys.getActivate()))
            printSys();

        if ((m_core->name.getActivate()))
            printUser();

        if ((m_core->ram.getActivate()))
            printRam();

        if ((m_core->_cpu.getActivate()))
            printCPU();

        if ((m_core->net.getActivate()))
            printNet();

        if (key())
        {
            endwin();
            break;
        }

        usleep(10000);
        refresh();
    }
}

void nCurses::printUser()
{
    attron(A_BOLD);
    attron(COLOR_PAIR(1));
    printw("User info : \n\t");
    attroff(A_BOLD);
    attroff(COLOR_PAIR(1));

    printw("%s\n\t", m_core->name.getHostname().c_str());
    printw("%s\n\n", m_core->name.getUsername().c_str());
}

void nCurses::printTime()
{
    attron(A_BOLD);
    attron(COLOR_PAIR(1));
    printw("Time info : \n\t");
    attroff(A_BOLD);
    attroff(COLOR_PAIR(1));


    printw("%s\n", m_core->current_date.get().c_str());
}

void nCurses::printSys()
{
    attron(A_BOLD);
    attron(COLOR_PAIR(1));
    printw("System info : \n\t");
    attroff(A_BOLD);
    attroff(COLOR_PAIR(1));

    printw("%s\n\t", m_core->sys.getKernelname().c_str());
    printw("%s\n\t", m_core->sys.getKernelrelease().c_str());
    printw("%s\n\n", m_core->sys.getOs().c_str());
}

void nCurses::printRam()
{
    attron(A_BOLD);
    attron(COLOR_PAIR(1));
    printw("Ram info : \n\t");
    attroff(A_BOLD);
    attroff(COLOR_PAIR(1));

    attron(A_BOLD);
    printw("Total : \t");
    attroff(A_BOLD);
    printw("%f Gb\n\t", m_core->ram.getTotal());

    attron(A_BOLD);
    printw("Used : \t\t");
    attroff(A_BOLD);
    printw("%f Gb\n\t", m_core->ram.getUsed());

    attron(A_BOLD);
    printw("Available : \t");
    attroff(A_BOLD);
    printw("%f GB\n\n", m_core->ram.getAvailable());
}

void nCurses::printCPU()
{
    attron(A_BOLD);
    attron(COLOR_PAIR(1));
    printw("CPU info : \n");
    attroff(A_BOLD);
    attroff(COLOR_PAIR(1));

    std::vector<float> cpu = m_core->_cpu.calculs();
    int j = 0;

    for (size_t i(0); i < cpu.size(); ++i, j++)
    {
        attron(A_BOLD);
        if (j != 0)
            printw("\tCPU %d : ", (j - 1));
        else
            printw("\tCPU :   ");
        attroff(A_BOLD);
        printw("%f %\n", cpu[i]);
    }

    attron(A_BOLD);
    printw("\n\tVendor info : \t");
    attroff(A_BOLD);
    printw("%s \n\t", m_core->_cpu.get_vendor_id().c_str());

    attron(A_BOLD);
    printw("Model info : \t");
    attroff(A_BOLD);
    printw("%s \n\t", m_core->_cpu.get_model().c_str());

    attron(A_BOLD);
    printw("Frequency info :");
    attroff(A_BOLD);
    printw("%s \n\t", m_core->_cpu.get_frequency().c_str());

    attron(A_BOLD);
    printw("Family info : \t");
    attroff(A_BOLD);
    printw("%s \n\t", m_core->_cpu.get_family().c_str());

    attron(A_BOLD);
    printw("Sizes info : \t");
    attroff(A_BOLD);
    printw("%s \n\t", m_core->_cpu.get_sizes().c_str());
}

void nCurses::printNet()
{
    attron(A_BOLD);
    attron(COLOR_PAIR(1));
    printw("\nNetwork info : \n\t");
    attroff(A_BOLD);
    attroff(COLOR_PAIR(1));

    attron(A_BOLD);
    printw("Lo : \t");
    attroff(A_BOLD);
    printw("%s bytes\n\t", m_core->net.get_LO().c_str());
    attron(A_BOLD);
    printw("WLP : \t");
    attroff(A_BOLD);
    printw("%s bytes\n\n\n", m_core->net.get_WLP().c_str());
}

bool nCurses::key()
{
    attron(A_BOLD);
    attron(m_core->current_date.getActivate() ? COLOR_PAIR(3) :COLOR_PAIR(2));
    printw("Press 't' to%s\n", m_core->current_date.getActivate() ? " remove time info" : " add time info");
    attroff(A_BOLD);
    attroff(COLOR_PAIR(3));

    attron(A_BOLD);
    attron(m_core->name.getActivate() ? COLOR_PAIR(3) :COLOR_PAIR(2));
    printw("Press 'u' to%s\n", m_core->name.getActivate() ? " remove user info" : " add user info");
    attroff(A_BOLD);
    attroff(COLOR_PAIR(3));

    attron(A_BOLD);
    attron(m_core->sys.getActivate() ? COLOR_PAIR(3) :COLOR_PAIR(2));
    printw("Press 's' to%s\n", m_core->sys.getActivate() ? " remove system info" : " add system info");
    attroff(A_BOLD);
    attroff(COLOR_PAIR(3));

    attron(A_BOLD);
    attron(m_core->_cpu.getActivate() ? COLOR_PAIR(3) :COLOR_PAIR(2));
    printw("Press 'c' to%s\n", m_core->_cpu.getActivate() ? " remove CPU info" : " add CPU info");
    attroff(A_BOLD);
    attroff(COLOR_PAIR(3));

    attron(A_BOLD);
    attron(m_core->ram.getActivate() ? COLOR_PAIR(3) :COLOR_PAIR(2));
    printw("Press 'r' to%s\n", m_core->ram.getActivate() ? " remove Ram info" : " add Ram info");
    attroff(A_BOLD);
    attroff(COLOR_PAIR(3));

    attron(A_BOLD);
    attron(m_core->net.getActivate() ? COLOR_PAIR(3) :COLOR_PAIR(2));
    printw("Press 'n' to%s\n", m_core->net.getActivate() ? " remove network info" : " add network info");
    attroff(A_BOLD);
    attroff(COLOR_PAIR(3));

    attron(A_BOLD);
    attron(COLOR_PAIR(2));
    printw("\n\nPress 'q' to exit");
    attroff(COLOR_PAIR(2));
    attron(A_BOLD);

    int ch;
    switch (ch = getch()) {
        case 113 :
            ungetch(ch);
            return true;
            break;
        case 116:
            m_core->current_date.setActivate(!m_core->current_date.getActivate());
            return false;
            break;
        case 115:
            m_core->sys.setActivate(!m_core->sys.getActivate());
            return false;
            break;
        case 117:
            m_core->name.setActivate(!m_core->name.getActivate());
            return false;
            break;
        case 114:
            m_core->ram.setActivate(!m_core->ram.getActivate());
            return false;
            break;
        case 99:
            m_core->_cpu.setActivate(!m_core->_cpu.getActivate());
            return false;
            break;
        case 110:
            m_core->net.setActivate(!m_core->net.getActivate());
            return false;
            break;
    }
    return false;
}
