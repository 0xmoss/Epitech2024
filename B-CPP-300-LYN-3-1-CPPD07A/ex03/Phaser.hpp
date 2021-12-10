/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD07A-
** File description:
** Phaser.hpp
*/

#ifndef PHASER_H_
    #define PHASER_H_

    class Phaser {
        private:
            static const int Empty;

        public:
            enum AmmoType {
                
            };

            Phaser(int maxAmmo, AmmoType type);
            ~Phaser();

            void fire();
            void ejectClip();
            void changeType(AmmoType newType);
            void reload();
            void addAmo(AmmoType type);

            int getCurrentAmmos();
    }

#endif /* PHASER_H_ */