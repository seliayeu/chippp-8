#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class SkipEqualByte : public Instruction {
public:
    Register reg;
    unsigned char byte;

    SkipEqualByte(Register reg, unsigned char byte) : reg{ reg }, byte{ byte } {};
    void op(Environment& env) override {
        unsigned int regInd{ static_cast<unsigned int>(reg) };
        if (env.VRegisters[regInd] == byte)
            env.pc += 4;
        else
            env.pc += 2;
    }
};
