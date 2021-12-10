/*
** EPITECH PROJECT, 2021
** C / C++ PROJECT
** File description:
** file
*/

#include "pool.hpp"
#include "commands.hpp"

pool::pool() : m_function_queue(), m_lock(), m_data_condition(), m_accept_functions(true)
{
}

pool::~pool()
{
}

void pool::push(std::function<void()> func)
{
    std::unique_lock<std::mutex> lock(m_lock);
    m_function_queue.push(func);
    lock.unlock();
    m_data_condition.notify_one();
}

void pool::close()
{
    std::unique_lock<std::mutex> lock(m_lock);
    m_accept_functions = false;
    lock.unlock();
    m_data_condition.notify_all();
}

void pool::infinite_loop_func()
{
    std::function<void()> func;
    while (true)
    {
        {
            std::unique_lock<std::mutex> lock(m_lock);
            m_data_condition.wait(lock, [this]() {return !m_function_queue.empty() || !m_accept_functions; });
            if (m_function_queue.empty() && !m_accept_functions)
                return;
            func = m_function_queue.front();
            m_function_queue.pop();
        }
        func();
    }
}
