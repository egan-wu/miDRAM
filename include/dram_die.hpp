#include "common.hpp"

#define UNKNOWN_ACTIVE_ROW 0xFFFFFFFF

// Bank states
#define BANK_NOT_READY 0
#define BANK_IDLE      1
#define BANK_ACTIVE    2
#define BANK_READ      3
#define BANK_WRITE     4

class BANK {
private:
    const uint32_t row_num;
    const uint32_t col_num;
    uint32_t act_row;
    uint8_t bank_state;
    std::vector<std::vector<uint8_t>> data;

public:
    BANK (uint32_t row_num_, uint32_t col_num_) : row_num(row_num_), col_num(col_num_)
    {
        data.resize(row_num, std::vector<uint8_t>(col_num, 0));
        bank_state = BANK_IDLE;
    }

    void activate(uint32_t row);
    void read(uint32_t col, uint8_t* buffer);
    void write(uint32_t col, const uint8_t* buffer);
    void precharge();
    uint8_t get_bank_state();
    uint32_t get_active_row();
};

class DIE {

};

class MODE_REGISTER {
public:
    MODE_REGISTER() = default;
};

class COMMAND_DECODER {
public:
    COMMAND_DECODER() = default;
};

class ADDRESS_DECODER {
public:
    ADDRESS_DECODER() = default;
};

class DRAM_DEVICE {
private:
    MODE_REGISTER _mode_register;
    COMMAND_DECODER _command_decoder;
    ADDRESS_DECODER _address_decoder;

public:
    DRAM_DEVICE() = default;
    void init();
    void start();
    void stop();
    bool is_running();
};