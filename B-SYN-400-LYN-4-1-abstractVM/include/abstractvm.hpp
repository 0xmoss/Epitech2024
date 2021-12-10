/*
** EPITECH PROJECT, 2021
** SYN_Pool
** File description:
** abstractvm
*/

#ifndef ABSTRACTVM_HPP

    #define ABSTRACTVM_HPP

    #include <iostream>
    #include <fstream>
    #include <array>
    #include <vector>
    #include <algorithm>
    #include <map>
    #include <unistd.h>
    #include <cstring>
    #include <string>

    #include "IOperand.hpp"
    #include "errors.hpp"

    #define UNKNOWN "__UNKNOWN__"
    #define EMPTY "__EMPTY__"
    #define END ";;"

    class abstractvm
    {
        public:
            abstractvm();
            ~abstractvm();

            bool open();
            bool parser();
            bool check();
            bool parser(std::string);
            int id_0(std::string);
            int id_1(std::string);
            bool handler(std::string, std::string);
            bool handler_0(std::string &);
            bool handler_1(std::string &, std::string);


            // COMMANDS
            std::string vm_push(std::string, std::string);
            std::string vm_pop(void);
            std::string vm_dump(void);
            std::string vm_clear(void);
            std::string vm_dup(void);
            std::string vm_swap(void);
            std::string vm_assert(std::string, std::string);
            std::string vm_add(void);
            std::string vm_sub(void);
            std::string vm_mul(void);
            std::string vm_div(void);
            std::string vm_mod(void);
            std::string vm_load(std::string, std::string);
            std::string vm_store(std::string, std::string);
            std::string vm_print(void);
            std::string vm_exit(void);

            std::string path = EMPTY;

        private:
            typedef std::string (abstractvm::*function_type_0)(void);
            typedef std::string (abstractvm::*function_type_1)(std::string, std::string);

            std::map<std::string, function_type_0> mapped_functions_0 = {
                { "pop", &abstractvm::vm_pop },
                { "dump", &abstractvm::vm_dump },
                { "clear", &abstractvm::vm_clear },
                { "dup", &abstractvm::vm_dup },
                { "swap", &abstractvm::vm_swap },
                { "add", &abstractvm::vm_add },
                { "sub", &abstractvm::vm_sub },
                { "mul", &abstractvm::vm_mul },
                { "div", &abstractvm::vm_div },
                { "mod", &abstractvm::vm_mod },
                { "print", &abstractvm::vm_print },
                { "exit", &abstractvm::vm_exit }
            };   // defining a map
            std::map<std::string, function_type_1> mapped_functions_1 = {
                { "push", &abstractvm::vm_push },
                { "assert", &abstractvm::vm_assert },
                { "load", &abstractvm::vm_load },
                { "store", &abstractvm::vm_store }
            };

            bool openned = false;
            std::array<std::string, 6> types = {
                "int8",
                "int16",
                "int32",
                "float",
                "double",
                "bigdecimal"
            };
            IOperand *regist[16];
            std::vector<IOperand *> stack;
    };

#endif /* ABSTRACTVM_HPP */
