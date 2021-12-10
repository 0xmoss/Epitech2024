/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** CPU.hpp
*/

#ifndef _CPU_HPP_
    #define _CPU_HPP_

    #include "main.hpp"

    class CPU {
        public:
            CPU();
            ~CPU();

            enum CPUStates {
                S_USER = 0,
                S_NICE,
                S_SYSTEM,
                S_IDLE,
                S_IOWAIT,
                S_IRQ,
                S_SOFTIRQ,
                S_STEAL,
                S_GUEST,
                S_GUEST_NICE
            };

            typedef struct CPUData {
                std::string cpu;
                size_t times[10];
            } CPUData;

            void ReadStatsCPU(std::vector<CPUData> &);
            size_t GetIdleTime(const CPUData &);
            size_t GetActiveTime(const CPUData &);
            bool getActivate() const {return _activate_module;}

            void setActivate(bool choice);

            void display();

            // CPU VALUES
            const std::vector<CPUData> get_1();
            const std::vector<CPUData> get_2();
            void set();

            // CPU CALCULS
            std::vector<float> calculs();

            // CPU INFORMATIONS
            void set_infos();

            std::string get_vendor_id();
            std::string get_model();
            std::string get_frequency();
            std::string get_family();
            std::string get_sizes();

        private:
            std::vector<CPUData> usage;
            std::vector<CPUData> not_used;

            bool _activate_module;

            size_t NUM_ENTRIES;

            float ACTIVE_TIME;
            float TOTAL_TIME;
            float IDLE_TIME;

            // CPU INFORMATIONS
            std::string vendor_id;
            std::string model;
            std::string frequency;
            std::string family;
            std::string sizes;
    };

#endif /* !_CPU_HPP_ */