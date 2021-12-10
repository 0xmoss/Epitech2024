/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD08-
** File description:
** Droid.hpp
*/

#ifndef DROID_HH_
    #define DROID_HH_

    #include <string>
    #include <iostream>

    class Droid {
        private:
            std::string serial;
            size_t energy;
            const size_t attack;
            const size_t toughness;
            std::string *status;
        public:
            Droid(std::string id = "");
            Droid(Droid const&);
            ~Droid();

            std::string getId() const;
            size_t getEnergy() const;
            size_t getAttack() const;
            size_t getToughness() const;
            std::string *getStatus() const;

            void setId(std::string);
            void setEnergy(size_t);
            void setStatus(std::string*);

            Droid& operator=(Droid const&);

            bool operator==(Droid const &) const;
            bool operator!=(Droid const &) const;

            Droid& operator<<(size_t &);
    };

    std::ostream & operator<<(std::ostream & os, const Droid & droid);

#endif /* !DROID_HH_ */