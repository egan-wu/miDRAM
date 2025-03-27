#include <iostream>
#include "dram_controller.hpp"

int main() {

    DRAM::Config ddr_config_0 = {8192, 1024, 8, 15, 15, 12};
    DRAM::DramController controller(ddr_config_0);

    // Simulate requests
    controller.addRequest(DRAM::Request(DRAM::address(0x3F8AC253), DRAM::RequestType::WRITE, 0));
    controller.addRequest(DRAM::Request(DRAM::address(0x1000), DRAM::RequestType::READ, 1));

    controller.processRequests();

    return 0;
}