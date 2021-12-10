/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush2- [WSL: Ubuntu-20.04]
** File description:
** Box
*/

#ifndef BOX_HPP_
    #define BOX_HPP_

    #include "../Toy/Toy.hpp"
    #include "../Wrap/Wrap.hpp"

    class Box : public Wrap {
        public:
            Box();
            ~Box();

            bool getOpen() const { return (_is_open); }
            Toy *getToy() const { return (_toy); }

            void wrapMeThat(Toy *toy);
            Toy *openMe();
            void closeMe();
        protected:
        private:
            Toy *_toy;
            bool _is_open;
    };

#endif /* !BOX_HPP_ */
