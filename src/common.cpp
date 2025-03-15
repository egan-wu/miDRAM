#include "common.hpp"

namespace DRAM {

std::ostream& operator<<(std::ostream& os, const address& obj) {
    os << std::hex << "0x" << obj.addr() << std::dec << " [" << obj.row() << ":" << obj.bank() << ":" <<  obj.col() << ":" << obj.offset() << "]";
    return os;
}

}