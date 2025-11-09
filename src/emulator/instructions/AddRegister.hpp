#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"
#include <limits.h>

class AddRegister : public Instruction {
public:
    unsigned int raw;
    const Register dest{};
    const Register source{};
    const unsigned char byte{};
    AddRegister(unsigned int raw, Register dest, Register source) : raw{ raw }, dest{ dest }, source{ source } {};

    void op(Environment& env) override {
        unsigned int destInd{ static_cast<unsigned int>(dest) };
        unsigned int sourceInd{ static_cast<unsigned int>(source) };
        unsigned int res{ static_cast<unsigned int>(env.registers[destInd] + env.registers[sourceInd]) }; 
        if (res > UCHAR_MAX)
            env.registers[15] = 1; // set VF to 1 for carry
                                   //
        env.registers[destInd] = static_cast<unsigned char>(res);
        env.pc += 1;
    }
};
