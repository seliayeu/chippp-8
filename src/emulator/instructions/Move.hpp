#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class Move : public Instruction {
public:
    unsigned int raw;
    const Register dest{};
    const Register source{};
    Move(unsigned int raw, Register dest, Register source) : raw{ raw }, dest{ dest }, source{ source }  {};
    void op(Environment& env) override {
        unsigned int destInd{ static_cast<unsigned int>(dest) };
        unsigned int sourceInd{ static_cast<unsigned int>(source) };
        env.VRegisters[destInd] = env.VRegisters[sourceInd];
        env.pc += 1;
    }
};
