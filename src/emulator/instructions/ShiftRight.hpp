#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"
#include <limits.h>

class ShiftRight : public Instruction {
public:
    const Register dest{};
    const unsigned char byte{};
    ShiftRight(Register dest) : dest{ dest } {};

    void op(Environment& env) override {
        unsigned int destInd{ static_cast<unsigned int>(dest) };
        unsigned int res{ static_cast<unsigned int>(env.VRegisters[destInd] >> 1) }; 


        bool setVF{ (env.VRegisters[destInd] & 0x01) > 0 };
        env.VRegisters[destInd] = static_cast<unsigned char>(res);

        if (setVF)
            env.VRegisters[15] = 1; // set VF to 1
        else
            env.VRegisters[15] = 0;
        env.pc += 2;
    }
};
