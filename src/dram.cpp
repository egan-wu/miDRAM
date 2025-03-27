#include "dram.hpp"

namespace DRAM {

Dram::Dram(Config cfg) : config(cfg)
{
    memory.resize(config.BANKS, std::vector<uint8_t>(config.ROWS * config.COLUMNS, 0));
}

uint8_t Dram::read(address addr) {
    return memory[addr.bank()][addr.row()*addr.col()];
}

void Dram::write(address addr, uint8_t data) {
    memory[addr.bank()][addr.row()*addr.col()] = data;
}

} 