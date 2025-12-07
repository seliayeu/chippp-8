#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class And : public Instruction {
public:
    unsigned int raw;
    const Register dest{};
    const Register source{};
    And(Register dest, Register source) : dest{ dest }, source{ source }  {};
    void op(Environment& env) override {
        unsigned int destInd{ static_cast<unsigned int>(dest) };
        unsigned int sourceInd{ static_cast<unsigned int>(source) };
        env.VRegisters[destInd] &= env.VRegisters[sourceInd];
        env.pc += 2;
    }
};
