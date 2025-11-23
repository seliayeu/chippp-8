#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"
#include <limits.h>

class ShiftLeft : public Instruction {
public:
    unsigned int raw;
    const Register dest{};
    const unsigned char byte{};
    ShiftLeft(unsigned int raw, Register dest, Register) : raw{ raw }, dest{ dest } {};

    void op(Environment& env) override {
        unsigned int destInd{ static_cast<unsigned int>(dest) };
        unsigned int res{ static_cast<unsigned int>(env.VRegisters[destInd] >> 1) }; 
        if ((env.VRegisters[destInd] & 0x80) != 0)
            env.VRegisters[15] = 1; // set VF to 1
        else
            env.VRegisters[15] = 0;
        env.VRegisters[destInd] = static_cast<unsigned char>(res);
        env.pc += 1;
    }
};
