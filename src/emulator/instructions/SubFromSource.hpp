#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"
#include <limits.h>

class SubFromSource : public Instruction {
public:
    unsigned int raw;
    const Register dest{};
    const Register source{};
    const unsigned char byte{};
    SubFromSource(unsigned int raw, Register dest, Register source) : raw{ raw }, dest{ dest }, source{ source } {};

    void op(Environment& env) override {
        unsigned int destInd{ static_cast<unsigned int>(dest) };
        unsigned int sourceInd{ static_cast<unsigned int>(source) };
        unsigned int res{ static_cast<unsigned int>(env.VRegisters[sourceInd] - env.VRegisters[destInd]) }; 
        if (env.VRegisters[sourceInd] > env.VRegisters[destInd])
            env.VRegisters[15] = 1; // set VF to 1 for carry
        else     
            env.VRegisters[15] = 0;
        env.VRegisters[destInd] = static_cast<unsigned char>(res);
        env.pc += 1;
    }
};
