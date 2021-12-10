/*
** EPITECH PROJECT, 2021
** B-SYN-400-LYN-4-1-abstractVM-
** File description:
** infinsub
*/

#include "operations.hpp"

std::string operations::infinsub(std::string a, std::string b)
{
    int tmp;
    char retenue = '0';
    std::string result = "";
    std::vector<std::string> before = {
        "0",
        "0"
    };
    std::vector<std::string> after = {
        "0",
        "0"
    };
    unsigned long add = 0;
    long a_floating = std::count(a.begin(), a.end(), '.');
    long b_floating = std::count(b.begin(), b.end(), '.');
    bool coma = false;

    if (a_floating > 0) {
        coma = true;
        before[0] = a.substr(0, a.find('.'));
        after[0] = a.substr(before[0].length() + 1, a.length() - before[0].length());
    } else
        before[0] = a;
    if (b_floating > 0) {
        coma = true;
        before[1] = b.substr(0, b.find('.'));
        after[1] = b.substr(before[1].length() + 1, b.length() - before[1].length());
    } else
        before[1] = b;

    if (coma == true) {
        if (after[1].length() > after[0].length()) {
            add = after[1].length() - after[0].length();
            for (unsigned long i = 0; i < add; i++)
                after[0] += '0';
        } else {
            add = after[0].length() - after[1].length();
            for (unsigned long i = 0; i < add; i++)
                after[1] += '0';
        }
        for (unsigned long i = after[0].length(); i > 0; i--) {
            tmp = ((static_cast<int>(after[0][i - 1]) - '0') - (static_cast<int>(after[1][i - 1]) - '0') - (static_cast<int>(retenue) - '0'));
        if (tmp < 0) {
            retenue = '1';
            tmp *= -1;
        } else
            retenue = '0';
        result += std::to_string(tmp);
        }
        result += '.';
    }
    if (before[0] <= before[1]) {
        std::reverse(before[0].begin(), before[0].begin());
        add = before[1].length() - before[0].length();
        for (unsigned long i = 0; i < add; i++)
            before[0].insert(0, "0");
        std::reverse(before[0].begin(), before[0].begin());
    } else {
        std::reverse(before[1].begin(), before[1].begin());
        add = before[0].length() - before[1].length();
        for (unsigned long i = 0; i < add; i++)
            before[1].insert(0, "0");
        std::reverse(before[1].begin(), before[1].begin());
    }

    for (unsigned long i = before[0].length(); i > 0; i--) {
        tmp = ((static_cast<int>(before[0][i - 1]) - '0') - (static_cast<int>(before[1][i - 1]) - '0') - (static_cast<int>(retenue) - '0'));
        if (tmp < 0) {
            retenue = '1';
            tmp *= -1;
        } else
            retenue = '0';
        result += std::to_string(tmp);
    }
    if (retenue != '0')
        result.push_back(retenue);

    std::reverse(result.begin(), result.end());

    return (result);
}
