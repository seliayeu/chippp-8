#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class Move : public Instruction {
public:
    const Register dest{};
    const Register source{};
    Move(Register dest, Register source) : dest{ dest }, source{ source }  {};
    void op(Environment& env) override {
        unsigned int destInd{ static_cast<unsigned int>(dest) };
        unsigned int sourceInd{ static_cast<unsigned int>(source) };
        env.VRegisters[destInd] = env.VRegisters[sourceInd];
        env.pc += 2;
    }
};
