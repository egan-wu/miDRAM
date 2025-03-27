#ifndef DRAM_HPP
#define DRAM_HPP

#include <cstdint>
#include <vector>
#include "common.hpp"
#include "config.hpp"

namespace DRAM {

    class Bank {
    private:
        std::vector<std::vector<bool>> cells;

    public:

    };

    class Die {
    private:
        std::vector<Die> banks;
        
    public:
        uint8_t read(address addr);
        void write(address addr, uint8_t data);
    };

    class Dram {
    private:
        std::vector<std::vector<uint8_t>> memory;
        Config config;

    public:
        Dram(Config cfg);
        uint8_t read(address addr);
        void write(address addr, uint8_t data);
    };
}

#endif