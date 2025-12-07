#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class JumpAddress : public Instruction {
public:
    unsigned int addr;
    JumpAddress(unsigned int addr) : addr{ addr } {};
    void op(Environment& env) override {
        env.pc = addr;
    }
};
