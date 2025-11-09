#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class Execute : public Instruction {
public:
    unsigned int raw;
    unsigned int addr;
    Execute(unsigned int raw, unsigned int addr) : raw{ raw }, addr{ addr } {};
    void op(Environment& env) override {
        env.sp++;
        env.stack[env.sp - 1] = env.pc;
        env.pc = addr;
    }
};
