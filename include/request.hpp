#ifndef REQUEST_H
#define REQUEST_H

#include <cstdint>

namespace DRAM {

enum class RequestType { READ, WRITE };

struct Request {
    uint64_t address;
    RequestType type;
    uint32_t timestamp;

    Request(uint64_t addr, RequestType t, uint32_t ts)
        : address(addr), type(t), timestamp(ts) {}
};

}

#endif