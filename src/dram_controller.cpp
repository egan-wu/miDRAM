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
                data = dram.read(req.address);
                std::cout << "Read data: " << static_cast<int>(data) << " from " << req.address << std::endl;
                break;

            case RequestType::WRITE:
            dram.write(req.address, 0xFF);
                std::cout << "Write 0xFF to " << req.address << std::endl;
                break;

            default:
                std::cout << "Unknown request type!!" << std::endl;
                break;
        }
    }
}

}