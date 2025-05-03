#include "dram_die.hpp"

void BANK::activate(uint32_t row) {
    if (row >= row_num) { 
        throw std::out_of_range("Row out of range"); 
    }

    /** TODO: some AC timing delay */
    act_row = row;
    bank_state = BANK_ACTIVE;
}

void BANK::read(uint32_t col, uint8_t* buffer)
{
    if (act_row == UNKNOWN_ACTIVE_ROW) {
        throw std::runtime_error("No active row");
    }

    if (col >= col_num) { 
        throw std::out_of_range("Column out of range"); 
    }

    /** TODO: some AC timing delay */
    buffer[0] = data[act_row][col];
    bank_state = BANK_READ;
}

void BANK::write(uint32_t col, const uint8_t* buffer)
{
    if (act_row == UNKNOWN_ACTIVE_ROW) {
        throw std::runtime_error("No active row");
    }

    if (col >= col_num) { 
        throw std::out_of_range("Column out of range"); 
    }

    /** TODO: some AC timing delay */
    data[act_row][col] = buffer[0];
    bank_state = BANK_WRITE;
}

void BANK::precharge()
{
    /** TODO: some AC timing delay */
    act_row = UNKNOWN_ACTIVE_ROW;
    bank_state = BANK_IDLE;
}

uint8_t BANK::get_bank_state()
{   
    return bank_state;
}

uint32_t BANK::get_active_row()
{
    return act_row;
}