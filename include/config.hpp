#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <cstdint>

namespace DRAM {

/**
 *  DRAM configuration
 * 
 *  TOTALSIZE: 8192 * 1024 * 8 (bits) = 8 (M-Bytes)
 */
struct config {
    static constexpr uint32_t ROWS = 8192;
    static constexpr uint32_t COLUMNS = 1024;
    static constexpr uint32_t BANKS = 8;
    static constexpr uint32_t TIMING_tRCD = 15;
    static constexpr uint32_t TIMING_tCAS = 15;
    static constexpr uint32_t TIMING_tRP = 12;
};

}

#endif