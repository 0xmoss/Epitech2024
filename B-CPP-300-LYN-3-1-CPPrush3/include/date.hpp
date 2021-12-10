/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** date.hpp
*/

#ifndef _DATE_HPP_
    #define _DATE_HPP_

    #include "main.hpp"
    #include "IMonitorModule.hpp"

    class date : public IMonitorModule {
        public:
            date();
            ~date();

            // GET VALUES
            std::string get() override;
            bool getActivate() const {return _activate_module;}

            // SET VALUES
            void set() override;
            void setActivate(bool choice) { this->_activate_module = choice;}

            // DISPLAY VALUES
            void display() override;
        private:
            time_t now;
            std::string _date_;
            bool _activate_module;
    };

#endif /* !_DATE_HPP_ */