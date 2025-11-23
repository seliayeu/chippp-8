#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class SkipPressed : public Instruction {
public:
    unsigned int raw;
    Register reg;

    SkipPressed(unsigned int raw, Register reg) : raw{ raw }, reg{ reg } {};
    void op(Environment& env) override {
        // if (env.VRegisters[reg1Ind] != env.VRegisters[reg2Ind] )
        //     env.pc += 2;
        // else
        //     env.pc += 1;
        //     TODO
        env.pc += 1;
    }
};
