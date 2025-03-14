#ifndef DRAM_HPP
#define DRAM_HPP

#include <cstdint>
#include <vector>
#include "config.hpp"

namespace DRAM {
    
    class Dram {
    private:
        std::vector<std::vector<uint8_t>> memory;

    public:
        Dram();
        uint8_t read(uint64_t address);
        void write(uint64_t address, uint8_t data);
    };
}

#endif