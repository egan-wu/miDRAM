#include <iostream>
#include "dram_controller.hpp"

int main() {
    DRAM::DramController controller;

    // Simulate requests
    controller.addRequest(DRAM::Request(DRAM::address(0x3F8AC253), DRAM::RequestType::WRITE, 0));
    controller.addRequest(DRAM::Request(DRAM::address(0x1000), DRAM::RequestType::READ, 1));

    controller.processRequests();

    return 0;
}