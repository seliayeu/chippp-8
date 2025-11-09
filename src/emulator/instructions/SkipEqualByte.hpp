#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class SkipEqualByte : public Instruction {
public:
    unsigned int raw;
    Register reg;
    unsigned char byte;

    SkipEqualByte(unsigned int raw, Register reg, unsigned char byte) : raw{ raw }, reg{ reg }, byte{ byte } {};
    void op(Environment& env) override {
        unsigned int regInd{ static_cast<unsigned int>(reg) };
        if (env.registers[regInd] == byte)
            env.pc += 2;
    }
};
