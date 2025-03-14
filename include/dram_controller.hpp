#ifndef DRAM_CONTROLLER_H
#define DRAM_CONTROLLER_H

#include <queue>
#include "request.hpp"
#include "dram.hpp"

namespace DRAM {

class DramController {
private:
    Dram dram;
    std::queue<Request> requestQueue;

public:
    void addRequest(const Request& req);
    void processRequests();
};

}

#endif