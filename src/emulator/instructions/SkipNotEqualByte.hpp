#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class SkipNotEqualByte : public Instruction {
public:
    unsigned int raw;
    Register reg;
    unsigned char byte;

    SkipNotEqualByte(unsigned int raw, Register reg, unsigned char byte) : raw{ raw }, reg{ reg }, byte{ byte } {};
    void op(Environment& env) override {
        unsigned int regInd{ static_cast<unsigned int>(reg) };
        if (env.VRegisters[regInd] != byte)
            env.pc += 2;
        else
            env.pc += 1;
    }
};
