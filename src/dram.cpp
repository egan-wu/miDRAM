#include "dram.hpp"

namespace DRAM {

Dram::Dram() {
    memory.resize(config::BANKS, std::vector<uint8_t>(config::ROWS * config::COLUMNS, 0));
}

uint8_t Dram::read(uint64_t address) {
    return memory[address % config::BANKS][address % (config::ROWS * config::COLUMNS)];
}

void Dram::write(uint64_t address, uint8_t data) {
    memory[address % config::BANKS][address % (config::ROWS * config::COLUMNS)] = data;
}

} 