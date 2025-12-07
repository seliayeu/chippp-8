#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class Call : public Instruction {
public:
    unsigned int addr;
    Call(unsigned int addr) : addr{ addr } {};
    void op(Environment& env) override {
        env.stack[env.sp++] = env.pc + 2;
        env.pc = addr;
    }
};
