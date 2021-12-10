/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-
** File description:
** CPU.cpp
*/

#include "CPU.hpp"

CPU::CPU()
{
    this->vendor_id = "_EMPTY_";
    this->model = "_EMPTY_";
    this->frequency = "_EMPTY_";
    this->family = "_EMPTY_";
    this->sizes = "_EMPTY_";
    this->_activate_module = false;

    return;
}

CPU::~CPU()
{
    this->vendor_id = "_EMPTY_";
    this->model = "_EMPTY_";
    this->frequency = "_EMPTY_";
    this->family = "_EMPTY_";
    this->sizes = "_EMPTY_";

    return;
}

void CPU::setActivate(bool choice)
{
    this->_activate_module = choice;
}

void CPU::ReadStatsCPU(std::vector<CPU::CPUData> &entries)
{
    std::ifstream fileStat("/proc/stat");
    std::string line;

    const std::string STR_CPU("cpu");
    const std::size_t LEN_STR_CPU = STR_CPU.size();
    const std::string STR_TOT("tot");

    while (std::getline(fileStat, line)) {
        if (!line.compare(0, LEN_STR_CPU, STR_CPU)) {
            std::istringstream ss(line);

            entries.emplace_back(CPU::CPUData());
            CPU::CPUData &entry = entries.back();

            ss >> entry.cpu;

            if (entry.cpu.size() > LEN_STR_CPU) {
                entry.cpu.erase(0, LEN_STR_CPU);
            } else {
                entry.cpu = STR_TOT;
            }

            for (int i = 0; i < 10; ++i) {
                ss >> entry.times[i];
            }
        }
    }
    fileStat.close();
}

size_t CPU::GetIdleTime(const CPU::CPUData &entry)
{
    return (entry.times[S_IDLE] + entry.times[S_IOWAIT]);
}

size_t CPU::GetActiveTime(const CPU::CPUData &entry)
{
    return (
        entry.times[S_USER] +
        entry.times[S_NICE] +
        entry.times[S_SYSTEM] +
        entry.times[S_IRQ] +
        entry.times[S_SOFTIRQ] +
        entry.times[S_STEAL] +
        entry.times[S_GUEST] +
        entry.times[S_GUEST_NICE]
    );
}

const std::vector<CPU::CPUData> CPU::get_1()
{
    std::vector<CPU::CPUData> entry;

    ReadStatsCPU(entry);

    return (entry);
}

const std::vector<CPU::CPUData> CPU::get_2()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::vector<CPU::CPUData> entry;

    ReadStatsCPU(entry);

    return (entry);
}

std::vector<float> CPU::calculs()
{
    const std::vector<CPU::CPUData> &entry_1 = CPU::get_1();
    const std::vector<CPU::CPUData> &entry_2 = CPU::get_2();
    this->NUM_ENTRIES = entry_1.size();
    std::vector<float> res;

    for (size_t i = 0; i < this->NUM_ENTRIES; ++i) {
        const CPU::CPUData &e1 = entry_1[i];
        const CPU::CPUData &e2 = entry_2[i];

        this->ACTIVE_TIME = static_cast<float>(
            CPU::GetActiveTime(e2) - CPU::GetActiveTime(e1)
        );
        this->IDLE_TIME = static_cast<float>(
           CPU:: GetIdleTime(e2) - CPU::GetIdleTime(e1)
        );
        this->TOTAL_TIME = (ACTIVE_TIME + IDLE_TIME);

        res.push_back(100.f * this->ACTIVE_TIME / this->TOTAL_TIME);
    }

    return (res);
}

void CPU::display()
{
    std::vector<float> cal = calculs();

    for (float i : cal)
        std::cout << i << std::endl;
}

std::string CPU::get_model()
{
    if (this->model == "_EMPTY_")
        set_infos();
    return (this->model);
}

std::string CPU::get_vendor_id()
{
    if (this->vendor_id == "_EMPTY_")
        set_infos();
    return (this->vendor_id);
}

std::string CPU::get_frequency()
{
    if (this->frequency == "_EMPTY_")
        set_infos();
    return (this->frequency);
}

std::string CPU::get_family()
{
    if (this->family == "_EMPTY_")
        set_infos();
    return (this->family);
}

std::string CPU::get_sizes()
{
    if (this->sizes == "_EMPTY_")
        set_infos();
    return (this->sizes);
}

// CPU INFO
void CPU::set_infos()
{
    std::string line;
    std::ifstream finfo("/proc/cpuinfo");

    while(std::getline(finfo,line)) {
        std::stringstream str(line);
        std::string itype;
        std::string info;

        if (this->vendor_id == "_EMPTY_" &&
        std::getline(str, itype, ':' ) &&
        std::getline(str, info) &&
        itype.substr(0,9) == "vendor_id" ) {
            this->vendor_id = info;
        }

        if (this->model == "_EMPTY_" &&
        std::getline(str, itype, ':' ) &&
        std::getline(str, info) &&
        itype.substr(0,10) == "model name" ) {
            this->model = info;
        }

        if (this->frequency == "_EMPTY_" &&
        std::getline(str, itype, ':' ) &&
        std::getline(str, info) &&
        itype.substr(0,7) == "cpu MHz" ) {
            this->frequency = info;
        }

        if (this->family == "_EMPTY_" &&
        std::getline(str, itype, ':' ) &&
        std::getline(str, info) &&
        itype.substr(0,10) == "cpu family" ) {
            this->family = info;
        }

        if (this->sizes == "_EMPTY_" &&
        std::getline(str, itype, ':' ) &&
        std::getline(str, info) &&
        itype.substr(0,13) == "address sizes" ) {
            this->sizes = info;
        }

        if (this->sizes != "_EMPTY_" &&
        this->family != "_EMPTY_" &&
        this->frequency != "_EMPTY_" &&
        this->model != "_EMPTY_" &&
        this->vendor_id != "_EMPTY_") {
            break;
        }
    }
    finfo.close();
}

