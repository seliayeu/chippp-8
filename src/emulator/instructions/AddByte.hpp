#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"
#include <limits.h>

class AddByte : public Instruction {
public:
    const Register dest{};
    const unsigned char byte{};
    AddByte(Register dest, unsigned char byte) : dest{ dest }, byte{ byte } {};
    void op(Environment& env) override {
        unsigned int regInd{ static_cast<unsigned int>(dest) };
        unsigned int res{ static_cast<unsigned int>(env.VRegisters[regInd] + byte) }; 
        env.VRegisters[regInd] = static_cast<unsigned char>(res);
        env.pc += 2;
    }
};
