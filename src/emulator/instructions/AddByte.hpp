#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"
#include <limits.h>

class AddByte : public Instruction {
public:
    const Register dest{};
    const unsigned char byte{};
    unsigned int raw;
    AddByte(Register dest, unsigned char byte, unsigned int raw) : dest{ dest }, byte{ byte }, raw{ raw } {};
    void op(Environment& env) override {
        unsigned int regInd{ static_cast<unsigned int>(dest) };
        unsigned int res{ static_cast<unsigned int>(env.registers[regInd] + byte) }; 
        // No carry?
        // if (res > UCHAR_MAX) {
        //     env.registers[15] = 1; // set VF to 1 for carry
        // }
        env.registers[regInd] = static_cast<unsigned char>(res);
        env.pc += 1;
    }
};
