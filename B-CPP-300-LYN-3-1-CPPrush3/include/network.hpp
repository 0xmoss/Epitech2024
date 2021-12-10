/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** network.hpp
*/

#ifndef _NETWORK_HPP_
	#define _NETWORK_HPP_

    #include "main.hpp"

    class network {
        public:
            network();
            ~network();

            void set_WLP(std::string);
            void set_LO(std::string);

            std::string get_WLP();
            std::string get_LO();
            bool getActivate() const {return _activate_module;}

            void set();
            void setActivate(bool choice) {_activate_module = choice;}

            void display();
        private:
            std::string wlp;
            std::string  lo;
            bool _activate_module;
    };
    
#endif /* !_NETWORK_HPP_ */