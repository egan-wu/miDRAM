#ifndef COMMON_HPP
#define COMMON_HPP

#include <cstdint>
#include <iostream>

namespace DRAM {

    const uint32_t tRCD = 100;
    const uint32_t tCL  = 100;

    const uint8_t ROW_ADDR_BIT = 16;
    const uint8_t BANK_ADDR_BIT = 3;
    const uint8_t COL_ADDR_BIT = 10;
    const uint8_t BYTE_OFFSET_BIT = 3;

    const uint8_t BYTE_OFFSET_SHIFT = 0; 
    const uint8_t ROW_ADDR_SHIFT = BYTE_OFFSET_BIT + BYTE_OFFSET_SHIFT;
    const uint8_t BANK_ADDR_SHIFT = ROW_ADDR_BIT + ROW_ADDR_SHIFT;
    const uint8_t COL_ADDR_SHIFT = BANK_ADDR_BIT + BANK_ADDR_SHIFT;

    struct address {
        uint32_t row_addr  : ROW_ADDR_BIT;
        uint32_t col_addr  : COL_ADDR_BIT;
        uint32_t bank_addr : BANK_ADDR_BIT;
        uint32_t byte_ofst : BYTE_OFFSET_BIT;

        // constructor
        address(uint32_t addr) {
            row_addr = (addr >> ROW_ADDR_SHIFT) & ((1 << ROW_ADDR_BIT) - 1);
            col_addr = (addr >> COL_ADDR_SHIFT) & ((1 << COL_ADDR_BIT) - 1);
            bank_addr = (addr >> BANK_ADDR_SHIFT) & ((1 << BANK_ADDR_BIT) - 1);
            byte_ofst = (addr >> BYTE_OFFSET_SHIFT) & ((1 << BYTE_OFFSET_BIT) - 1);

            // std::cout << "address: 0x" << std::hex << addr << std::dec << std::endl;
            // std::cout << "row: " << std::hex << row_addr << std::dec << std::endl;
            // std::cout << "col: " << std::hex << col_addr << std::dec << std::endl;
            // std::cout << "bank: " << std::hex << bank_addr << std::dec << std::endl;
            // std::cout << "byte_offset: " << std::hex << byte_ofst << std::dec << std::endl;
        } 
        
        uint32_t row() const { return row_addr; }
        uint32_t col() const { return col_addr; }
        uint32_t bank() const { return bank_addr; }
        uint32_t offset() const { return byte_ofst; }
        uint32_t addr() const { return (row_addr << ROW_ADDR_SHIFT) | (col_addr << COL_ADDR_SHIFT) | (bank_addr << BANK_ADDR_SHIFT) | (byte_ofst << BYTE_OFFSET_SHIFT); }
        friend std::ostream& operator<<(std::ostream& os, const address& obj);
    };
}

#endif