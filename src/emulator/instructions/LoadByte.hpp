#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class LoadByte : public Instruction {
public:
    unsigned int raw;
    const Register dest{};
    const unsigned char byte{};
    LoadByte(unsigned int raw, Register dest, unsigned char byte) : raw{ raw }, dest{ dest }, byte{ byte }  {};
    void op(Environment& env) override {
        unsigned int destInd{ static_cast<unsigned int>(dest) };
        env.registers[destInd] = byte;
    }
};
