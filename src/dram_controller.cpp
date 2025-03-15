#include "dram_controller.hpp"
#include <iostream>

namespace DRAM {

void DramController::addRequest(const Request& req) {
    requestQueue.push(req);
}

void DramController::processRequests() {
    uint8_t data = 0xFF;

    while(!requestQueue.empty()) {
        Request req = requestQueue.front();
        requestQueue.pop();
        
        switch (req.type) {
            case RequestType::READ:
                data = dram.read(req.addr);
                std::cout << "Read data: " << static_cast<int>(data) << " from " << req.addr << std::endl;
                break;

            case RequestType::WRITE:
            dram.write(req.addr, 0xFF);
                std::cout << "Write 0xFF to " << req.addr << std::endl;
                break;

            default:
                std::cout << "Unknown request type!!" << std::endl;
                break;
        }
    }
}

}