#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <cstdint>

namespace DRAM {

/**
 *  DRAM configuration
 * 
 *  TOTALSIZE: 8192 * 1024 * 8 (bits) = 8 (M-Bytes)
 */
struct Config {
    uint32_t ROWS = 8192;
    uint32_t COLUMNS = 1024;
    uint32_t BANKS = 8;
    uint32_t TIMING_tRCD = 15;
    uint32_t TIMING_tCAS = 15;
    uint32_t TIMING_tRP = 12;
};

}

#endif