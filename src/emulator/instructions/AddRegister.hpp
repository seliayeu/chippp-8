#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"
#include <limits.h>
#include <iostream>

class AddRegister : public Instruction {
public:
    const Register dest{};
    const Register source{};
    const unsigned char byte{};
    AddRegister(Register dest, Register source) : dest{ dest }, source{ source } {};

    void op(Environment& env) override {
        unsigned int destInd{ static_cast<unsigned int>(dest) };
        unsigned int sourceInd{ static_cast<unsigned int>(source) };
        unsigned int res{ static_cast<unsigned int>(env.VRegisters[destInd] + env.VRegisters[sourceInd]) }; 
        env.VRegisters[destInd] = static_cast<unsigned char>(res);

        if (res > UCHAR_MAX)
            env.VRegisters[15] = 1; // set VF to 1 for carry
        else
            env.VRegisters[15] = 0;
        env.pc += 2;
    }
};
