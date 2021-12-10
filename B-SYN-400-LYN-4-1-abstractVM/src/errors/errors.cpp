/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM-
** File description:
** errors
*/

#include "errors.hpp"

Exception::Exception(std::string errorCode, const std::string &message) noexcept : _errorCode(errorCode), _message(message)
{
    Exception::_message += errorCode;

    return;
}

const char *Exception::what() const noexcept
{
    return (this->_message.c_str());
}
