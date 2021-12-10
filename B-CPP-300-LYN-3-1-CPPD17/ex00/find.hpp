/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD17-
** File description:
** find.hpp
*/

#ifndef _FIND_HPP_
    #define _FIND_HPP_

    #include <algorithm>

    template<typename Obj>
    typename Obj::iterator do_find(Obj &container, int nb)
    {
        return(std::find(container.begin(), container.end(), nb));
    }

#endif /* !_FIND_HPP_ */