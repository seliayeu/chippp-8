#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class SkipNotEqualRegister : public Instruction {
public:
    unsigned int raw;
    Register reg1;
    Register reg2;

    SkipNotEqualRegister(unsigned int raw, Register reg1, Register reg2) : raw{ raw }, reg1{ reg1 }, reg2{ reg2 } {};
    void op(Environment& env) override {
        unsigned int reg1Ind{ static_cast<unsigned int>(reg1) };
        unsigned int reg2Ind{ static_cast<unsigned int>(reg2) };
        if (env.registers[reg1Ind] != env.registers[reg2Ind] )
            env.pc += 2;
    }
};
