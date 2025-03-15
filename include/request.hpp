#ifndef REQUEST_H
#define REQUEST_H

#include <cstdint>
#include "common.hpp"

namespace DRAM {

enum class RequestType { READ, WRITE };

struct Request {
    address addr;
    RequestType type;
    uint32_t timestamp;

    Request(address a, RequestType t, uint32_t ts)
        : addr(a), type(t), timestamp(ts) {}
};

}

#endif