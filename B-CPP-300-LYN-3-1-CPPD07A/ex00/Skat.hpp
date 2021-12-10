/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD07A-
** File description:
** Skat.hpp
*/

#ifndef SKAT_H_
    #define SKAT_H_

    #include <string>

    class Skat {
        private:
            std::string _name;
            int _stimPaks;
        public:
            Skat(std::string const&, int);
            Skat(std::string const&);
            Skat(int);
            Skat();
            ~Skat();

            int &stimPaks();
            const std::string &name() const;
            void shareStimPaks(int, int&);
            void addStimPaks(unsigned int);
            void useStimPaks();
            void status() const;
    };

#endif /* !SKAT_H_ */